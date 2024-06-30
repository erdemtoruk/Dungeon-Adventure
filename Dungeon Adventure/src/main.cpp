#include <ctime>

#include "unit.cpp"
#include "item.cpp"
#include "player.cpp"
#include "monster.cpp"
#include "dungeon.cpp"


int main(){
	
	srand(time(0));
	
	std::cout << "Enter your hero name: ";
	std::string input;
	std::getline(std::cin, input);
	Player p1 = Player(input);

	Dungeon d1 = Dungeon(p1);
	d1.play();
	
	return 0;
}
