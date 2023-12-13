#include<iostream>
#include<math.h>
#include<Eigen/Eigen> 


using namespace std;
using namespace Eigen;

int main(){
    Matrix<double,10,1>test;
    test.setZero();

    cout<<test<<endl;
}