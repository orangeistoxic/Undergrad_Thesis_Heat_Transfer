#include<iostream>
#include<math.h>


using namespace std;

int main(){
    const int deltaX=200;
    for(int i=0;i<=deltaX;i++){  
        float XPosi=(float)i/deltaX;
        cout<<exp(XPosi)<<endl;
    }
}