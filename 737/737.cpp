#include <iostream>
#include <map>
using namespace std;

int main() {
	string wrd;
	map <string, int> words;
	
	while (cin >> wrd) {
		if (words.size() == 0) {
			words.insert({wrd, 1});
		}
		else {
			bool isMatched = false;

			for (auto itr = words.begin(); itr != words.end(); itr++) {
				if (wrd.compare(itr->first) == 0) {
					isMatched = true;
					(itr->second)++;
					break;
				}				
			}
			if (!isMatched) {
				words.insert({ wrd, 1 });
			}
		}
	}

	cout << endl;
	for (auto itr = words.begin(); itr != words.end(); itr++) {
		cout << itr->first << ' ' << itr->second << endl;
	}

	return 0;
}