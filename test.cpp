#include "./containers/Vector.hpp"
#include <vector>
#include <iostream>

void vector_test() {
    
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

    // default operator= check
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

    // default operator= check
    {    
        Vector<int> a = myVector;
        std::cout << "Size: " << a.size() << " Capacity: " << a.capacity()  << std::endl;
        for (int i = 0; i < 10; ++i) {
            std::cout << "Value: " << a[i];
            std::cout << " Size: " << a.size() << " Capacity: " << a.capacity() << std::endl;
        }
    }

    //different constructors
    {  // vector_test(); // Vector(); []; at; push_back; operator=; Vector(&Vector); size(); capacity(); ~Vector();
    // std::vector<int> v(5); //создает вектор size=5 cap=5, value всегда ноль
    std::vector<int> v(5, 3); // (size, value)
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "Value: " << v[i];
        std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }

    Vector<int> myVector(5, 3);
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << "Value: " << myVector[i];
        std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity() << std::endl;
    }
    }

    //back and front
    {
    // vector_test();
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        // std::cout << "Value: " << v[i];
        // std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }
    std::cout << "first elem is: " << v.front() << ", last elem is: " << v.back() << std::endl;


    Vector<int> myVector; 

    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i);
        // std::cout << "Value: " << myVector[i];
        // std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity() << std::endl;
    }
    std::cout << "first elem is: " << myVector.front() << ", last elem is: " << myVector.back() << std::endl;
}
// empty
{
    std::vector<int> v(5);
    std::cout << v.empty() << std::endl;
    // 0 - not empty (if size > 0)
    // 1 - empty

    Vector<int> myVector(5); 
    std::cout << myVector.empty() << std::endl;

}

{
    // default swap testing
    std::vector<int> a1;
     for (int i = 0; i < 5; ++i) {
        a1.push_back(9);
        std::cout << a1[i];
    }
    std::vector<int> a2;
    std::cout << std::endl;
     for (int i = 0; i < 9; ++i) {
        a2.push_back(i);
        std::cout << a2[i];
    }

    std::cout << std::endl << std::endl;
    a1.swap(a2);
    for (size_t i = 0; i < a1.size(); ++i) {
        std::cout << a1[i];
    }
     std::cout << " Size: " << a1.size() << " Capacity: " << a1.capacity() << std::endl;
     for (size_t i = 0; i < a2.size(); ++i) {
        std::cout << a2[i];
    }
    std::cout << " Size: " << a2.size() << " Capacity: " << a2.capacity() << std::endl<< std::endl<< std::endl;

    //////my swap testing
    {Vector<int> a1;
    for (int i = 0; i < 5; ++i) {
        a1.push_back(9);
        std::cout << a1[i];
    }
    Vector<int> a2;
    std::cout << std::endl;
     for (int i = 0; i < 9; ++i) {
        a2.push_back(i);
        std::cout << a2[i];
    }


    std::cout << std::endl << std::endl;
    a1.swap(a2);
    for (size_t i = 0; i < a1.size(); ++i) {
        std::cout << a1[i];
    }
     std::cout << " Size: " << a1.size() << " Capacity: " << a1.capacity() << std::endl;
     for (size_t i = 0; i < a2.size(); ++i) {
        std::cout << a2[i];
    }
    std::cout << " Size: " << a2.size() << " Capacity: " << a2.capacity() << std::endl;
}
}

//resize testing
{
        std::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);

    std::cout << "The vector holds: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(2, 4);
    std::cout << "After resize down to 2 (initializer = 4): ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

std::cout << '\n';std::cout << '\n';
    {
        Vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

    std::cout << "The vector holds: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(2, 4);
    std::cout << "After resize down to 2 (initializer = 4): ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';

    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(size_t i = 0; i < c.size(); ++i) {
        std::cout << c[i] << ' ';}
    std::cout <<"\nSize: " << c.size();
    std::cout <<"\nCapacity: " << c.capacity();
    std::cout << '\n';
    }
}

// pop_back testing
{    std::vector<int> v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
        std::cout << "Value: " << v[i];
        std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }
    v.pop_back();
    std::cout << "\nDef vector after popping back\n";

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "Value: " << v[i];
        std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
    }

    std::cout << '\n';
    std::cout << '\n';

    Vector<int> myVector;
    for (int i = 0; i < 10; ++i) {
        myVector.push_back(i);
        std::cout << "Value: " << myVector[i];
        std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
    }
    std::cout << "\nMy vector after popping back\n";

    myVector.pop_back();
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << "Value: " << myVector[i];
        std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
    }}
}
