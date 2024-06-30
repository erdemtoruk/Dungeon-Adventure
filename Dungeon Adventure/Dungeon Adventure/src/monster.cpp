#include "../include/monster.hpp"

Monster::Monster() : Unit("Empty", 0, 0, 0) {}

Monster::Monster(std::string in_name, float in_health, int in_attack, int in_defense) : Unit(in_name, in_health, in_attack, in_defense){}

void Monster::take_damage(float dmg){
	health -= dmg * 100 / (100 + defense);
}
