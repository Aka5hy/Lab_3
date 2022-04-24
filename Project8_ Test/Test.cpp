#include<iostream>
#include"../diffr.h"
#include"../SVG.h"
#include<vector>
#include<cassert>
#include<stdlib.h>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_min_max({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}
void
test_neganive(){
    double min = 0;
    double max = 0;
    find_min_max({ -1, -2, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);

}
void
test_zero() {
    double min = 0;
    double max = 0;
    find_min_max({}, min, max);
    assert(min == 0);
    assert(max == 0);

}
void
test_0ne() {
    double min = 0;
    double max = 0;
    find_min_max({0}, min, max);
    assert(min == 0);
    assert(max == 0);

}
void
test_ratio() {
    double ratio;

    find_ratio(4, 10, 100, 10, ratio);
    assert(ratio == 1);

}
void
test_ratio_2() {
    double ratio;

    find_ratio(10, 10, 100, 10, ratio);
    assert(ratio != 1);

}
void
Test_picture() {
    size_t height = Picture_ratio(11, 10, 100, 10);
    
    assert(height == 110 );
}


using namespace std;
int main()
{
    test_positive();
    test_neganive();
    test_zero();
    test_0ne();
    test_ratio();
    test_ratio_2();
    Test_picture();
    assert(Width_calculate(10) == 2);
	return 1;
}