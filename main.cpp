#include "./containers/Vector.hpp"
#include "./containers/Stack.hpp"
#include "./containers/Map.hpp"
#include "./utils/Iterator.hpp"
#include "./utils/RBTree.hpp"
#include "./utils/Pair.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace ft;

int main() {
	std::cout << "<3 <3 <3 VECTOR TESTS <3 <3 <3			" << std::endl;
   //  vector_test();
	std::cout << "\n<3 <3 <3 STACK TESTS <3 <3 <3			" << std::endl;
	std::map<int, int> s;
	s.insert(std::make_pair(8, 6));
	s.insert(std::make_pair(10, 52));
	s.insert(std::make_pair(3, 11));
	
	std::pair<std::map<int, int>::iterator, bool> pairTest = s.insert(std::make_pair(3, 11));
	bool boo = pairTest.second;
	std::cout << "insert bool (inserting existing value): " << boo << std::endl;

	pairTest = s.insert(std::make_pair(5, 11));
	boo = pairTest.second;
	std::cout << "insert bool (inserting new value): " << boo << std::endl;
	// std::map<int, int>::iterator a =  s.find(10);


	ft::map<int, int> mys;
	mys.insert(ft::make_pair(8, 6));
	mys.insert(ft::make_pair(10, 52));
	mys.insert(ft::make_pair(3, 11));

	ft::map<int, int> neww;
	neww.insert(ft::make_pair(5, 3));
	neww.insert(ft::make_pair(2, 1));
	neww.insert(ft::make_pair(7, 8));
	// ft::map<int, int>::iterator mya =  mys.find(10);
	mys = neww;
	// std::cout << s.find(10)->second << std::endl;
	std::cout << mys.find(7)->second << std::endl;


	// ft::map<char, int> m;
	// m.insert(ft::make_pair('A', 5));
	
	//  stack_test();x

    // std::vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

 
    // std::cout << "Before clear:\n";
    // for (size_t i = 0; i < v.size(); ++i) {
    //     std::cout << "Value: " << v[i];
    //     std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << std::endl;
    // }
    // std::cout << "Clear\n";
    // v.clear();
 
    // std::cout << "After clear:\n";
    // for (size_t i = 0; i < v.size(); ++i) {
    //     std::cout << "Value: " << v[i];
    //     std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << std::endl;
    // }
    // std::cout << std::endl << std::endl;
    // {
    // Vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

 
    // std::cout << "Before clear:\n";
    // for (size_t i = 0; i < v.size(); ++i) {
    //     std::cout << "Value: " << v[i];
    //     std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << std::endl;
    // }
    // std::cout << "Clear\n";
    // v.clear();
 
    // std::cout << "After clear:\n";
    // for (size_t i = 0; i < v.size(); ++i) {
    //     std::cout << "Value: " << v[i];
    //     std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << std::endl;
    // }
    // }

}