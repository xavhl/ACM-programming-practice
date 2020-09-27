#include <iostream>
using namespace std;

int* jumpCnt(int noOfWalls, int jump[2]) {
    int walls[noOfWalls];
    
    for(int i=0; i<noOfWalls; i++) {
        int height;
        cin >> height;
        walls[i] = height;
    }
    
    
    for(int j=0; j<noOfWalls-1; j++) {
        //int curWall = walls[j];
        if(walls[j] < walls[j+1])
            jump[0]++;
        else if(walls[j] > walls[j+1])
            jump[1]++;
    }
    
    return jump;
}

int main(int argc, const char * argv[]) {
    int noOfCases;
    cin >> noOfCases;
    
    for(int i=0; i<noOfCases; i++) {
        int noOfWalls;
        int jump[2] = {0, 0};
        
        cin >> noOfWalls;
        jumpCnt(noOfWalls, jump);
        
        cout << "Case " << i+1 << ": " << jump[0] << " " << jump[1] << endl;
    }
    
    return 0;
}
