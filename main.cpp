#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

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
    for (int i = 0; getline(InputFile, line); i++)
    {
        N++;
    }
    return N;
}

int main(){
// File initilization

    ifstream InputFile("XMCD#0000_rotated_norm.txt");    
    ofstream OutputFile("Out_1.txt");
    
// Filling spin of data
    double is_eneregy = 0;
    double N = counter("XMCD#0000_rotated_norm.txt");

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

    cout << "Число строк в файле: " << N << endl; 

    double qmin = -5;
    double qmax = 5;
    double dq = 0.1;

    int stepsQ = (qmax-qmin)/dq;
    printf("stepsQ = %d\n", stepsQ);
    
    int totalSteps = stepsQ*stepsQ;
    printf("totalSteps = %d\n", totalSteps);

    // qx and qy must be turned into vector<>;

#pragma omp for
    for (int m = 0; m <= totalSteps; m++){
        double qx = qmin + (m / stepsQ) * dq;
        double qy = qmin + (m % stepsQ) * dq;

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){

                double value = (qx * (spin[i].x - spin[j].x) + qy * (spin[i].y - spin[j].y));

                is_eneregy += (spin[i].mx * spin[j].mx + spin[i].my * spin[j].my) * cos(value);     
            }
        }
        is_eneregy = is_eneregy * (1/N);
        cout << is_eneregy << ' ' << qx << ' ' << qy << endl;
    }
    InputFile.close();
    return 0;
}
    
    
