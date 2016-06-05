#include <iostream>
#ifndef KERNEL_H
#define KERNEL_H

#define PI			3.14159265359
#define E			2.718281828459
#define LAPLACIAN	1
#define PREWITT		2
#define SOBEL		3
#define GAUSSIAN	4

class Kernel {
public:
	//! @fn     Kernel(int width, int height, int mode, int strength)
	//! @brief  Constructor of a Kernel
	//! @param  width		The width value of the kernel (x size)
	//! @param  height		The height value of the kernel (y size)
	//! @param  mode		Which kernel has to be created
	//! @param  strength	The strength of the values in the kernel (1=default)
	Kernel(int width, int height, int mode, int strength);
	//! @fn     ~Kernel()
	//! @brief  Destructor of a Kernel
	~Kernel();
	//! @fn     void fillKernel(int mode, int strength)
	//! @brief  Switch to decide what kind of kernel had to be made
	//! @param  mode		Which kernel has to be created
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillKernel(int mode, int strength);
	//! @fn     void fillNormalKernel(int strength)
	//! @brief  Fills the kernel with 1 value
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillNormalKernel(int strength);
	//! @fn     void fillLaplacianKernel(int strength)
	//! @brief  Fills the kernel with Laplacian values
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillLaplacianKernel(int strength);
	//! @fn     void fillPrewittKernel(int strength)
	//! @brief  Fills the kernel with Prewitt values
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillPrewittKernel(int strength);
	//! @fn     void fillSobelKernel(int strength)
	//! @brief  Fills the kernel with Sobel values
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillSobelKernel(int strength);
	//! @fn     void fillGaussianKernel(int strength)
	//! @brief  Fills the kernel with Gaussian values
	//! @param  strength	The strength of the values in the kernel (1=default)
	void fillGaussianKernel(int strength);

	//! @fn     const int getWidth() const
	//! @brief  returns the width of the kernel
	//! @return int		the width value
	const int getWidth() const;
	//! @fn     const int getHeight() const
	//! @brief  returns the height of the kernel
	//! @return int		the height value
	const int getHeight() const;
	//! @fn     const int* getKernel() const
	//! @brief  returns the array with values of the kernel
	//! @return int*	Array with int values of kernel
	const int* getKernel() const;
	//! @fn     const int getValue(int val) const
	//! @brief  returns a specific value of the kernel
	//! @param  val		The number of the value which is wanted
	//! @return int		A specific value in the kernel
	const int getValue(int val) const;
	//! @fn     const int getDivFactor() const
	//! @brief  returns the division factor of the kernel
	//! @return int		The division factor of the kernel
	const int getDivFactor() const;

	//! @fn     void printKernel()
	//! @brief  prints the values of the kernel
	void printKernel();

private:
	int* data;
	int width;
	int height;
	int size;
};
#endif