#include <iostream>
#include <vector>
#include"diffr.h"
using namespace std;


using namespace std;
int main()
{
	//���� ������
	const size_t maximum_asterisks_in_bin = 80;

	size_t number_count;
	cerr << "enter number_count: ";
	cin >> number_count;

	cerr << "Enter numbers:\n";

	vector<double> numbers = input_numbers(number_count);

	size_t bin_count;

	cerr << "Enter bin_count: \n";
	cin >> bin_count;

	// �������

	double min;
	double max;
	find_min_max(numbers, min, max);


	double bin_size = (max - min) / bin_count;

	vector<size_t> bins(bin_count, 0);

	for (size_t i = 0; i < number_count; i++)
	{
		bool found = false;
		for (size_t j = 0; j < (bin_count - 1) && !found; j++)
		{
			auto lo = (min + j * bin_size);
			auto hi = (min + (j + 1) * bin_size);
			if ((lo <= numbers[i]) && numbers[i] < hi)
			{
				bins[j]++;
				found = true;
			}
		}
		if (!found)
		{
			bins[bin_count - 1]++;
		}
	}

	size_t max_bin = bins[0];
	for (size_t bin : bins)
	{
		if (max_bin < bin)
		{
			max_bin = bin;
		}

	}
	double ratio = 1;
	find_ratio(max_bin, maximum_asterisks_in_bin, ratio);
	

	//����� ������
	show_bin(bins, max_bin, ratio);

	return 1;
}