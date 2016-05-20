#include <iostream>

#define PI 3.14159265359
#define E  2.718281828459

class Kernel {
public:
	// mode kan zijn: Laplacian, Prewitt, Sobel, Gaussian
	Kernel(int width, int height, int mode, int strength);	// mode moet geen int zijn, maar enum
	~Kernel();
	void fillKernel(int width, int height, int mode, int strength);
	void fillNormalKernel(int width, int height, int strength);
	void fillLaplacianKernel(int width, int height, int strength);
	void fillPrewittKernel(int width, int height, int strength);
	void fillSobelKernel(int width, int height, int strength);
	void fillGaussianKernel(int width, int height, int strength);

	const int getWidth() const;
	const int getHeight() const;

private:
	double data[];	// beter een std array...
	int width;
	int height;
};