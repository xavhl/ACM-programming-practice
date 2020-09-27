#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

string sub(string s) {
	string tem = s, res = "";

    int cntA = 0, cntB;
    while(cntA < tem.length()) {
        char cmp = 'a';
        
		cntB = cntA;
        while(cntB < tem.length()) {
            
			if (tem[cntB] > cmp) {
				cmp = tem[cntB];
				cntA = cntB;
			}
			
			cntB++;
        }
        
		res += cmp;
		cntA++;
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
