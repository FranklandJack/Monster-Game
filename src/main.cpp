// For any commandline input/output.
#include <iostream>   


// For storing player name.
#include <string>  


// For implementing the player in the game.
#include "Player.hpp"  


// For implementing the various monsters in the game.
#include "Monster.hpp" 


// For pseudo random number generation in the game.
#include <cstdlib>     


// For seeding the pseudo random number generation in the game.
#include <ctime>       

// This it the lookup table that is declared in the Monster class. Because it is a static array
// it has to be defined outside the class. 
Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES] 
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};


// This is a quick way to grab the players name as a command line input. 
std::string getPlayerName()
{
    std::cout << "Enter your name (please, no spaces): ";
    std::string playerName;
    std::cin >> playerName;
    return playerName;
}


// This deals with the player attacking the monster. 
void attackMonster(Player &p, Monster &m)
{

    // If the player is dead, it cannot by definition fight the monster, so it can return early.
    if(p.isDead()) return;
    

    // Otherwise the player hits monster. 
    std::cout << "You hit the " << m.getName()<<" for " << p.getAttack() << " damage.\n";

    m.reduceHealth(p.getAttack());


    // If the monster is dead then it cannot retaliate. The player gets to keep the monster's gold and also levels up. 
    if(m.isDead())
    {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.levelUp();
        std::cout << "you are now level " << p.getLevel() << '\n';
        std::cout << "you found " << m.getGold() << " gold.\n";
        p.addGold(m.getGold());
    }
    
}


// Reciprocal of the attackMonster() function, deals with monster attacking player.
void attackPlayer(Monster &m, Player &p)
{

    // If the monster is dead, it cannot attack the player, so it returns early. 
    if(m.isDead()) return;
    

    // Otherwise monster hits player. 
    std::cout << "The " << m.getName() << " hit you for " << m.getAttack() << " damage.\n";

    p.reduceHealth(m.getAttack());


    // Since the monsters don't accumulate gold, or level up, the function ends here, unlike the attackMonster() function.
}


// This deals with the fight between the player and a monster.
void fightMonster(Player &p)
{

    // First need to randomly generate a monster to fight with.
    Monster m = Monster::getRandomMonster();
    std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")\n";
    

    // While neither the player or monster is dead they can still fight.
    while(!p.isDead()&&!m.isDead())
    {

        // Get the user action input.
        std::cout << "Run or fight?(R/F):";
        char playerChoice;
        std::cin >> playerChoice;
        

        if(playerChoice=='R'||playerChoice=='r')
        {

            // If the player chooses to run then they have a 50/50 chance of success. 
            if(2 == Monster::getRandomNumber(1, 2))
            {
                std::cout << "You successfullly escaped!\n";


                // At this point the function ends, since the player has escaped from the monster. 
                return;
            }
    

            // If the player fails to flee then the monster gets a free attack on the player, and we return to the start of the 
            // fight process. 
            else
            {
                std::cout << "You failed to escape! (oh no)\n";
                attackPlayer(m, p);
                continue;
            }
        }
        

        // If the player chooses to fight then they get to attack first, then the monster attacks second.
        if(playerChoice=='F'||playerChoice=='f')
        {
            attackMonster(p, m);
            attackPlayer(m, p);
        }
    }
    

    // If either the monster or player is dead, there is no more fighting to be done so the function ends.
    return;
}

int main()
{

    // Set initial seed value to that of system clock.
    srand(static_cast<unsigned int>(time(0))); 


    // Get rid of first result since this sometimes gives non random results.
    rand(); 
    

    // Gather the user details and create a Player object so we can play the game.
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    
    Player myPlayer(playerName);
    
    std::cout << "Welcome to this state of the art monster simulation game " << myPlayer.getName() << "!\n";


    // Logically, while the player hasn't died or hasn't won, they must still be playing.
    while(!myPlayer.isDead()&&!myPlayer.hasWon())
    {
        fightMonster(myPlayer);
    }


    // Now either the player is dead, or they have won, so the game logic must deal with both those cases.
    if(myPlayer.isDead())
    {
        std::cout << "Oh no " << myPlayer.getName() << " you are dead! " << "You finished the game with " << 
        myPlayer.getGold() << " gold at level " << myPlayer.getLevel() << ".\n";
    }
    
    else
        std::cout << "Congratulations " << myPlayer.getName() << " You won the game with " << 
        myPlayer.getGold() << " gold! Well done you.\n";
    return 0;
}
