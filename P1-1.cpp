#define EIGEN_STACK_ALLOCATION_LIMIT 0 //跑deltaX=200的會太大 所以要加這條

#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> //要另外裝


using namespace std;
using namespace Eigen;
                                                    //以下變數"deltaX"所代表的並不是實際上deltaX的意思，而是其倒數
                                                    //所以當變數 deltaX=50時，該題的deltaX實際上應該是1/50
                                                    
void  Numerical_Solution_50(){
    
    const int deltaX=50;
    Matrix<float,deltaX+1,1> NumericalSol,SecondODE,Solution_Error;   //deltaX=50,所以會有51個節點
    Matrix<float,deltaX+1,deltaX+1> CoeMatrix; //同上,51*51的矩陣
    

    CoeMatrix.setZero();  
    for(int i=0;i<=deltaX;i++){    //設定係數
        if(i==0){                 //由於此題的函數是exp(X)，其二階導數仍然是exp(X)，所以便將Boundary Condition也一併併入系數矩陣中，其系數設定為 1
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
    

    for(int i=0;i<=deltaX;i++){  //計算題目給的原函式的二階導數
        float XPosi=(float)i/deltaX;
        SecondODE(i,0)=exp(XPosi);
    }

    NumericalSol=CoeMatrix.colPivHouseholderQr().solve(SecondODE); //Eigen預設的解線性矩陣公式,不過有些解題函式似乎有BUG的樣子?
                                                                   //目前已知是A.colPivHouseholderQr()會是對的  
    
    cout<<"|||||||||||||||||||||Numerical_Solution||||||||||||||||||||||||||||||"<<endl;
    cout<<NumericalSol<<endl;

    for(int i=0;i<=deltaX;i++){          //計算Solution Error
        float XPosi=(float)i/deltaX;
        Solution_Error(i,0)=NumericalSol(i,0)-exp(XPosi);
    }
    
    float norm_Sol_Error=0;    //計算Solution Error 的 Norm
    for(int i=0;i<=deltaX;i++){
        norm_Sol_Error+=Solution_Error(i,0)*Solution_Error(i,0);
    }
    norm_Sol_Error=sqrt(norm_Sol_Error);

    cout<<"|||||||||||||||||||||Norm of Solution Error||||||||||||||||||||||||||||||"<<endl;
    cout<<norm_Sol_Error<<endl;

}

//接下來都一樣 DeltaX不同而已

void  Numerical_Solution_100(){
    
    const int deltaX=100;
    Matrix<float,deltaX+1,1> NumericalSol,SecondODE,Solution_Error;   
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
                                                                    
    
    cout<<"|||||||||||||||||||||Numerical_Solution||||||||||||||||||||||||||||||"<<endl;
    cout<<NumericalSol<<endl;


    for(int i=0;i<=deltaX;i++){          //計算Solution Error
        float XPosi=(float)i/deltaX;
        Solution_Error(i,0)=NumericalSol(i,0)-exp(XPosi);
    }
    
    float norm_Sol_Error=0;    //計算Solution Error 的 Norm
    for(int i=0;i<=deltaX;i++){
        norm_Sol_Error+=Solution_Error(i,0)*Solution_Error(i,0);
    }
    norm_Sol_Error=sqrt(norm_Sol_Error);

    cout<<"|||||||||||||||||||||Norm of Solution Error||||||||||||||||||||||||||||||"<<endl;
    cout<<norm_Sol_Error<<endl;
}


void  Numerical_Solution_200(){
    
    const int deltaX=200;
    Matrix<float,deltaX+1,1> NumericalSol,SecondODE,Solution_Error;   
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
                                                                    
    
    cout<<"|||||||||||||||||||||Numerical_Solution||||||||||||||||||||||||||||||"<<endl;
    cout<<NumericalSol<<endl;

    for(int i=0;i<=deltaX;i++){          //計算Solution Error
        float XPosi=(float)i/deltaX;
        Solution_Error(i,0)=NumericalSol(i,0)-exp(XPosi);
    }
    
    float norm_Sol_Error=0;    //計算Solution Error 的 Norm
    for(int i=0;i<=deltaX;i++){
        norm_Sol_Error+=Solution_Error(i,0)*Solution_Error(i,0);
    }
    norm_Sol_Error=sqrt(norm_Sol_Error);

    cout<<"|||||||||||||||||||||Norm of Solution Error||||||||||||||||||||||||||||||"<<endl;
    cout<<norm_Sol_Error<<endl;
}

void  Numerical_Solution_Abt(){                      //怕麻煩
   
    const int deltaX=100;                           //改這裡就好
    Matrix<float,deltaX+1,1> NumericalSol,SecondODE,Solution_Error;   
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
                                                                    
    
    cout<<"|||||||||||||||||||||Numerical_Solution||||||||||||||||||||||||||||||"<<endl;
    cout<<NumericalSol<<endl;

    for(int i=0;i<=deltaX;i++){          //計算Solution Error
        float XPosi=(float)i/deltaX;
        Solution_Error(i,0)=NumericalSol(i,0)-exp(XPosi);
    }
    
    float norm_Sol_Error=0;    //計算Solution Error 的 Norm
    for(int i=0;i<=deltaX;i++){
        norm_Sol_Error+=Solution_Error(i,0)*Solution_Error(i,0);
    }
    norm_Sol_Error=sqrt(norm_Sol_Error);

    cout<<"|||||||||||||||||||||Norm of Solution Error||||||||||||||||||||||||||||||"<<endl;
    cout<<norm_Sol_Error<<endl;
}

int main(){

    Numerical_Solution_Abt();
}

