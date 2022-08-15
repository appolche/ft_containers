#include "./containers/Set.hpp"

#include <set>

void set_tests()
{
	{
	std::set<int> first;                                // empty set of ints
	first.insert(0); first.insert(1); first.insert(2); first.insert(3);
	std::set<int> second (first.begin(), first.end());  // iterating through first
	std::set<int> third (second);                       // a copy of third

	ft::set<int> first1;                                // empty vector of ints
	first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
	std::set<int> second1 (first1.begin(), first1.end());  // iterating through first
	std::set<int> third1 (second1);                       // a copy of third
	//Size/maxsize
	std::cout << "std::Set: Size/maxsize of first: " << first.size() << " " << first.max_size() << '\n';
	std::cout << "ft::Set: Size/maxsize of first1: " << first1.size() << " " << first1.max_size() << '\n';
	//empty
	std::cout << "std::Set: second is empty? : " << std::boolalpha << second.empty() << std::endl;
	std::cout << "ft::Set: second1 is empty? : " << std::boolalpha << second1.empty() << std::endl;
	//insert duplicate
	first1.insert(0);									first.insert(0);
	std::cout << "std::Set: Size/maxsize of first: " << first.size() << "\n";
	std::cout << "ft::Set: Size/maxsize of first1: " << first1.size() << '\n';
	}

	{
	std::cout << "swap/find/cout tests\n";
	std::set<int> first;								ft::set<int> first1;
	first.insert(0); first.insert(1); first.insert(2); first.insert(3);
	first1.insert(0); first1.insert(1); first1.insert(2); first1.insert(3);
	std::set<int> second;								ft::set<int> second1;
	second.insert(4); second.insert(5); second.insert(6); second.insert(7);
	second1.insert(4); second1.insert(5); second1.insert(6); second1.insert(7);
	std::cout << "std::set: before swap first-second: " << *(first.find(0)) << " " << *(first.find(1)) << " " << *(first.find(2)) << " " << *(first.find(3)) << std::endl;
	std::cout << "ft::set: before swap first-second: " << *(first1.find(0)) << " " << *(first1.find(1)) << " " << *(first1.find(2)) << " " << *(first1.find(3)) << std::endl;
	first.swap(second);
	first1.swap(second1);
	std::cout << "std::set: after swap first-second: " << *(first.find(4)) << " " << *(first.find(5)) << " " << *(first.find(6)) << " " << *(first.find(7)) << std::endl;
	std::cout << "ft::set: after swap first-second: " << *(first1.find(4)) << " " << *(first1.find(5)) << " " << *(first1.find(6)) << " " << *(first1.find(7)) << std::endl;
	//cout
	std::cout << "first.count(4): " << first.count(4) << std::endl;
	std::cout << "first1.count(4): " << first1.count(4) << std::endl;
	std::cout << "first.count(35): " << first.count(35) << std::endl;
	std::cout << "first1.count(35): " << first1.count(35) << std::endl;
	// lower_bound/upper_bound
	std::cout << "std::set: first: " << *(first.lower_bound(42)) << " " << *(first.upper_bound(1)) << std::endl;
	std::cout << "ft::set: first1: " << *(first1.lower_bound(42)) << " " << *(first1.upper_bound(1)) << std::endl;

	std::cout << "operator >< = !=/erase/count tests\n" ;
	if (first == second)
		std::cout << "std:: first = second\n";
	if (first != second)
		std::cout << "std:: first != second\n";
	if (first > second)
		std::cout << "std:: first > second\n";
	if (first < second)
		std::cout << "std:: first < second\n";

	if (first1 == second1)
		std::cout << "ft:: first1 = second1\n";
	if (first1 != second1)
		std::cout << "ft:: first1 != second1\n";
	if (first1 > second1)
		std::cout << "ft:: first1 > second1\n";
	if (first1 < second1)
		std::cout << "ft:: first1 < second1\n";
	}
}
