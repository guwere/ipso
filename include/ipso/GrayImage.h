#pragma once
#include "common.h"
#include "Image.h"
#include "OneDHistogram.h"
#include "BinaryImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

namespace ipso{
	//! Represents a single channel image.
	class IPSO_API GrayImage : public Image
	{
	public:
		//enum ThreshType{THRESH_BINARY,THRESH_OTSU,THRESH_ADAPTIVE};
		GrayImage(const std::string &location);
		GrayImage(const cv::Mat &gray);
		~GrayImage();
		OneDHistogram computeHistogram(int numBins);
		BinaryImage binaryThreshold(int threshVal) const;
		BinaryImage otsuThreshold() const;
		BinaryImage adaptiveThreshold(int blockSize, double C, 
					CV_CONST adaptiveMethod=cv::ADAPTIVE_THRESH_MEAN_C , CV_CONST thresholdType=cv::THRESH_BINARY) const;
	};
}
