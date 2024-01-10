#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "book.h"
#include "rating.h"
using namespace std;
void fillUserTitleMap(const vector<Rating>& ratings, map<int, vector<string>>& userTitleMap);
#endif