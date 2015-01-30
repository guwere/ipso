#pragma once
#include <type_traits>
//#define DISABLE_SHOWSCALED
namespace ipso{
	/**
	checks if parameter array contains only either 0's or any other value for the range of T
	*/
	template<typename T>
	bool isBinary(const T* data,int len)
	{
		T val = 0;
		for (int i = 0; i < len; i++)
		{
			if(data[i] != 0)
				if(val != 0 && data[i] != val) return false;
				else val = data[i];
		}
		return true;
	}

#ifdef DISABLE_SHOWSCALED
#define showScaled (void)sizeof	
#else
	void showScaled(const cv::Mat &img, float factor, char* window_name)
	{
		cv::Mat result;
		resize(img, result, cv::Size(img.cols*factor, img.rows*factor), 0, 0, cv::INTER_CUBIC);
		cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
		imshow(window_name, result);

	}
	void showScaled(const BasicType &img, float factor, char* window_name)
	{
		cv::Mat result;
		cv::Mat curr = img.draw();
		resize(curr, result, cv::Size(curr.cols*factor, curr.rows*factor), 0, 0, cv::INTER_CUBIC);
		cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
		imshow(window_name, result);

}
#endif // DISABLE_SHOWSCALED

}