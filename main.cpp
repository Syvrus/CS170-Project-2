#include "data.h"

using namespace std;

int main(){
    
    string test, in;
    int a;
    Data d;
    vector<vector<float>> featureLists;
//Prompt
    cout << "Welcome to Brian Corbita's Feature Selection Algorithm\n";
    cout << "Enter the name of the test file: ";
//Enter file name
    cin >> test;
//Open file
    ifstream fin(test.c_str());
    if(fin.is_open()){
        while(getline(fin, in)){
            stringstream line(in); //takes text line
            float feature;
            vector<float> features;

            while(line >> feature) //gets each float in line
                features.push_back(feature); //puts in designated feature spots
            featureLists.push_back(features); //puts in list of features
        }
        fin.close();
    } else {//Error checking
        cout << "Error: File not found\n";
        return 0;
    }

    d.setData(featureLists);

    cout << "Type the number of algorithm desired: \n";
    cout << "1. Forward Selection\n";
    cout << "2. Backward Elimination\n";

    cin >> a;

    if(a == 1){
        d.setDirection(true);
    } else {
        d.setDirection(false);
    }

    d.search();

}