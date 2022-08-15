#include "./containers/Vector.hpp"
#include "./containers/Stack.hpp"
#include "./containers/Map.hpp"
#include "./containers/Set.hpp"
#include "./utils/Iterator.hpp"
#include "./utils/RBTree.hpp"
#include "./utils/Pair.hpp"
#include <iostream>

int main() {
	std::cout << "\n	<3 <3 <3 VECTOR TESTS <3 <3 <3			" << std::endl;
    vector_test();
	std::cout << "\n	<3 <3 <3 STACK TESTS <3 <3 <3			" << std::endl;
    stack_test();
	std::cout << "\n	<3 <3 <3 PAIR TESTS <3 <3 <3			" << std::endl;
    pair_test();
	std::cout << "\n	<3 <3 <3 MAP TESTS <3 <3 <3			" << std::endl;
	map_tests();
	std::cout << "\n	<3 <3 <3 SET TESTS <3 <3 <3			" << std::endl;
	set_tests();
}