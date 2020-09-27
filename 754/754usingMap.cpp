#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int largestMinDist(int N, int C) {
	vector<pair<int, int>> floorPlan;

	for (int i = 0; i < N; i++) {
		int xi;
		cin >> xi;
		floorPlan.push_back(pair<int, int>(xi, 0));
	}

	sort(floorPlan.begin(), floorPlan.end());

	int first, last;//first and last elements, respectively with smallest and largest values
	first = floorPlan[0].first;
	++floorPlan[0].second;//==1, reserve the room
	last = floorPlan[floorPlan.size() - 1].first;
	++floorPlan[floorPlan.size() - 1].second;

	int interval = (first + last) / (C - 1);//divide the range into uniform portions

	for (int i = 0; i < C - 2; C++) {//first and last already marked
		int targetValue = interval * (i + 1);//value of ith interval, ith = i+1
		int targetPos = 0;

		//binary search
		int left = 0, right = floorPlan.size()-1;

		while (left != right) {
			int middle = (left + right) / 2;

			if (floorPlan[middle].first < targetValue)
				left = middle;
			else if (targetValue < floorPlan[middle].first)
				right = middle;
			else {
				targetPos = middle;
				break;
			}

			if (left == right - 1) {//two closest candidates left
				if (((targetValue - floorPlan[left].first) <= (floorPlan[right].first - targetValue)) || right == floorPlan.size()-1)
					targetPos = left;
				else if (((targetValue - floorPlan[left].first) > (floorPlan[right].first - targetValue)) || left == 0)
					targetPos = right;
			}
		}

		//reserve the room
		if(floorPlan[targetPos].second==0)
			++floorPlan[targetPos].second;
		else {
			bool roomReserved = false;
			while (roomReserved) {

			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, C;
		cin >> N >> C;
		cout << largestMinDist(N, C) << endl;
	}

	return 0;
}