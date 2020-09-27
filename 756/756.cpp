#include <iostream>
#include <queue>
using namespace std;

int main() {
	int noOfOperations;
	while (cin >> noOfOperations) {
		priority_queue<int>heap;
		int sum = 0;

		for (int i = 0; i < noOfOperations; ++i) {
			char operation;
			cin >> operation;

			if (operation == 'a') {
				int value;
				cin >> value;
				heap.push(value);
				sum += value;
			}
			else if (operation == 'p') {
				sum -= heap.top();
				heap.pop();
			}
			else//operation == 'r'
				cout << sum << endl;
		}

		heap = {};
		sum = 0;
	}

	return 0;
}