#include <iostream>
#include <cmath>
#include <string>
using namespace std;
/*
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
}*/

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
/*
char** copyMap(char** map, int row, int col) {
	char** mapcop = new char* [row];
	for (int i = 0; i < row; i++) {
		mapcop[i] = new char [col];
		for (int j = 0; j < col; j++)
			mapcop[i][j] = map[i][j];
	}		
	return mapcop;
}*/

int count(char** map, char dir, int row, int col) {
	int sum = 0;
	if (dir == 'c') {
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
	}
	else {
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
	}
	return sum;
}

int flipAndCount(char** map, int row, int col) {
    int sum = 0;
    
    if(row<col) {
        
        for (int i = 0; i < pow(2, row); i++) {
            int tsum = 0;
            
            for(int j = 0; j < row; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < col; k++) {
                        if (map[j][k] == '0')
                            map[j][k] = '1';
                        else
                            map[j][k] = '0';
                    }
                }
                //flip(tmap, 'r', j, row, col);
            }
            
            tsum = count(map, 'c', row, col);
            if (sum < tsum)
                sum = tsum;
            
            //flip back the map
            for(int j = 0; j < row; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < col; k++) {
                        if (map[j][k] == '0')
                            map[j][k] = '1';
                        else
                            map[j][k] = '0';
                    }
                }
            }
            //
        }
    }
    else {
        for (int i = 0; i < pow(2, col); i++) {
            int tsum = 0;
            
            for (int j = 0; j < col; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < row; k++) {
                        if (map[k][j] == '0')
                            map[k][j] = '1';
                        else
                            map[k][j] = '0';
                    }
                }
            }
            
            tsum = count(map, 'r', row, col);
            if (sum < tsum)
                sum = tsum;
            
            //flip back the coin
            for (int j = 0; j < col; j++) {
                if (i & (1 << j)) {
                    for (int k = 0; k < row; k++) {
                        if (map[k][j] == '0')
                            map[k][j] = '1';
                        else
                            map[k][j] = '0';
                    }
                }
            }
            //
        }
    }
    return sum;
}
/*
int getMax(char** map, int row, int col) {
	int sum = 0;
	if (row < col) {
		for (int i = 0; i < pow(2, row); i++) {
			//char** tmap = new char*[row];
			//tmap = copyMap(map, row, col);
            
            char** tmap = new char* [row];
            for (int i = 0; i < row; i++) {
                tmap[i] = new char [col];
                for (int j = 0; j < col; j++)
                    tmap[i][j] = map[i][j];
            }
            
			int tsum = 0;//

			for(int j = 0; j < row; j++) {
				if (i & (1 << j))
					flip(tmap, 'r', j, row, col);
			}

			tsum = count(tmap, 'c', row, col);
			if (sum < tsum)
				sum = tsum;
            delete []tmap;
            tmap = NULL;
		}
	}
	else {
		for (int i = 0; i < pow(2, col); i++) {
			//char** tmap = new char* [row];
			//tmap = copyMap(map, row, col);
            
            char** tmap = new char* [row];
            for (int i = 0; i < row; i++) {
                tmap[i] = new char [col];
                for (int j = 0; j < col; j++)
                    tmap[i][j] = map[i][j];
            }
            
			int tsum = 0;

			for (int j = 0; j < col; j++) {
				if (i & (1 << j))
					flip(tmap, 'c', j, row, col);
			}

			tsum = count(tmap, 'r', row, col);
			if (sum < tsum)
				sum = tsum;
            delete []tmap;
            tmap = NULL;
		}
	}
	return sum;
}*/

int main() {
	int row, col;
	
	while (cin >> row >> col) {
        if(row < 1|| row > 100|| col < 1|| col > 10) {
            cout<<"Out of boundary"<<endl;
            break;
        }
        else {
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
            
            cout << flipAndCount(rows, row, col) << endl;
        }
	}

	return 0;
}
