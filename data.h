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
//setters
    void setData(vector<vector<float>> d);
    void setDirection(bool d);
//Calculates accuracy
    float validate(vector<int> f, int g);
//Goes through data
    void search(); 
private:
//helpers
    float euclidean(vector<float> x, vector<float> y, vector<int> f, int j);

};