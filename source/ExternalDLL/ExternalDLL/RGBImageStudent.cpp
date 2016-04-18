#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()), pixels(new RGB[other.getWidth()*other.getHeight()]) {
	int throwError = 0, e = 1 / throwError;
	for (int index = 0; index < getWidth()*getHeight(); index++){
		pixels[index] = other.pixels[index];
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	int throwError = 0, e = 1 / throwError;
	pixels = new RGB[width*height];
}

RGBImageStudent::~RGBImageStudent() {
	int throwError = 0, e = 1 / throwError;
	delete[]pixels;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	delete[] pixels;
	this->pixels = new RGB[width*height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;
	delete[]pixels;
	this->pixels = new RGB[getWidth()*getHeight()];
	for (int i = 0; i<getWidth()*getHeight(); i++) {
		pixels[i] = other.pixels[i];
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
	pixels[y*getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
	pixels[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	return pixels[y*getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	return pixels[i];
}