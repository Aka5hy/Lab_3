
#include <iostream>
#include <vector>
#include"SVG.h"
#include<string.h>
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <windows.h>




using namespace std;

#include"diffr.h"
void
ver(int argc, char** argv, CURL* curl) {
    bool verbose = false;

    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-verbose") {
            verbose = true;
            break;
        }
    }
    if (verbose) {

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    }
    bool oper = false;
    if (!verbose) {
        for (int i = 0; i < argc; i++)
        {
            if (bool(strstr(argv[i], "-"))) {
                oper = true;

            }
        }
        if (oper) {
            cerr << "I don't now what i need say to help, sorry.\n But uou shoud do it.\n JUST DO IT!!!";
        }
    }

};

size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    size_t data_size = item_size * item_count;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(reinterpret_cast<const char*>(items), data_size);
    return data_size;

}




Input
download(const string& address, int argc, char** argv) {
    stringstream buffer;
    CURL* curl = curl_easy_init();
    if (curl) {

        ver(argc, argv, curl);

        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << curl_easy_strerror(res);
            exit(1);
        }

    }

    return read_input(buffer, false);
}



/// //////////////////

int
main(int argc, char** argv)
{
    
	if(argc > 1 ) {

		cerr << argc << endl;
		for (int i = 0; i < argc; i++)
		{
			cerr << "argv[" << i + 1 << "]" << argv[i];
			cerr << endl;
		}
		cerr << endl << endl << endl << endl;

		return 0;
	}


	//Ввод данных
    Input input;
    if (argc > 1) {
        input = download(argv[1], argc, argv);
    }

    else {
        input = read_input(cin, true);
    }

    

	// Расчеты
	const auto bins = make_histogramm(input);
	//Вывод данных
	show_histogram_svg(bins);

	
	return 1;
}