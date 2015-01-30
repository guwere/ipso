#pragma once
#include "common.h"
#include <opencv2\imgproc\imgproc.hpp>

namespace ipso{

	//! An interface for all entity classes (ColorImage, Contours,etc.) in IPSO.
	class IPSO_API BasicType
	{
	public:
		/** 
		\brief Checks if the underlying storing container has data. 
		*/
		virtual bool hasData() const = 0;
		/**
		\brief returns the data object as a Mat intended to be displayed.
		*/
		virtual cv::Mat draw() const = 0;
	protected:
		BasicType(){};
		~BasicType(){};
	};

}