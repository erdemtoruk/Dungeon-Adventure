#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <vector>

#include "player.hpp"
#include "monster.hpp"
#include "item.hpp"

class Dungeon{
	Player player1;
	std::vector<Monster> monster_market;
	std::vector<Item> item_market;
	
	Monster room1[5];
	Monster room2[5];
	bool flag;
	int enemy_num;
	
	
	int choose_enemy(int);
	void fight_status(int, Monster[]);
	void choose_item();
	bool drop_item();
	int create_room();
	void show_room(int);
	void print_message();
	void fight(Monster[], int);
	
	public:
		Dungeon(Player);
		void play();	
};

#endif //DUNGEON_HPP
