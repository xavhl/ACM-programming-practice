#include <iostream>
using namespace std;
/*
void countSort(unsigned long long int arr[], unsigned long long int noOfElements, unsigned long long int exp) {
	unsigned long long int* output = new unsigned long long int[noOfElements];

	unsigned long long int count[1024] = { 0 };
	unsigned long long int i;

	for (i = 0; i < noOfElements; ++i)
		++count[(arr[i] / exp) & 1023];//(arr[i] / exp) % 1024

	for (i = 1; i < 1024; ++i)
		count[i] += count[i - 1];

	for (i = noOfElements - 1; i >= 0; --i) {
		output[count[(arr[i] / exp) & 1023] - 1] = arr[i];
		--count[(arr[i] / exp) & 1023];

		if (i == 0) break;
	}

	for (i = 0; i < noOfElements; ++i)
		arr[i] = output[i];

	delete[] output;
}*/

void radixSort(unsigned long long int* arr, unsigned long long int noOfElements, unsigned long long int max) {
	unsigned long long int exp;

	unsigned long long int* output = new unsigned long long int[noOfElements];

	unsigned long long int count[1024] = { 0 };
	unsigned long long int i;

	for (exp = 0; (max >> (10 * exp)) > 0; ++exp) {/*
		for (i = 0; i < noOfElements; ++i)
			++count[(arr[i] >> (10 * exp)) - (((arr[i] >> (10 * exp)) >> 10) << 10)];//(arr[i] / exp) % 1024

		for (i = 1; i < 1024; ++i)
			count[i] += count[i - 1];

		for (i = noOfElements - 1; i >= 0; --i) {
			output[count[(arr[i] >> (10 * exp)) - (((arr[i] >> (10 * exp)) >> 10) << 10)] - 1] = arr[i];
			--count[(arr[i] >> (10 * exp)) - (((arr[i] >> (10 * exp)) >> 10) << 10)];
			//output[count[(arr[i] / exp) - (((arr[i] / exp) >> 10) << 10)] - 1] = arr[i];
			if (i == 0) break;
		}

		for (i = 0; i < noOfElements; ++i)
			arr[i] = output[i];
		*/
		for (i = 0; i < noOfElements; ++i) {
			++count[(arr[i] >> (10 * exp)) & 1023];
			//++count[(arr[i] >> (10 * exp)) & 1023];//(arr[i] / exp) % 1024
		}

		for (i = 1; i < 1024; ++i)
			count[i] += count[i - 1];

		for (i = noOfElements - 1; i >= 0; --i) {
			output[count[(arr[i] >> (10 * exp)) & 1023] - 1] = arr[i];
			--count[(arr[i] >> (10 * exp)) & 1023];
			//output[count[(arr[i] >> (10 * exp)) & 1023] - 1] = arr[i];
			//--count[(arr[i] >> (10 * exp)) & 1023];

			if (i == 0) break;
		}

		for (i = 0; i < noOfElements; ++i) {
			if (i < 1024)
				count[i] = 0;

			arr[i] = output[i];
		}
	}

	delete[] output;
	/*
	for (exp = 1; max / exp > 0; exp = exp << 10)//exp *= 1024
		countSort(arr, noOfElements, exp);*/
}

unsigned long long int fibonacciSequence(unsigned long long int sequenceRange, unsigned long long int modulo) {
	unsigned long long int* sequence = new unsigned long long int[sequenceRange + 1];
	sequence[0] = 0;//% modulo;
	sequence[1] = 1;//% modulo;

	unsigned long long int i, j, max = 0;//, pisano1 = -1, pisano2 = -1, pisanoPeriod = 0;
	for (i = 2; i < sequenceRange + 1; ++i) {
		/*if (pisano1 == pisano2 - 1) {
			if (pisano2 + 1 == i) {
				j = 3;
				pisanoPeriod = pisano1 - 1;
			}

			sequence[i] = sequence[j];
			j = (j + 1) % pisanoPeriod;
		}
		else {*/
			sequence[i] = (sequence[i - 2] + sequence[i - 1]) % modulo;

			/*if (sequence[i] == 0) pisano1 = i;
			if (sequence[i] == 1) pisano2 = i;
		}*/

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
	/*
	cout << "12345/1024 = " << 12345 / 1024 << endl;
	cout << "12345/1024*1024 = " << 12345 / 1024 * 1024 << endl << endl;
	cout << "12345>>10 = " << (12345 >> 10) << endl;
	cout << "12345>>10<<10 = " << ((12345 >> 10) << 10) << endl << endl;
	cout << "12345%1024 = " << 12345 % 1024 << endl;
	cout << "12345 - 12345>>10<<10 = " << (12345 - ((12345 >> 10) << 10)) << endl;
	cout << "12345 & (10-1) = " << (12345 & 9) << endl;
	while (1) {
		int a, b;
		cin >> a >> b;
		cout << (a & (b - 1)) << endl;
	}*/

	return 0;
}