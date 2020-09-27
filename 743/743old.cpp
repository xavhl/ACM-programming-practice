#include <iostream>
#include <string>
#include <stack>
using namespace std;

void checkSyntax(string line) {
	stack<char> code;
	int pos = 0;
	bool unmatchedClosing = false;

	for (int i = 0; i < line.length(); i++) {
		if (code.empty())
			pos = i+1;

		if (line[i] == '(' || line[i] == '[' || line[i] == '{')
			code.push(line[i]);
		else if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
			char c = code.top();

			if (c=='(') {
				if (char(c + 1) == line[i])
					code.pop();
				else {
					cout << i + 1 << endl;
					unmatchedClosing = true;
					break;
				}
			}
			else if (c == '[' || c == '{') {
				if (char(c + 2) == line[i])
					code.pop();
				else {
					cout << i + 1 << endl;
					unmatchedClosing = true;
					break;
				}
			}
		}
	}
	if (!code.empty()) {
		if(!unmatchedClosing)
			cout << pos << endl;
	}
	else
		cout << "Sucess" << endl;
}

int main() {
	string line;

	while (getline(cin, line))
		checkSyntax(line);

	return 0;
}