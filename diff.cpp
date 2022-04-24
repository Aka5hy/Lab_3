#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

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

	if (numbers.size() == 0) {
		exit;
	}
	else {
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
}
vector<double>
input_numbers(size_t count) {
	vector<double> result(count);
	for (size_t i = 0; i < count; i++) {
		cin >> result[i];
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
void find_ratio(size_t max_bin, const size_t maximum_in_bin, double& ratio) {

	/*if (max_bin > maximum_in_bin)
	{
		ratio = (double)maximum_aste_in_bin / (double)max_bin;
	}*/
}
	

