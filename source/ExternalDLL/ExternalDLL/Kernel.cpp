#include "Kernel.h"

Kernel::Kernel(int width, int height, int mode, int strength) {		// strength kan van -10 tot 10 lopen
	// eerst checken of beiden wel oneven (anders geen middelste pixel :( )
	if (width % 2 && height % 2) {	// misschien sneller als eerst size berekenen en dan checken?
		fillKernel(width, height, mode, strength);
	}
}

void Kernel::fillKernel(int witdth, int height, int mode, int strength) {
	switch (mode) {
		case LAPLACIAN:	fillLaplacianKernel(width, height, strength);	break;		// Laplacian
		case PREWITT:	fillPrewittKernel(width, height, strength);		break;		// Prewitt
		case SOBEL:		fillSobelKernel(width, height, strength);		break;		// Sobel
		case GAUSSIAN:	fillGaussianKernel(width, height, strength);	break;		// Gaussian
		default:		fillNormalKernel(width, height, strength);		break;		// Normal
	}
}

void Kernel::fillNormalKernel(int width, int height, int strength) {	// deze vult de kernel met waarden
	int size = width * height;
	data = new int[size];

	for (int i = 0; i < size; ++i){
		data[i] = strength;
	}
}

void fillLaplacianKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];


}

void fillPrewittKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];

	//-1-1-1
	// 0 0 0
	// 1 1 1

	int middenrij = height % 2;
	int beginMidden = width * middenrij;
	int eindMidden = beginMidden + width;	
	
	for (int i = 0; i < size; ++i) {
		if (i < beginMidden){
			data[i] = -strength;
		}
		else if (i >= eindMidden) {
			data[i] = strength;
		}
		else data[i] = 0;
	}
	
	// er is er ook nog 1 voor:
	//-1 0 1
	//-1 0 1
	//-1 0 1
}

void fillSobelKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];

	//-1 -2 -1
	// 0  0  0
	// 1  2  1


}

/*
void fillGaussianKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];
	for (int i = 0; i < size; ++i){
		data[i] = <int>((1 / (2 * PI * strength ^ 2)) * E ^ ((width ^ 2 + height ^ 2) / (2 * strength ^ 2)); // strength is hier dus de deviation!! let op!: ff kijken of strength dan wel de juiste waarde heeft!  strength wil je hier eigenlijk tussen de 0.0 en de 1.0
	}
} */

int* getKernel() {
	return data;
}

void printKernel(){
	std::cout << "boe" << std::endl;

	
}