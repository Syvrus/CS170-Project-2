#include "data.h"

//Constructor
Data::Data(){

}

//Setter
void Data::setData(vector<vector<float>> d){
    data = d;
}

void Data::setDirection(bool d){
    forward = d;
}

float Data::search(){
    float most = 0;
    //When forward selection is chosen
    if(forward){
        vector<int> features, best;
        for(unsigned i = 1; i < data[0].size(); i++){
            float accuracy = 0;
            int highest = 1;

            //cout << "On subject " << i + 1 << " of the file\n";
            cout << "On the " << i << "th level of the tree\n";
            for(unsigned j = 1; j < data[i].size(); j++){
                vector<int>::iterator it;
                it = find(features.begin(), features.end(), j);
                //Checks what feature is not added yet
                if(it == features.end()){
                    cout << "--Considering adding feature " << j << '\n';
                    /*
                    Calculate accuracy here
                    */
                    accuracy = j + 1;
                    //Keeps track of highest accuracy
                    if(accuracy > most){
                        most = accuracy;
                        highest = j;
                    }
                } else {
                    it = features.begin();
                }
            }
            
        
            cout << "On level " << i << " added feature " << highest << '\n';
            features.push_back(highest);
            most = 0;
       }
    } else { //Background elimination
        vector<int> features, best;
        //Initial set to start full
        for(unsigned i = 1; i < data[0].size(); i++){
            features.push_back(i);
        }
        for(unsigned i = 1; i < data[0].size(); i++){
            float accuracy = 0;
            int highest = 1;

            //cout << "On subject " << i + 1 << " of the file\n";
            cout << "On the " << i << "th level of the tree\n";
            for(unsigned j = 1; j < data[i].size(); j++){
                vector<int>::iterator it;
                it = find(features.begin(), features.end(), j);
                //Checks what feature is not added yet
                if(it != features.end()){
                    cout << "--Considering removal of feature " << j << '\n';
                    /*
                    Calculate accuracy here
                    */
                    accuracy = j + 1;
                    //Keeps track of highest accuracy
                    if(accuracy > most){
                        most = accuracy;
                        highest = j;
                    }
                } else {
                    it = features.begin();
                }
            }
            
        
            cout << "On level " << i << " removed feature " << highest << '\n';
            cout << *(features.begin() + (highest - 1));
            features.erase(features.begin() + (highest - 1));
            most = 0;
       }
    }
    return 0;
}