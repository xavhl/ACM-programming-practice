#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int>A, B, S, temA;

	int noOfCases;//1 <= T <= 10	
	while (cin >> noOfCases) {
		for (int i = 0; i < noOfCases; i++) {
			int noOfstackA;//1 <= n <= 3000
			cin >> noOfstackA;

			for (int j = 0; j < noOfstackA; j++) {
				int ele;
				cin >> ele;
				A.push(ele);
			}

			int noOfPermutations;//m <= 200
			cin >> noOfPermutations;

			for (int k = 0; k < noOfPermutations; k++) {
				int* expB = new int[noOfstackA];
				for (int j = 0; j < noOfstackA; j++)
					cin >> expB[j];

				//verify
				temA = A;
				bool valid = true;

				for (int j = 0; j < noOfstackA; j++) {
					do {
						valid = false;

						if (!S.empty() && S.top() == expB[j]) {//check stack S
							B.push(S.top());
							S.pop();
							valid = true;
						}
						else if (!temA.empty()) {
							bool eleFound = false;//for finding element in stack A

							if (temA.top() == expB[j])
								eleFound = true;

							while (temA.top() != expB[j]) {
								S.push(temA.top());
								temA.pop();

								if (temA.empty())
									break;

								if (temA.top() == expB[j])
									eleFound = true;
							}

							if (eleFound) {
								B.push(temA.top());
								temA.pop();
								valid = true;
							}
						}
						else
							break;
					} while (B.top() != expB[j]);
					if (!valid) {
						cout << "Impossible" << endl;
						break;
					}
				}
				if (valid) {
					cout << "Aye" << endl;
				}

				delete[] expB;
				expB = NULL;

				while (!B.empty())
					B.pop();
			}
		}
	}
}