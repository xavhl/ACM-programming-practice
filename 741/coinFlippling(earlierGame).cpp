#include <iostream>
using namespace std;

void iniMap(int arr[30][3]) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 3; j++) {
			int r = rand() % 100 + 1;

			if (r > 50) {
				arr[i][j] = 1;
			}
			else
				arr[i][j] = 0;
		}
	}
}

void printCount(int arr[30][3]) {
	int rowSumSum = 0, colSumSum = 0;

	for (int i = 0; i < 30; i++) {
		int rowSum = 0;
		cout << i + 1 << ".\t";
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << "\t";
			if (arr[i][j] > 0)
				rowSum++;
		}
		cout << rowSum << endl;
		rowSumSum += rowSum;
	}

	cout << "\t";
	for (int j = 0; j < 3; j++) {
		int colSum = 0;
		for (int i = 0; i < 30; i++) {
			if (arr[i][j] > 0)
				colSum++;
		}
		cout << colSum << "\t";
		colSumSum += colSum;
	}
	cout << endl << endl << "rowSumSum: " << rowSumSum;
	cout << endl << "colSumSum: " << colSumSum << endl;
}

void setMap(int map[30][3], int cop[30][3]) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 3; j++) {
			cop[i][j] = map[i][j];
		}
	}
}

void flip(int arr[30][3], char cmd) {
	int num, r, c;
	cout << "Input number: ";
	cin >> num;

	if (cmd == 'r') {
		r = num - 1;
		for (int j = 0; j < 3; j++)
			arr[r][j] = (arr[r][j] + 1) % 2;
	}
	else if (cmd == 'c') {
		c = num - 1;
		for (int i = 0; i < 30; i++)
			arr[i][c] = (arr[i][c] + 1) % 2;
	}
}

int main()
{
    cout << "Coin Flipping" << endl << endl;

	int map[30][3], cop[30][3];
	iniMap(map);
	setMap(map, cop);
	printCount(cop);

	do {
		char cmd;
		cout << "Input command: ";
		cin >> cmd;

		if (cmd == 'r' || cmd == 'c')
			flip(cop, cmd);
		else if (cmd == '0')
			setMap(map, cop);
		else if (cmd == 'x')
			break;
		
		printCount(cop);
	} while (1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
