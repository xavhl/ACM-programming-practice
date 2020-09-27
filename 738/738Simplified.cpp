#include <iostream>
using namespace std;

int main() {
	int n;
	
    while(cin >> n) {
        if (n < 2) {
            if(n < 0)
                cout << 0 << endl;
            else
                 cout << n << endl;
        }
        else {
            int secPrev = 0, firPrev = 1, sum = 0;
            
            for (int i = 0; i < n - 1; i++) {
                sum = secPrev + firPrev;
                
                if (sum > 9)
                    sum %= 10;
                
                secPrev = firPrev;
                firPrev = sum;
            }
            cout << sum << endl;
        }
    }
	return 0;
}
