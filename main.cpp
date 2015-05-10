#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>
#include "tools.h"
#include "Initialization.h"
#include "RecognitionLearning.h"
#include "PeopleRecognition.h"

using namespace std;

using namespace cv;

int main(int argc, char** argv )
{
  //takeForeground(50,10);
  //takeBackground(15000,-1);
  CvHaarClassifierCascade *cascade;
  cascade = ( CvHaarClassifierCascade* )cvLoad( "haarcascade.xml", 0, 0, 0 );
  locatePeople();
  return 0;
}