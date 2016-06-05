/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "PreProcessing.h"
#include "RGBImageStudent.h"
#include "IntensityImageStudent.h"
#include "Kernel.h"

class StudentPreProcessing : public PreProcessing {
public:
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;
	IntensityImage * stepScaleImage(const IntensityImage &image) const;
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage & KernelAppliance(IntensityImage& newImage, const IntensityImage & oldImage, const Kernel & kern) const;
	double kernelSum(const int kernHorOff, const int kernVerOff, const IntensityImage & oldImage, const Kernel & kern, int x, int y, bool xAdd, bool yAdd) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;
};