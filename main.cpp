
#include <iostream>
#include <vector>
#include"SVG.h"
#include<string.h>
#include <curl/curl.h>




using namespace std;

#include"diffr.h"
int
main()
{
	

	//���� ������
	const auto input = read_input(cin,true);
	// �������
	const auto bins = make_histogramm(input);
	//����� ������
	show_histogram_svg(bins);

	
	return 1;
}