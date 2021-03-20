#include <iostream> //cout
#include <string> //string
#include <fstream> //filestream
#include <sstream> //stringstream
#include <vector> //vector
#include <cmath> //pow, sqrt
#include <algorithm> //find
#include <chrono> //keeping time

using namespace std;
using namespace std::chrono;

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