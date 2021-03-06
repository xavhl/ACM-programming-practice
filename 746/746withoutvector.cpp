#include <iostream>
using namespace std;

int main() {
	int N;

	while (cin >> N) {
		int headCnt, estTime;

		for (int i = 0; i < N; i++) {
			int arrivalTime, servingTime, tolerance;
			cin >> arrivalTime >> servingTime >> tolerance;
			bool nextOne = false;

			if (i == 0) {//first customer must be served
				estTime = arrivalTime + servingTime;
				++headCnt;

				if (N == 1)//exceptional case for only 1 customer
					cout << arrivalTime << endl;
			}
			else {
				if (headCnt <= tolerance && i!= N - 1) {//special case
					if (estTime < arrivalTime)
						estTime = arrivalTime + servingTime;
					else
						estTime += servingTime;//update finishing time of current customer
					nextOne = true;
				}

				int noOfCustomers = 0, noOfLeftCustomers = 0;

				if (estTime <= arrivalTime)//previous customers all left
					noOfCustomers = 0;
				else {//count number of customers ahead in descending order
					for (auto itr = waitingList.rbegin(); itr != waitingList.rend(); ++itr) {
						if (*itr > arrivalTime)
							++noOfCustomers;
						else {
							//waitingList.erase(waitingList.begin(), waitingList.begin() + (itr - waitingList.begin()));
							break;
						}

						if (noOfCustomers > tolerance)//stop counting and skip
							nextOne = true;
					}/*
					 for (int leavingTime : waitingList) {//count number of customers ahead in ascending order
						 if (leavingTime <= arrivalTime)
							noOfLeftCustomers++;
						 else {
							 noOfCustomers = waitingList.size() - noOfLeftCustomers;
							 break;
						 }
					 }*/
				}

				if (i != N - 1) {
					if (noOfCustomers <= tolerance && !nextOne) {
						if (estTime < arrivalTime)
							estTime = arrivalTime + servingTime;
						else
							estTime += servingTime;//update finishing time of current customer
					}
				}
				else {//if this is the last customer
					if (noOfCustomers <= tolerance) {
						if (estTime < arrivalTime)
							cout << arrivalTime;
						else
							cout << estTime;
					}
					else
						cout << -1;

					cout << endl;
				}
			}
		}
	}

    return 0;
}

