#include "./containers/Vector.hpp"
#include <vector>

int main() {
    
    std::vector<int> v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }
    
}