#include "../include/player.hpp"

Player::Player(std::string in_name) : Unit(in_name, 100.0, 3, 0), max_health(100.0),experience(0), level(1), item_counter(6){}

void Player::take_damage(float dmg){
	health -= dmg * 100 / (100 + defense);
}

void Player::gain_exp(int exp){
	experience += exp;
	if(experience >= 100){
		level++;
		experience -= 100;
	}
}

void Player::add_item(Item item){
	/*
	if(item_counter < 10){
		inventory[item_counter] = item;
		item_counter++;
	}
	else{
		for (int i = 9; i > 0; i--){
			inventory[i] = inventory[i-1];
		}
		inventory[0] = item; 
	}
	*/
	
	inventory[item.get_no()] = item;
	
	calc_stats();
}
/*
void Player::pop_item(int num){
	if(num <= 10){
		for (int i = num-1; i < 9; i++){
			inventory[i] = inventory[i+1];
		}
		inventory[9] = Item();
		//item_counter--;
	}
	calc_stats();
}
*/
void Player::calc_stats(){
	float _health = 0.0;
	int _attack = 0;
	int _defense = 0;
	for(int i = 0; i < item_counter; i++){
		_health += inventory[i].get_health();
		_attack += inventory[i].get_attack();
		_defense += inventory[i].get_defense();
	}
	max_health = 50 * (level + 1) + _health;
	attack = 3 * level + _attack;
	defense = 2 * (level-1) + _defense; 
}

void Player::show_status(){
	std::cout << "   " << name << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Health: " << health << "/" << max_health << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: "<< defense << std::endl;
	std::cout << "Level: "<< level << "  " << experience << "/100"<< std::endl;
	std::cout << "    Inventory" << std::endl;
	std::cout << "-------------------" << std::endl;
	for(int i = 0; i < item_counter; i++){
		std::cout << i+1 << ":    ";
		inventory[i].show_stats();
	}
}

void Player::use_potion(float value){
	health += value;
	if(health > max_health){
		health = max_health; 
	}
}

int Player::get_level(){
	return level;
}
