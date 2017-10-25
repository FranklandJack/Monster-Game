#ifndef Player_hpp
#define Player_hpp


// For inheritance purposes. 
#include "Creature.hpp" 

/**
 *
 * \class Player
 *
 * \brief Models a Player which can fight and lvel up in a game.
 *
 * Inherits publically from Creature so there are all the neccecary member variables to implement the player in 
 * a simulation or game. The player also has a level which represents the users progress in the simulation and game.
 * The player can level up which will increase their and attack by 1. A player is to be considered having 'won' if
 * their level exceeds 20. 
 *
 */
class Player: public Creature
{

private:


    /**
     * 
     * \brief Int variable to represent the level of the player. 
     * 
     * This will start always at 1, but can be increased via the levelUp() function.
     *
     */
    int m_level=1;
    
public:


    /** 
     *
     * \brief Simple constructor which calls the base class constructor with some fixed values which represent player details.
     *
     * The base class constructor is called with the provided name, but with the fixed vales of; '@' which is the players symbol
     * and initializes the m_sylmbol variable, 10 which is the players intital health and initializes the m_health variable, 1 
     * which is the players initial attack and initializes the m_attack variable, 0 which is the players initial gold and 
     * initializes the m_gold variable.      
     *
     * \param name std::string which will set the m_name variable in the base class and represents the players name.
     *
     */
    Player(std::string name):Creature(name,'@',10,1,0){}
    

    /** 
     *
     * \brief Levels up the player
     *
     * Levelling up the player results in the m_level and m_attack member variable increasing by 1.
     *
     */
    void levelUp();


    /**
     * \brief Getter for the m_level member variable.
     *
     * \return Integer value representing the level of the player, which is the value of m_level.
     *
     */
    const int getLevel() const;

    /**
     *
     * \brief Check whether the player has "won".
     *
     * Player is considered to have won if their level exceeds 20.
     *
     * \return Boolean value repreenting wether the player has won(true) or not-won(false)
     *
     */
    const bool hasWon() const;
};

#endif /* Player_hpp */
