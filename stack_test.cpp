#include "./containers/Vector.hpp"
#include "./containers/Stack.hpp"
#include "./utils/Iterator.hpp"

#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace ft;

void stack_test()
{

	std::cout << "*****************************\n*        CONSTRUCTORS       *\n*****************************" << std::endl;
	std::cout << "  1. DEFAULT CONTRUCTOR + PUSH + SIZE + TOP + EMPTY + TOP" << std::endl;
	{
		std::stack<int, std::vector<int> > v;
		std::cout << "STL: Empty: " << v.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			v.push(i);
		}
		std::cout << "STL: (after Push) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;
		v.pop();
		std::cout << "STL: (after Pop) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;


		Stack<int> myVector;
		std::cout << "MY:  Empty: " << myVector.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			myVector.push(i);
		}
		std::cout << "MY:  (after Push) Empty: " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
		myVector.pop();
		std::cout << "MY:  (after Pop) Empty " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
	}

	std::cout << "\n  2. WITH ANY CONTAINER INSIDE" << std::endl;
	{
		std::stack<int, std::deque<int> > v;
		std::cout << "STL: Empty: " << v.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			v.push(i);
		}
		std::cout << "STL: (after Push) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;
		v.pop();
		std::cout << "STL: (after Pop) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;


		Stack<int, std::deque<int> > myVector;
		std::cout << "MY:  Empty: " << myVector.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			myVector.push(i);
		}
		std::cout << "MY:  (after Push) Empty: " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
		myVector.pop();
		std::cout << "MY:  (after Pop) Empty " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
	}

	std::cout << "\n  3. COPY CONSTRUCTOR + OPERATOR=" << std::endl;
	{
		std::stack<int, std::deque<int> > v;
		std::cout << "STL: Empty: " << v.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			v.push(i);
		}
		std::cout << "STL: (after Push) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;
		v.pop();
		std::cout << "STL: (after Pop) Empty: " << v.empty() << " , Top: " << v.top() << " Size: " << v.size() << std::endl;


		Stack<int, std::deque<int> > myVector;
		std::cout << "MY:  Empty: " << myVector.empty() << std::endl;
		for (int i = 0; i < 5; ++i) {
			myVector.push(i);
		}
		std::cout << "MY:  (after Push) Empty: " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
		myVector.pop();
		std::cout << "MY:  (after Pop) Empty " << myVector.empty() << " , Top: " << myVector.top() << " Size: " << myVector.size() << std::endl;
	}

	std::cout << "\n*****************************\n*        OPERATORS       *\n*****************************" << std::endl;
	   std::cout << "\n  1. COMPARE OPERATORS " << std::endl;
	{
		std::stack<int> s1;
		std::stack<int> s2;
		std::stack<int> s3;
		ft::Stack<int> myStack1;
		ft::Stack<int> myStack2;
		ft::Stack<int> myStack3;

		s1.push(3); s1.push(2); s1.push(1);
		s2.push(2); s2.push(1);
		s3.push(4); s3.push(2); s3.push(1);

		myStack1.push(3); myStack1.push(2); myStack1.push(1);
		myStack2.push(2); myStack2.push(1);
		myStack3.push(4); myStack3.push(2); myStack3.push(1);

		std::cout << "[STL] compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (s1 == s2) << std::endl;
		std::cout << "!= : " << (s1 != s2) << std::endl;
		std::cout << "< :  " << (s1 < s2) << std::endl;
		std::cout << "> :  " << (s1 > s2) << std::endl;
		std::cout << "<= : " << (s1 <= s2) << std::endl;
		std::cout << ">= : " << (s1 >= s2) << std::endl;
		std::cout << "[MY]  compare 1 2 3 with 1 2" << std::endl;
		std::cout << "== : " << (myStack1 == myStack2) << std::endl;
		std::cout << "!= : " << (myStack1 != myStack2) << std::endl;
		std::cout << "< :  " << (myStack1 < myStack2) << std::endl;
		std::cout << "> :  " << (myStack1 > myStack2) << std::endl;
		std::cout << "<= : " << (myStack1 <= myStack2) << std::endl;
		std::cout << ">= : " << (myStack1 >= myStack2) << std::endl;

		std::cout << "[STL] compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (s1 == s3) << std::endl;
		std::cout << "!= : " << (s1 != s3) << std::endl;
		std::cout << "< :  " << (s1 < s3) << std::endl;
		std::cout << "> :  " << (s1 > s3) << std::endl;
		std::cout << "<= : " << (s1 <= s3) << std::endl;
		std::cout << ">= : " << (s1 >= s3) << std::endl;
		std::cout << "[MY]  compare 1 2 3 with 1 2 4" << std::endl;
		std::cout << "== : " << (myStack1 == myStack3) << std::endl;
		std::cout << "!= : " << (myStack1 != myStack3) << std::endl;
		std::cout << "< :  " << (myStack1 < myStack3) << std::endl;
		std::cout << "> :  " << (myStack1 > myStack3) << std::endl;
		std::cout << "<= : " << (myStack1 <= myStack3) << std::endl;
		std::cout << ">= : " << (myStack1 >= myStack3) << std::endl;

		std::stack<int> s_copy(s1);
		ft::Stack<int> myStack_copy(myStack1);
		std::cout << "[STL] compare equal stacks" << std::endl;
		std::cout << "== : " << (s1 == s_copy) << std::endl;
		std::cout << "!= : " << (s1 != s_copy) << std::endl;
		std::cout << "< :  " << (s1 < s_copy) << std::endl;
		std::cout << "> :  " << (s1 > s_copy) << std::endl;
		std::cout << "<= : " << (s1 <= s_copy) << std::endl;
		std::cout << ">= : " << (s1 >= s_copy) << std::endl;
		std::cout << "[MY]  compare equal stacks"  << std::endl;
		std::cout << "== : " << (myStack1 == myStack_copy) << std::endl;
		std::cout << "!= : " << (myStack1 != myStack_copy) << std::endl;
		std::cout << "< :  " << (myStack1 < myStack_copy) << std::endl;
		std::cout << "> :  " << (myStack1 > myStack_copy) << std::endl;
		std::cout << "<= : " << (myStack1 <= myStack_copy) << std::endl;
		std::cout << ">= : " << (myStack1 >= myStack_copy) << std::endl;
	}
}
