#pragma once
#include "common.h"
#include "BasicType.h"
#include <opencv2\imgproc\imgproc.hpp>

namespace ipso{
	//! Base class for drawable image types - ColorImage, BinaryImage, GrayImage
	class IPSO_API Image : public BasicType
	{
	public:
		/**
		\brief returns the data object as a Mat.
		*/
		virtual cv::Mat getData() const;
		virtual bool hasData() const;
		virtual cv::Mat draw() const;

	protected:
		Image();
		Image::Image(const cv::Mat& img);
		virtual ~Image();
		cv::Mat image;
	};
}
