
#include "Hash.h"

//–еализовать hashmap(wiki, метод цепочек), использу€ vector и list.
//	void insert(const std::string& key, int value)
//	std::pair<int, bool> find(const std::string& key) //bool --- найден или нет, int --- значение
//	void erase((const std::string& key)				  // удал€ет один экземпл€р записи
//	operator<< дл€ вывода на экран

int main() {
	Hashmap<int> a;

	std::string b = "Laura Palmer";
	int number1 = 634;
	std::string c = "Donna Hayward";
	int number2 = 73;
	std::string d = "The Log Lady";
	int number3 = 166;
	std::string e = "Dr. Jacoby";
	int number4 = 835;
	std::string f = "Agent Cooper";
	int number5 = 966;
	std::string g = "Shelly Johnson";
	int number6 = 846;
	std::string h = "Pete Martell";
	int number7 = 835;
	std::string i = "Bobby Briggs";
	int number8 = 164;
	std::string j = "Sheriff Harry S. Truman";
	int number9 = 614;

	a.insert(b, number1);
	a.insert(c, number2);
	a.insert(d, number3);
	a.insert(e, number4);
	a.insert(f, number5);
	a.insert(g, number6);
	a.insert(h, number7);
	a.insert(i, number8);
	a.insert(j, number9);

	a.erase(b);

	std::cout << a;
	if ((a.find(b)).second == 0)
		std::cout << "\n Who murdered Laura Palmer?";
	else
		std::cout << "\n Twin Peaks is a very calm, beautiful place";

	return 0;
}