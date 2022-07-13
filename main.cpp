#include "./containers/Vector.hpp"
#include "./containers/Stack.hpp"
#include "./containers/Map.hpp"
#include "./utils/Iterator.hpp"
#include "./utils/RBTree.hpp"
#include "./utils/Pair.hpp"
#include <vector>
#include <map>
#include <iostream>

using namespace ft;

int main() {
	{
	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::map<char,int> first;		ft::map<char,int> first1;
	first['a']=10;					first1['a']=10;
	first['b']=30;					first1['b']=30;
	first['c']=50;					first1['c']=50;
	first['d']=70;					first1['d']=70;
	first['f']=90;					first1['f']=90;
	//begin/end
	std::cout << "std::map<char,int> first: " << first.begin()->first << " " << first.begin()->second << std::endl;
	std::cout << "ft::map<char,int> first1: " << first1.begin()->first << " " << first1.begin()->second << std::endl;
	//range contructor
	std::map<char,int> second (first.begin(),first.end());
	ft::map<char,int> second1 (first1.begin(),first1.end());
	//size/maxsize/empty
	std::cout << "std::map<char,int> second: " << second.size() << " " << second.max_size() << " " << std::boolalpha << second.empty() << std::endl;
	std::cout << "ft::map<char,int> second1: " << second1.size() << " " << second1.max_size() << " " << std::boolalpha << second1.empty() << std::endl;
	//copy contructor
	std::map<char,int> third (second);
	ft::map<char,int> third1 (second1);
	// lower_bound/upper_bound
	std::cout << "std::map<char,int> first: " << third.lower_bound('e')->second << " " << third.upper_bound('b')->second << std::endl;
	std::cout << "ft::map<char,int> first1: " << third1.lower_bound('e')->second << " " << third1.upper_bound('b')->second << std::endl;
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/

	{//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
	std::map<float,std::string> first;		ft::map<float,std::string> first1;
	first[0.1]="You ";						first1[0.1]="much ";
	first[0.2]="have ";						first1[0.2]="I ";
	first[0.3]="no ";						first1[0.3]="hate ";
	first[0.4]="idea ";						first1[0.4]="the ";
	first[0.5]="how ";						first1[0.5]="ft_containers ";
	//[]
	std::cout << "std::map<float,std::string> first: " << first[0.1] << first[0.2] << first[0.3]<< first[0.4] << first[0.5] << first[42] << std::endl;
	std::cout << "ft::map<float,std::string> first1: " << first1[0.1] << first1[0.2] << first1[0.3]<< first1[0.4] << first1[0.5] << first[42] << std::endl;
	//at
	try
	{
		std::cout << "std::map<float,std::string> first: " << first.at(0.5) << std::endl << first.at(0.6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "ft::map<float,std::string> first1: " << first1.at(0.5) << std::endl << first1.at(0.6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//pair/insert
	first.insert(std::pair<float, std::string>(99.9, "hello!"));
	first1.insert(ft::pair<float, std::string>(99.9, "hello!"));
	std::cout << "std::map<float,std::string> first: " << first[99.9] << std::endl;
	std::cout << "ft::map<float,std::string> first1: " << first1[99.9] << std::endl;
	//swap
	std::map<float,std::string> second;		ft::map<float,std::string> second1;
	second[1]="one ";						second1[1]="one ";
	second[2]="two ";						second1[2]="two ";
	second[3]="three ";						second1[3]="three ";
	second[4]="four ";						second1[4]="four ";
	second[5]="five ";						second1[5]="five ";
	first.swap(second);
	first1.swap(second1);
	std::cout << "std::map: after swap first-second: " << first[1] << first[2] << second[0.1]<< second[0.2] << std::endl;
	std::cout << "ft::map: after swap first-second: " << first1[1] << first1[2] << second1[0.1]<< second1[0.2] << std::endl;

	//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
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
	//erase
	std::cout << "first element of std::map before erase 1: "<< first.begin()->first << std::endl;
	std::cout << "first element of ft::map before erase 1: "<< first1.begin()->first << std::endl;
	first.erase(first.begin());
	first1.erase(first1.begin());
	std::cout << "first element of std::map after erase 1: " << first.begin()->first << std::endl;
	std::cout << "first element of ft::map after erase 1: " << first1.begin()->first << std::endl;

	//cout
	std::cout << "first.count(2): " << first.count(2) << std::endl;
	std::cout << "first1.count(2): " << first1.count(2) << std::endl;
	std::cout << "first.count(35): " << first.count(35) << std::endl;
	std::cout << "first1.count(35): " << first1.count(35) << std::endl;
	}//~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/~/
}
	// std::cout << "<3 <3 <3 VECTOR TESTS <3 <3 <3			" << std::endl;
   //  vector_test();
	// std::cout << "\n<3 <3 <3 STACK TESTS <3 <3 <3			" << std::endl;
	// std::map<int, int> s;
	// s.insert(std::make_pair(8, 6));
	// s.insert(std::make_pair(10, 52));
	// s.insert(std::make_pair(3, 11));
	
	// std::pair<std::map<int, int>::iterator, bool> pairTest = s.insert(std::make_pair(3, 11));
	// bool boo = pairTest.second;
	// std::cout << "insert bool (inserting existing value): " << boo << std::endl;

	// pairTest = s.insert(std::make_pair(5, 11));
	// boo = pairTest.second;
	// std::cout << "insert bool (inserting new value): " << boo << std::endl;
	// // std::map<int, int>::iterator a =  s.find(10);


	// ft::map<int, int> mys;
	// mys.insert(ft::make_pair(8, 6));
	// mys.insert(ft::make_pair(10, 52));
	// mys.insert(ft::make_pair(3, 11));

	// ft::map<int, int> neww;
	// neww.insert(ft::make_pair(5, 3));
	// neww.insert(ft::make_pair(2, 1));
	// neww.insert(ft::make_pair(7, 8));
	// // ft::map<int, int>::iterator mya =  mys.find(10);
	// mys = neww;
	// // std::cout << s.find(10)->second << std::endl;
	// std::cout << mys.find(7)->second << std::endl;


	// ft::map<char, int> m;
	// m.insert(ft::make_pair('A', 5));
	
	//  stack_test();x

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