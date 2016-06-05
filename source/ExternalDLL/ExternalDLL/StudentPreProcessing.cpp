#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <math.h>
#include <time.h>

/* KNOWN COMBO's
Kern(3,3,PREWITT,2) : female-2;
*/

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

	//time calculation
	clock_t time = clock();

	IntensityImageStudent nImage(image.getWidth(), image.getHeight());
	Kernel kern(3, 3,PREWITT, 2);
	KernelAppliance(nImage, image, kern);

	time = clock() - time;
	std::cout << "The amount of time spent calculating: " << time << " milliseconds \n";
	return new IntensityImageStudent(nImage);
}

IntensityImage & StudentPreProcessing::KernelAppliance(IntensityImage& newImage, const IntensityImage & oldImage, const Kernel & kern) const{
	int kernVerOff = kern.getHeight() / 2;
	int kernHorOff = kern.getWidth() / 2;

	for (int y = 0; y < oldImage.getHeight(); y++){
		for (int x = 0; x < oldImage.getWidth(); x++){
			double result = 0;

			if (y >= kernVerOff && y < oldImage.getHeight() - kernVerOff){
				if (x >= kernHorOff && x < oldImage.getWidth() - kernHorOff){
					//Checks the kernel in all directions
					result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, true, true);
					result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, true, false);
				}
			}

			int nPixel = (int)round(result);
			if (nPixel < 0){ nPixel = 0; }
			if (nPixel > 255){ nPixel = 255; }

			newImage.setPixel(x, y, nPixel);
		}
	}
	return newImage;
}

double StudentPreProcessing::kernelSum(int kernHorOff, int kernVerOff, const IntensityImage & oldImage, const Kernel & kern, int x, int y, bool xAdd, bool yAdd) const{
	double result = 0;
	int value = 0;
	for (int yWeight = -1 * kernVerOff; yWeight <= kernVerOff; yWeight++){
		for (int xWeight = -1 * kernHorOff; xWeight <= kernHorOff; xWeight++){
			double temp = kern.getValue(value) * ((int)oldImage.getPixel((xAdd ? x + xWeight : x - xWeight), (yAdd ? y + yWeight : y - yWeight)));
			result += temp;
			value++;
		}
	}
	value = 0;
	for (int yWeight = -1 * kernVerOff; yWeight <= kernVerOff; yWeight++){
		for (int xWeight = -1 * kernHorOff; xWeight <= kernHorOff; xWeight++){
			double temp = kern.getValue(value) * ((int)oldImage.getPixel((xAdd ? x + yWeight : x - yWeight), (yAdd ? y + xWeight : y - xWeight)));
			result += temp;
			value++;
		}
	}
	if (result < 0){ result = result * -1; }
	result = result * 1; //Change this to change the output of each kernel 1 for 3x3, 0.4 for 5x5 recommended. This is solely for the Threshold.
	return result;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}