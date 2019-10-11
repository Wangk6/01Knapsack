#include <iostream> 
#include "knapsack.h"


using namespace farmingdale;
status test1();
status test2();
status test3();
status test4();

int main() {
	status t1stat, t2stat, t3stat, t4stat;

	if (FAILURE == (t1stat = test1())) {
		std::cerr << "Test 1 failed. Line: " << __LINE__ << std::endl;
	}
	if (FAILURE == (t2stat = test2())) {
		std::cerr << "Test 2 failed. Line: " << __LINE__ << std::endl;
	}
	if (FAILURE == (t3stat = test3())) {
		std::cerr << "Test 3 failed. Line: " << __LINE__ << std::endl;
	}
	if (FAILURE == (t4stat = test4())) {
		std::cerr << "Test 4 failed. Line: " << __LINE__ << std::endl;
	}
	if (SUCCESS == t1stat && SUCCESS == t2stat ||
		SUCCESS == t3stat && SUCCESS == t4stat) {
		std::cout << "All tests passed" << std::endl;
	} else {
		system("pause");
		return 1;
	}
	system("pause");
	return 0;
}


status test1() {
	// problem source: https://www.geeksforgeeks.org/knapsack-problem/
	farmingdale::knapsack sack;

	//Add to sack Weight, Value
	sack.addItem(10, 60);
	sack.addItem(20, 100);
	sack.addItem(30, 120);

	int totalValue;
	int configsChecked;

	//Enter total weight allowed, total value of the weight and configurations
	std::vector<bool> result = sack.knapsackSolve(50, totalValue, configsChecked);
	std::cerr << "Total1 is " << totalValue << std::endl;
	std::cerr << configsChecked << " different configurations were checked of the possible " << (2<<(result.size()-1)) << " configurations" << std::endl;
	sack.print(result);
	if (220 == totalValue) {

		return SUCCESS;
	} 
	return FAILURE;
}
status test2() {
	// problem source: https://www.lindo.com/doc/online_help/lingo17_0/a_sample_knapsack_problem.htm
	farmingdale::knapsack sack;
	sack.addItem(1, 2);
	sack.addItem(3, 9);
	sack.addItem(4, 3);
	sack.addItem(3, 8);
	sack.addItem(3, 10);
	sack.addItem(1, 6);
	sack.addItem(5, 4);
	sack.addItem(10, 10);
	int totalValue;
	int configsChecked;

	std::vector<bool> result = sack.knapsackSolve(15, totalValue, configsChecked);
	std::cerr << "Total2 is " << totalValue << std::endl;
	std::cerr << configsChecked << " different configurations were checked of the possible " << (2 << (result.size() - 1)) << " configurations" << std::endl;
	sack.print(result);
	if (38 == totalValue) {

		return SUCCESS;
	}
	return FAILURE;
}

status test3() {
	// problem source: https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_multiple/knapsack_multiple.html (P01, test 127-note: answer there seems to be wrong)
	farmingdale::knapsack sack;
	sack.addItem(23, 92);
	sack.addItem(31, 57);
	sack.addItem(29, 49);
	sack.addItem(44, 68);
	sack.addItem(53, 60);
	sack.addItem(38, 43);
	sack.addItem(63, 67);
	sack.addItem(85, 84);
	sack.addItem(89, 87);
	sack.addItem(82, 72);
	int totalValue;
	int configsChecked;

	std::vector<bool> result = sack.knapsackSolve(127, totalValue, configsChecked);
	std::cerr << "Total3 is " << totalValue << std::endl;
	std::cerr << configsChecked << " different configurations were checked of the possible " << (2 << (result.size() - 1)) << " configurations" << std::endl;
	sack.print(result);
	if (266 == totalValue) {

		return SUCCESS;
	}
	return FAILURE;
}
status test4() {
	// problem source: https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_multiple/knapsack_multiple.html (P01, test 70-note: answer there seems to be wrong)
	farmingdale::knapsack sack;
	sack.addItem(23, 92);
	sack.addItem(31, 57);
	sack.addItem(29, 49);
	sack.addItem(44, 68);
	sack.addItem(53, 60);
	sack.addItem(38, 43);
	sack.addItem(63, 67);
	sack.addItem(85, 84);
	sack.addItem(89, 87);
	sack.addItem(82, 72);
	int totalValue;
	int configsChecked;

	std::vector<bool> result = sack.knapsackSolve(70, totalValue, configsChecked);
	std::cerr << "Total3 is " << totalValue << std::endl;
	std::cerr << configsChecked << " different configurations were checked of the possible " << (2 << (result.size() - 1)) << " configurations" << std::endl;
	sack.print(result);
	if (160 == totalValue) {

		return SUCCESS;
	}
	return FAILURE;
}