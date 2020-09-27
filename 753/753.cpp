#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int xorWeight(string tree) {
	vector<int> weight;
	stack<char> syntax;
	
	for (string::size_type i = 0; i < tree.size(); i++) {
		if (tree[i] == ')')
			continue;

		int count = 0;
		for (string::size_type j = i; j < tree.size(); j++) {
			if (tree[j] == '(') {
				count++;
				syntax.push(tree[j]);
			}
			else //if (tree[j] == ')')
				syntax.pop();
			
			if (syntax.empty())
				break;
		}
		weight.push_back(count);
	}

	int xorSum = weight[0];
	for (auto i = weight.begin() + 1; i != weight.end();++i) {
		xorSum = xorSum ^ *i;
	}

	weight.clear();
	return xorSum;
}

int main() {
	string tree;
	while (cin >> tree)
		cout << xorWeight(tree) << endl;

	return 0;
}