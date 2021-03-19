#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

class Data {
    vector<vector<float>> data;
    string file;
    bool forward = true;
public:
    Data();

    void setData(vector<vector<float>> d);
    void setDirection(bool d);


    void validate();
    float search(); //returns highest accuracy

};