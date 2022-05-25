
#include <iostream>
#include <vector>
#include"diffr.h"
#include"SVG.h"



struct Input {
	vector<double> numbers;
	size_t bin_count;
};


using namespace std;

int main()
{
	//���� ������
	const auto input = read_input(cin,true);
	// �������
	auto bins = make_histogramm(input);
	//����� ������

	cout << input.bin_count;
	show_histogram_svg(bins);


	return 1;
}