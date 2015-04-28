#ifndef RECOGNITIONLEARNING_H
#define RECOGNITIONLEARNING_H

#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>
#include "tools.h"

int takePicture(int number, double ms, std::string address, std::string filename);

#endif
