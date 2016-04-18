/*
* Copyright (c) 2016 Remco Nijkamp and Zehna van den Berg - All Rights Reserved
*/

#pragma once
#include "RGBImage.h"
class RGBImageStudent : public RGBImage {
private:
	RGB * pixels;

public:

	RGBImageStudent();
	RGBImageStudent(const RGBImageStudent &other);
	RGBImageStudent(const int width, const int height);
	~RGBImageStudent();

	void set(const int width, const int height);
	void set(const RGBImageStudent &other);

	void setPixel(int x, int y, RGB pixel);
	void setPixel(int i, RGB pixel);

	RGB getPixel(int x, int y) const;
	RGB getPixel(int i) const;
};