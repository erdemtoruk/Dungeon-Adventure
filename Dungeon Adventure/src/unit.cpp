

#include "../include/unit.hpp"

Unit::Unit(std::string in_name, float in_health, int in_attack, int in_defense) : name(in_name), health(in_health), attack(in_attack), defense(in_defense){}

std::string Unit::get_name(){
	return name;
}

float Unit::get_health(){
	return health;
}

int Unit::get_attack(){
	return attack;
}

int Unit::get_defense(){
	return defense;
}
