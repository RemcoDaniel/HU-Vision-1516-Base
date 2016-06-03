#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// maken van een kernel --> aparte methode of klasse ervoor
	// nieuwe afbeelding maken
	// kernel over oude gooien (zonder te wijzigen)
	// 


	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}