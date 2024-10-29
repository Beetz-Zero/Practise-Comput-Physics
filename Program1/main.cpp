#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <complex> 

using namespace std;

struct spin{
    double x;
    double y;
    double mx;
    double my;
    double junk;
};

int counter(string x){
    ifstream InputFile(x);
    string  line;
    int N = 0;
    for (int i = 0; getline(InputFile, line); i++)
    {
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
    string line;
    
    spin spin[1100];

    for(int i = 0;getline(InputFile,line);i++){
        istringstream file(line);

        file >> spin[i].x;
        file >> spin[i].y;
        file >> spin[i].mx;
        file >> spin[i].my;
        file >> spin[i].junk; 
    }
//------------------------------------------------------------------------------------------------------------//
    double is_eneregy = 0;
    double sinses = 0;
    for (double qx = -5; qx < 5; qx += 0.1){
        for (double qy = -5; qy < 5.1; qy += 0.1){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){

                double value = (qx *(spin[i].x - spin[j].x) + qy * (spin[i].y - spin[j].y));

                is_eneregy += (spin[i].mx * spin[j].mx + spin[i].my * spin[j].my) * (cos(value*(180/3.14)));

                sinses = sin(value*(180.0/3.14));
                }
            }
            is_eneregy = is_eneregy * (1/N);
            OutputFile << is_eneregy<<" "<< qx << " " << qy << " "<< sinses << endl;
        }
    }

    InputFile.close();
}