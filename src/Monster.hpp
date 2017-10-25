#ifndef Monster_hpp
#define Monster_hpp


/// For inheritance. 
#include "Creature.hpp"


/// For random number generation.
#include <cstdlib>


/// For random number generation.
#include <ctime>



/**
 *
 * \class Monster
 *
 * \brief Models a monster which can fight in a game.
 *
 * Inherits publically from Creature so there are all the neccecary member variables to implement the monster in 
 * a simulation or game. The monster has one extra member variable that is not inherited which is the Type of the 
 * Monster. There are several useful data structures and functions in the class that make dealing with multiple 
 * and varied monsters in game/simulation very easy. 
 *
 */
class Monster: public Creature
{
    
public:
    
    /**
     *
     * \enum Type
     *
     * \brief Enumerates the difference types of Monsters.
     *
     * This enumeration type can take on three different values representing three different types of monsters.
     * Since they correspond to integer values in the enumeration this is very useful for randomly generating monsters. 
     * The MAX_TYPES hold the utility value that is the total number of different types of monsters.  
     *
     */
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };
    

    /**
     *
     * \struct MonsterData
     * 
     * \brief Struct to hold the different attributes of the Monster.
     *
     * This struct is a useful way to hold the attributes of the different monsters and it is used in the look up table
     * when generating monsters randomly.
     *
     */
    struct MonsterData
    {
        const char* name;
        char symbol;
        int health;
        int damage;
        int gold;
    };
    

    /**
     * 
     * \brief A look up table of MonsterData structs to hold the attributes for each monster type.
     *
     * The elements of this array each correspond to a MonsterData struct for each monster Type which holds the 
     * attributes of the corresponding monster Type. Due to the fact that type is an enumeration it is very easy to access
     * the elements of the lookup table by using the subscript operator on the array with the type you are interested in. 
     * i.e. the MonsterData struct for the Slime type can be accessed by monsterData[Slime]. The relative variable you are 
     * interested in can then be accessed via the member selection variable. i.e. to get the health of a slime just do 
     * monsterData[Slime].health.
     *
     * This is a static variable since it doesn't really belong to any object Monster. For this reason it needs to be defined
     * outside of the class, a good place is the main method. 
     *
     */
    static  MonsterData monsterData[MAX_TYPES];


    /// Member variable which represents the Type of the monster, as defined in the Type enumration.
    Type m_type;


    /**
     *
     * \brief Constructor that creates a monster from a given Type.
     *
     * The constructor uses the lookup table to initialize each of the base member variables of the Creature class based on the 
     * type it received. For a complete description of how this works see the documentation for the monsterData lookup table. 
     *
     * \param type Type instance that will be used as the monster Type which is being constructed. 
     *
     */
    Monster(Type type);


    /**
     *
     * \brief Generates random integers. 
     *
     * Function generates random integers in a specified range (inclusive). It is static since it doesn't belong to any instance of
     * the monster and is really just a helper function for generating random monsters, however it is kept public since it may be 
     * useful in a main method.
     *
     * \param min Integer representing the minimum value in the range in which the random numbers will be generated. 
     *
     * \param max Integer representing the maximum value in the range in which the random numbers will be generated. 
     *
     * \return Random integer between min and max inclusive. 
     *
     */
    static int getRandomNumber(int min, int max);


    /**
     *
     * \brief Generates a random monster. 
     *
     * Function generates a random monster. It is static since it doesn't belong to any instance of monster but returns an instance 
     * of a monster that is generated randomly. This function makes use of the fact that the monster Type is a enumration to convert
     * a randomly generated integer which is less than MAX_TYPES into a Monster Type, it then uses the Type to generate a monster using
     * the Monster(Type) constructor.
     *
     * \return Random Monster object. 
     *
     */
    static Monster getRandomMonster();

};



#endif /* Monster_hpp */
