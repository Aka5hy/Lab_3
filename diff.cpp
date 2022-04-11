#include <iostream>
#include <vector>
using namespace std;
void find_min_max(vector<double> numbers, double& min, double& max) {
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
input_numbers(size_t count) {
	vector<double> result(count);
	for (size_t i = 0; i < count; i++) {
		cin >> result[i];
	}
	return result;
}
 void show_bin(vector<size_t> bins, size_t max_bin, const double ratio) {

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
void find_ratio(size_t max_bin, const size_t maximum_asterisks_in_bin, double& ratio) {

	if (max_bin > maximum_asterisks_in_bin)
	{
		ratio = (double)maximum_asterisks_in_bin / (double)max_bin;
	}
}
	

