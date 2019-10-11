#ifndef H_KNAPSACK
#define H_KNAPSACK
#include <vector> // STL vector for dynamic arrays

namespace farmingdale {
	struct item;
	class knapsack;
	enum status { SUCCESS, FAILURE };
}

struct farmingdale::item {
	int weight;
	int value;
};

class farmingdale::knapsack {
private:
	std::vector<item> items; // vector of items. You can access this like an array (items[3]), but also get the 
							// advantage of things like items.size();
public:
	std::vector<bool> knapsackSolve(int capacity, int &totalValue, int &numberOfConfigsChecked);
	status addItem(int weight, int value);
	void print(std::vector<bool> included = std::vector<bool>());
};


#endif // H_KNAPSACK
