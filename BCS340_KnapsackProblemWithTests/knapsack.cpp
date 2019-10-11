#include <vector>  // for the STL vector type
#include <iostream>  // for cout
#include <string>  // for operator<<(stream,string)
#include "knapsack.h"
#include <algorithm>
using namespace farmingdale;
using namespace std;

//Method: knapsackSolve
//Purpose: Inputs the max capacity load, the the value and number of possible configurations checked
std::vector<bool> knapsack::knapsackSolve(int capacity, int &totalValue, int &numberOfConfigsChecked) {
	//Sort the weights of item in ascending order
	//std::sort(items.begin(), items.end(),[](item i, item j) { return (i.weight < j.weight); });

	///////////////////////////////
	//						Weight Available
	//				0	10	20	30	40	50
	//	Weight	 10	0	60	60	60	60	60
	//	of Item  20	0	0	100	100	100	100
	//			 30	0	0	0	120	120	120

	int roww = items.size()+1;
	int coll = capacity + 1;
	//Rows declared
	std::vector< std::vector<int> > weightVector(roww, std::vector<int>(coll, 0));

	//Number of items into workingVector
	std::vector<bool> workingVector(items.size()); 
	//Sets every item to false, as in not included in the sack
	//workingVector connects with vector "items" by index to find information
	std::fill(workingVector.begin(), workingVector.end(), false); // all false so far
	totalValue = 0;                 
	numberOfConfigsChecked = 0;

	//Populate the sack by weight of item in weightVector array
	for (int i = 1; i < roww; i++) { //Rowd
		for (int j = 1; j < coll; j++) { //Col
			numberOfConfigsChecked++;
			int currentItemValue = items[i - 1].value;
			int currentItemWeight = items[i - 1].weight;
			if (currentItemWeight <= j) { //If weight of item is less than capacity, enter value, else 0 **CORRECT**
				int leftOverWeight = j - currentItemWeight; //Leftover weight from current item
				//If current item value + leftover weight's item value is greater than prev item[j] at same weight, set currentItemValue+Leftoverweight
				if ((currentItemValue + weightVector[i - 1][leftOverWeight]) >= weightVector[i - 1][j]) {
					weightVector[i][j] = (currentItemValue + weightVector[i - 1][leftOverWeight]);
				}
				else {
					weightVector[i][j] = weightVector[i - 1][j];
				}
			}
			else { //Set value to previous row value
				weightVector[i][j] = weightVector[i - 1][j];
			}
		}
	}

	//Display array items
	//std::cout << "		Weight Available" << endl;
	//for (int i = 0; i < col; i++) {
	//	for (int j = 0; j < capacity+1; j++)
	//		std::cout << weightVector[i][j] << " ";
	//	std::cout << std::endl;
	//}


	totalValue = weightVector[items.size()][capacity];
	//1. To find which ones are included, see the value of item and if it exists in previous rows, if not then we include item as part of the bag
	//2. Then we subtract the value and weight of our totalValue object and total weight left by the item we added to our bag and 
	//if the value in current row does exist in previous row, check the one before that one until the value of item exists in origin
	int maxVal = totalValue;
	for (int i = coll; i > 0; i--) {
		int occurance = 0;
		int originalLocation = 0;
		for(int j = roww; j > 0; j--){
			//If value matches index, check if its unique by looking at previous rows, track match by increase occurance
			if (maxVal == weightVector[j-1][i-1] && maxVal != 0) {
				occurance++;
				originalLocation = j;
			}
		}
		if (occurance > 0) {
			workingVector[originalLocation-2] = 1;
			maxVal -= items[originalLocation - 2].value;
			int leftOverWeight = (coll) - (items[originalLocation - 2].weight);
			i = leftOverWeight+1;
		}
	}
	return workingVector;
}

// These methods are written already

status knapsack::addItem(int weight, int value) {
	item thisItem;
	thisItem.value = value;
	thisItem.weight = weight;
	items.push_back(thisItem);
	return SUCCESS;
}




void knapsack::print(std::vector<bool> included) {
	std::cout << "\tValue\t\tWeight\t\tIncluded?\n";
	int count = 0;
	for (std::vector<item>::iterator iIter = items.begin(); iIter != items.end(); ++iIter) {
		std::string thisInc = (0 == included.size()) ? "No" : ((included[count]) ? "Yes" : "No");
		std::cout << "\t" << iIter->value << " \t\t" << iIter->weight << " \t\t" << thisInc << std::endl;
			++count;
	} // for (std::vector<item>::iterator
}