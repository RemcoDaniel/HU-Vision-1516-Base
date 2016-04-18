/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include <memory>
class IntensityImageStudent : public IntensityImage {
private:
	std::unique_ptr<Intensity[]> pixelArray;

public:
	IntensityImageStudent();
	IntensityImageStudent(const IntensityImageStudent &other);
	IntensityImageStudent(const int width, const int height);

	void set(const int width, const int height);
	void set(const IntensityImageStudent &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;
};