#include <iostream>
#include <vector>
#include"diffr.h"
#include"SVG.h"
using namespace std;


using namespace std;
int main()
{
	//Ввод данных
	const size_t maximum_asterisks_in_bin = 80;

	size_t number_count;
	cerr << "enter number_count: ";
	cin >> number_count;

	cerr << "Enter numbers:\n";

	vector<double> numbers = input_numbers(number_count);

	size_t bin_count;

	cerr << "Enter bin_count: \n";
	cin >> bin_count;

	// Расчеты

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
	
	//Вывод данных
	
	show_histogram_svg_2(bins);

	


	return 1;
}