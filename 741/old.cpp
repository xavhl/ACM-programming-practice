#include <iostream>
#include <vector>
using namespace std;

int main() {
    //vector<vector<int>> map;
    int row, col;
    cin >> row >> col;
    
    string *str = new string[row];
    //vector<string> str;
    for(int i=0; i<row; i++) {
        string ith;
        cin >> ith;
        str[i] = ith;
        //str.push_back(ith);
    }
    
    int **map = new int*[row];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            map[i] = new int[col];
            if(str[i][j]=='0')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }
    
    cout << "map: " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    
    
    return 0;
}
