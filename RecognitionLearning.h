#ifndef RECOGNITIONLEARNING_H
#define RECOGNITIONLEARNING_H

#include <fstream>
#include <string>
#include <unistd.h>
#include "tools.h"

int takePicture(int number, double ms, std::string address, std::string filename);
int takeBackground(int number, double ms);
int takeForeground(int number, double ms);

#endif
