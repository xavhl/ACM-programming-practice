#include <iostream>
#include <cmath>
using namespace std;

class Map {
private:
	int row, col;	
public:
	Map(int, int);
	char** rows = new char* [row];
	void setMap();
	void flip(char**, char, int);
	void copyMap(char**);
	int count(char**, char);
	int getMax();
};

Map::Map(int r, int c) {
	row = r;
	col = c;
	for (int i = 0; i < row; i++)
		rows[i] = new char[col];
}

void Map::setMap() {
	for (int i = 0; i < row; i++) {
		string ith;
		cin >> ith;

		for (int j = 0; j < col; j++) {
			if (ith[j] == '0')
				rows[i][j] = '0';
			else
				rows[i][j] = '1';
		}
	}
}

void Map::flip(char** tmap, char direction, int line) {
	if (direction == 'r') {
		for (int j = 0; j < col; j++) {
			if (tmap[line][j] == '0')
				tmap[line][j] = '1';
			else
				tmap[line][j] = '0';
		}
	}
	else
		for (int i = 0; i < row; i++) {
			if (tmap[i][line] == '0')
				tmap[i][line] = '1';
			else
				tmap[i][line] = '0';
		}
}

void Map::copyMap(char** mapcop) {
	for (int i = 0; i < row; i++) {
		mapcop[i] = new char[col];
		for (int j = 0; j < col; j++)
			mapcop[i][j] = rows[i][j];
	}
}

int Map::count(char** tmap, char dir) {
	int sum = 0;
	if (dir == 'c') {
		for (int j = 0; j < col; j++) {
			int colSum = 0;
			for (int i = 0; i < row; i++) {
				if (tmap[i][j] == '1')
					colSum++;
			}
			if (colSum < row / 2)
				colSum = row - colSum;
			sum += colSum;
		}
	}
	else {
		for (int i = 0; i < row; i++) {
			int rowSum = 0;
			for (int j = 0; j < col; j++) {
				if (tmap[i][j] == '1')
					rowSum++;
			}
			if (rowSum < col / 2)
				rowSum = col - rowSum;
			sum += rowSum;
		}
	}
	return sum;
}

int Map::getMax() {
	int sum = 0;
	if (row < col) {
		for (int i = 0; i < pow(2, row); i++) {
			char** tmap = new char* [row];
			copyMap(tmap);

			int tsum = 0;

			for (int j = 0; j < row; j++) {
				if (i & (1 << j))
					flip(tmap, 'r', j);
			}

			tsum = count(tmap, 'c');
			if (sum < tsum)
				sum = tsum;
		}
	}
	else {
		for (int i = 0; i < pow(2, col); i++) {
			char** tmap = new char* [row];
			copyMap(tmap);

			int tsum = 0;

			for (int j = 0; j < col; j++) {
				if (i & (1 << j))
					flip(tmap, 'c', j);
			}

			tsum = count(tmap, 'r');
			if (sum < tsum)
				sum = tsum;
		}
	}
	return sum;
}

int main() {
	int row, col;
	
	while (cin >> row >> col) {
		Map *map = new Map(row, col);
		map->setMap();
		cout << map->getMax() << endl;
		delete map;
	}

	return 0;
}