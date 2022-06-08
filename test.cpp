#include "./containers/Vector.hpp"
#include "./utils/Iterator.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace ft;

void vector_test() {

    std::cout << "*****************************\n*        CONSTRUCTORS       *\n*****************************" << std::endl;
    std::cout << "  1. DEFAULT" << std::endl; 
    {
        std::vector<int> v;
        std::cout << "STL: Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size() << std::endl;
        Vector<int> myVector;
        std::cout << "MY:  Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
    }

    std::cout << "\n  2. WITH SIZE AND VALUE" << std::endl;
    {
        std::vector<int> v(5, 3);
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << "STL: Value: " << v[i] << " ";
            std::cout << "Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size() << std::endl;
        }
         std::cout << "\n";
        Vector<int> myVector(5, 3);
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << "MY:  Value: " << myVector[i] << " ";
            std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
        }
    }
    std::cout << "\n  2b. WITH SIZE ONLY" << std::endl;
    {
        std::vector<int> v(5);
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << "STL: Value: " << v[i] << " ";
            std::cout << "Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size() << std::endl;
        }
         std::cout << "\n";
        Vector<int> myVector(5);
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << "MY:  Value: " << myVector[i] << " ";
            std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
        }
    }

    std::cout << "\n  3. COPY CONSTRUCT" << std::endl;
    {
        std::vector<int> a(6, 8);
        std::vector<int> v(a);
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << "STL: Value: " << v[i] << " ";
            std::cout << "Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size() << std::endl;
        }
         std::cout << "\n";
        Vector<int> myFirstVector(6, 8);
        Vector<int> myVector(myFirstVector);
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << "MY:  Value: " << myVector[i] << " ";
            std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
        }
    }

    std::cout << "\n  4. OPERATOR \" = \"" << std::endl;
    {
        std::vector<int> a(6, 8);
        std::vector<int> v = a;
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << "STL: Value: " << v[i] << " ";
            std::cout << "Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size() << std::endl;
        }
         std::cout << "\n";
        Vector<int> myFirstVector(6, 8);
        Vector<int> myVector = myFirstVector;
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << "MY:  Value: " << myVector[i] << " ";
            std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
        }
    }

    std::cout << "\n  5. ASSIGN" << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for (size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        c.assign(5, 8);
        for (size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}

    std::cout << "\n";
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        myVector.assign(5, 8);
        for (size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
    }

    std::cout << "\n*****************************\n*        ITERATORS       *\n*****************************" << std::endl;
    std::cout << "\n  1. BEGIN/END, RBEGIN/REND " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<"\nBegin: " << *(c.begin());
        std::cout <<" End: " << *(c.end() - 1);
        std::cout <<"\nRbegin: " << *(c.rbegin());
        std::cout <<" Rend: " << *(c.rend() - 1) << std::endl;

    std::cout << "\n";
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout <<"\nBegin: " << *(myVector.begin());
        std::cout <<" End: " << *(myVector.end() - 1);
        std::cout <<"\nRbegin: " << *(myVector.rbegin());
        std::cout <<" Rend: " << *(myVector.rend() - 1) << std::endl;
    }

    std::cout << "\n  2. CREATE ITERS AND MOVING BY *IT " << std::endl;
    {
        {std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::vector<int>::iterator it = c.begin();
        std::vector<int>::iterator ite = c.end();
    

        std::cout << "STL: The vector holds: ";
        for(; it != ite; ++it) {
            std::cout << *it << ' ';}
        }

    std::cout << "\n";
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        Vector<int>::iterator it = myVector.begin();
        Vector<int>::iterator ite = myVector.end();
        std::cout << "MY:  The vector holds: ";
        for(; it != ite; ++it) {
            std::cout << *it << ' ';}
    }
    
    std::cout << "\n*****************************\n*       ELEMENT ACCESS      *\n*****************************" << std::endl;
    
    std::cout << "\n  1. AT (WITHOUT PUSH_BACK)" << std::endl;
    {
        std::vector<int> v(5, 3);
        std::cout << "STL: " << v.at(4) << std::endl;
        try {
            std::cout << "STL: " << v.at(12) << std::endl;
        } catch (std::exception &ex) {
            std::cout << "Exception! " << ex.what() << std::endl;
        }

         std::cout << "\n";
        Vector<int> myVector(5, 3);
        std::cout << "MY:  " << myVector.at(4) << std::endl;
        try {
            std::cout << "MY:  " << myVector.at(12) << std::endl;
        } catch (std::exception &ex) {
            std::cout << "Exception! " << ex.what() << std::endl;
        }
    }
    
    std::cout << "\n  2. FRONT / BACK (WITH PUSH_BACK)" << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i) {
            v.push_back(i);
            std::cout << "STL: Value: " << v[i] << " ";
            std::cout << "Size: " << v.size() << " Cap: " << v.capacity()  << std::endl;
        }
        std::cout << "STL: first elem is: " << v.front() << ", last elem is: " << v.back() << std::endl;
         std::cout << "\n";

        Vector<int> myVector;
        for (int i = 0; i < 10; ++i) {
            myVector.push_back(i);
            std::cout << "MY:  Value: " << myVector[i] << " ";
            std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << std::endl;
        }
        std::cout << "MY:  first elem is: " << myVector.front() << ", last elem is: " << myVector.back() << std::endl;
    }

    std::cout << "\n*****************************\n*        CAPACITY       *\n*****************************" << std::endl;
    std::cout << "\n  1. EMPTY, SIZE, CAPACITY, MAX_SIZE " << std::endl;
    {
        std::vector<int> v;
        std::cout << "STL: (before push_back): " << v.empty() << std::endl;
        for (int i = 0; i < 10; ++i) {
            v.push_back(i);
        }
        std::cout << "STL: (after push_back):  " << v.empty() << " ";
        std::cout << "Size: " << v.size() << " Cap: " << v.capacity() << " Max_size: " << v.max_size()  << std::endl;
         std::cout << "\n";

        Vector<int> myVector;
        std::cout << "MY:  (before push_back): " << myVector.empty() << std::endl;
        for (int i = 0; i < 10; ++i) {
            myVector.push_back(i);
        }
        std::cout << "MY:  (after push_back):  " << myVector.empty() << " ";
        std::cout << "Size: " << myVector.size() << " Cap: " << myVector.capacity() << " Max_size: " << myVector.max_size() << std::endl;
    }

    std::cout << "\n  2. RESIZE " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;

        c.resize(5);
        std::cout << "STL: After resize up to 5: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;
        c.resize(2);
        std::cout << "STL: After resize down to 2: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;
        c.resize(6, 4);
        std::cout << "STL: After resize up to 6 (initializer = 4): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;
        c.resize(2, 4);
        std::cout << "STL: After resize down to 2 (initializer = 4): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;
        c.resize(5);
        std::cout << "STL: After resize up to 5: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" (Size: " << c.size() << " Cap: " << c.capacity() << ")"<< std::endl;

    std::cout << "\n";
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
        myVector.resize(5);
        std::cout << "MY:  After resize up to 5: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
        myVector.resize(2);
        std::cout << "MY:  After resize down to 2: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
        myVector.resize(6, 4);
        std::cout << "MY:  After resize up to 6 (initializer = 4): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
        myVector.resize(2, 4);
        std::cout << "MY:  After resize down to 2 (initializer = 4): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
        myVector.resize(5);
        std::cout << "MY:  After resize up to 5: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout << " (Size: " << myVector.size() << " Cap: " << myVector.capacity() << ")"<< std::endl;
    }

    std::cout << "\n  3. RESERVE " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<"Cap: " << c.capacity() << std::endl;

        c.reserve(10);
        std::cout << "STL: After reserve: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout <<" Cap: " << c.capacity() << std::endl;

    std::cout << "\n";
        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout <<"Cap: " << myVector.capacity() << std::endl;

        myVector.reserve(10);
        std::cout << "MY:  After reserve: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        std::cout <<" Cap: " << myVector.capacity() << std::endl;
    }

    std::cout << "\n*****************************\n*        MODIFIERS       *\n*****************************" << std::endl;
    std::cout << "\n  1. CLEAR " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        c.clear();
        std::cout << "\nSTL: The vector after clear(): " << "IsEmpty?: " << c.empty() << " Size: " << c.size() << std::endl;

        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        myVector.clear();
        std::cout << "\nMY:  The vector after clear(): " << "IsEmpty?: " << myVector.empty() << " Size: " << myVector.size() << std::endl;
    }
    std::cout << "\n  2. ERASE " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::vector<int>::const_iterator it = c.begin();
        std::vector<int>::const_iterator ite = c.end();
        c.erase(it);
        std::cout << "\nSTL: The vector after erase(): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << "Size: " << c.size() << "\n";

       { Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY: The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        Vector<int>::iterator it = myVector.begin();
        Vector<int>::iterator ite = myVector.end();
        myVector.erase(it);
        std::cout << "\nMY: The vector after erase(): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << "Size: " << myVector.size() << "\n";
        }
    }
        std::cout << "\n  2b. ERASE(FIRST, LAST)" << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::vector<int>::const_iterator it = c.begin();
        std::vector<int>::const_iterator ite = c.end();
        c.erase(it, ite);
        std::cout << "\nSTL: The vector after erase all elements(): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << "Size: " << c.size() << "\n";

       { Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY: The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        Vector<int>::iterator it = myVector.begin();
        Vector<int>::iterator ite = myVector.end();
        myVector.erase(it, ite);
        std::cout << "\nMY: The vector after erase all elements(): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << "Size: " << myVector.size() << "\n";
        }
    }
        std::cout << "\n  3. POP BACK " << std::endl;
    {
        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        c.pop_back();
        std::cout << "\nSTL: The vector after popping back holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}


        Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "\nMY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        myVector.pop_back();
        std::cout << "\nMY:  The vector after popping back holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
    }

            std::cout << "\n  3. SWAP " << std::endl;
    {
        std::vector<int> c;
        std::vector<int> b;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);
        b.push_back(8);
        b.push_back(9);

        std::cout << "STL: The vector C holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout << "\nSTL: The vector B holds: ";
        for(size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << ' ';}
        c.swap(b);
        std::cout << "\nSTL: The vector C after swap holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout << "\nSTL: The vector B after swap holds: ";
        for(size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << ' ';}

        {Vector<int> c;
        Vector<int> b;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);
        b.push_back(8);
        b.push_back(9);

        std::cout << "\nMY:  The vector C holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout << "\nMY:  The vector B holds: ";
        for(size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << ' ';}
        c.swap(b);
        std::cout << "\nMY:  The vector C after swap holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::cout << "\nMY:  The vector B after swap holds: ";
        for(size_t i = 0; i < b.size(); ++i) {
            std::cout << b[i] << ' ';}}
    }
    std::cout << "\n  3. INSERT " << std::endl;
    {
        std::cout << "\n  3a. INSERT(pos, value) " << std::endl;

        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::vector<int>::const_iterator it = c.begin();
        std::vector<int>::const_iterator ite = c.end();
        c.insert(it, 6);
        std::cout << "\nSTL: The vector after insert(pos, value): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << "Size: " << c.size() << "\n";

       { Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        Vector<int>::iterator it = myVector.begin();
        Vector<int>::iterator ite = myVector.end();
        myVector.insert(it, 6);
        std::cout << "\nMY:  The vector after insert(pos, value): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << "Size: " << myVector.size() << "\n";
        }
    }
    {
        std::cout << "\n  3b. INSERT(pos, count, value) " << std::endl;

        std::vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);

        std::cout << "STL: The vector holds: ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << ' ';}
        std::vector<int>::const_iterator it = c.begin();
        std::vector<int>::const_iterator ite = c.end();
        c.insert(it, 3, 6);
        std::cout << "\nSTL: The vector after insert(pos, count, value): ";
        for(size_t i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " ";
        }
        std::cout << "Size: " << c.size() << "\n";

        { Vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);

        std::cout << "MY:  The vector holds: ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << ' ';}
        Vector<int>::iterator it = myVector.begin();
        Vector<int>::iterator ite = myVector.end();
        myVector.insert(it, 3, 6);
        std::cout << "\nMY:  The vector after insert(pos, count, value): ";
        for(size_t i = 0; i < myVector.size(); ++i) {
            std::cout << myVector[i] << " ";
        }
        std::cout << "Size: " << myVector.size() << "\n";
        }
    }
    std::cout << "\n*****************************\n*        OPERATORS       *\n*****************************" << std::endl;
    {
		std::cout << "compare operators test" << std::endl;
		std::vector<int> std_vec1, std_vec2, std_vec3;
		ft::Vector<int> ft_vec1, ft_vec2, ft_vec3;
		std_vec1.push_back(1); std_vec1.push_back(2); std_vec1.push_back(3);
		std_vec2.push_back(1); std_vec2.push_back(2);
		std_vec3.push_back(1); std_vec3.push_back(2); std_vec3.push_back(4);
		ft_vec1.push_back(1); ft_vec1.push_back(2); ft_vec1.push_back(3);
		ft_vec2.push_back(1); ft_vec2.push_back(2);
		ft_vec3.push_back(1); ft_vec3.push_back(2); ft_vec3.push_back(4);

		std::cout << "[std] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec2) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec2) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec2) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec2) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec2) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec2) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec2) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec2) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec2) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec2) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec2) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec2) << std::endl;

		std::cout << "[std] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec3) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec3) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec3) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec3) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec3) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec3) << std::endl;
		std::cout << "[ft] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec3) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec3) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec3) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec3) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec3) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec3) << std::endl;

		std::vector<int> std_vec_copy(std_vec1);
		ft::Vector<int> ft_vec_copy(ft_vec1);
		std::cout << "compare equal vectors" << std::endl;
		std::cout << "[std]" << std::endl;
		std::cout << "== : " << (std_vec1 == std_vec_copy) << std::endl;
		std::cout << "!= : " << (std_vec1 != std_vec_copy) << std::endl;
		std::cout << "< : " << (std_vec1 < std_vec_copy) << std::endl;
		std::cout << "> : " << (std_vec1 > std_vec_copy) << std::endl;
		std::cout << "<= : " << (std_vec1 <= std_vec_copy) << std::endl;
		std::cout << ">= : " << (std_vec1 >= std_vec_copy) << std::endl;
		std::cout << "[ft]" << std::endl;
		std::cout << "== : " << (ft_vec1 == ft_vec_copy) << std::endl;
		std::cout << "!= : " << (ft_vec1 != ft_vec_copy) << std::endl;
		std::cout << "< : " << (ft_vec1 < ft_vec_copy) << std::endl;
		std::cout << "> : " << (ft_vec1 > ft_vec_copy) << std::endl;
		std::cout << "<= : " << (ft_vec1 <= ft_vec_copy) << std::endl;
		std::cout << ">= : " << (ft_vec1 >= ft_vec_copy) << std::endl;
	}

    
// insert, assign, construct (input it, enaable if, is integral), operators

}
