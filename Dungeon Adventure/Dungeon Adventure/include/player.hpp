#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"

class Player : public Unit{	
	float max_health;
	int experience;
	int level;
	int item_counter;
	Item inventory[6];
	
	public:
		Player(std::string);
		virtual void take_damage(float);
		void gain_exp(int);
		void add_item(Item);
		//void pop_item(int);
		void calc_stats();
		void show_status();
		void use_potion(float);	
		int get_level();	
};

#endif //PLAYER_HPP
