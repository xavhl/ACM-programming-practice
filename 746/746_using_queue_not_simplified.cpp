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
			bool nextOne = false;

			if (i == 0) {//first customer must be served
				waitingTimes.push(arrivalTime + servingTime);

				if (N == 1)//exceptional case for only 1 customer
					cout << arrivalTime << endl;
			}
			else {
				if (waitingTimes.size() <= tolerance && i != N - 1) {//special case
					if (waitingTimes.back() < arrivalTime)
						waitingTimes.push(arrivalTime + servingTime);
					else
						waitingTimes.push(waitingTimes.back() + servingTime);//update finishing time of current customer
					nextOne = true;
				}

				if (waitingTimes.back() <= arrivalTime) {//previous customers all left
					noOfCustomers = 0;

					while (!waitingTimes.empty())
						waitingTimes.pop();
				}
				else {//count number of customers ahead in descending order
					while (waitingTimes.front() <= arrivalTime) {
						waitingTimes.pop();

						if (waitingTimes.size() <= tolerance)
							break;
					}
					//noOfCustomers = waitingTimes.size();
				}

				if (i != N - 1) {
					if (waitingTimes.size() <= tolerance && !nextOne) {
						if (waitingTimes.back() < arrivalTime)
							waitingTimes.push(arrivalTime + servingTime);
						else
							waitingTimes.push(waitingTimes.back() + servingTime);//update finishing time of current customer
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