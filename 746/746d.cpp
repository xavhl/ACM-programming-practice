#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;

	while (cin >> N) {
		vector<int> waitingList;//record of time customers finish and leave

		for (int i = 0; i < N; ++i) {
			int arrivalTime, servingTime, tolerance;
			cin >> arrivalTime >> servingTime >> tolerance;

			if (i == 0) {//first customer must be served
				waitingList.push_back(arrivalTime + servingTime);

				if (N == 1)//exceptional case for only 1 customer
					cout << arrivalTime << endl;
			}
			else {
				int noOfCustomers = 0, noOfLeftCustomers = 0;

				if (waitingList[waitingList.size() - 1] <= arrivalTime)
					noOfCustomers = 0;
				else {
					for (auto itr = waitingList.rbegin(); itr != waitingList.rend(); ++itr) {//count number of customers ahead
						if (*itr > arrivalTime)
							++noOfCustomers;
						else
							break;
					}/*
					for (int leavingTime : waitingList) {//count number of customers ahead
						if (leavingTime <= arrivalTime)
							noOfLeftCustomers++;
						else {
							noOfCustomers = waitingList.size() - noOfLeftCustomers;
							break;
						}
					}*/
				}

				if (i != N - 1) {
					if (noOfCustomers <= tolerance) {
						if (waitingList[waitingList.size() - 1] < arrivalTime)
							waitingList.push_back(arrivalTime + servingTime);
						else
							waitingList.push_back(waitingList[waitingList.size() - 1] + servingTime);//push back finishing time of current customer

					}
				}
				else {//if this is the last customer
					if (noOfCustomers <= tolerance) {
						if (waitingList[waitingList.size() - 1] < arrivalTime)
							cout << arrivalTime;
						else
							cout << waitingList[waitingList.size() - 1];
					}
					else
						cout << -1;

					cout << endl;
				}
			}
		}

		waitingList.clear();
	}

	return 0;
}