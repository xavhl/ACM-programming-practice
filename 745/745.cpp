#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<int> pile;
		
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int card;
			cin >> card;
			pile.push_back(card);
		}

		int m;
		cin >> m;
		for (int k = 0; k < m; k++) {
			char op;
			cin >> op;
			if (op == 'm') {
				//int max = pile[0];
				int max = pile.front();
				//for (auto itr = pile.begin(); itr != pile.end(); itr++) {
				for(auto itr : pile) {
					if (max < itr)
						max = itr;
				}
				cout << max << endl;
			}
			else if (op == 'r')
				pile.pop_back();
			else if (op == 'a') {
				int card;
				cin >> card;
				pile.push_back(card);
			}
		}
	}

	return 0;
}