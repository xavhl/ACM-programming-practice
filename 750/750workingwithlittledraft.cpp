#include <iostream>
#include <vector>
using namespace std;

class Family {
public:
	vector<int> familyTree;
	vector<int> rank;//rank of relationship, in ascending order, oldest ancestor will have 1
	int rootMember;
	int noOfFamilyMembers;

	Family(int rootMember, int noOfFamilyMembers) : rank(noOfFamilyMembers, 1) {
		this->rootMember = rootMember;
		this->noOfFamilyMembers = noOfFamilyMembers;
		//familyTree.reserve(noOfFamilyMembers);
		familyTree.resize(noOfFamilyMembers);
		//rank.resize(noOfFamilyMembers);
		familyTree[rootMember - 1] = 0;//mark root ancestor
		drawTree();
		
		//testing
		cout << endl << "familyTree ";
		for (auto itr = familyTree.begin(); itr != familyTree.end(); ++itr)
			cout << *itr << " ";
		cout << endl << "rank ";
		for (auto itr = rank.begin(); itr != rank.end(); ++itr)
			cout << *itr << " ";
		cout << endl;
	}

	~Family() {
		familyTree.clear();
		rank.clear();
	}

	void drawTree() {
		for (int j = 0; j < noOfFamilyMembers - 1; ++j) {//input family members
			int member, parent;
			cin >> member >> parent;
			familyTree[member - 1] = parent - 1;
			rank[member - 1] += rank[parent - 1];
		}
	}

	int find(int member) {
		if(familyTree[member]==0)
			return member;
		return familyTree[member];
	}

	int searchCommonAncestor(int A, int B) {
		int ancestor = 0;
		int parentOfA = find(A - 1), parentOfB = find(B - 1);

		if (rank[A - 1] != rank[B - 1]) {//if not in same level, move upward
			int rankDifference = 0;
			if (rank[A - 1] > rank[B - 1]) {
				rankDifference = rank[A - 1] - rank[B - 1];

				for (int i = 0; i < rankDifference; ++i)
					parentOfA = find(parentOfA);
			}
			else {
				rankDifference = rank[B - 1] - rank[A - 1];

				for (int i = 0; i < rankDifference; ++i)
					parentOfB = find(parentOfB);
			}
		}

		while (parentOfA != parentOfB) {
			parentOfA = find(parentOfA);
			parentOfB = find(parentOfB);
		}

		ancestor = parentOfA;

		return ancestor + 1;
	}
};

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int rootMember, noOfFamilyMembers;
		cin >> rootMember >> noOfFamilyMembers;

		Family* family = new Family(rootMember, noOfFamilyMembers);

		int memberA, memberB;
		cin >> memberA >> memberB;

		cout << family->searchCommonAncestor(memberA, memberB) << endl;

		delete family;
	}

	return 0;
}