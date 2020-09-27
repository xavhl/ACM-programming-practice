#include <iostream>
#include <cmath>
using namespace std;

char** setMap(int row, int col) {
	char** rows = new char*[row];

	for (int i = 0; i < row; i++) {
		char* cols = new char[col];
		rows[i] = cols;

		string ith;
		cin >> ith;

		for (int j = 0; j < col; j++) {
			if (ith[j] == '0')
				cols[j] = '0';
			else
				cols[j] = '1';
		}
	}

	return rows;
}

void flip(char** map, char direction, int line, int row, int col) {
	if (direction == 'r') {
		for (int j = 0; j < col; j++) {
			if (map[line][j] == '0')
				map[line][j] = '1';
			else
				map[line][j] = '0';
		}
	}
	else
		for (int i = 0; i < row; i++) {
			if (map[i][line] == '0')
				map[i][line] = '1';
			else
				map[i][line] = '0';
		}
}

char** copyMap(char** map, int row, int col) {
	char** mapcop = new char* [row];
	for (int i = 0; i < row; i++) {
		mapcop[i] = new char [col];
		for (int j = 0; j < col; j++)
			mapcop[i][j] = map[i][j];
	}		
	return mapcop;
}
/*
void printMap(char** map, int row, int col) {
	cout << "Map" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

int count(char** map, int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (map[i][j] == '1')
				sum++;
	}
	return sum;
}*/

int countCols(char** map, int row, int col) {
	int sum = 0;
	for (int j = 0; j < col; j++) {
		int colSum = 0;
		for (int i = 0; i < row; i++) {
			if (map[i][j] == '1')
				colSum++;
		}
		if (colSum < row / 2)
			colSum = row - colSum;
		sum += colSum;
	}
	return sum;
}

int countRows(char** map, int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		int rowSum = 0;
		for (int j = 0; j < col; j++) {
			if (map[i][j] == '1')
				rowSum++;
		}
		if (rowSum < col / 2)
			rowSum = col - rowSum;
		sum += rowSum;
	}
	return sum;
}

int getMax(char** map, int row, int col) {
	int sum = 0;
	if (row < col) {
		for (int i = 0; i < pow(2, row); i++) {
			char** tmap = new char*[row];
			tmap = copyMap(map, row, col);

			int tsum = 0;

			for (int j = 0; j < row; j++) {
				if (i & (1 << j))
					flip(tmap, 'r', j, row, col);
			}

			tsum = countCols(tmap, row, col);
			if (sum < tsum)
				sum = tsum;
		}
	}
	else {
		for (int i = 0; i < pow(2, col); i++) {
			char** tmap = new char* [row];
			tmap = copyMap(map, row, col);

			int tsum = 0;

			for (int j = 0; j < col; j++) {
				if (i & (1 << j))
					flip(tmap, 'c', j, row, col);
			}

			tsum = countRows(tmap, row, col);
			if (sum < tsum)
				sum = tsum;
		}
	}
	return sum;
}

int main() {
	int row, col;
	/*
	while (cin >> row >> col) {
		setMap(row, col);
	}
	*/
	cin >> row >> col;
	
	char ** rows = setMap(row, col);
	cout << getMax(rows, row, col) << endl;
	
	/* TEST
	cin >> row >> col;
	char** rows = setMap(row, col);
	printMap(rows, row, col);
	cout << "total: " << count(rows, row, col) << endl;

	char dir;
	int line;
	cout << "Flip: ";
	cin >> dir >> line;
	flip(rows, dir, line, row, col);
	printMap(rows, row, col);
	cout << endl << "total: " << count(rows, row, col) << endl;
	*/
	return 0;
}