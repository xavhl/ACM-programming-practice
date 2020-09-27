#include <iostream>
#include <cmath>
using namespace std;

char** setMap(int size) {
	char** img = new char* [size];

	for (int i = 0; i < size; i++) {
		char* side = new char[size];
		img[i] = side;

		string line;
		cin >> line;

		for (int j = 0; j < size; j++)
			img[i][j] = line[j];
	}
	return img;
}

bool compareQuad(char** edge, int x, int y, int quadsize) {
	bool isIdentical = false;

	char a = edge[x][y], b = edge[x][y + quadsize], c = edge[x + quadsize][y], d = edge[x + quadsize][y + quadsize];
	if (a == b && c == d && a == c)
		isIdentical = true;

	return isIdentical;
}

int count(char** edge, int x, int y, int size) {
	
	int quadsize = size / 2;

	if (quadsize == 1) {
		if (compareQuad(edge, x, y, quadsize))
			return 1;
		else
			return 4 + 1;
	}
	else {
		int sum = 0;

		int x1 = x, y1 = y;
		int q1 = count(edge, x1, y1, quadsize);
		int x2 = x + quadsize, y2 = y;
		int q2 = count(edge, x2, y2, quadsize);
		int x3 = x, y3 = y + quadsize;
		int q3 = count(edge, x3, y3, quadsize);
		int x4 = x + quadsize, y4 = y + quadsize;
		int q4 = count(edge, x4, y4, quadsize);
		
		if (q1 == q2 && q3 == q4 && q1 == q3 && compareQuad(edge, x, y, quadsize))
			sum = 1;
		else
			sum = q1 + q2 + q3 + q4 + 1;
		return sum;
	}
}

int main() {
	int exp;

	while (cin >> exp) {
		int size = pow(2, exp);

		char** img = new char* [size];
		img = setMap(size);

		cout << count(img, 0, 0, size) << endl;
	}	

	return 0;
}