#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Input {
	vector<double> numbers;
	size_t bin_count;
};


size_t
find_max(vector<size_t> bins) {
	size_t max;
	if (bins.size() > 0) {
		 max = bins[0];

		for (size_t bin : bins) {
			if (max < bin) {
				max = bin;
			}
		}
	}
	else {
		exit(0);
	}
	return max;
}
void 
find_min_max(vector<double> numbers, double& min, double& max) {

		min = numbers[0];
		max = numbers[0];
		for (double number : numbers)
		{
			if (min > number)
			{
				min = number;
			}
			if (max < number)
			{
				max = number;
			}
		}
	
}
vector<double>
input_numbers(istream& in,size_t count) {
	vector<double> result(count);
	for (size_t i = 0; i < count; i++) {
		in >> result[i];
	}
	return result;
}
void show_bin(vector<size_t> bins, const double max_bin, const double ratio) {

	for (size_t i = 0; i < (max_bin * ratio); i++)
	{
		cout << "\t";
		for (size_t bin : bins)
		{
			if (i < (bin * ratio))
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
}
double
find_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line) {
	double ratio = 1;
	if (max_bin * bin_heght > Height - 2 * Red_line)
	{
		ratio = double(Height - 2 * Red_line) / ((double(bin_heght) * double(max_bin)));
	}
	return ratio;
}
	
size_t
Picture_ratio(size_t max_bin, const size_t bin_heght, const size_t Height, const size_t Red_line) {
	
	if (max_bin * bin_heght < Height - 2 * Red_line) {
	
		return Height;
	}
	else {
		return max_bin * bin_heght + 2 * Red_line;
	}
}
size_t
Width_calculate(const size_t Need) {

	size_t i = 1;
	while (Need >= pow(10,i)) {
		i++;
	}

	return i;
}

vector <size_t>
make_histogramm(struct Input a) {

	double min;
	double max;
	find_min_max(a.numbers, min, max);


	double bin_size = (max - min) / a.bin_count;

	vector<size_t> bins(a.bin_count, 0);

	for (size_t i = 0; i < a.numbers.size(); i++)
	{
		bool found = false;
		for (size_t j = 0; j < (a.bin_count - 1) && !found; j++)
		{
			auto lo = (min + j * bin_size);
			auto hi = (min + (j + 1) * bin_size);
			if ((lo <= a.numbers[i]) && a.numbers[i] < hi)
			{
				bins[j]++;
				found = true;
			}
		}
		if (!found)
		{
			bins[a.bin_count - 1]++;
		}
		
	}


	return  bins;

}
Input
read_input(istream& in, bool tr) {
	Input data;
	if (tr) {
		cerr << "Enter number count: ";
	}
	size_t number_count;
	in >> number_count;

	if (tr) {
		cerr << "Enter numbers: ";
	}
	data.numbers = input_numbers(in, number_count);
	if (tr) {
		cerr << "Enter bin_count: ";
	}
	in >> data.bin_count;

	return data;
}