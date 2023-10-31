#define EIGEN_STACK_ALLOCATION_LIMIT  0
#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> 
#include<iomanip>
#define Pi acos(-1)    //定義Pi


using namespace std;
using namespace Eigen;

void TruncErr(){
    const int ReDeltaX=10;
    double DeltaX=(double)1/ReDeltaX;
    const int ReDeltaT=10;
    double DeltaT=(double)1/ReDeltaT;

    Matrix<double,ReDeltaX+1,ReDeltaT+1> NumSol;
    NumSol.setZero();

    for(int i=0;i<=ReDeltaX;i++){
        
        NumSol(i,0)=sin(Pi*i*DeltaX)+i*DeltaX+1;
    }

    for(int j=0;j<=ReDeltaT;j++){
        NumSol(0,j)=1;
        NumSol(ReDeltaT,j)=2;
    }

    for(int j=1;j<=ReDeltaT;j++){
        for(int i=1;i<=ReDeltaX-1;i++){
            NumSol(i,j)=NumSol(i,j-1)+(1*DeltaT/pow(DeltaX,2))*(NumSol(i+1,j-1)-2*NumSol(i,j-1)+NumSol(i-1,j-1));
        }
    }
    

    cout<<NumSol<<endl;
        
    
}


int main(){
    TruncErr();
}