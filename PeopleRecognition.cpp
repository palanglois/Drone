#include "PeopleRecognition.h"

using namespace cv;

// Prototype function to locate someone on the camera field using descriptor
int locatePeople(std::vector<float> descriptor)
{
  //Opening Camera
  VideoCapture cap(CV_CAP_ANY);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 800/*200*/);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 600/*150*/);    
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
    //flip(img,img,-1); //Remove this line if the picture is reversed
    imshow("video capture", img);
    if (waitKey(20) >= 0)
      break;
  }
}