#include "Monster.hpp"

Monster::Monster(Type type): Creature(monsterData[type].name, 
                                      monsterData[type].symbol,
                                      monsterData[type].health, 
                                      monsterData[type].damage,
                                      monsterData[type].gold){}

int Monster::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster Monster::getRandomMonster()
{
    Type monsterType = static_cast<Type>(getRandomNumber(0, MAX_TYPES-1));
    return Monster(monsterType);
}
