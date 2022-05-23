#include "./containers/Vector.hpp"
#include <vector>
#include <iostream>

int main() {
    
    std::vector<int> v;

    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;

    std::cout << "Check default push_back" << std::endl;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }

    std::cout << std::endl;
    Vector<int> myVector;
    std::cout << "Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;

    std::cout << "Check my push_back" << std::endl;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i);
        std::cout << "Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
    }

    
}