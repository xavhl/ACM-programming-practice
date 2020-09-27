#include <iostream>
using namespace std;

class Town {
private:
	int* group;
	int* size;
	int population;
	int largestGroup;
	
public:
	Town(int n) {
		group = new int[n];
		size = new int[n]; 
		population = n;
		largestGroup = 0;		

		for (int i = 0; i < n; i++) {
			group[i] = i;
			size[i] = 1;
		}
	}

	~Town() {
		delete[] group;
		delete[] size;
	}

	int find(int);
	void befriend(int, int);
	int getLargestGroup() { return largestGroup; }
};

int Town::find(int person) {
	if (group[person] != person)//not alone, with other friends as a group
		group[person] = find(group[person]);//path compression, look for root

	return group[person];
}

void Town::befriend(int A, int B) {//union
	int groupOfA = find(A), groupOfB = find(B);

	if (groupOfA == groupOfB) {//skip if already friends in same group
		return;
	}

	group[groupOfB] = groupOfA;//change root of one group to another, i.e. union/ merge
	size[groupOfA] += size[groupOfB];//increment size

	if (largestGroup < size[groupOfA])//update record of largestGroup
		largestGroup = size[groupOfA];
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int noOfPersons, noOfPairs;
		cin >> noOfPersons >> noOfPairs;

		Town* town = new Town(noOfPersons);
		for (int i = 0; i < noOfPairs; ++i) {
			int A, B;
			cin >> A >> B;
			town->befriend(A - 1, B - 1);
		}
		cout << town->getLargestGroup() << endl;
		delete town;
	}

	return 0;
}