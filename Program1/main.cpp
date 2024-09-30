#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
    std::ifstream file("D:/Programmin/C++/Practise-Comput-Physics/XMCD#0000..txt");
    if (!file.is_open()){
        cout<<"File isn't initialised"<<endl;
    }
    int N;
    cout<<"Enter Number of spins"<<endl;
    cin>>N;
    for (int i = 0; i < N; i++){
        for (int i = 0; i < N; i++){
            cout<<"bruh"<<endl;
        }
    }
}