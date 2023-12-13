#define EIGEN_STACK_ALLOCATION_LIMIT  0
#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> 
#include<iomanip>
#define Pi acos(-1)    //定義Pi

using namespace std;
using namespace Eigen;

void NormSolErr(){
    const int ReDeltaX=500;
    double DeltaX=(double)1/ReDeltaX;
    const int ReDeltaT=2500000;
    double DeltaT=(double)1/ReDeltaT;

    Matrix<double,ReDeltaX+1,1>NumSol_Old,NumSol_New,ExSol,SolErr;
    NumSol_Old.setZero();
    NumSol_New.setZero();
    ExSol.setZero();
    SolErr.setZero();

    NumSol_New(0,0)=1;
    NumSol_New(ReDeltaX,0)=2;

    for(int i=0;i<=ReDeltaX;i++){
        NumSol_Old(i,0)=sin(Pi*(i*DeltaX))+(i*DeltaX)+1;
    }
    
    double normSolErr=0;

    for(int j=1;j<=ReDeltaT;j++){

        for(int i=1;i<=ReDeltaX-1;i++){
            NumSol_New(i,0)=NumSol_Old(i,0)+(1*DeltaT/pow(DeltaX,2))*(NumSol_Old(i+1,0)-2*NumSol_Old(i,0)+NumSol_Old(i-1,0));
        }

        for(int i=0;i<=ReDeltaX;i++){
            ExSol(i,0)=expl(-1*pow(Pi,2)*j*DeltaT)*sin(Pi*(i*DeltaX))+(i*DeltaX)+1;
        }

        for(int i=0;i<=ReDeltaX;i++){
            SolErr(i,0)=abs(ExSol(i,0)-NumSol_New(i,0));
            normSolErr+=pow(SolErr(i,0),2);
        }

        for(int i=1;i<=ReDeltaX-1;i++){
            NumSol_Old(i,0)=NumSol_New(i,0);
        }
    }

    normSolErr=sqrt(normSolErr);

    cout<<normSolErr<<endl;

}



int main(){
    NormSolErr();
}