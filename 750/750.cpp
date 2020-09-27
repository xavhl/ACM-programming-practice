#include <iostream>
#include <vector>
using namespace std;

class Family {
public:
	vector<int> familyTree;
	//vector<int> rank;//rank of relationship, in ascending order, oldest ancestor will have 1
	int rootMember;
	int noOfFamilyMembers;

	Family(int rootMember, int noOfFamilyMembers) : /*rank(noOfFamilyMembers, 1),*/ familyTree(noOfFamilyMembers) {
		this->rootMember = rootMember;
		this->noOfFamilyMembers = noOfFamilyMembers;
		familyTree[rootMember] = -1;//mark root ancestor
		drawTree();
	}

	~Family() {
		familyTree.clear();
		//rank.clear();
	}

	void drawTree() {
		for (int j = 0; j < noOfFamilyMembers - 1; ++j) {//input family members
			int member, parent;
			cin >> member >> parent;
			familyTree[member - 1] = parent - 1;//link parent
			//rank[member - 1] += rank[parent - 1];//increment rank
		}
	}

	int find(int member) {
		if (familyTree[member] == -1)//if this is the oldest ancestor return itself
			return member;
		return familyTree[member];
	}

	int searchCommonAncestor(int A, int B) {
		if (A == B)
			return A;

		int ancestor = rootMember;
		
		int parentOfA = find(A), rankOfA = 1;
		while (parentOfA != rootMember) {//count depth in family tree, in ascending order, ancestor has rank 0
			if (parentOfA == B)
				return parentOfA;

			parentOfA = find(parentOfA);
			++rankOfA;
		}
		parentOfA = find(A);

		int parentOfB = find(B), rankOfB = 1;
		while (parentOfB != rootMember) {
			if (parentOfB == A)
				return parentOfB;

			parentOfB = find(parentOfB);
			++rankOfB;
		}
		parentOfB = find(B);

		//cout << "rankofA " << rankOfA << " rankofB " << rankOfB << endl;
		//bool isParent = false;

		if (rankOfA != rankOfB) {//if not in same level, move upward
			int rankDifference = 0;
			if (rankOfA > rankOfB) {
				rankDifference = rankOfA - rankOfB;

				for (int i = 0; i < rankDifference; ++i)
					parentOfA = find(parentOfA);
			}
			else {
				rankDifference = rankOfB - rankOfA;

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