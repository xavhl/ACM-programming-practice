#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int countMinDist(vector<int> rooms) {
	return 0;
}

int largestMinDist(int N, int C) {
	vector<int> input;

	for (int i = 0; i < N; i++) {
		int xi;
		cin >> xi;
		input.push_back(xi);
	}

	vector<int> hotelRooms = input;
	sort(hotelRooms.begin(), hotelRooms.end());

	vector<int> customerRooms;
	int first, last;//first and last elements, respectively with smallest and largest values

	first = hotelRooms[0];
	customerRooms.push_back(first);//reserve the room
	last = hotelRooms[hotelRooms.size() - 1];
	customerRooms.push_back(last);

	int interval = (first + last) / (C - 1);//divide the range into uniform portions

	for (int i = 0; i < C - 2; i++) {//first and last already marked
		int targetValue = interval * (i + 1);//value of ith interval, ith = i+1
		int targetPos = 0;

		//binary search
		int left = 0, right = hotelRooms.size()-1;

		while (left != right - 1) {
			int middle = (left + right) / 2;

			if (hotelRooms[middle] < targetValue)
				left = middle;
			else if (targetValue < hotelRooms[middle])
				right = middle;
			else {
				targetPos = middle;
				break;
			}

			if (left == right - 1) {//two closest candidates left
				if (((targetValue - hotelRooms[left]) <= (hotelRooms[right] - targetValue)) || right == hotelRooms.size()-1)
					targetPos = left;
				else if (((targetValue - hotelRooms[left]) > (hotelRooms[right] - targetValue)) || left == 0)
					targetPos = right;
			}
		}

		//reserve the room
		customerRooms.push_back(hotelRooms[targetPos]);
		hotelRooms.erase(hotelRooms.begin() + targetPos);
	}

	sort(customerRooms.begin(), customerRooms.end());
	for (auto itr = customerRooms.begin(); itr != customerRooms.end(); ++itr)
		cout << *itr << " ";

	return 0;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, C;
		cin >> N >> C;
		//cout << largestMinDist(N, C) << endl;
		largestMinDist(N, C);
	}

	return 0;
}