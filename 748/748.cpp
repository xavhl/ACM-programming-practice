#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Image {
public:
	int noOfLayers, imageSize;
	int*** layers;

	Image(int);
	~Image() { delete[] layers; }
	void countNodes();
	void flipAndUpdateAndPrint(int, int);
};

Image::Image(int sizeExponent) {
	this->noOfLayers = sizeExponent + 1;
	this->layers = new int** [noOfLayers];

	this->imageSize = pow(2, sizeExponent);
	int** pixelLayer = new int* [imageSize];

	for (int i = 0; i < imageSize; i++) {
		int* pixelRow = new int[imageSize];

		string pixelRowString;
		cin >> pixelRowString;

		for (int j = 0; j < imageSize; j++)
			pixelRow[j] = pixelRowString[j] - 48;

		pixelLayer[i] = pixelRow;
	}

	layers[0] = pixelLayer;

	countNodes();
}

void Image::countNodes() {
	if (this->imageSize == 1) {
		layers[0][0][0] = 1;
		return;
	}

	int layerSize = this->imageSize;

	for (int i = 1; i < noOfLayers; ++i) {
		layerSize /= 2;
		int** upperLayer = new int* [layerSize];

		for (int j = 0; j < layerSize; ++j) {
			int* upperLayerRow = new int[layerSize];
			//
			for (int k = 0; k < layerSize; ++k) {
				int q1 = layers[i - 1][2 * j][2 * k];
				int q2 = layers[i - 1][2 * j][2 * k + 1];
				int q3 = layers[i - 1][2 * j + 1][2 * k];
				int q4 = layers[i - 1][2 * j + 1][2 * k + 1];

				if (q1 == 0 && q2 == 0 && q3 == 0 && q4 == 0) {
					if (i == noOfLayers - 1)
						upperLayerRow[k] = 1;
					else
						upperLayerRow[k] = 0;
				}
				else if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1)
					upperLayerRow[k] = 1;
				else {
					upperLayerRow[k] = q1 + q2 + q3 + q4 + 1;

					if (q1 == 0)
						++upperLayerRow[k];
					if (q2 == 0)
						++upperLayerRow[k];
					if (q3 == 0)
						++upperLayerRow[k];
					if (q4 == 0)
						++upperLayerRow[k];
				}
			}

			upperLayer[j] = upperLayerRow;
		}

		layers[i] = upperLayer;
	}
}

void Image::flipAndUpdateAndPrint(int row, int col) {
	int r = row, c = col;
	this->layers[0][r][c] = (this->layers[0][r][c] + 1) % 2;

	if (this->imageSize == 1)
		layers[0][0][0] = 1;

	for (int i = 1; i < noOfLayers; ++i) {
		r /= 2;	c /= 2;
		int noOfNodesOriginal = layers[i][r][c], noOfNodes;

		int q1 = layers[i - 1][2 * r][2 * c];
		int q2 = layers[i - 1][2 * r][2 * c + 1];
		int q3 = layers[i - 1][2 * r + 1][2 * c];
		int q4 = layers[i - 1][2 * r + 1][2 * c + 1];

		if (q1 == 0 && q2 == 0 && q3 == 0 && q4 == 0)
			if (i == noOfLayers - 1)
				noOfNodes = 1;
			else
				noOfNodes = 0;
		else if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1)
			noOfNodes = 1;
		else {
			noOfNodes = q1 + q2 + q3 + q4 + 1;

			if (q1 == 0)
				++noOfNodes;
			if (q2 == 0)
				++noOfNodes;
			if (q3 == 0)
				++noOfNodes;
			if (q4 == 0)
				++noOfNodes;
		}

		if (noOfNodesOriginal == noOfNodes)
			break;
		else
			layers[i][r][c] = noOfNodes;
	}

	cout << layers[noOfLayers - 1][0][0] << endl;
}

int main() {
	int noOfCases;
	cin >> noOfCases;

	for (int i = 0; i < noOfCases; ++i) {
		int sizeExponent;
		cin >> sizeExponent;

		Image* image = new Image(sizeExponent);

		int noOfOperations;
		cin >> noOfOperations;

		for (int j = 0; j < noOfOperations; ++j) {
			int row, col;
			cin >> row >> col;

			image->flipAndUpdateAndPrint(row - 1, col - 1);
		}

		delete image;
	}

	return 0;
}