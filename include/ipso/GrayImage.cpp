#include "GrayImage.h"

namespace ipso{
	using namespace cv;
	using std::vector;
	GrayImage::GrayImage(const std::string &location)
	{
		image = imread(location, CV_LOAD_IMAGE_GRAYSCALE);
	}
	GrayImage::GrayImage(const Mat &gray)
	{
		assert(gray.channels() == 1 && "Cannot initialize GrayImage with a Mat containing more than one channel.");
		gray.copyTo(image);
	}
	GrayImage::~GrayImage()
	{
	}

	OneDHistogram GrayImage::computeHistogram(int numBins)
	{
		Mat rawHist;
		float range[] = { 0.f, 256.f };
		const float* ranges[] = { range };
		const int *channels = { 0 };
		calcHist(&image, 1, 0, Mat(), rawHist, 1, &numBins, ranges, true, false);
		OneDHistogram result(rawHist, numBins);
		return result;
	}
	BinaryImage GrayImage::binaryThreshold(int threshVal) const
	{
		Mat binary;
		threshold(image, binary, threshVal, 255, THRESH_BINARY);
		BinaryImage result(binary, threshVal);
		return result;
	}
	BinaryImage GrayImage::otsuThreshold() const
	{
		Mat binary;
		int threshVal = threshold(image, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);
		BinaryImage result(binary, threshVal);
		return result;
	}
	BinaryImage GrayImage::adaptiveThreshold(int blockSize, double C,
		CV_CONST adaptiveMethod, CV_CONST thresholdType) const
	{
		Mat binary;
		cv::adaptiveThreshold(image, binary, 255, adaptiveMethod, thresholdType, blockSize, C);
		BinaryImage result(binary);
		return result;
	}
}