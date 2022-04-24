#include <iostream>
#include <vector>
#include"diffr.h"
#include<string>
using namespace std;

void
svg_begin(double width = 400, double height = 300) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text) {
    
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

    void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black") {
        cout << "<rect x='" << x << "' y='" << y << "' " "width='" << width << "' " "height='" << height 
             << "' " "stroke='" << stroke << "' " "fill='" << fill << "' />";
    }


void
show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 30;

    bool flag ;
   
    if (find_max(bins) > 999 || bins.size() > (IMAGE_WIDTH - TEXT_LEFT * 2) / 30 ){
        flag = false;
    }
    else {
        flag = true;
    
    }

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    if (flag) {

        double ratio;
        find_ratio(find_max(bins), BIN_HEIGHT, IMAGE_HEIGHT, TEXT_BASELINE, ratio );

        
        size_t i = 0;
        for (size_t bin : bins) {

            svg_text(TEXT_LEFT + BLOCK_WIDTH * i, TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_LEFT - 1 + BLOCK_WIDTH * i, TEXT_BASELINE + 2, BLOCK_WIDTH, BIN_HEIGHT * bin * ratio, "black", "grey");

            i++;
        }
    }
    else {
        
        cout << "Error: Limit of elemets in histagram was broken";
        svg_text(TEXT_LEFT, TEXT_BASELINE, "Error: Limit of elemets in histagramm was broken!!");
    
    }

    svg_end();
}
void
show_histogram_svg_2(const vector<size_t>& bins) {



    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 30;


    size_t Heigt = Picture_ratio(find_max(bins), BIN_HEIGHT, IMAGE_HEIGHT, TEXT_BASELINE);
    svg_begin(IMAGE_WIDTH, double(Heigt));

        size_t i = 0;
        for (size_t bin : bins) {

            svg_text(TEXT_LEFT + BLOCK_WIDTH * i, TEXT_BASELINE, to_string(bin));
            svg_rect(TEXT_LEFT - 1 + BLOCK_WIDTH * i, TEXT_BASELINE + 2, BLOCK_WIDTH, BIN_HEIGHT * bin, "black", "grey");

            i++;
        }

    svg_end();




}