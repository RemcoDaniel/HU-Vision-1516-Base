#include "StudentPreProcessing.h"
#include "GrayscaleAlgorithm.h"
#include "ImageFactory.h"
#include "HereBeDragons.h"
#include "Kernel.h"

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

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	// maken van een kernel --> aparte methode of klasse ervoor
	// nieuwe afbeelding maken
	// kernel over oude gooien (zonder te wijzigen)
	//
	IntensityImageStudent* nImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
	Kernel kern(3,3,1,1);
	//int kernVerOff = image.getHeight() / 2;
	//int kernHorOff = image.getWidth() / 2;
	//std::cout << "Kernel height divided: " << kernVerOff << '\n';
	//for (int y = 0; y < image.getHeight() - kernVerOff; y++){
	//	while (y < kern.getHeight() / 2){
	//		y++;
	//	}
	//	for (int x = 0; x < image.getWidth() - kernHorOff; x++){
	//		while (x < kern.getWidth() / 2){
	//			x++;
	//		}
	//		//Actual appliance
	//		
	//		//end Actual appliance
	//	}
	//}

	return KernelAppliance(nImage, image, kern);
}

IntensityImage & StudentPreProcessing::KernelAppliance(IntensityImage & newImage, IntensityImage & oldImage, Kernel kern){
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
			int yWeight = -1 * kernVerOff;
			int xWeight = -1 * kernHorOff;

			while (yWeight < 0){
				while ()
			}
			//end Actual appliance
		}
	}
	return newImage;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}