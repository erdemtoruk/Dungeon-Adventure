#include <fstream>
#include <sstream>
#include <cstdlib>


#include "../include/dungeon.hpp"

const int LEVEL_1_MONSTERS = 7; //Number of Level 1 Monsters
const int LEVEL_2_MONSTERS = 7; //Number of Level 2 Monsters
const int LEVEL_3_MONSTERS = 7; //Number of Level 3 Monsters

const int LEVEL_1_ITEMS = 6; //Number of Level 1 Items
const int LEVEL_2_ITEMS = 7; //Number of Level 2 Items
const int LEVEL_3_ITEMS = 10; //Number of Level 3 Items

Dungeon::Dungeon(Player p1) : flag(true), player1(p1), enemy_num(1){
	std::ifstream file1("../data/monsters.txt");
	std::ifstream file2("../data/items.txt");
	
	std::string line;
    std::string name;
    std::string value2;
    std::string value3;
    std::string value4;
    std::string value5;
    float health;
    int attack;
    int defense;
    int no;
    
	if(file1.is_open()){	
		while (getline(file1, line)) {	
			std::stringstream ss;
			ss << line;
			ss >> name >> value2 >> value3 >> value4;
            health = atof(value2.c_str());
            attack = atoi(value3.c_str());
            defense = atoi(value4.c_str());
			monster_market.push_back(Monster(name, health, attack, defense));	
        }
        file1.close();
	}
	else{
		std::cerr << "Dosya açýlamadý: " << "../data/monsters.txt" << std::endl;
	}
	
	if(file2.is_open()){	
		while (getline(file2, line)) {	
			std::stringstream ss;
			ss << line;
			ss >> name >> value2 >> value3 >> value4 >> value5;
            health = atof(value2.c_str());
            attack = atoi(value3.c_str());
            defense = atoi(value4.c_str());
            no = atoi(value5.c_str());
			item_market.push_back(Item(name, health, attack, defense, no));	
        }
        file2.close();
	}
	else{
		std::cerr << "Dosya açýlamadý: " << "../data/items.txt" << std::endl;
	}
	
	//create_room(3);
}

int Dungeon::create_room(){
	int enemy = 1;
	int mod;
	int add;
	
	if(player1.get_level() == 1){
		enemy = 1;
		mod = LEVEL_1_MONSTERS;
		add = 0;
	}
	else if(player1.get_level() == 2){
		enemy = 2;
		mod = LEVEL_1_MONSTERS + LEVEL_2_MONSTERS;
		add = 0;
	}
	else if(player1.get_level() < 5){
		enemy = 3;
		mod = LEVEL_2_MONSTERS;
		add = LEVEL_1_MONSTERS;
	}
	else if(player1.get_level() < 7){
		enemy = 4;
		mod = LEVEL_2_MONSTERS + LEVEL_3_MONSTERS ;
		add = LEVEL_1_MONSTERS;
	}
	else{
		enemy = 5;
		mod = LEVEL_3_MONSTERS;
		add = LEVEL_1_MONSTERS + LEVEL_2_MONSTERS;
	}
	
	
	for(int i = 0; i < enemy; i++){
		int index = (rand() % mod) + add;
		room1[i] = monster_market.at(index);
		
		index = (rand() % mod) + add;
		room2[i] = monster_market.at(index);
	}
	
	flag = false;
	return enemy;
}

void Dungeon::show_room(int enemy){
	
	std::cout << "Room 1" << std::endl;
	std::cout << "-------------------" << std::endl;
	for(int i = 0; i < enemy; i++){
		std::cout << i+1 <<". " << room1[i].get_name() << std::endl << std::endl;
	}
	
	std::cout << "Room 2" << std::endl;
	std::cout << "-------------------" << std::endl;
	for(int i = 0; i < enemy; i++){
		std::cout << i+1 <<". " << room2[i].get_name() << std::endl << std::endl;
	}	
}

int Dungeon::choose_enemy(int enemy_number){
	
	std::string in;
	int num;
		
	std::cout << "\nWho will you hit: ";
	std::getline(std::cin, in);
	
	std::istringstream iss(in);
	iss >> num;
	
	if(num > 0 && num < enemy_number + 1){
		return num - 1;
	}
	else{
		std::cout << "Invalid input! Try again." << std::endl;
		choose_enemy(enemy_number);
	}
}

void Dungeon::fight_status(int enemy_number, Monster room[]){
	std::cout << "======= " << player1.get_name() << " =======" << std::endl << std::endl;
	std::cout << "Health: " << player1.get_health() << " | Attack: " << player1.get_attack() << " | Defense: " << player1.get_defense() << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
			
	std::cout << "======= Enemies =======" << std::endl << std::endl;
	for(int i = 0; i < enemy_number; i++){
		if(room[i].get_health() > 0){
			std::cout << i+1 << ": " << room[i].get_name() << " | Health: " << room[i].get_health() << " | Attack: " << room[i].get_attack() << " | Defense: " << room[i].get_attack() << std::endl;
		}
		else{
			std::cout << i+1 << ":  Death"<< std::endl;
		}
	}
}

bool Dungeon::drop_item(){
	int num = player1.get_level() * 3 + (rand() % 100);
	
	return num > 50;
}

void Dungeon::choose_item(){
	
	int mod;
	int add;
	
	if(player1.get_level() == 1){
		mod = LEVEL_1_ITEMS;
		add = 0;
	}
	else if(player1.get_level() == 2){
		mod = LEVEL_1_ITEMS + LEVEL_2_ITEMS;
		add = 0;
	}
	else if(player1.get_level() == 3){
		mod = LEVEL_2_ITEMS;
		add = LEVEL_1_ITEMS;
	}
	else if(player1.get_level() == 4){
		mod = LEVEL_2_ITEMS + LEVEL_3_ITEMS;
		add = LEVEL_1_ITEMS;
	}
	else{
		mod = LEVEL_3_ITEMS;
		add = LEVEL_1_ITEMS + LEVEL_2_ITEMS;
	}
	
	int chosen_item = (rand() % mod) + add;
		std::cout << "You found " << item_market.at(chosen_item).get_name() << std::endl;
		std::cout << "Do you want to take? (y/n) ";
		std::string input;
		while(true){
			std::getline(std::cin, input);
			if(input == "y"){
				player1.add_item(item_market.at(chosen_item));
				break;
			}
			else if(input == "n"){
				break;
			}
			else{
				std::cout << "Invalid input" << std::endl;
			}
		}
}

void Dungeon::fight(Monster room[], int enemy_number){
	flag = true;
	
	while((player1.get_health() > 0) && (room[0].get_health() > 0 || room[1].get_health() > 0 || room[2].get_health() > 0 || room[3].get_health() > 0 || room[4].get_health() > 0)){
			
			fight_status(enemy_number, room);
			
			int chosen_enemy = choose_enemy(enemy_number);
			room[chosen_enemy].take_damage(player1.get_attack());	
			
			for(int i = 0; i < enemy_number; i++){
				if(room[i].get_health() > 0){
					player1.take_damage(room[i].get_attack());
					break;
				}	
			}	
		}
		if(player1.get_health() > 0){
			std::cout << "You won the battle" << std::endl;
			
			if(rand() % 7 == 0){
				std::cout << "You found health potion! 20hp recovered." << std::endl;
				player1.use_potion(20.0);
			}
			
			player1.gain_exp(14);
			
			if(drop_item()){
				choose_item();	
			}
			
			play();		
		}
		else{
			std::cout << "You died!" << std::endl;
		}
}

void Dungeon::print_message(){
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Available commands:" << std::endl;
    std::cout << "    s: show status" << std::endl;
    //cout << "    pX: pop X. item" << endl;
    std::cout << "    r: show rooms" << std::endl;
    std::cout << "    cX: go X. room" << std::endl;
    std::cout << "    q: exit the game properly" << std::endl;
}

void Dungeon::play(){
	print_message();
	
	std::string input;
	std::getline(std::cin, input);
	std::cout << "------------------------------------------------------------" << std::endl;
	if(input == "q"){
		std::cout << "=========== Game over ===========" << std::endl;
		player1.show_status();
	}
	else if (input == "s"){
		player1.show_status();
		play();
	}
	/*
	else if (input[0] == 'p'){
		istringstream iss(input.substr(1, input.length()));
		int num;
		iss >> num;
		if(num < 11 && num > 0){
			player1.pop_item(num);
		}
		else{
			cout << "Invalid input. Try again" << endl;
		}
		play();
	}
	*/
	else if(input == "r"){
		if(flag){
			enemy_num = create_room();
		}
		show_room(enemy_num);
		play();
	}
	else if(input[0] == 'c'){
		std::istringstream iss(input.substr(1, input.length()));
		int num;
		iss >> num;
		if(num == 1){
			if(!flag){
				fight(room1, enemy_num);
			}
			else{
				std::cout << "Rooms were not created" << std::endl;
				play();
			}
		}
		else if(num == 2){
			if(!flag){
				fight(room2, enemy_num);
			}
			else{
				std::cout << "Rooms were not created" << std::endl;
				play();
			}
		}
		else{
			std::cout << "Invalid input. Try again" << std::endl;
			play();
		}
	}
	else{
		std::cout << "Invalid input. Try again" << std::endl;
		play();
	}
}
