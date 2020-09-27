#include <iostream>
#include <queue>
using namespace std;

int getDigit(unsigned long int num, unsigned long int digitIndex) {
	unsigned long n = num;

	for (int i = 0; i < digitIndex; ++i)
		n /= 10;

	return n % 10;
}

void radixSort(unsigned long int Arr[], unsigned long int noOfElements, unsigned long int noOfDigits) {
	queue<unsigned long int>* C = new queue<unsigned long int>[10];
	unsigned long int i, j, k;

	//A[i]; i, 0 to n-1; d, 0 to 9
	for (i = 0; i < noOfDigits; ++i) {
		for (j = 0; j < noOfElements; ++j)
			C[getDigit(Arr[j], i)].push(Arr[j]);

		for (j = 0, k = 0; k < 10; ++k) {
			while (!C[k].empty()) {
				Arr[j] = C[k].front();
				C[k].pop();
				++j;
			}
		}
	}
}

unsigned long int fibonacciSequence(unsigned long int sequenceRange, unsigned long int modulo) {
	unsigned long int* sequence = new unsigned long int[sequenceRange + 1];
	sequence[0] = 0;
	sequence[1] = 1;

	unsigned long int i, j, max = 0;

	unsigned long int num0 = sequence[0], num1 = sequence[1], num2 = 0, pisano1 = -1, pisano2 = -1, pisanoPeriod = 0;
	for (i = 2; i < sequenceRange + 1; ++i) {
		if (pisano1 == pisano2 - 1) {
			if (pisano2 + 1 == i) { 
				j = 3; 
				pisanoPeriod = pisano1 - 1;
			}

			sequence[i] = sequence[j];
			j = (j + 1) % pisanoPeriod;
		}
		else {
			num2 = num0 + num1;
			sequence[i] = num2 % modulo;

			if (sequence[i] == 0) pisano1 = i;
			if (sequence[i] == 1) pisano2 = i;

			num0 = num1;
			num1 = num2;
		}
		if (max < sequence[i])//record largest number for number of digits
			max = sequence[i];
	}
	/*
	for (i = 0, j = 0; i < sequenceRange + 1; ++i) {
		if (j < (sequenceRange + 1) - 2) {
			sequence[j + 2] = sequence[j] + sequence[j + 1];
			++j;
		}

		sequence[i] = sequence[i] % modulo;

		if (max < sequence[i])//record largest number for number of digits
			max = sequence[i];
	}*/

	for (i = 0; max > 0; ++i)//count number of digits
		max /= 10;

	radixSort(sequence, (sequenceRange + 1), i);
	/*
	for (i = 0; i < sequenceRange;++i) {
		cout << sequence[i] << " ";
	}
	cout << endl;

	return 0;*/

	unsigned long int weightedSum = 0;
	for (i = 1; i < sequenceRange + 1; ++i)
		weightedSum += sequence[i] * i;

	delete[] sequence;

	return weightedSum % modulo;
	//return fmod(weightedSum, modulo);
}

int main() {
	int noOfCases;
	cin >> noOfCases;
	
	for (int i = 0; i < noOfCases; ++i) {
		unsigned long int sequenceRange, modulo;
		cin >> sequenceRange >> modulo;
		cout << fibonacciSequence(sequenceRange, modulo) << endl;
	}

	return 0;
}