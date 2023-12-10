#ifndef Player_cpp
#define Player_cpp
#include "Player.h"

Player::Player(int hP, int strength, int finesse, int iq, int exp, int money, int armor,
			   std::string name, CLASS className)
{
	if (hP < 0 || armor < 0 || exp < 0 || strength < 0 || finesse < 0 || iq < 0)
		throw "Incorrect input";
	this->hP = hP;
	this->strength = strength;
	this->finesse = finesse;
	this->iq = iq;
	this->exp = exp;
	this->money = money;
	this->armor = armor;
	this->name = name;
	this->className = className;
}

void Player::set_health(int value)
{
	if (value < 0)
		this->hP = 0;
	else
		this->hP = value;
}

void Player::set_strength(int value)
{
	if (value < 0)
		this->strength = 10;
	else
		this->strength = value;
}

void Player::set_finesse(int value)
{
	if (value < 0)
		this->finesse = 10;
	else
		this->finesse = value;
}

void Player::set_intelligence(int value)
{
	if (value < 0)
		this->iq = 10;
	else
		this->iq = value;
}

void Player::set_exp(int value)
{
	if (value < 0)
		this->exp = 0;
	else
		this->exp = value;
}

void Player::set_money(int value)
{
	this->money = value;
}

void Player::set_armor(int value)
{
	if (value < 0)
		this->armor = 0;
	else
		this->armor = value;
}

int Player::get_hp() const
{
	return this->hP;
}

int Player::get_strength() const
{
	return this->strength;
}

int Player::get_finesse() const
{
	return this->finesse;
}

int Player::get_intelligence() const
{
	return this->iq;
}

int Player::get_exp() const
{
	return this->exp;
}

int Player::get_money() const
{
	return this->money;
}

int Player::get_armor() const
{
	return this->armor;
}

std::string Player::get_name() const
{
	return this->name;
}

void Player::set_name(std::string value)
{
	this->name = value;
}

CLASS Player::get_class() const
{
	return this->className;
}

void Player::set_character(CLASS className)
{
	Classes player_subclass(className);
	this->hP = player_subclass.hP;
	this->strength = player_subclass.strength;
	this->finesse = player_subclass.finesse;
	this->iq = player_subclass.iq;
	this->exp = player_subclass.exp;
	this->money = player_subclass.money;
	this->armor = player_subclass.armor;
	this->className = player_subclass.className;
}

#endif