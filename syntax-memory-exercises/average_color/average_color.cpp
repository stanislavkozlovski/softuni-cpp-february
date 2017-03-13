#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>     /* atoi */
#include <sstream>      // std::stringstream
using namespace std;

template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1) {
    static const char* digits = "0123456789ABCDEF";
    std::string rc(hex_len,'0');
    for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
        rc[i] = digits[(w>>j) & 0x0f];
    return rc;
}

tuple<const long unsigned*, const long unsigned*> readRGBValues() {
    /* Read Two RGB values from STDIN, convert each value to a decimal and return a tuple of two arrays, which hold the red, green and blue values*/
    string input;
    getline(cin, input);
    char red[2] = {input[1], input[2]};
    char green[2] = {input[3], input[4]};
    char blue[2] = {input[5], input[6]};
    char* nlptr;
    const long unsigned *rgb = new long unsigned[3] {strtoul(red, &nlptr, 16), strtoul(green, &nlptr, 16), strtoul(blue, &nlptr, 16)};

    char red_2[2] = {input[9], input[10]};
    char green_2[2] = {input[11], input[12]};
    char blue_2[2] = {input[13], input[14]};
    
    const long unsigned *rgb_2 = new long unsigned[3] {strtoul(red_2, &nlptr, 16), strtoul(green_2, &nlptr, 16), strtoul(blue_2, &nlptr, 16)};
    return make_tuple(rgb, rgb_2);
}

void appendZero(string &hexValue) {
    if (hexValue.size() == 1) {
        hexValue += '0';
    }
}

string buildHexRepr(long unsigned red, long unsigned green, long unsigned blue) {
    stringstream sstream;

    sstream << hex << red;
    string redHexValue = sstream.str();
    sstream.str("");
    sstream << hex << green;
    string greenHexValue = sstream.str();
    sstream.str("");
    sstream << hex << blue;
    string blueHexValue = sstream.str();
    appendZero(redHexValue);
    appendZero(greenHexValue);
    appendZero(blueHexValue);
    // if (redHexValue.size() == 1) {
    //     redHexValue += '0';
    // }
    // if (greenHexValue.size())
    return redHexValue + greenHexValue + blueHexValue;
}

int main() {
    const long unsigned* rgb_1;
    const long unsigned* rgb_2;
    const int RGB_VALUES_LEN = 3;
    tie(rgb_1, rgb_2) = readRGBValues();
    long unsigned red_1 = rgb_1[0];
    long unsigned red_2 = rgb_2[0];
    long unsigned green_1 = rgb_1[1];
    long unsigned green_2 = rgb_2[1];
    long unsigned blue_1 = rgb_1[2];
    long unsigned blue_2 = rgb_2[2];
    
    long unsigned average_red = (red_1 + red_2) / 2;
    long unsigned average_green = (green_1 + green_2) / 2;
    long unsigned average_blue = (blue_1 + blue_2) / 2;
    delete[] rgb_1;
    delete[] rgb_2;
    string decimalValues = to_string(average_red) + to_string(average_green) + to_string(average_blue);;
    // cout << hex << average_red << endl;;
    cout << buildHexRepr(average_red, average_green, average_blue) << endl;
    return 0;
}