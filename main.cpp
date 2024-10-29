#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector> 

using namespace std;

struct spin{
    float x;
    float y;
    float mx;
    float my;
    float junk;
};  

int main(){
// File initilization

    ifstream InputFile("XMCD#0000_rotated_norm.txt");    
    ofstream OutputFile("Out_1.txt");
    
// Filling spin of data
    double is_eneregy = 0;

    string line;
    
    spin spin[1100];

    int k = 0; 

    while(getline(InputFile, line)){

        istringstream iss(line);

        iss >> spin[k].x;
        iss >> spin[k].y;
        iss >> spin[k].mx;
        iss >> spin[k].my;
        iss >> spin[k].junk;  
        k++;

    }

    cout << "Число строк в файле: " << k << endl;  

    for(double qx = -5; qx < 5.1f; qx += .1f){    
        for(double qy = -5; qy < 5.1f; qy += .1f){

            for(int i = 0; i < k; i++){
                for(int j = 0; j < k; j++){

                    float value = (qx * (spin[i].x - spin[j].x) + qy * (spin[i].y - spin[j].y));

                    is_eneregy += (spin[i].mx * spin[j].mx + spin[i].my * spin[j].my) * cos(value);     
                }
            }
            is_eneregy = is_eneregy * (1/k);
            OutputFile << is_eneregy << ' ' << qx << ' ' << qy << endl;
        }
    }
    
    InputFile.close();
    return 0;
}