#include "BinaryImage.h"
#include "utility.h"
#include <vector>

namespace ipso{
	using namespace cv;
	using std::vector;
	/*-------------constructors---------*/
	BinaryImage::BinaryImage(const Mat& img){
		assert(img.channels() == 1 && "Binary image can have only a single channel");
		assert(isBinary(img.data, img.total()) && "parameter image is not binary");
		img.copyTo(image);
		highThresh = 0;
		lowThresh = 0;
	}
	
	BinaryImage::BinaryImage(const Mat& img, int threshVal) :highThresh(threshVal)
	{
		assert(img.channels() == 1 && "Binary image can have only a single channel");
		assert(isBinary(img.data, img.total()) && "parameter image is not binary");
		img.copyTo(image);
		lowThresh = 0;

	}

	BinaryImage::~BinaryImage()
	{

	}
	/*-----------Getter/Setter methods------------*/
	int BinaryImage::getHighThreshVal()
	{
		return highThresh;
	}
	int BinaryImage::getLowThreshVal()
	{
		return lowThresh;
	}

	/*--------------Processing Methods--------------*/
	BinaryImage BinaryImage::invert() const
	{
		Mat dest;
		bitwise_not(image, dest);
		BinaryImage result(dest);
		return result;
	}
	BinaryImage BinaryImage::morphology(CV_CONST morphOp, int elemWidth, int elemHeight) const
	{
		Mat dest;
		Mat element(elemWidth, elemHeight, CV_8U, Scalar(1));
		morphologyEx(image, dest, morphOp, element);
		BinaryImage result(dest);
		return result;
	}
	BinaryImage BinaryImage::canny(uchar low, uchar high, int kernelSize)
	{
		lowThresh = low; highThresh = high;
		Mat dest;
		Canny(image, dest, low, high, kernelSize);
		BinaryImage result(dest);
		return result;
	}
	Contours BinaryImage::contours(CV_CONST retrMode, CV_CONST approxMethod) const
	{
		std::vector<std::vector<Point> > contours;
		std::vector<Vec4i> hierarchy;
		findContours(image, contours, hierarchy, retrMode, approxMethod, Point(0, 0));
		Contours result(contours, hierarchy, image.size());
		return result;
	}
}