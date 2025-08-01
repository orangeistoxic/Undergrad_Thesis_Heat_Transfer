#define EIGEN_STACK_ALLOCATION_LIMIT  0
#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> 
#include<iomanip>
#define Pi acos(-1)    //定義Pi

using namespace std;
using namespace Eigen;

void NormSolErr_BTCS(){
    const int ReDeltaX=100;        //DeltaX的倒數 變更格子大小請在此更動
    double DeltaX=(double)1/ReDeltaX;
    const int ReDeltaT=100000;    //DeltaT的倒數 變更格子大小請在此更動
    double DeltaT=(double)1/ReDeltaT;
    double MaxNorm=0;

    Matrix<double,ReDeltaX-1,1>NumSol_Old,NumSol_New,ExSol,SolErr,Boundary_Condition;
    NumSol_Old.setZero();
    NumSol_New.setZero();
    ExSol.setZero();
    SolErr.setZero();
    Boundary_Condition.setZero();

    Boundary_Condition(0,0)=1;
    Boundary_Condition(ReDeltaX-2,0)=2;

    Matrix<double,ReDeltaX-1,ReDeltaX-1> CoeMatrix;
    CoeMatrix.setZero();

    for(int i=0;i<=ReDeltaX-2;i++){
        for(int j=0;j<=ReDeltaX-2;j++){
            if(i==j){
                CoeMatrix(i,j)=1+2*(DeltaT/pow(DeltaX,2));
            }
            else if(i==j+1 || i==j-1){
                CoeMatrix(i,j)=-1*(DeltaT/pow(DeltaX,2));
            }
        }
    }

    for(int i=0;i<=ReDeltaX-2;i++){
        NumSol_Old(i,0)=sin(Pi*((i+1)*DeltaX))+((i+1)*DeltaX)+1;
    }

    double normSolErr=0;

    for(int j=1;j<=ReDeltaT;j++){

        NumSol_New=CoeMatrix.colPivHouseholderQr().solve(NumSol_Old+(Boundary_Condition*(DeltaT/pow(DeltaX,2))));

        for(int i=0;i<=ReDeltaX-2;i++){
            ExSol(i,0)=expl(-1*pow(Pi,2)*j*DeltaT)*sin(Pi*((i+1)*DeltaX))+((i+1)*DeltaX)+1;
        }

        for(int i=0;i<=ReDeltaX-2;i++){
            SolErr(i,0)=abs(ExSol(i,0)-NumSol_New(i,0));

            if(SolErr(i,0)>MaxNorm)
            {
                MaxNorm=SolErr(i,0);
            }

            normSolErr+=pow(SolErr(i,0),2);
        }

        NumSol_Old=NumSol_New;


    }

    normSolErr=sqrt(normSolErr/((ReDeltaX+1)*(ReDeltaT+1)));
    cout<<"2 Norm: "<<normSolErr<<endl;
    cout<<"Max Norm: "<<MaxNorm<<endl;
}



int main(){
    NormSolErr_BTCS();
}