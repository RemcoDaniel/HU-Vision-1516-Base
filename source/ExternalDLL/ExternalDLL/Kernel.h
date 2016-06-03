#include <iostream>
#ifndef KERNEL_H
#define KERNEL_H

#define PI 3.14159265359
#define E  2.718281828459
#define LAPLACIAN 1
#define PREWITT 2
#define SOBEL 3
#define GAUSSIAN 4

class Kernel {
public:
	// mode kan zijn: Laplacian, Prewitt, Sobel, Gaussian
	Kernel(int width, int height, int mode, int strength);	// mode moet geen int zijn, maar enum
	~Kernel();
	void fillKernel(int mode, int strength);
	void fillNormalKernel(int strength);
	void fillLaplacianKernel(int strength);
	void fillPrewittKernel(int strength);
	void fillSobelKernel(int strength);
	void fillGaussianKernel(int strength);

	const int getWidth() const;
	const int getHeight() const;
	const int getSize() const;
	int* getKernel();

	void printKernel();

private:
	int* data;	// beter een std array...
	int width;
	int height;
	int size;
};
#endif