#pragma once
#include "Algorithm.h"
#include "IntensityImage.h"
#include "RGBImage.h"

class GrayscaleStudent :
	public Algorithm<RGBImage, IntensityImage>
{
public:
	GrayscaleStudent();
	~GrayscaleStudent();

	void doAlgorithm(const RGBImage &input, IntensityImage &dst);
	Intensity rgbToGrayAverage(RGB rgb);
	Intensity rgbToGrayLuminosity(RGB rgb);
};

