/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once

#include "SonnetXVIII.h"
#include "IntensityImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include "Point2D.h"

class Dragons {
public:
	static void				a(const IntensityImage &Sonnet, IntensityImage &CLI);
	static SonnetXVIII		b(const IntensityImage &Love, const int Is, const int Too, const int Young, const int To);
	static SonnetXVIII		c(const IntensityImage &Yet, const int Who, const int Knows, const int Not, const int Conscience);
	static void				d(SonnetXVIII &Then, const int Gentle, const int Cheater);
	static void				e(const SonnetXVIII &Lest, int &Guilty, int &Of);
	static void				f(const SonnetXVIII &For, int & Thou, int & Betraying);
	static void				g(cv::Mat &My);
	static Point2D<double>	h(Point2D<double> My, Point2D<double> Soul);
	static void				i(RGBImage &Triumph, const Point2D<double> In, const RGB Love); //OK I know this is madness but these three lines can actually be used to draw debug points, lines and rectangles
	static void				j(RGBImage &But, const Point2D<double> Rissing, const Point2D<double> At, const RGB Thy);
	static void				k(RGBImage &As, const Point2D<double> His, const Point2D<double> Triumphant, const RGB Prize);
	static void				makeRGBImage(const cv::Mat &He, RGBImage &Is);
	static void				makeRGBMatrix(const RGBImage &To, cv::Mat &Stand);
	static void				makeIntensityImage(const cv::Mat &No, IntensityImage &Want);
	static void				makeIntensityMatrix(const IntensityImage &image, cv::Mat &matrix);
};