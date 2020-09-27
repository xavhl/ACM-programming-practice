#include <iostream>
using namespace std;

void radixSort(unsigned long long int* arr, unsigned long long int noOfElements, unsigned long long int max) {
	unsigned long long int* output = new unsigned long long int[noOfElements];
	unsigned long long int count[1024] = { 0 };

	unsigned long long int i, exp;

	for (exp = 0; (max >> (10 * exp)) > 0; ++exp) {//max * 2^(10*exp)
		for (i = 0; i < noOfElements; ++i)
			++count[(arr[i] >> (10 * exp)) & 1023];

		for (i = 1; i < 1024; ++i)
			count[i] += count[i - 1];

		for (i = noOfElements - 1; i >= 0; --i) {
			output[count[(arr[i] >> (10 * exp)) & 1023] - 1] = arr[i];//output[count[arr[i] * 2^(10*exp) % 1024] - 1]
			--count[(arr[i] >> (10 * exp)) & 1023];//count[arr[i] * 2^(10*exp) % 1024]

			if (i == 0) break;
		}

		for (i = 0; i < noOfElements; ++i) {
			if (i < 1024)
				count[i] = 0;

			arr[i] = output[i];
		}
	}

	delete[] output;
}

unsigned long long int fibonacciSequence(unsigned long long int sequenceRange, unsigned long long int modulo) {
	unsigned long long int* sequence = new unsigned long long int[sequenceRange + 1];
	sequence[0] = 0;
	sequence[1] = 1;

	unsigned long long int i, max = 0;
	for (i = 2; i < sequenceRange + 1; ++i) {
		sequence[i] = (sequence[i - 2] + sequence[i - 1]) % modulo;

		if (max < sequence[i])//record largest number for number of digits
			max = sequence[i];
	}

	radixSort(sequence, (sequenceRange + 1), max);

	unsigned long long int weightedSum = 0;
	for (i = 1; i < sequenceRange + 1; ++i)
		weightedSum += sequence[i] * i % modulo;

	delete[] sequence;

	return weightedSum % modulo;
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		unsigned long long int sequenceRange, modulo;
		cin >> sequenceRange >> modulo;
		cout << fibonacciSequence(sequenceRange, modulo) << endl;
	}

	return 0;
}