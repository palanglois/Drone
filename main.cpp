#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>
#include "tools.h"
#include "RecognitionLearning.h"

using namespace std;

using namespace cv;

int main(int argc, char** argv )
{
  takePicture(5,1,"images/","bg.txt");
  //locatePeople();
  return 0;
}