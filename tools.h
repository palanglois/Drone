#ifndef TOOLS_H
#define TOOLS_H

#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>
#include "WatershedSegmenter.h"

int locatePeople(std::vector<float> descriptor = cv::HOGDescriptor::getDefaultPeopleDetector());
void segmentBody(cv::Mat image);
int takePicture(int number, double fps);
std::string to_string(int n);

#endif