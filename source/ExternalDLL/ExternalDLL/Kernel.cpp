#include "Kernel.h"

Kernel::Kernel(int width, int height, int mode, int strength) {
	this->width = width;
	this->height = height;
	size = width * height;

	if (width % 2 && height % 2) {	// checken of er een middelste waarde is
		fillKernel(mode, strength);
	}
	else{
		// printen dat verkeerde kernel en stoppen
		// kernel weer deleten!

		// of:
		// printen dat kernel onjuiste waarde en dat kernel 1 groter gemaakt in x en/of y richting
		// this->width++;
		// this->height++;
		// size = this->width * this->height;
		// dan alsnog kernel gaan vullen
	}
}

Kernel::~Kernel(){
	delete[] data;
}

void Kernel::fillKernel(int mode, int strength) {
	data = new int[size];
	switch (mode) {
		case LAPLACIAN:	fillLaplacianKernel(strength);	break;
		case PREWITT:	fillPrewittKernel(strength);	break;
		case SOBEL:		fillSobelKernel(strength);		break;
		case GAUSSIAN:	fillGaussianKernel(strength);	break;
		default:		fillNormalKernel(strength);		break;
	}
	printKernel();
}

void Kernel::fillNormalKernel(int strength) {
	for (int i = 0; i < size; ++i){
		data[i] = strength;
	}
}

void Kernel::fillLaplacianKernel(int strength){
	// blablabla
}

void Kernel::fillPrewittKernel(int strength){	// horizontaal!
	int middenrij = height / 2;
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
}

void Kernel::fillSobelKernel(int strength){	// horizontaal!
	/*
	-1 -2 -1
	 0  0  0
	 1  2  1

	 we nemen de width en dan kijken we hoe groot deze is.
	 de rij rond de middelste rij geven we iets meer gewicht mee. (zie hierboven)
	 bij 3 maken we de middelste waarde 2, dus 121
	 bij 5 maken we de middelste waarde 3, dus 12321
	 bij 7 maken we de middelste waarde 4, dus 1234321
	 dus als de kernel groter is dan 3x3 krijg je zoiets:
	 -1 -1 -1 -1 -1
	 -1 -2 -3 -2 -1	(1e element is voorMiddenRij)
	  0  0  0  0  0	(1e element is beginMidden)
	  1  2  3  2  1	(1e element is eindMidden)
	  1  1  1  1  1	(1e element is eindNaMiddenRij) */

	int middenrij = height / 2;
	int beginMidden = width * middenrij;
	int voorMiddenRij = beginMidden - width;
	int eindMidden = beginMidden + width;
	int eindNaMiddenRij = eindMidden + width;

	int tPos = 0;
	int tNeg = 0;
	for (int i = 0; i < size; ++i) {
		if (i < voorMiddenRij) {
			data[i] = -1;
		}
		else if (i < beginMidden) {
			if (i < (voorMiddenRij + ((width / 2) + 1))){
				tNeg--;
			}
			else tNeg++;
			data[i] = tNeg;
		}
		else if (i < eindMidden) {
			data[i] = 0;
		}
		else if (i < eindNaMiddenRij) {
			if (i < (eindMidden + ((width / 2) + 1))){
				tPos++;
			}
			else tPos--;
			data[i] = tPos;
		}
		else data[i] = 1;
	}
}


void Kernel::fillGaussianKernel(int strength){
	for (int i = 0; i < size; ++i){
		//data[i] = <int>((1 / (2 * PI * strength ^ 2)) * E ^ ((width ^ 2 + height ^ 2) / (2 * strength ^ 2));
		// strength is hier dus de deviation!! let op!: ff kijken of strength dan wel de juiste waarde heeft!  
		// strength wil je hier eigenlijk tussen de 0.0 en de 1.0  (gewoon omlaag trekken???)
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

const int Kernel::getValue(int val) const{
	return data[val];
}

const int Kernel::getDivFactor() const{
	int total = 0;
	int size = getWidth() * getHeight();
	for (int i = 0; i < size; i++){
		total += data[i];
	}
	return total;
}

void Kernel::printKernel(){
	for (int i = 0; i < size; i += width) {
		for (int e = 0; e < width; ++e) {
			std::cout << data[i + e] << " ";
		}
		std::cout << std::endl;
	}
}