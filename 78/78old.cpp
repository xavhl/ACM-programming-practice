#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sub(string s) {
	int bit, len;
	string res = s;

	len = s.size();
	bit = pow(2, len);//permutations of possible subsequences

	for (int i = 1; i < bit; i++) {//skip i = 0 wherein tem=""
		string tem = "";

		for (int j = 0; j < len; j++) {
			if (i & (1 << j))//bitwise operators, sec operand is to left shift digit 1
				tem += s[j];
		}

		if (res.compare(tem) < 0)
			res = tem;
	}

	return res;
}

int main() {
	int num;
	vector<string> lis;

	cin >> num;
	for (int i = 0; i < num; i++) {
		string wrd;

		cin >> wrd;
		lis.push_back(sub(wrd));
	}

	//print result
	for (int i = 0; i < lis.size(); i++)
		cout << lis[i] << endl;
	
	return 0;
}