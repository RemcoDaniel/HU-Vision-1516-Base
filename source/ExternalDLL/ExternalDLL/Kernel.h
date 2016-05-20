#include <iostream>

class Kernel {
public:
	// mode kan zijn: Laplacian, Prewitt, Sobel, Gaussian
	Kernel(int width, int height, int mode);	// mode moet geen int zijn, maar enum
	~Kernel();
	void fillKernel(int width, int height, int mode);
	void fillNormalKernel(int width, int height);
	void fillLaplacianKernel(int width, int height);
	void fillPrewittKernel(int width, int height);
	void fillSobelKernel(int width, int height);
	void fillGaussianKernel(int width, int height);

	const int getWidth() const;
	const int getHeight() const;

private:
	double data[];	// beter een std array...
	int width;
	int height;
};