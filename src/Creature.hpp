#ifndef Creature_hpp
#define Creature_hpp


/// For the creature name.
#include <string> 


/**
 *
 * \class Creature
 *
 * \brief Models a creature which can fight in a game.
 *
 * The Creature has a name, a symbol, health level, attack level and gold level. This makes it useful 
 * for games and simulations involving conflicts between creatures that result in exchanges of gold. 
 *
 */
class Creature
{

protected:

    /// Std::string variable to hold the name of the creature. 
    std::string m_name;

    /// Char variable to hold a symbol that represents the creature. 
    char m_symbol;

    /// Integer variable that represents the health of the creature.
    int m_health;

    /// Integer variable that represents the number of damage points done when the creature attacks.
    int m_attack;

    /// Integer variable that represents the amount of gold the creature has. 
    int m_gold;
    
public:
    /**
     *
     * \brief Standard constructor that just initializes the member variables by copying in the arguments. 
     *
     * \param name std::string which will set the m_name member variable of the creature.
     *
     * \param symbol char which will set the m_symbol member variable of the creature. 
     *
     * \param health Integer value which will set the m_health member variable of the creature. 
     *
     * \param attack Integer value which will set the m_attack member variable of the creature.
     *
     * \param gold Integer value which will set the m_gold member variabe of the creature. 
     *
     */
    Creature(std::string name, char symbol , int health, int attack, int gold);


    /**
     *
     * \brief Simple getter for the m_name member variable.
     *
     * \return Constant reference for the m_name member variable.
     *
     */
    const std::string& getName() const;


    /**
     *
     * \brief Simple getter for the m_symbol member variable.
     *
     * \return char value which is a copy of the m_symbol member variable.
     *
     */
    char getSymbol() const;


    /**
     *
     * \brief Simple getter for the m_health member variable.
     *
     * \return Integer value which is a copy of the m_health member variable.
     *
     */
    int getHealth() const;


    /**
     *
     * \brief Simple getter for the m_attack member variable.
     *
     * \return Integer value which is a copy of the m_attack member variable.
     *
     */
    int getAttack() const;


    /**
     *
     * \brief Simple getter for the m_golf member variable.
     *
     * \return Integer value which is a copy of the m_gold member variable.
     *
     */
    int getGold() const;
    

    /**
     *
     * \brief Reduces the creatures health by a given amount.
     *
     * This method replaces any setter methods for the health that one might expect. 
     *
     * \param hp Integer value which is the number of health points to reduce the creature's m_health member variable by.
     *
     */
    void reduceHealth(int hp);


    /**
     *
     * \brief Checks whether the creature is dead.
     *
     * The creature is considered to be dead if m_health <= 0.
     *
     * \return Boolean value representing whether the creature is alive(true) or dead(false).
     *
     */
    bool isDead();

    /**
     *
     * \brief Adds a specified amount of gold the the creature.
     *
     * This method replaces any setter methods for the gold that one might expect. 
     *
     * \param golf Integer value which is the amount by which to increase the creature's m_gold member variable by.
     *
     */
    void addGold(int gold);
};

#endif /* Creature_hpp */
