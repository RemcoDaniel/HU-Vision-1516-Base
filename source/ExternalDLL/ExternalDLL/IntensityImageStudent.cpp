#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
	IntensityImage(other.getWidth(), other.getHeight()),
	pixelArray(new Intensity[getWidth() * getHeight()])
{
	//int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	for (int i = 0; i < getWidth() * getHeight(); i++){
		pixelArray[i] = other.pixelArray[i];
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : 
	IntensityImage(width, height),
	pixelArray(new Intensity[getWidth() * getHeight()])
{}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	pixelArray.reset (new Intensity[width * height]);
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	//int throwerror = 0, e = 1 / throwerror;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	pixelArray.reset(new Intensity[getWidth() * getHeight()]);
	for (int i = 0; i < getWidth() * getHeight(); i++){
		pixelArray[i] = other.pixelArray[i];
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	pixelArray[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	pixelArray[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	return pixelArray[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return pixelArray[i];
}