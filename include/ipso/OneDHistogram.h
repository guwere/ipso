#pragma once
#include "common.h"
#include "BasicType.h"
#include "GrayImage.h"
#include <opencv2\imgproc\imgproc.hpp>

namespace ipso{
	//! Represents a one dimensional histogram.
	class IPSO_API OneDHistogram : public BasicType
	{
	public:
		OneDHistogram();
		OneDHistogram(const cv::Mat& rawHist,int numBins);
		virtual ~OneDHistogram();
		virtual bool hasData() const;
		virtual cv::Mat draw() const;
		virtual cv::Mat getHist() const;

		OneDHistogram normalize() const;
	    OneDHistogram equalize() const;
	    GrayImage backProject(const GrayImage& image) const;
	    double compareHist(const OneDHistogram& other, CV_CONST compareMethod) const;

	   cv::Scalar drawingColor;
	   int drawingTickness;

	protected:
		int numBins;
		cv::Mat hist;
	};
}
