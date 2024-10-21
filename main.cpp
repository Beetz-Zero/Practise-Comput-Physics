#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <complex> 

using namespace std;

struct spin{
    float x;
    float y;
    float mx;
    float my;
    float junk;
};

int counter(string x){
    ifstream InputFile(x);
    string  line;
    int N = 0;

    while(getline(InputFile, line)){
        N++;
    }

    return N;
}

int main(){

// File initilization

    ifstream InputFile("XMCD#0000..txt");   
    ofstream OutputFile("Out.txt"); 

//------------------------------------------------------------------------------------------------------------//
// Count number of lines

    double N = counter("XMCD#0000..txt");

    cout << "Число строк в файле: " << N << endl;  

//------------------------------------------------------------------------------------------------------------//
// Filling spin of data

    int vect_r;

    string line;
    
    spin spin[1100];

    int k = 0; // Interior counter for each parametr of spin
    for(int i = 0;getline(InputFile,line);i++){
        istringstream file(line);

        file >> spin[i].x;
        file >> spin[i].y;
        file >> spin[i].mx;
        file >> spin[i].my;
        file >> spin[i].junk; 
    }
    /*int n = k;

    for(k = 0; k < n; k++){     
        cout << spin[k].x << '\t' << spin[k].y << '\t' << spin[k].mx << '\t' << spin[k].my << endl;
    }*/

//------------------------------------------------------------------------------------------------------------//
    double is_eneregy = 0;
    for (float qx = -5; qx < 6; qx++){
        for (float qy = -5; qy < 6; qy++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){

                double value = (qx *(spin[i].x - spin[j].x) + qy * (spin[i].y - spin[j].y));

                is_eneregy += (spin[i].mx * spin[j].mx + spin[i].my * spin[j].my) * (cos(value*(180/3.14)));
                }
            }
            is_eneregy = is_eneregy * (1/N);
            OutputFile << is_eneregy<<" "<< qx << " " << qy << endl;
        }
    }

    InputFile.close();
}