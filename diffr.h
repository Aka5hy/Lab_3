#pragma once
#include <iostream>
#include <vector>
using namespace std;

void 
find_min_max(vector<double> numbers, double& min, double& max);
vector<double> 
input_numbers(size_t count);
void
find_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line, double& ratio);
void
show_bin(vector<size_t> bins, const size_t max_bin, const double ratio);
size_t
find_max(vector<size_t> bins);
size_t
Picture_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line);