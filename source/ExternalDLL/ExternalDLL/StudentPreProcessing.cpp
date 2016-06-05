#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include <math.h>

/* KNOWN COMBO's
Kern(5,5,PREWITT,1) result * 0.4 : female-2,
Kern(5,5,PREWITT,1) result * 0.4 : male-1(shirt = face though)
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
	IntensityImageStudent nImage(image.getWidth(), image.getHeight());
	Kernel kern(5, 5,PREWITT, 1);
	KernelAppliance(nImage, image, kern);
	return new IntensityImageStudent(nImage);
}

IntensityImage & StudentPreProcessing::KernelAppliance(IntensityImage& newImage, const IntensityImage & oldImage, const Kernel & kern) const{
	int kernVerOff = kern.getHeight() / 2;
	int kernHorOff = kern.getWidth() / 2;
	//std::cout << "Kernel height divided: " << kernVerOff << '\n';

	for (int y = 0; y < oldImage.getHeight() - kernVerOff; y++){
		while (y < kernVerOff){
			y++;
		}
		for (int x = 0; x < oldImage.getWidth() - kernHorOff; x++){
			while (x < kernHorOff){
				x++;
			}
			//Actual appliance
			double result = 0;

			result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, true, true);
			result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, true, false);
			result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, false, true);
			result += kernelSum(kernHorOff, kernHorOff, oldImage, kern, x, y, false, false);

			if (kern.getDivFactor() != 0){
				result = result / kern.getDivFactor();
			}

			int nPixel = (int)round(result);
			//std::cout << "nPixel Value: " << nPixel << '\n';
			if (nPixel < 0){ nPixel = 0; }
			//nPixel = nPixel * 4; Addition to help threshold
			if (nPixel > 255){ nPixel = 255; }
			newImage.setPixel(x, y, nPixel);
			//end Actual appliance
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
	if (result < 0){ result = 0; }
	result = result * 0.4; //Change this to change the output of each kernel
	return result;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}