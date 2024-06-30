#ifndef ITEM_HPP
#define ITEM_HPP

#include "unit.hpp"

class Item : public Unit{
	int no;
	
	public:
		Item();
		Item(std::string, float, int, int, int);
		void show_stats();
		int get_no();
		//0: Kask | 1: G���sl�k | 2: Silah | 3: Kalkan | 4: Bacakl�k | 5: Ayakkab� 
		virtual void take_damage(float);
};

#endif //ITEM_HPP
