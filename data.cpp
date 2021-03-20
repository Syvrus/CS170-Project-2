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

float Data::validate(vector<int> feat, int g){
    float x = 0;

    for(unsigned i = 0; i < data.size(); i++){
        vector<float> feature = data[i];
        float min = 9999; //Minimum distance will most likely be less than this
        vector<float> neighbor;//nearest neighbor

        for(unsigned j = 0; j < data.size(); j++){
            if(j != i){
                float distance = euclidean(feature, data[j], feat, g); //Gets the euclidean distance between the different 
                if(distance < min){//When something smaller than the smallest is found
                    min = distance;
                    neighbor = data[j];
                }
            }
        }
        //Correctly classified
        if(neighbor[0] == 1 && feature[0] == 1){ 
            x++;
        } else if(neighbor[0] == 2 && feature[0] == 2){ 
            x++;
        }
    }
    return x / (float)data.size(); //correct class / data size
}

void Data::search(){
    float most = 0, best = 0;
    vector<int> features, bestFeats;

    //When forward selection is chosen
    if(forward){
        for(unsigned i = 1; i < data[0].size(); i++){
            float accuracy = 0;
            int highest = 1;

            //cout << "On subject " << i + 1 << " of the file\n";
            cout << "On the " << i << "th level of the tree\n";
            for(int j = 1; j < data[i].size(); j++){
                vector<int>::iterator it;
                it = find(features.begin(), features.end(), j);
                //Checks what feature is not added yet
                if(it == features.end()){
                    cout << "--Considering adding feature " << j << ": ";
                    //Add feature to check
                    features.push_back(j);
                    accuracy = validate(features, j);
                    cout << accuracy * 100 << "% Accuracy\n";
                    //accuracy = j + 1;
                    //Keeps track of highest accuracy
                    if(accuracy > most){
                        most = accuracy;
                        highest = j;
                    }
                    //Remove out for time being
                    if(features.size() > 1){
                        features.erase(features.begin() + features.size() - 1);
                    }
                } else {
                    it = features.begin();
                }
            }
            
        
            cout << "On level " << i << " added feature " << highest << " with accuracy of " << most * 100 << "%\n";
            features.push_back(highest);
            if (most > best){
                best = most;
                bestFeats = features;
            } else{
                cout << "Accuracy decrease detected, keeping prior save feature as best\n";
            }
            most = 0;
       }
    } else { //Background elimination
        //vector<int> features, best;
        //Initial set to start full
        for(unsigned i = 1; i < data[0].size(); i++){
            features.push_back(i);
        }
        for(unsigned i = 1; i < data[0].size(); i++){
            float accuracy = 0;
            int highest = 1;

            cout << "On the " << i << "th level of the tree\n";
            for(unsigned j = 1; j < data[i].size(); j++){
                vector<int>::iterator it;
                it = find(features.begin(), features.end(), j);
                //Checks what feature is not added yet
                if(it != features.end()){
                    cout << "--Considering removal of feature " << j << ": ";
                    
                    accuracy = validate(features, j);
                    cout << accuracy * 100 << "% Accuracy\n";
                    //accuracy = j + 1;
                    //Keeps track of highest accuracy
                    if(accuracy > most){
                        most = accuracy;
                        highest = j;
                    }
                } else {
                    it = features.begin();
                }
            }
            
        
            cout << "On level " << i << " removed feature " << highest << " with accuracy of " << most * 100 << "%\n";
            //cout << *(features.begin() + (highest - 1));
            if(features.size() > 1){
                features.erase(features.begin() + (highest - 1));
            } else { //When size of the set is 1 so it doesn't point to an empty space
                features.clear();
            }
            if (most > best){
                best = most;
                bestFeats = features;
            } else{
                cout << "Accuracy decrease detected, keeping prior save feature as best\n";
            }
            most = 0;
       }
    }
    cout << "Search complete. Best subset is: { ";
    for(unsigned i = 0; i < bestFeats.size() - 1; i++){
        cout << bestFeats[i] << ", ";
    }
    cout << bestFeats[bestFeats.size() - 1] << " } when an accuracy of " << best * 100 << "%\n";
}
//Based on the algorithm from geeksforgeeks
float Data::euclidean(vector<float> x, vector<float> y, vector<int> feat, int g){
    double squareSum = 0;
    for(unsigned i = 0; i < feat.size(); i++){
        squareSum += pow(x[feat[i]] - y[feat[i]], 2);
    }
    if(forward){
        squareSum += pow(x[g] - y[g], 2);
    }
    return sqrt(squareSum);
}
