#pragma once
/*! \mainpage Documentation
*	\author Antonio Nikolov -- School of Computer Science and Statistics, Trinity College Dublin
	\version 0.1
	\date 26/03/2014
\section intro_sec Why IPSO?
IPSO is a high level wrapper on top of OpenCV. I don't like the procedural nature of OpenCV
 so I thought it was a good idea to encapsulate the most common operations in OpenCV 
 into classes. IPSO favors functional style of programming. The object data is immutable (mostly) and the result of operations on the data
 are returned as a new object rather than changing the state of the current object.
* 
\section License
Just like OpenCv , IPSO is released under the BSD license. It is free for both academic and commercial use
*
* \section install_sec How to Use the Library
 Download the latest version  from the <a href="#"> download page </a>. The library has a dependency on the OpenCV libraries 
 opencv_highguiXXXd <BR>
 opencv_imgprocXXXd <BR>
 opencv_coreXXXd <BR>
 in Debug mode and <BR>
 opencv_highguiXXX <BR>
 opencv_imgprocXXX <BR>
 opencv_coreXXX <BR>
 in Release mode. XXX is the version of OpenCV you are using. <BR> 
  Link against those 3 libraries <BR>
  Make reference in the include path of the project to the OpenCV include directory <BR>
  Make reference in the include path of the project to the ISPO include directory <BR>
  If you are linking dynamically then copy over the dynamic version of the 3 libraries to
		the working directory of the project. <BR>

\section Example Use
The following code loads two color images, compares their histograms and displays the histograms on the screen.
\code
#include <Ipso/ColorImage.h>
#include <Ipso/utility.h>
#include <iostream>
using namespace std;
using namespace ipso;
int _tmain(int argc, _TCHAR* argv[])
{
	OneDHistogram hist_template(ColorImage("template_hand.jpg").toGray().computeHistogram(50).normalize());
	OneDHistogram hist_test(ColorImage("test_hand.jpg").toGray().computeHistogram(50).normalize());
	double compare_result = hist_template.compareHist(hist_template, CV_COMP_CHISQR);
	showScaled(hist_template, 1.0, "test_histogramcompare:hist_template");
	showScaled(hist_test, 1.0, "test_histogramcompare:hist_test");
	cvWaitKey();
	return 0;
}

\endcode
*/


#ifdef IPSO_EXPORTS
#define IPSO_API __declspec(dllexport)
#else
#define IPSO_API __declspec(dllimport)
#endif

#include <cassert>

//! All classes in IPSO are part of the ipso:: namespace
namespace ipso {
	class IPSO_API GrayImage;
	class IPSO_API BinaryImage;
	class IPSO_API ColorImage;
	class IPSO_API OneDHistogram;
	class IPSO_API Contours;
}
typedef int CV_CONST;
