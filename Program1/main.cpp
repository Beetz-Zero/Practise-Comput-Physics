#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int countString(string Path);
struct spin
{
    float x;
    float y;
    float spin;
};


int main(){
    string Path;
    cout<<"Enter path to source data: ";
    cin >> Path;
    int N = countString(Path);
    ifstream file(Path);
    string line;
    spin spin1;
    spin spin2;
    
    cout << line;
    /*for (int i = 0; i < N; i++){
        for (int i = 0; i < N; i++){
            cout<<"bruh"<<endl;
        }
    }
    */
}

int countString(string Path){
    ifstream file(Path);
    int N = 0;
    if (file.is_open()) { 
    string line; 

    while (getline(file, line)) { 
      N++; 
    }
}

    file.close();
    return N;
}