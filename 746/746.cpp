//#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;

	while (cin >> N) {
		queue<int> waitingTimes;

		for (int i = 0; i < N; i++) {
			int arrivalTime, servingTime, tolerance, noOfCustomers;
			cin >> arrivalTime >> servingTime >> tolerance;

			if (i == 0) {//first customer must be served
				waitingTimes.push(arrivalTime + servingTime);

				if (N == 1)//exceptional case for only 1 customer
					cout << arrivalTime << endl;
			}
			else {
				if (waitingTimes.back() <= arrivalTime) {//previous customers all left
					while (!waitingTimes.empty())
						waitingTimes.pop();
				}
				else {//remove left customers
					while (waitingTimes.front() <= arrivalTime) {
						waitingTimes.pop();

						if (waitingTimes.size() <= tolerance)//stop if enough number are removed
							break;
					}
				}

				if (i != N - 1) {
					if (waitingTimes.size() <= tolerance) {//update finishing time of current customer
						if (waitingTimes.back() < arrivalTime)//if customer arrive after all previous customers left
							waitingTimes.push(arrivalTime + servingTime);
						else//if still some customers being served
							waitingTimes.push(waitingTimes.back() + servingTime);//add up the time
					}
				}
				else {//if this is the last customer
					if (waitingTimes.size() <= tolerance) {
						if (waitingTimes.back() < arrivalTime)
							cout << arrivalTime;
						else
							cout << waitingTimes.back();
					}
					else
						cout << -1;

					cout << endl;
				}
			}
		}

		while (!waitingTimes.empty())
			waitingTimes.pop();
	}

	return 0;
}