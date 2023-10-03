#include<iostream>
#include<math.h>
#include<Eigen/Eigen> 


using namespace std;

int main(){
    const int deltaX=500;
    for(int i=0;i<=deltaX;i++){  
        float XPosi=(float)i/deltaX;
        cout<<XPosi<<endl;
    }
}