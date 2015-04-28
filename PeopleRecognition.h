#ifndef PEOPLERECOGNITION_H
#define PEOPLERECOGNITION_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>

int locatePeople(std::vector<float> descriptor = cv::HOGDescriptor::getDefaultPeopleDetector());

#endif