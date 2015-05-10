#include "RecognitionLearning.h"

using namespace cv;

//Take number picture every ms seconds
//Pictures are stored in address with a reference file called filename
int takePicture(int number, int skip,string address,string filename,string prefixe)
{
  //Open/Create the bg file
  std::ofstream file((address+filename).c_str(),std::ios::out);
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
    for(int j=0;j<skip;j++) //10 is to be changed when the good webcam is here
    {
      cap >> img;
    }
    cap >> img;
    //sleep(1.0);
    if (!img.data)
	continue;
    imwrite(address+"im"+prefixe+to_string(i)+".jpg",img); // Save current pict
    file << "im"+prefixe+to_string(i)+".jpg" << std::endl; // Add the pict to the bg.txt
    std::cout << "image number : " << i << std::endl;
  }
  file.close();
  return 1;
}

//Taking the foreground's pictures
int takeBackground(int number, double ms)
{
  takePicture(number,ms,"images/","bg.txt","bg");
}

//Taking the background's pictures

int takeForeground(int number, double ms)
{
  //takePicture(number,ms,"fgPict/","fg.txt");
  takePicture(number,ms,"images/","fg.txt","fg");
}