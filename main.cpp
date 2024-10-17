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

//------------------------------------------------------------------------------------------------------------//
// Count number of lines

    int N = counter("XMCD#0000..txt");

    cout << "Число строк в файле: " << N << endl;  

//------------------------------------------------------------------------------------------------------------//
// Filling spin of data

    int vect_r;

    string line;
    
    spin spin[1100];

    int k = 0; // Interior counter for each parametr of spin

    while(getline(InputFile, line)){

        istringstream iss(line);

        iss >> spin[k].x;
        iss >> spin[k].y;
        iss >> spin[k].mx;
        iss >> spin[k].my;
        iss >> spin[k].junk;  
        k++;

    }
    /*int n = k;

    for(k = 0; k < n; k++){     
        cout << spin[k].x << '\t' << spin[k].y << '\t' << spin[k].mx << '\t' << spin[k].my << endl;
    }*/

//------------------------------------------------------------------------------------------------------------//

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            double value = (spin[i].x*(spin[i].x - spin[j].x) + spin[j].x * (spin[i].y - spin[j].y));

            double is_eneregy = (spin[i].mx * spin[j].mx + spin[i].my * spin[j].my) * (cos(value)*(180/3.14));

            cout << is_eneregy << endl;
        }
    }

    InputFile.close();

}