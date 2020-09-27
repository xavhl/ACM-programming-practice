#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Image {
public:
	int noOfLayers, imageSize;
	int*** layers;

	Image(int);
	void countNodes();
	void print();
};

void Image::print() {
	/*int layerSize = imageSize;

	for (int i = 0; i < this->noOfLayers; ++i) {
		cout << endl;
		for (int j = 0; j < layerSize; ++j) {
			cout << endl;
			for (int k = 0; k < layerSize; ++k)
				cout << layers[i][j][k];
		}
		layerSize /= 2;
	}*/
	cout << layers[noOfLayers - 1][0][0] << endl;
}

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

	//for first upper layer which has different counting rule for raw pixelLayer
	/*
	layerSize /= 2;
	int** upperLayer1 = new int* [layerSize];

	for (int j = 0; j < layerSize; ++j) {
		int* upperLayerRow = new int[layerSize];

		for (int k = 0; k < layerSize; ++k) {/*
			upperLayerRow[k] = (layers[0][2 * j][2 * k] == layers[0][2 * j][2 * k + 1] &&
				layers[0][2 * j + 1][2 * k] == layers[0][2 * j + 1][2 * k + 1] &&
				layers[0][2 * j][2 * k] == layers[0][2 * j + 1][2 * k])
				? ((layers[0][2 * j][2 * k] == 0) ? 0 : 1)
				: 5;*/

				/*cout << layers[0][2 * j][2 * k] << " " << layers[0][2 * j][2 * k + 1] << endl <<
					layers[0][2 * j + 1][2 * k] << " " << layers[0][2 * j + 1][2 * k + 1] << endl;
			}

			upperLayer1[j] = upperLayerRow;
		}

		layers[1] = upperLayer1;
		*/

		//for all other upper layers

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

int main() {
	int sizeExponent;
	while (cin >> sizeExponent) {

		Image* image = new Image(sizeExponent);
		image->print();
		delete image;
	}

	return 0;
}