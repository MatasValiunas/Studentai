#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include <deque>
#include <list>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

using std::cout;
using std::endl;
using std::string;

extern "C"
DLL_API

#endif