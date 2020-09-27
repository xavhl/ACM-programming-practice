#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		vector<tuple<int, int, int>> queue;

		for (int i = 0; i < N; ++i) {
			int A, O, L;
			cin >> A >> O >> L;
			queue.push_back(tuple<int, int, int>(A, O, L));
		}

		int timer = get<0>(queue[0]) + get<1>(queue[0]);//first customer must be served

		for (auto itr = queue.begin() + 1; itr != queue.end(); ++itr) {//so skip first one
			int noOfCustomer = 0;//count of previous customers
			int arrivalTime = get<0>(*itr), servingTime= get<1>(*itr), tolerance = get<2>(*itr);//for current customer

			for (auto itr2 = queue.begin(); itr2 != itr + 1; ++itr2) {//loop all previous customers for current customer
				if (itr2 == itr) {//update condition of current customer, whether leaving or not		#2
					if (itr == queue.end()-1) {//conclude condition if loop is on last customer			#4
						if (noOfCustomer <= tolerance)
							cout << timer;
						else
							cout << -1;

						cout << endl;
					}
					else {
						if (noOfCustomer <= tolerance)//number of previous customers is acceptable		#3
							timer += servingTime;
						else//will leave and not be counted
							//queue.erase(itr);
							;
					}
				}
				else {//increment count																	#1
					if (get<0>(*itr2) + get<1>(*itr2) > arrivalTime)//check whether the previous one has finished and left
						++noOfCustomer;
				}
			}
		}
	}

	return 0;
}