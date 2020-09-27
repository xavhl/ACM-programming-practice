#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<int> waitingList;//record of time customers finish and leave

		int arrivalTime, servingTime, tolerance;//first customer must be served
		cin >> arrivalTime >> servingTime >> tolerance;
		waitingList.push_back(arrivalTime + servingTime);

		for (int i = 1; i < N; ++i) {
			int arrivalTime, servingTime, tolerance;
			cin >> arrivalTime >> servingTime >> tolerance;

			int noOfCustomers = 0, noOfLeftCustomers = 0;

			for (int leavingTime : waitingList) {//count number of customers ahead
				if (leavingTime <= arrivalTime)
					noOfLeftCustomers++;
				else {
					noOfCustomers = waitingList.size() - noOfLeftCustomers;
					break;
				}
			}

			if (i != N - 1) {
				if (noOfCustomers <= tolerance)
					waitingList.push_back(waitingList[waitingList.size() - 1] + servingTime);//push back finishing time of current customer
			}
			else {//if this is the last customer
				if (noOfCustomers <= tolerance)
					cout << waitingList[waitingList.size() - 1];
				else
					cout << -1;

				cout << endl;
			}
		}

		waitingList.clear();
	}

	return 0;
}
