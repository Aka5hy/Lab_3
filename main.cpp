
#include <iostream>
#include <vector>
#include"SVG.h"
#include<string.h>
#include <curl/curl.h>




using namespace std;

#include"diffr.h"
int
main(int argc, char** argv)
{
	if(argc > 1 ) {
		cerr << argc << endl;
		for (size_t i = 0; i < argc; i++)
		{
			cerr << "argv[" << i + 1 << "]" << argv[i];
		}
		
		return 0;
	}

	//���� ������
	const auto input = read_input(cin,true);
	// �������
	const auto bins = make_histogramm(input);
	//����� ������
	show_histogram_svg(bins);

	
	return 1;
}