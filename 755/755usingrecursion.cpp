#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool sortByAscendingPrice(const pair<int, int>& a, const pair<int, int>& b) { return(a.second < b.second); }

long long int getMaxArea(long long int startDay, long long int endDay, vector<pair<long long int, long long int>>& sortedList, int prevMin) {
	int index = -1;
	long long int minDay = 0, minPrice = 0, minArea = 0;

	for (auto itr = sortedList.begin(); itr != sortedList.end(); ++itr) {
		if (startDay <= itr->first && itr->first <= endDay) {
			if (prevMin == itr->second) {
				minDay = itr->first;
				index = itr - sortedList.begin();
			}
			else if (prevMin < itr->second) {
				minPrice = itr->second;
				minDay = itr->first;
				index = itr - sortedList.begin();
				minArea = minPrice * (endDay - startDay + 1);
			}
			else;

			break;
		}
	}

	if (index != -1)
		sortedList.erase(sortedList.begin() + index);

	if (startDay == endDay)
		return minPrice;
	
	long long int leftPart = 0, rightPart = 0;

	if(minDay!=startDay)
		leftPart = getMaxArea(startDay, minDay - 1, sortedList, minPrice);

	if(minDay!=endDay)
		rightPart = getMaxArea(minDay + 1, endDay, sortedList, minPrice);

	return max(minArea, max(leftPart, rightPart));
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		long long int noOfDays;
		cin >> noOfDays;

		vector<pair<long long int, long long int>> stockPrices;
		for (int j = 0; j < noOfDays; ++j) {
			long long int price;
			cin >> price;
			stockPrices.push_back({ j,price });
		}

		/*
		cout << "stock prices" << endl;
		for (auto itr = stockPrices.begin(); itr != stockPrices.end(); ++itr)
			cout << "index " << itr->first << " price " << itr->second << endl;
		cout << endl;*/

		long long int startDay = stockPrices.begin()->first, endDay = (stockPrices.end() - 1)->first;
		sort(stockPrices.begin(), stockPrices.end(), sortByAscendingPrice);

		cout << getMaxArea(startDay, endDay, stockPrices, 0) << endl;

		stockPrices.clear();
	}

	return 0;
}