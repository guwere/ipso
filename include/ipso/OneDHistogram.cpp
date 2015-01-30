#include "OneDHistogram.h"

namespace ipso{
	using namespace cv;

	OneDHistogram::OneDHistogram()
	{

	}
	OneDHistogram::OneDHistogram(const Mat& rawHist, int numBins)
		:hist(rawHist), numBins(numBins)
	{
		drawingColor = Scalar(0, 0, 255);
		drawingTickness = 1;
	}

	OneDHistogram::~OneDHistogram()
	{
	}

	bool OneDHistogram::hasData() const
	{
		return hist.data != 0;
	}
	Mat OneDHistogram::draw() const
	{
		int hist_w = 512; int hist_h = 400;
		int bin_w = cvRound((double)hist_w / numBins);

		Mat result(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
		for (int i = 1; i < numBins; i++)
		{
			line(result, Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
				Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))),
				drawingColor, drawingTickness, 8, 0);

		}
		return result;
	}
	Mat OneDHistogram::getHist() const
	{
		return hist;
	}

	OneDHistogram OneDHistogram::normalize() const
	{
		Mat resultHist;
		cv::normalize(hist, resultHist, 0, 255, NORM_MINMAX, -1, Mat());
		OneDHistogram result(resultHist, numBins);
		return result;
	}
	OneDHistogram OneDHistogram::equalize() const
	{
		Mat resultHist;
		cv::equalizeHist(hist, resultHist);
		OneDHistogram result(resultHist, numBins);
		return result;
	}
	GrayImage OneDHistogram::backProject(const GrayImage& image) const
	{
		Mat resultGray;
		float range[] = { 0, 256 };
		const float* ranges = { range };
		cv::calcBackProject(&image.getData(), 1, 0, hist, resultGray, &ranges, 1, true);
		GrayImage result(resultGray);
		return result;
	}
	double OneDHistogram::compareHist(const OneDHistogram& other, CV_CONST compareMethod) const
	{
		return cv::compareHist(this->hist, other.getHist(), compareMethod);
	};
}
