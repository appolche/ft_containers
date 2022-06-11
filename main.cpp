#include "./containers/Vector.hpp"
#include "./containers/Stack.hpp"
#include "./utils/Iterator.hpp"
#include <vector>
#include <iostream>

int main() {
	std::cout << "<3 <3 <3 VECTOR TESTS <3 <3 <3			" << std::endl;
    vector_test();
	std::cout << "\n<3 <3 <3 STACK TESTS <3 <3 <3			" << std::endl;

	 stack_test();

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