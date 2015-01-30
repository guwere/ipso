#pragma once
#include "common.h"
#include "Image.h"
#include "GrayImage.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

namespace ipso{
	//! Represent a 3-channel RGB color image.
	class IPSO_API ColorImage : public Image
	{
	public:
		ColorImage(const std::string &location);
		ColorImage(const GrayImage &red,const GrayImage &green,const GrayImage &blue);
		ColorImage(const cv::Mat &red,const cv::Mat &green,const cv::Mat &blue);
		~ColorImage();
		GrayImage toGray() const;
		GrayImage getRedChannel() const;
		GrayImage getBlueChannel() const;
		GrayImage getGreenChannel() const;
		GrayImage getHueChannel() const;
		GrayImage getLuminanceChannel() const;
		GrayImage getSaturationChannel() const;
		GrayImage getValueChannel() const;
	};
}
