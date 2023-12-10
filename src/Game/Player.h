#ifndef Player_h
#define Player_h
#include "../Enum.h"
#include "Classes.h"
#include <string>
#include <utility>

class Player
{
public:
	explicit Player(int hP = 10, int strength = 10, int finesse = 10, int iq = 10,
					int exp = 0, int money = 100, int armor = 5, std::string name = "Robert", CLASS className = FIGHTER);

	void set_health(int value);

	void set_strength(int value);

	void set_finesse(int value);

	void set_intelligence(int value);

	void set_exp(int value);

	void set_money(int value);

	void set_armor(int value);

	void set_name(std::string value);

	int get_hp() const;

	int get_strength() const;

	int get_finesse() const;

	int get_intelligence() const;

	int get_exp() const;

	int get_money() const;

	int get_armor() const;

	CLASS get_class() const;

	void set_character(CLASS className);

	std::string get_name() const;

private:
	int hP;
	int strength;
	int finesse;
	int iq;
	int exp;
	int money;
	int armor;
	std::string name;
	CLASS className;
};

#endif