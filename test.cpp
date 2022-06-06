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
    
    // std::cout << "\n  2. CONST ITERS / CONST REVERSE ITERS" << std::endl;
	// {
    //     Vector<int> myVector;

	// 	std::cout << "-CONST ITERS" << std::endl;
	// 	Vector<int>::const_iterator	it = myVector.begin();
	// 	Vector<int>::const_iterator	ite = myVector.end();
	// 	for ( ; it != ite; it++) {
	// 		*it = 5;
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl << std::endl;
	// }
	// {
    //     Vector<int> myVector;

	// 	std::cout << "-CONST REVERSE ITERS" << std::endl;
	// 	Vector<int>::const_reverse_iterator	it = myVector.rbegin();
	// 	Vector<int>::const_reverse_iterator	ite = myVector.rend();
	// 	for ( ; it != ite; it++) {
	// 		*it = 5;
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl << std::endl;
	// }

    //     std::cout << "MY:  The vector holds: ";
    //     for(size_t i = 0; i < myVector.size(); ++i) {
    //         std::cout << myVector[i] << ' ';}
    //     std::cout <<"Cap: " << myVector.capacity() << std::endl;

        // myVector.reserve(10);
    //     std::cout << "MY:  After reserve: ";
    //     for(size_t i = 0; i < myVector.size(); ++i) {
    //         std::cout << myVector[i] << ' ';}
    //     std::cout <<" Cap: " << myVector.capacity() << std::endl;
    
    


//     std::cout << "Check default push_back" << std::endl;
//     for (int i = 0; i < 10; ++i) {
//         v.push_back(i);
//         std::cout << "Value: " << v[i];
//         std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
//     }
//         std::cout << "Value: " << v[5];
    
//     std::cout << "\n----------------------------------------------------" << std::endl;
//     Vector<int> myVector;
//     std::cout << "Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
//     std::cout << "Check my push_back and []" << std::endl;
//     for (int i = 0; i < 10; ++i) {
//         myVector.push_back(i);
//         std::cout << "Value: " << myVector[i];
//         std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
//     }



// {
//     // default swap testing
//     std::vector<int> a1;
//      for (int i = 0; i < 5; ++i) {
//         a1.push_back(9);
//         std::cout << a1[i];
//     }
//     std::vector<int> a2;
//     std::cout << std::endl;
//      for (int i = 0; i < 9; ++i) {
//         a2.push_back(i);
//         std::cout << a2[i];
//     }

//     std::cout << std::endl << std::endl;
//     a1.swap(a2);
//     for (size_t i = 0; i < a1.size(); ++i) {
//         std::cout << a1[i];
//     }
//      std::cout << " Size: " << a1.size() << " Capacity: " << a1.capacity() << std::endl;
//      for (size_t i = 0; i < a2.size(); ++i) {
//         std::cout << a2[i];
//     }
//     std::cout << " Size: " << a2.size() << " Capacity: " << a2.capacity() << std::endl<< std::endl<< std::endl;

//     //////my swap testing
//     {Vector<int> a1;
//     for (int i = 0; i < 5; ++i) {
//         a1.push_back(9);
//         std::cout << a1[i];
//     }
//     Vector<int> a2;
//     std::cout << std::endl;
//      for (int i = 0; i < 9; ++i) {
//         a2.push_back(i);
//         std::cout << a2[i];
//     }


//     std::cout << std::endl << std::endl;
//     a1.swap(a2);
//     for (size_t i = 0; i < a1.size(); ++i) {
//         std::cout << a1[i];
//     }
//      std::cout << " Size: " << a1.size() << " Capacity: " << a1.capacity() << std::endl;
//      for (size_t i = 0; i < a2.size(); ++i) {
//         std::cout << a2[i];
//     }
//     std::cout << " Size: " << a2.size() << " Capacity: " << a2.capacity() << std::endl;
// }
// }


// // pop_back testing
// {    std::vector<int> v;

//     for (int i = 0; i < 10; ++i) {
//         v.push_back(i);
//         std::cout << "Value: " << v[i];
//         std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
//     }
//     v.pop_back();
//     std::cout << "\nDef vector after popping back\n";

//     for (size_t i = 0; i < v.size(); ++i) {
//         std::cout << "Value: " << v[i];
//         std::cout << " Size: " << v.size() << " Capacity: " << v.capacity()  << " Max_size: " << v.max_size() << std::endl;
//     }

//     std::cout << '\n';
//     std::cout << '\n';

//     Vector<int> myVector;
//     for (int i = 0; i < 10; ++i) {
//         myVector.push_back(i);
//         std::cout << "Value: " << myVector[i];
//         std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
//     }
//     std::cout << "\nMy vector after popping back\n";

//     myVector.pop_back();
//     for (size_t i = 0; i < myVector.size(); ++i) {
//         std::cout << "Value: " << myVector[i];
//         std::cout << " Size: " << myVector.size() << " Capacity: " << myVector.capacity()  << std::endl;
//     }}
}
