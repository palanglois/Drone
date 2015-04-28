#include "RecognitionLearning.h"

using namespace cv;

//Take number picture every ms seconds
//Pictures are stored in address with a reference file called filename
int takePicture(int number, double ms,string address,string filename)
{
  //Open/Create the bg file
  std::ofstream file("images/"+filename,std::ios::out);
  if(!file)
    return -1;
  //VideoCapture cap(1);
  VideoCapture cap(CV_CAP_ANY);
  //cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
  //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
  double fps = 15;
  if (!cap.isOpened())
    return -1;
  Mat img;
  
  namedWindow("video capture", CV_WINDOW_AUTOSIZE);
  for(int i=0;i<number;i++)
  {
    //Requires the good framerate to create a good interval
    for(int j=0;j<10;j++) //10 is to be changed when the good webcam is here
    {
      cap >> img;
    }
    cap >> img;
    sleep(1.0);
    if (!img.data)
	continue;
    imwrite(address+"im"+to_string(i)+".jpg",img); // Save current pict
    file << address+"im"+to_string(i)+".jpg" << std::endl; // Add the pict to the bg.txt
  }
  file.close();
}