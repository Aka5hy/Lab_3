#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct Input;

void 
find_min_max(vector<double> numbers, double& min, double& max);
vector<double> 
input_numbers(istream& in,size_t count);
double
find_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line);
void
show_bin(vector<size_t> bins, const size_t max_bin, const double ratio);
size_t
find_max(vector<size_t> bins);
size_t
Picture_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line);
size_t
Width_calculate(const size_t Need);
vector <size_t>
make_histogramm(struct Input a);
Input
read_input(istream& in, bool tr);