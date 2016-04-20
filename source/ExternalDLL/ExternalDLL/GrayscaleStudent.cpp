#include "GrayscaleStudent.h"
#include "ImageIO.h"
#include <math.h>

GrayscaleStudent::GrayscaleStudent(){}

GrayscaleStudent::~GrayscaleStudent(){}

void GrayscaleStudent::doAlgorithm(const RGBImage & in, IntensityImage & out){
	int total = in.getHeight() * in.getWidth();
	out.set(in.getWidth(), in.getHeight());
	for (int i = 0; i < total; i++){
		RGB rgb = in.getPixel(i);
		Intensity grayValue = rgbToGrayAverage(rgb);
		out.setPixel(i, grayValue);
	}
}

Intensity GrayscaleStudent::rgbToGrayAverage(RGB rgb){
	return (rgb.r + rgb.g + rgb.b) / 3;
}

Intensity GrayscaleStudent::rgbToGrayLuminosity(RGB rgb){
	return (rgb.r *0.21 + rgb.g * 0.72 + rgb.b * 0.07);
}
