#define EIGEN_STACK_ALLOCATION_LIMIT 0 //跑deltaX=200的會太大 所以要加這條

#include<iostream>
#include<math.h>
#include<Eigen/Eigen> //要另外裝



using namespace std;
using namespace Eigen;

void Theorical_TrunError_50(){
    const int deltaX=50;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){
        float XPosi=(float)i/deltaX;
        TrunError(i,0)=exp(XPosi)/(12*deltaX*deltaX); //帶入Truncation Error，且先算出函數的四階導數是exp(x)
        
          
    }

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
    
}

void  Numerical_TrunError_50(){
    const int deltaX=50;
    Matrix<float,deltaX+1,1> TrunError,NumericalSol,SecondODE;   //deltaX=50,所以會有51個節點
    Matrix<float,deltaX+1,deltaX+1> CoeMatrix; //同上,51*51的矩陣
    

    CoeMatrix.setZero();  
    for(int i=0;i<=deltaX;i++){    //設定係數
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
    

    for(int i=0;i<=deltaX;i++){  //計算原函數
        float XPosi=(float)i/deltaX;
        SecondODE(i,0)=exp(XPosi);
    }

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE); //Eigen預設的解線性矩陣公式,不過有些解題函式似乎有BUG的樣子?
                                                                   //目前已知是A.colPivHouseholderQr()會是對的
    TrunError=NumericalSol-SecondODE;  //相減得Trumcation Error
    
    
    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

//下面都一樣 deltaX不同而已

void Theorical_TrunError_100(){
    const int deltaX=100;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){
        float XPosi=(float)i/deltaX;
        TrunError(i,0)=exp(XPosi)/(12*deltaX*deltaX);
        
          
    }

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
    
}

void  Numerical_TrunError_100(){
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
    

    for(int i=0;i<=deltaX;i++){
        float XPosi=(float)i/deltaX;
        SecondODE(i,0)=exp(XPosi);
    }

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    TrunError=NumericalSol-SecondODE;
    
    
    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}

void Theorical_TrunError_200(){
    const int deltaX=200;
    Matrix<float,deltaX+1,1> TrunError;

    for(int i=0;i<=deltaX;i++){
        float XPosi=(float)i/deltaX;
        TrunError(i,0)=exp(XPosi)/(12*deltaX*deltaX);
        
          
    }

    cout<<"|||||||||||||||||||||Theorical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
    
}

void  Numerical_TrunError_200(){
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
    

    for(int i=0;i<=deltaX;i++){
        float XPosi=(float)i/deltaX;
        SecondODE(i,0)=exp(XPosi);
    }

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE);

    TrunError=NumericalSol-SecondODE;
    
    
    cout<<"|||||||||||||||||||||Numerical_TrunError||||||||||||||||||||||||||||||"<<endl;
    cout<<TrunError<<endl;
}


int main(){


    Theorical_TrunError_200(); 
    Numerical_TrunError_200();
    
    
}

