#include <iostream>
using namespace std;

int lastDigitOfFibonacci(int n) {
    if (n < 2) {
        if(n < 0)
            return 0;
        else
            return n;
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
		return sum;
	}
}

int main() {
	int n;
    while(cin >> n)
        cout << lastDigitOfFibonacci(n) << endl;
    
	return 0;
}
