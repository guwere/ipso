#include "Image.h"

namespace ipso{
	using namespace cv;
	Image::Image()
	{
	}
	Image::Image(const Mat& img)
	{
		img.copyTo(image);
	}

	Image::~Image()
	{
	}
	Mat Image::getData() const
	{
		return image;
	}
	bool Image::hasData() const
	{
		return image.data != 0; // explicit comparison supressses warning C4800
	}
	Mat Image::draw() const
	{
		return image;
	}
}