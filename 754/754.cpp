#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(int boundary, vector<int> dist, int total, int noOfSegments) {
	int count = 0;//count number of possible segments

	int sum = 0;//temporary sum for each potential segment
	for (auto itr = dist.begin(); itr != dist.end(); ++itr) {
		sum += *itr;

		if (sum >= boundary) {//a valid segment with a sum meets(>=) boundary
			count++;
			sum = 0;//reset sum for next potential segments
		}
	}

	if (count >= noOfSegments)//true indicates the possibility for the segments/ sub arrays to have a sum larger than the boundary
		return true;
	else//number of segments, that have sum larger than boundary, is not sufficient for the required number, thus impossible 
		return false;
}

int largestMinDist(int N, int C) {
	vector<int> hotelRooms;//e.g. hotel rooms: 1 2 4 8 9

	for (int i = 0; i < N; i++) {
		int xi;
		cin >> xi;
		hotelRooms.push_back(xi);
	}
	sort(hotelRooms.begin(), hotelRooms.end());

	vector<int> roomDistances;//record of separations between each rooms
	int prevRoom = hotelRooms[0];//e.g. room distances: 1 2 4 1

	for (auto itr = hotelRooms.begin() + 1; itr != hotelRooms.end(); ++itr) {
		roomDistances.push_back(*itr - prevRoom);
		prevRoom = *itr;
	}

	//binary search for optimal largest minimum distance
	int start = 1, end = 0;//start (minimum distance possible) == 1
	for (auto itr = roomDistances.begin(); itr != roomDistances.end(); ++itr)
		end += *itr;//end (maximum distance possible) == summation of all room distances e.g. 1+2+4+1=8

	int largestMinDist = 0;
	while (start <= end) {
		int middle = (start + end) / 2;

		if (check(middle, roomDistances, N - 1, C - 1)) {//check if middle is a valid largest min distance
			largestMinDist = middle;
			start = middle + 1;
		}
		else
			end = middle - 1;
	}

	return largestMinDist;
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