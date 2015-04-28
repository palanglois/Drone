#include "tools.h"

using namespace cv;

// Prototype function to locate someone on the camera field using descriptor
int locatePeople(std::vector<float> descriptor)
{
  //Opening Camera
  VideoCapture cap(CV_CAP_ANY);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);    
  if (!cap.isOpened())
    return -1;
  
  Mat img;
  HOGDescriptor hog;
  hog.setSVMDetector(descriptor);
  
  namedWindow("video capture", CV_WINDOW_AUTOSIZE);
  while (true)
  {
    cap >> img;
    if (!img.data)
	continue;
    vector<Rect> found, found_filtered;
    hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);

    size_t i, j;
    for (i=0; i<found.size(); i++)
    {
      Rect r = found[i];
      for (j=0; j<found.size(); j++)
	if (j!=i && (r & found[j])==r)
	  break;
      if (j==found.size())
	found_filtered.push_back(r);
    }
    for (i=0; i<found_filtered.size(); i++)
    {
      Rect r = found_filtered[i];
      r.x += cvRound(r.width*0.1);
      r.width = cvRound(r.width*0.8);
      r.y += cvRound(r.height*0.06);
      r.height = cvRound(r.height*0.9);
      rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
    }
    flip(img,img,-1); //Remove this line if the picture is reversed
    imshow("video capture", img);
    if (waitKey(20) >= 0)
      break;
  }
}



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