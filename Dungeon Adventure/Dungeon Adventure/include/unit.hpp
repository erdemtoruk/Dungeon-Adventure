#ifndef UNIT_HPP
#define UNIT_HPP

#include <iostream>

class Unit{
	protected:
		std::string name;
		float health;
		int attack;
		int defense;
	
	public:
		Unit(std::string, float, int, int);
		virtual void take_damage(float) = 0;
		std::string get_name();
		float get_health();
		int get_attack();
		int get_defense();
};

#endif //UNIT_HPP
