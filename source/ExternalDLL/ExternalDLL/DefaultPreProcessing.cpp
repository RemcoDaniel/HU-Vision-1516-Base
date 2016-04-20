/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "DefaultPreProcessing.h"
#include "ImageIO.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "Dragons.h"

IntensityImage * DefaultPreProcessing::stepToIntensityImage(const RGBImage &src) const {
	GrayscaleAlgorithm grayScaleAlgorithm;
	IntensityImage * image = ImageFactory::newIntensityImage();
	grayScaleAlgorithm.doAlgorithm(src, *image);
	return image;
}

IntensityImage * DefaultPreProcessing::stepScaleImage(const IntensityImage &src) const {
	cv::Mat matrix;
	Dragons::makeIntensityMatrix(src, matrix);
	int size = 200 * 200;
	int matrixSize = matrix.cols * matrix.rows;
	if (size < matrixSize){
		double scale = 1.0 / sqrt(matrixSize / size);
		cv::resize(matrix, matrix, cv::Size(), scale, scale, cv::INTER_LINEAR);
	}
	IntensityImage * image = ImageFactory::newIntensityImage();
	Dragons::makeIntensityImage(matrix, *image);
	return image;
}

IntensityImage * DefaultPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	cv::Mat intensityMatrix;
	Dragons::makeIntensityMatrix(image, intensityMatrix);
	//cv::medianBlur(*image, *image, 3);
	//cv::GaussianBlur(*image, *image, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
	cv::Mat matrix = (cv::Mat_<float>(9, 9) << 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, -4, -4, -4, 1, 1, 1, 1, 1, 1, -4, -4, -4, 1, 1, 1, 1, 1, 1, -4, -4, -4, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0);
	cv::Mat OverParkOverPale;
	filter2D(intensityMatrix, OverParkOverPale, CV_8U, matrix, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
	IntensityImage * intensityImage = ImageFactory::newIntensityImage();
	Dragons::makeIntensityImage(OverParkOverPale, *intensityImage);
	return intensityImage;
}

IntensityImage * DefaultPreProcessing::stepThresholding(const IntensityImage &image) const {
	cv::Mat matrix;
	Dragons::makeIntensityMatrix(image, matrix);
	cv::threshold(matrix, matrix, 220, 255, cv::THRESH_BINARY_INV);
	IntensityImage * intensityImage = ImageFactory::newIntensityImage();
	Dragons::makeIntensityImage(matrix, *intensityImage);
	return intensityImage;
}