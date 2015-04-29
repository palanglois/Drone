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
  takeBackground(50,1);
  //locatePeople();
  return 0;
}