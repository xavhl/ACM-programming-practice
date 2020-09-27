//reference taken from https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long int getMaxArea(const vector<long long int>& stockPrices) {
	stack<long long int> index;

	long long int i = 0, maxArea = 0;
	while (i < stockPrices.size()) {
		if (index.empty() || stockPrices[index.top()] <= stockPrices[i])
			index.push(i++);
		else {
			long long int prev = index.top();
			index.pop();

			long long int prevArea = stockPrices[prev] * (index.empty() ? i : i - index.top() - 1);

			if (maxArea < prevArea)
				maxArea = prevArea;
		}
	}
	//i == stockPrices.size()
	while (!index.empty()) {
		long long int prev = index.top();
		index.pop();

		long long int prevArea = stockPrices[prev] * (index.empty() ? i : i - index.top() - 1);

		if (maxArea < prevArea)
			maxArea = prevArea;
	}

	return maxArea;
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		long long int noOfDays;
		cin >> noOfDays;

		vector<long long int> stockPrices;
		for (long long int j = 0; j < noOfDays; ++j) {
			long long int price;
			cin >> price;
			stockPrices.push_back(price);
		}

		cout << getMaxArea(stockPrices) << endl;

		stockPrices.clear();
	}

	return 0;
}