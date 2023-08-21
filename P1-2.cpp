#define EIGEN_STACK_ALLOCATION_LIMIT 0 

#include<bits/stdc++.h>  
#include<math.h>
#include<Eigen/Eigen> 


using namespace std;
using namespace Eigen;

void Theorical_TrunError_50(){
    const int deltaX=50;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){   //已知函數四階倒數為0,故Truncation Error皆為0
        TrunError(i,0)=0/(12*deltaX*deltaX);
    } 

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Numerical_TrunError_50(){
    const int deltaX=50;
    Matrix<float,deltaX+1,1> TrunError,NumericalSol,SecondODE;
    Matrix<float,deltaX+1,deltaX+1> CoeMatrix;

    CoeMatrix.setZero();
    for(int i=0;i<=deltaX;i++){
        if(i==0){
            CoeMatrix(i,i)=1;
        }
        else if(i==deltaX){
            CoeMatrix(i,i)=1;
        }
        else{
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i-1)=1*(deltaX*deltaX);
            CoeMatrix(i,i+1)=1*(deltaX*deltaX);
        }
    }

    SecondODE.setZero();

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    TrunError=NumericalSol-SecondODE;

    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Theorical_TrunError_100(){
    const int deltaX=100;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){   
        TrunError(i,0)=0/(12*deltaX*deltaX);
    } 

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Numerical_TrunError_100(){
    const int deltaX=100;
    Matrix<float,deltaX+1,1> TrunError,NumericalSol,SecondODE;
    Matrix<float,deltaX+1,deltaX+1> CoeMatrix;

    CoeMatrix.setZero();
    for(int i=0;i<=deltaX;i++){
        if(i==0){
            CoeMatrix(i,i)=1;
        }
        else if(i==deltaX){
            CoeMatrix(i,i)=1;
        }
        else{
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i-1)=1*(deltaX*deltaX);
            CoeMatrix(i,i+1)=1*(deltaX*deltaX);
        }
    }

    SecondODE.setZero();

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    TrunError=NumericalSol-SecondODE;

    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Theorical_TrunError_200(){
    const int deltaX=200;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){   
        TrunError(i,0)=0/(12*deltaX*deltaX);
    } 

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Numerical_TrunError_200(){
    const int deltaX=200;
    Matrix<float,deltaX+1,1> TrunError,NumericalSol,SecondODE;
    Matrix<float,deltaX+1,deltaX+1> CoeMatrix;

    CoeMatrix.setZero();
    for(int i=0;i<=deltaX;i++){
        if(i==0){
            CoeMatrix(i,i)=1;
        }
        else if(i==deltaX){
            CoeMatrix(i,i)=1;
        }
        else{
            CoeMatrix(i,i)=-2*(deltaX*deltaX);
            CoeMatrix(i,i-1)=1*(deltaX*deltaX);
            CoeMatrix(i,i+1)=1*(deltaX*deltaX);
        }
    }

    SecondODE.setZero();

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    TrunError=NumericalSol-SecondODE;

    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}


int main(){
    
    Theorical_TrunError_50();
    Numerical_TrunError_50();
}