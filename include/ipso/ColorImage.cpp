#include "ColorImage.h"

namespace ipso{
	using namespace cv;
	using std::vector;
	ColorImage::ColorImage(const string &location)
	{
		image = imread(location, CV_LOAD_IMAGE_COLOR);
	}
	ColorImage::ColorImage(const GrayImage &red, const GrayImage &green, const GrayImage &blue)
	{
		vector<Mat> temp;
		temp.push_back(blue.getData());
		temp.push_back(green.getData());
		temp.push_back(red.getData());
		merge(temp, image);
	}
	ColorImage::ColorImage(const Mat &red, const Mat &green, const Mat &blue)
	{
		vector<Mat> temp;
		temp.push_back(blue);
		temp.push_back(green);
		temp.push_back(red);
		merge(temp, image);
	}

	ColorImage::~ColorImage()
	{

	}

	GrayImage ColorImage::toGray() const{
		Mat gray;
		cvtColor(image, gray, CV_RGB2GRAY);
		GrayImage result(gray);
		return result;
	}
	GrayImage ColorImage::getBlueChannel() const
	{
		vector<Mat> bgr;
		split(image, bgr);
		return bgr[0];
	}
	GrayImage ColorImage::getGreenChannel() const
	{
		vector<Mat> bgr;
		split(image, bgr);
		return bgr[1];
	}
	GrayImage ColorImage::getRedChannel() const
	{
		vector<Mat> bgr;
		split(image, bgr);
		return bgr[2];
	}
	GrayImage ColorImage::getHueChannel() const
	{
		vector<Mat> hls;
		Mat hls_img;
		cvtColor(image, hls_img, CV_BGR2HLS);
		split(hls_img, hls);
		return hls[0];
	}

	GrayImage ColorImage::getLuminanceChannel() const
	{
		vector<Mat> hls;
		Mat hls_img;
		cvtColor(image, hls_img, CV_BGR2HLS);
		split(hls_img, hls);
		return hls[1];
	}
	GrayImage ColorImage::getSaturationChannel() const
	{
		vector<Mat> hls;
		Mat hls_img;
		cvtColor(image, hls_img, CV_BGR2HLS);
		split(hls_img, hls);
		return hls[2];
	}
	GrayImage ColorImage::getValueChannel() const
	{
		vector<Mat> hsv;
		Mat hlv_img;
		cvtColor(image, hlv_img, CV_BGR2HSV);
		split(hlv_img, hsv);
		return hsv[2];
	}
}