#define EIGEN_STACK_ALLOCATION_LIMIT 0 

#include<bits/stdc++.h>  
#include<math.h>
#include<Eigen/Eigen> 


using namespace std;
using namespace Eigen;

//使用和Pi-1_ver.2同樣的結構  CoeMatrix*NumSol-(B.C.)=SecondODE 

void Numerical_Solution_Abt(){
    const int deltaX=300;              //deltaX的大小請於此處更改
    Matrix<double,deltaX+1,1> NumSol;
    Matrix<long double,deltaX+1,1> SolErr;
    Matrix<double,deltaX-1,1> SecondODE,sNumSol,BC;
    Matrix<double,deltaX-1,deltaX-1> CoeMatrix;

    CoeMatrix.setZero();
    for(int i=0;i<deltaX-1;i++){
        if(i==0){
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i+1)=1*(deltaX*deltaX);
        }
        else if(i==deltaX-2){
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i-1)=1*(deltaX*deltaX);
        }
        else{
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i-1)=1*(deltaX*deltaX);
            CoeMatrix(i,i+1)=1*(deltaX*deltaX);
        }
    }
    
    SecondODE.setZero();

    BC.setZero();
    BC(0,0)=1*(deltaX*deltaX);
    BC(deltaX-2,0)=2*(deltaX*deltaX);

    SecondODE=SecondODE-BC;

    sNumSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    for(int i=0;i<=deltaX;i++){
        if(i==0){
            NumSol(i,0)=1;
        }
        else if(i==deltaX){
            NumSol(i,0)=2;
        }
        else{
            NumSol(i,0)=sNumSol(i-1,0);
        }
    }

    for(int i=0;i<=deltaX;i++){
        double XPosi=(double)i/deltaX;
        SolErr(i,0)=NumSol(i,0)-(XPosi+1);
    }
    
    long double norm_SolErr=0;
    for(int i=0;i<=deltaX;i++){
        norm_SolErr+=SolErr(i,0)*SolErr(i,0);
    }
    norm_SolErr=sqrt(norm_SolErr);
    cout<<NumSol<<endl;
    cout<<"||||||||||||"<<endl;
    cout<<norm_SolErr<<endl;

}



int main(){
    Numerical_Solution_Abt();
    
}