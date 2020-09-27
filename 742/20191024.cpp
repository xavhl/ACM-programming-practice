//#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool compareQuad(char** edge, int x, int y, int quadsize) {
	bool isIdentical = false;

	char a = edge[x][y], b = edge[x][y + quadsize], c = edge[x + quadsize][y], d = edge[x + quadsize][y + quadsize];
	if (a == b && c == d && a == c)
		isIdentical = true;

	return isIdentical;
}

int count(char** edge, int x, int y, int size) {
	if (size == 1)
		return 1;

	int quadsize = size / 2;
	if (quadsize == 1) {
		if (compareQuad(edge, x, y, quadsize))
			return 1;
		else
			return 4 + 1;
	}
	else {
		int sum = 0;

		int q1 = count(edge, x, y, quadsize);
		int q2 = count(edge, x + quadsize, y, quadsize);
		int q3 = count(edge, x, y + quadsize, quadsize);
		int q4 = count(edge, x + quadsize, y + quadsize, quadsize);

		if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1 && compareQuad(edge, x, y, quadsize))
			sum = 1;
		else
			sum = q1 + q2 + q3 + q4 + 1;

		return sum;
	}
}

int main() {
	int exp;

	while (cin >> exp) {
		if (0 <= exp && exp <= 10) {
			int size = pow(2, exp);

			//set up
			char** img = new char*[size];
			for (int i = 0; i < size; i++) {
				char* side = new char[size];
				img[i] = side;

				string line;
				cin >> line;

				for (int j = 0; j < size; j++)
					img[i][j] = line[j];
			}

			cout << count(img, 0, 0, size) << endl;
		}
		else
			break;
	}

	return 0;
}