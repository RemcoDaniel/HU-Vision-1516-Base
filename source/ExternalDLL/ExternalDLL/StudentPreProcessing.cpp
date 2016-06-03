#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <math.h>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}
//Returns new Intensity image with edges
IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// maken van een kernel --> aparte methode of klasse ervoor
	// nieuwe afbeelding maken
	// kernel over oude gooien (zonder te wijzigen)
	IntensityImageStudent nImage(image.getWidth(), image.getHeight());
	Kernel kern(3,3,SOBEL,1);
	KernelAppliance(nImage, image, kern);
	return new IntensityImageStudent(nImage);
}

IntensityImage & StudentPreProcessing::KernelAppliance(IntensityImage& newImage, const IntensityImage & oldImage, Kernel kern) const{
	int kernVerOff = kern.getHeight() / 2;
	int kernHorOff = kern.getWidth() / 2;
	std::cout << "Kernel height divided: " << kernVerOff << '\n';
	for (int y = 0; y < oldImage.getHeight() - kernVerOff; y++){
		while (y < kern.getHeight() / 2){
			y++;
		}
		for (int x = 0; x < oldImage.getWidth() - kernHorOff; x++){
			while (x < kern.getWidth() / 2){
				x++;
			}
			//Actual appliance
			double result = 0;
			int value = 0;
			for (int yWeight = -1 * kernVerOff; yWeight < kernVerOff; yWeight++){
				for (int xWeight = -1 * kernHorOff; xWeight < kernHorOff; xWeight++){
					double temp = kern.getValue(value) * oldImage.getPixel(x + xWeight, y + yWeight);
					std::cout << "kernel value: " << kern.getValue(value) << " old image pixelValue : " << oldImage.getPixel(x + xWeight, y + yWeight) << " temp result: " << temp << std::endl;
					result += temp;
					value++;
				}
			}
			std::cout << "Result : " << result;
			int nPixel = round(result / kern.getDivFactor());
			std::cout << ", after division: " << nPixel << '\n';
			newImage.setPixel(x, y, nPixel);
			//end Actual appliance
		}
	}
	return newImage;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}