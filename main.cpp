
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
	

	//Ввод данных
	const auto input = read_input(cin,true);
	// Расчеты
	const auto bins = make_histogramm(input);
	//Вывод данных
	show_histogram_svg(bins);

	
	return 1;
}