#include "./containers/Vector.hpp"
#include <vector>
#include <iostream>

int main() {
    
    std::vector<int> v;

    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;

    std::cout << "Check default push_back" << std::endl;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "Value: " << v[i];
        std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }
        std::cout << "Value: " << v[5];

    // default copy constructor check
    std::cout << "\n----------------------------------------------------" << std::endl;
    {
        std::vector<int> a(v);
        std::cout << "Size: " << a.size() << " Capacity: " << a.capacity()  << " Max_size: " << a.max_size() << std::endl;
        for (int i = 0; i < 10; ++i) {
            a.push_back(i);
            std::cout << "Value: " << a[i];
            std::cout << " Size: " << a.size() << " Capacity: " << a.capacity()  << " Max_size: " << a.max_size() << std::endl;
        }
    }

    // default operator = check
    std::cout << "\n----------------------------------------------------" << std::endl;
    {
        std::vector<int> a = v;
        std::cout << "Size: " << a.size() << " Capacity: " << a.capacity()  << " Max_size: " << a.max_size() << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << "Value: " << a[i];
            std::cout << " Size: " << a.size() << " Capacity: " << a.capacity()  << " Max_size: " << a.max_size() << std::endl;
        }
    }

    
    std::cout << "\n----------------------------------------------------" << std::endl;
    Vector<int> myVector;
    std::cout << "Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
    std::cout << "Check my push_back and []" << std::endl;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i);
        std::cout << "Value: " << myVector[i];
        std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
    }
    // copy constructor check
    std::cout << "\n----------------------------------------------------" << std::endl;
    {    
        Vector<int> a(myVector);
        std::cout << "Size: " << a.size() << " Capacity: " << a.capacity()  << std::endl;
        for (int i = 0; i < 10; ++i) {
            a.push_back(i);
            std::cout << "Value: " << a[i];
            std::cout << " Size: " << a.size() << " Capacity: " << a.capacity() << std::endl;
        }
    }

    // default operator = check
    {    
        Vector<int> a = myVector;
        std::cout << "Size: " << a.size() << " Capacity: " << a.capacity()  << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << "Value: " << a[i];
            std::cout << " Size: " << a.size() << " Capacity: " << a.capacity() << std::endl;
        }
    }
    
}