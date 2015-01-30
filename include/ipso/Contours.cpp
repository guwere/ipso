#include "Contours.h"

namespace ipso{
	using namespace cv;
	using std::vector;

	Contours::Contours()
	{
	}
	Contours::Contours(vector<vector<Point> > contours, vector<Vec4i> hierarchy, Size imgSize)
		:contours(contours), hierarchy(hierarchy), imgSize(imgSize)
	{
		drawingColor = Scalar(0, 0, 255);
		drawingTickness = 1;
	}

	Contours::~Contours()
	{
	}

	bool Contours::hasData() const
	{
		return contours.size() != 0;
	}
	Mat Contours::draw() const
	{
		Mat result = Mat::zeros(imgSize, CV_8UC3);
		for (int i = 0; i < contours.size(); i++)
			drawContours(result, contours, i, drawingColor, drawingTickness);
		return result;
	}

}