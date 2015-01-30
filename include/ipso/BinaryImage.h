#pragma once
#include "common.h"
#include "Image.h"
#include "OneDHistogram.h"
#include "Contours.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

namespace ipso{
	//! Represents a binary image.
	class IPSO_API BinaryImage : public Image
	{
	public:
		/**
		\brief Constructor. lowThresh and highThresh initialized to 0
		\param img  expecting single channel Mat with at most two distinct values
		\throw asserts that image is single channel
		\throw asserts that image is binary
		*/
		BinaryImage(const cv::Mat& img);
		/**
		\brief Constructor lowThresh initialized to 0
		\param img  expecting single channel Mat with at most two distinct values
		\param threshVal value to be set for highTresh
		\throw asserts that image is single channel
		\throw asserts that image is binary
		*/
		BinaryImage(const cv::Mat& img, int threshVal);
		~BinaryImage();
		//do not include the virtual fns!!! Forgetful, eh?

		int getHighThreshVal();
		int getLowThreshVal();

		/**
		\brief invert the binary image
		\returns inverted image
		*/
		BinaryImage invert() const;
		/**
		\brief applies morphological operation on the binary image
		\param morphOp type of morphological operation
		\param elemWidth width of the kernel
		\param elemHeight height of the kernel
		\details Currently only supports rectangular Kernel. Refer to OpenCV manual for <a href="http://docs.opencv.org/modules/imgproc/doc/filtering.html?highlight=morphologyex#morphologyex">morphological operations.</a>				 
		*/
		BinaryImage morphology(CV_CONST morphOp,int elemWidth, int elemHeight) const;
		/**
		\brief Performs canny edge detection
		*/
		BinaryImage canny(uchar low, uchar high, int kernelSize = 3);
		Contours contours(CV_CONST retrMode=cv::RETR_LIST, CV_CONST approxMethod=cv::CHAIN_APPROX_SIMPLE) const;
	protected:
		uchar highThresh; /**<High threshold for binary operations*/
		uchar lowThresh; /**<Low threshold for binary operations*/
	};
}
