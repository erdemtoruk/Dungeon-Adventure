#include "../include/item.hpp"

Item::Item() : Unit("Empty", 0 , 0, 0), no(-1) {};

Item::Item(std::string in_name, float in_health, int in_attack, int in_defense, int in_no) : Unit(in_name, in_health, in_attack, in_defense), no(in_no) {}

void Item::show_stats(){
	std::cout << name << std::endl;
	//cout << "-------------------" << endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: "<< defense << std::endl;
	std::cout << "-----------" << std::endl;
}

int Item::get_no(){
	return no;
}

void Item::take_damage(float dmg){
	health -= dmg;
}
