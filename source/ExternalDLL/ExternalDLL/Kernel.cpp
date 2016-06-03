#include "Kernel.h"

Kernel::Kernel(int w, int h, int mode, int strength) {		// strength kan van -10 tot 10 lopen
	width = w;
	height = h;
	size = width * height;

	// eerst checken of beiden wel oneven (anders geen middelste pixel :( )
	if (width % 2 && height % 2) {	// misschien sneller als eerst size berekenen en dan checken?
		fillKernel(mode, strength);
	}
}

Kernel::~Kernel(){
	delete[] data;
}

void Kernel::fillKernel(int mode, int strength) {
	data = new int[size];
	switch (mode) {
		case LAPLACIAN:	fillLaplacianKernel(strength);	break;		// Laplacian
		case PREWITT:	fillPrewittKernel(strength);	break;		// Prewitt
		case SOBEL:		fillSobelKernel(strength);		break;		// Sobel
		case GAUSSIAN:	fillGaussianKernel(strength);	break;		// Gaussian
		default:		fillNormalKernel(strength);		break;		// Normal
	}
}

void Kernel::fillNormalKernel(int strength) {	// deze vult de kernel met waarden
	int size = width * height;
	//data = new int[size];

	for (int i = 0; i < size; ++i){
		data[i] = strength;
	}
}

void Kernel::fillLaplacianKernel(int strength){
	int size = width * height;
	//data = new int[size];


}

void Kernel::fillPrewittKernel(int strength){
	int size = width * height;
	//data = new int[size];

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

void Kernel::fillSobelKernel(int strength){
	int size = width * height;
	//data = new int[size];

	//-1 -2 -1
	// 0  0  0
	// 1  2  1

	// we nemen de width en dan kijken we hoe groot deze is.
	// de rij rond de middelste rij geven we iets meer gewicht mee. (zie hierboven)
	// bij 3 maken we de middelste waarde 2, dus 121
	// bij 5 maken we de middelste waarde 3, dus 12321
	// bij 7 maken we de middelste waarde 4, dus 1234321
	// dus als de kernel groter is dan 3x3 krijg je zoiets:
	// -1 -1 -1 -1 -1
	// -1 -2 -3 -2 -1	(1e element is voorMiddenRij)
	//  0  0  0  0  0	(1e element is beginMidden)
	//  1  2  3  2  1	(1e element is eindMidden)
	//  1  1  1  1  1	(1e element is eindNaMiddenRij)

	int middenrij = height % 2;
	int beginMidden = width * middenrij;
	int voorMiddenRij = beginMidden - width;
	int eindMidden = beginMidden + width;
	int eindNaMiddenRij = eindMidden + width;

	for (int i = 0; i < size; ++i) {
		if (i < voorMiddenRij) {
			data[i] = -1;
		}
		else if (i < beginMidden) {
			// dat rare rijtje in de minus
			//
		}
		else if (i < eindMidden) {
			data[i] = 0;
		}
		else if (i < eindNaMiddenRij) {
			// dat rare rijtje in de plus
		}
		else data[i] = 1;
	}

	// ook deze kan weer andersom!!! (net als bij prewitt)

	printKernel();
}


void Kernel::fillGaussianKernel(int strength){
	for (int i = 0; i < size; ++i){
		//data[i] = <int>((1 / (2 * PI * strength ^ 2)) * E ^ ((width ^ 2 + height ^ 2) / (2 * strength ^ 2)); // strength is hier dus de deviation!! let op!: ff kijken of strength dan wel de juiste waarde heeft!  strength wil je hier eigenlijk tussen de 0.0 en de 1.0
		data[i] = 1;
	}
}

const int Kernel::getWidth() const {
	return width;
}

const int Kernel::getHeight() const {
	return height;
}

const int* Kernel::getKernel() const {
	return data;
}

void Kernel::printKernel(){
	int size = width * height;
	for (int i = 0; i < size; ++i) {
		std::cout << data[i] << " ";
		if (! (i%width)) {
			std::cout << std::endl;
		}
	}
}