#define EIGEN_STACK_ALLOCATION_LIMIT  0
#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> 
#include<iomanip>
#define Pi acos(-1)    //定義Pi

using namespace std;
using namespace Eigen;

void NormSolErr(){
    const int ReDeltaX=500;        //DeltaX的倒數 變更格子大小請在此更動
    double DeltaX=(double)1/ReDeltaX;
    const int ReDeltaT=2500000;    //DeltaT的倒數 變更格子大小請在此更動
    double DeltaT=(double)1/ReDeltaT;

    Matrix<double,ReDeltaX+1,1>NumSol_Old,NumSol_New,ExSol,SolErr;
    NumSol_Old.setZero();
    NumSol_New.setZero();
    ExSol.setZero();
    SolErr.setZero();

    NumSol_New(0,0)=1;                                           //設定Boundry Condition
    NumSol_New(ReDeltaX,0)=2;

    for(int i=0;i<=ReDeltaX;i++){                                //設定Initial Condition
        NumSol_Old(i,0)=sin(Pi*(i*DeltaX))+(i*DeltaX)+1;
    }
    
    double normSolErr=0;

    for(int j=1;j<=ReDeltaT;j++){                                

        for(int i=1;i<=ReDeltaX-1;i++){                    //計算新一個時間點的數值
            NumSol_New(i,0)=NumSol_Old(i,0)+(1*DeltaT/pow(DeltaX,2))*(NumSol_Old(i+1,0)-2*NumSol_Old(i,0)+NumSol_Old(i-1,0));
        }

        for(int i=0;i<=ReDeltaX;i++){                     //計算這個時間點下的正確解
            ExSol(i,0)=expl(-1*pow(Pi,2)*j*DeltaT)*sin(Pi*(i*DeltaX))+(i*DeltaX)+1;
        }

        for(int i=0;i<=ReDeltaX;i++){                     //累加所有的Solution Error
            SolErr(i,0)=abs(ExSol(i,0)-NumSol_New(i,0));
            normSolErr+=pow(SolErr(i,0),2);
        }

        for(int i=1;i<=ReDeltaX-1;i++){                   //更迭時間
            NumSol_Old(i,0)=NumSol_New(i,0);
        }
    }

    normSolErr=sqrt(normSolErr);                        //算出Norm

    cout<<normSolErr<<endl;

}



int main(){
    NormSolErr();
}