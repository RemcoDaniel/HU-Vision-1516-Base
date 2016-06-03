#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <math.h>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	// NOTE: ALLES HIER IS NOG GEWOON GEJAT :P :P :P

	GrayscaleAlgorithm grayScaleAlgorithm;
	IntensityImage * intensityImage = ImageFactory::newIntensityImage();
	grayScaleAlgorithm.doAlgorithm(image, *intensityImage);




	return intensityImage;
}

//IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	//return nullptr; // NOTE: ALLES HIER IS NOG GEWOON GEJAT :P :P :P


//}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {

}
//Returns new Intensity image with edges
IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// maken van een kernel --> aparte methode of klasse ervoor
	// nieuwe afbeelding maken
	// kernel over oude gooien (zonder te wijzigen)

	IntensityImageStudent nImage(image.getWidth(), image.getHeight());
	Kernel kern(3,3,1,1);
	KernelAppliance(nImage, image, kern);
	return new IntensityImageStudent(nImage);
}

IntensityImage & StudentPreProcessing::KernelAppliance(IntensityImage& newImage, const IntensityImage & oldImage, Kernel kern) const{
	int kernVerOff = oldImage.getHeight() / 2;
	int kernHorOff = oldImage.getWidth() / 2;
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
					result += temp;
					value++;
				}
			}
			std::cout << "Result : " << result;
			result = round(result / kern.divFactor());
			std::cout << ", after division: " << result << '\n';
			newImage.setPixel(x, y, result);
			//end Actual appliance
		}
	}
	return newImage;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}