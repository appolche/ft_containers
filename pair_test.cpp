#include "./utils/Pair.hpp"

void pair_test()
{
	std::cout << "*****************************\n*        PAIR       *\n*****************************" << std::endl;
	{
		std::pair<int, int> first(6, 1);
		std::pair<int, int> second(6, 2);
		bool check = first < second;
		std::cout << check << std::endl;

		ft::pair<int, int> myfirst(6, 1);
		ft::pair<int, int> mysecond(6, 2);
		bool mycheck = myfirst < mysecond;
		std::cout << mycheck << std::endl;
		
		{
			std::pair<int, int> first(6, 1);
			std::pair<int, int> second(6, 1);
			bool check = first > second;
			std::cout << check << std::endl;

			ft::pair<int, int> myfirst(6, 1);
			ft::pair<int, int> mysecond(6, 1);
			bool mycheck = myfirst > mysecond;
			std::cout << mycheck << std::endl;
		}
	}
}
