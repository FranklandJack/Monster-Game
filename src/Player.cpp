#include "Player.hpp"

void Player::levelUp()
{
    ++m_level;
    ++m_attack;
}

const int  Player::getLevel() const{return m_level;}

const bool Player::hasWon()   const{return m_level>=20;}