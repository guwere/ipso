#pragma once
#include "common.h"
#include "BasicType.h"
#include <opencv2\imgproc\imgproc.hpp>
#include <vector>

namespace ipso{
	//! Represents contours and their hierarchies
	class IPSO_API Contours : public BasicType
	{
	public:
		Contours();
		Contours(std::vector<std::vector<cv::Point> > contours, std::vector<cv::Vec4i> hierarchy, cv::Size imgSize);
		~Contours();
		virtual bool hasData() const;
		virtual cv::Mat draw() const;
    
		cv::Scalar drawingColor;
	    int drawingTickness;

	protected:
		std::vector<std::vector<cv::Point> > contours;
		std::vector<cv::Vec4i> hierarchy;
		cv::Size imgSize;

	};
}
