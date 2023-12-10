#ifndef Classes_h
#define Classes_h
#include "../Enum.h"

class Classes
{
public:
	Classes(CLASS className)
	{
		switch (className)
		{
		case (CLASS::FIGHTER):
			this->hP = 17;
			this->strength = 15;
			this->finesse = 21;
			this->iq = 100;
			this->exp = 50;
			this->money = 50;
			this->armor = 10;
			this->className = CLASS::FIGHTER;
			break;
		case (CLASS::SPION):
			this->hP = 11;
			this->strength = 10;
			this->finesse = 14;
			this->iq = 170;
			this->exp = 75;
			this->money = 100;
			this->armor = 5;
			this->className = CLASS::SPION;
			break;
		case (CLASS::PIRAT):
			this->hP = 16;
			this->strength = 22;
			this->finesse = 17;
			this->iq = 100;
			this->exp = 20;
			this->money = 10;
			this->armor = 1;
			this->className = CLASS::PIRAT;
			break;
		default:
			break;
		}
	};

	int hP;
	int strength;
	int finesse;
	int iq;
	int exp;
	int money;
	int armor;
	CLASS className;

	~Classes() = default;
};

#endif