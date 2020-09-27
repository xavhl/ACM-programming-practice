#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>> S;
		for (int j = 0; j < N; ++j) {
			int mi;
			cin >> mi;
			S.push_back(pair<int, int>(mi, j + 1));
		}

		vector<pair<int, int>> tmp;
		while (!S.empty()) {
			if (S.size() <= K) {//not S.size() < K
				if (S.size() == 1) {
					cout << S.begin()->second << endl;
					S.erase(S.begin(), S.end());
					continue;
				}
				else {
					move(S.begin(), S.end(), back_inserter(tmp));
					S.erase(S.begin(), S.end());
				}
			}
			else {
				move(S.begin(), S.begin() + K, back_inserter(tmp));
				S.erase(S.begin(), S.begin() + K);
			}

			int vmax = tmp.begin()->first;//, vmaxIndex; //for comparing vmax value
			auto itrTarget = tmp.begin();

			for (auto itr = tmp.begin(); itr != tmp.end(); ++itr) {
				if (vmax < itr->first) {
					vmax = itr->first;//update comparator
					//vmaxIndex = itr - tmp.begin() + 1;
					itrTarget = itr;
				}//else if vmax == itr->first => ignore;
			}
			cout << itrTarget->second << " ";
			tmp.erase(itrTarget);//remove vmax

			for (auto itr = tmp.begin(); itr != tmp.end(); ++itr)//subtract 1
				itr->first--;

			move(tmp.begin(), tmp.end(), back_inserter(S));
			tmp.erase(tmp.begin(), tmp.end());
		}

		S.clear();
		tmp.clear();
	}

	return 0;
}