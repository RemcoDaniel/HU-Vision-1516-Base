#include "Kernel.h"

Kernel::Kernel(int width, int height, int mode) {
	// eerst checken of beiden wel oneven (anders geen middelste pixel :( )
	if (width % 2 && height % 2) {	// misschien sneller als eerst size berekenen en dan checken?
		fillKernel(width, height, mode);
	}
}

void Kernel::fillKernel(int witdth, int height, int mode) {
	switch (mode) {
	case 1:		fillNormalKernel(width, height);	break;		// Normal
	case 2:		fillLaplacianKernel(width, height);	break;		// Laplacian
	case 3:		fillPrewittKernel(width, height);	break;		// Prewitt
	case 4:		fillSobelKernel(width, height);		break;		// Sobel
	case 5:		fillGaussianKernel(width, height);	break;		// Gaussian
	default:	std::cout << "value of x unknown";	break;
	}
}

void Kernel::fillNormalKernel(int width, int height) {	// deze vult de kernel met waarden
	int size = width * height;
	data = new int[size];

	double coeff = 0.04;
	for (int i = 0; i < size; ++i){
		data[i] = coeff;
	}
}

void fillLaplacianKernel(int width, int height){
	int size = width * height;
	data = new int[size];
}

void fillPrewittKernel(int width, int height){
	int size = width * height;
	data = new int[size];
}

void fillSobelKernel(int width, int height){
	int size = width * height;
	data = new int[size];
}

void fillGaussianKernel(int width, int height){
	int size = width * height;
	data = new int[size];
}