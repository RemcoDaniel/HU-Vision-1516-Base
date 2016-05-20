#include "Kernel.h"

Kernel::Kernel(int width, int height, int mode, int strength) {		// strength kan van -10 tot 10 lopen
	// eerst checken of beiden wel oneven (anders geen middelste pixel :( )
	if (width % 2 && height % 2) {	// misschien sneller als eerst size berekenen en dan checken?
		fillKernel(width, height, mode);
	}
}

void Kernel::fillKernel(int witdth, int height, int mode, int strength) {
	switch (mode) {
		case 1:		fillNormalKernel(width, height, strength);		break;		// Normal
		case 2:		fillLaplacianKernel(width, height, strength);	break;		// Laplacian
		case 3:		fillPrewittKernel(width, height, strength);		break;		// Prewitt
		case 4:		fillSobelKernel(width, height, strength);		break;		// Sobel
		case 5:		fillGaussianKernel(width, height, strength);	break;		// Gaussian
		default:	std::cout << "value of x unknown";				break;
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

}

void fillSobelKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];
}

/*
void fillGaussianKernel(int width, int height, int strength){
	int size = width * height;
	data = new int[size];
	for (int i = 0; i < size; ++i){
		data[i] = <int>((1 / (2 * PI * strength ^ 2)) * E ^ ((width ^ 2 + height ^ 2) / (2 * strength ^ 2)); // strength is hier dus de deviation!! let op!: ff kijken of strength dan wel de juiste waarde heeft!  strength wil je hier eigenlijk tussen de 0.0 en de 1.0
	}
} */