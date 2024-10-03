#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <string>

using namespace std;

int main(){
    ifstream InputFile("234.txt");    

    string  line;
    vector<float> numbers; 

    while(getline(InputFile, line)){

        istringstream frag(line);
        float number;

        while(frag >> number){
            numbers.push_back(number);
        }    
    }    
    for (float num : numbers) {
        cout << num << " ";
    }
    InputFile.close();
}   
