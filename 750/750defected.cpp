#include <iostream>
#include <vector>
using namespace std;

class Family {
public:
	vector<int> familyTree;
	vector<int> rank;//rank of relationship, in ascending order, oldest ancestor will have 1
	int rootMember;
	int noOfFamilyMembers;

	Family(int rootMember, int noOfFamilyMembers) : rank(noOfFamilyMembers, 1), familyTree(noOfFamilyMembers, -1) {
		this->rootMember = rootMember;
		this->noOfFamilyMembers = noOfFamilyMembers;
		familyTree[rootMember] = 0;//mark root ancestor
		drawTree();
	}

	~Family() {
		familyTree.clear();
		rank.clear();
	}

	void drawTree() {
		for (int j = 0; j < noOfFamilyMembers - 1; ++j) {//input family members
			int member, parent;
			cin >> member >> parent;
			if (familyTree[member - 1] == -1) {//not linked yet
				familyTree[member - 1] = parent - 1;//link parent
				rank[member - 1] += rank[parent - 1];//increment rank
			}
		}
	}

	int find(int member) {
		if(familyTree[member]==0)//if this is the oldest ancestor return itself
			return member;
		return familyTree[member];
	}

	int searchCommonAncestor(int A, int B) {
		int ancestor = 0;
		int parentOfA = find(A), parentOfB = find(B);

		if (rank[A] != rank[B]) {//if not in same level, move upward
			int rankDifference = 0;
			if (rank[A] > rank[B]) {
				rankDifference = rank[A] - rank[B];

				for (int i = 0; i < rankDifference; ++i)
					parentOfA = find(parentOfA);
			}
			else {
				rankDifference = rank[B - 1] - rank[A - 1];

				for (int i = 0; i < rankDifference; ++i)
					parentOfB = find(parentOfB);
			}
		}

		while (parentOfA != parentOfB) {//move upward together
			parentOfA = find(parentOfA);
			parentOfB = find(parentOfB);
		}

		ancestor = parentOfA;

		return ancestor;
	}
};

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int rootMember, noOfFamilyMembers;
		cin >> rootMember >> noOfFamilyMembers;

		Family* family = new Family(rootMember - 1, noOfFamilyMembers);//member number starts with 1 while vector id starts with 0

		int memberA, memberB;
		cin >> memberA >> memberB;

		cout << family->searchCommonAncestor(memberA - 1, memberB - 1) + 1 << endl;

		delete family;
	}

	return 0;
}