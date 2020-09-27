#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string wrd;
	vector <string> words;
	vector <int> index;
	
	while (cin >> wrd) {
		if (words.size() == 0) {
			words.push_back(wrd);
			index.push_back(1);
		}
		else {
			bool isMatched = false;
			int i, tpos;

			for (i = 0; i < words.size(); i++) {
				//tpos = 0;
				if (wrd.compare(words[i]) < 0) {
					//tpos = i;
					words.insert(words.begin(), wrd);
					index.insert(index.begin(), 1);
					break;
				}
				else if (wrd.compare(words[i]) == 0) {
					isMatched = true;
					index[i]++;
					break;
				}
				else {
					tpos = i + 1;
				}

				if (!isMatched) {
					words.insert(tpos, wrd);
					words.push_back(wrd);
					index.push_back(1);
				}
			}
		}
	}

	cout << endl;
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << ' ' << index[i] << endl;
	}

	return 0;
}