#include "tools.h"

using namespace cv;





void segmentBody(cv::Mat image)
{
  cv::Mat blank(image.size(),CV_8U,cv::Scalar(0xFF));
  cv::Mat dest;
  imshow("originalimage", image);

  // Create markers image
  cv::Mat markers(image.size(),CV_8U,cv::Scalar(0));
  //Rect(topleftcornerX, topleftcornerY, width, height);
  //top rectangle
  markers(Rect(0,0,image.cols, 5)) = Scalar::all(1);
  //bottom rectangle
  markers(Rect(0,image.rows-5,image.cols, 5)) = Scalar::all(1);
  //left rectangle
  markers(Rect(0,0,5,image.rows)) = Scalar::all(1);
  //right rectangle
  markers(Rect(image.cols-5,0,5,image.rows)) = Scalar::all(1);
  //centre rectangle
  int centreW = image.cols/4;
  int centreH = image.rows/4;
  markers(Rect((image.cols/2)+20,(image.rows/2)-(centreH/2), centreW-20, centreH)) = Scalar::all(2);
  markers.convertTo(markers,CV_BGR2GRAY);
  imshow("markers", markers);

  //Create watershed segmentation object
  WatershedSegmenter segmenter;
  segmenter.setMarkers(markers);
  cv::Mat wshedMask = segmenter.process(image);
  cv::Mat mask;
  convertScaleAbs(wshedMask, mask, 1, 0);
  double thresh = threshold(mask, mask, 1, 255, THRESH_BINARY);
  bitwise_and(image, image, dest, mask);
  dest.convertTo(dest,CV_8U);
  imshow("final_result", dest);
}

std::string to_string(int n)
{
  std::ostringstream stm;
  stm << n;
  return stm.str();
}