#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "unit.hpp"

class Monster : public Unit{
	public:
		Monster();
		Monster(std::string, float , int, int);
		virtual void take_damage(float);
};

#endif //MONSTER_HPP
