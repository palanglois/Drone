#ifndef PEOPLERECOGNITION_H
#define PEOPLERECOGNITION_H

#include "tools.h"

int locatePeople(std::vector<float> descriptor = cv::HOGDescriptor::getDefaultPeopleDetector());

#endif