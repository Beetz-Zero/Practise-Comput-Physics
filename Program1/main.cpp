#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    std::ifstream file("D:/Programmin/C++/Practise-Comput-Physics/XMCD#0000..txt");
    if (!file.is_open()){
        cout<<"File isn't initialised"<<endl;
    }
    
}