#define EIGEN_STACK_ALLOCATION_LIMIT  0
#include<bits/stdc++.h> 
#include<math.h>
#include<Eigen/Eigen> 
#include<iomanip>

using namespace std;
using namespace Eigen;

int main()
{
    const int gridSize=8; //only for square matrix 
    double delta=(double)1/gridSize;
    const int matSize=pow(gridSize-1,2);
    Matrix<double,matSize,matSize> mat;
    mat.setZero();
    for(int i=0;i<matSize;i++)
    {
        for(int j=0;j<matSize;j++)
        {
            if(i==j)
            {
                mat(i,j)=-4/pow(delta,2);
            }
            else if(j==i+1 && i%(gridSize-1)!=(gridSize-2))
            {
                mat(i,j)=1/pow(delta,2);
            }
            else if(j==i-1 && i%(gridSize-1)!=0)
            {
                mat(i,j)=1/pow(delta,2);
            }
            else if(j==i+(gridSize-1))
            {
                mat(i,j)=1/pow(delta,2);
            }
            else if(j==i-(gridSize-1))
            {
                mat(i,j)=1/pow(delta,2);
            }
        }
    }
    
    Matrix<double,matSize,1> Y_BC,X_BC;
    Y_BC.setZero();
    X_BC.setZero();


    for(int i=0;i<matSize;i++)
    {
        if(abs((i-0)<gridSize-1))
        {
            Y_BC(i,0)=(40-10*((i+1)*delta))/pow(delta,2);
        }
        else if(abs(i-(matSize-1))<gridSize-1)
        {
            Y_BC(i,0)=(40-10*(((i%(gridSize-1))+1)*delta))/pow(delta,2);
        }
    }

    for(int i=0;i<matSize;i++)
    {
        if(i%(gridSize-1)==0)
        {
            X_BC(i,0)=40/pow(delta,2);
        }
        else if(i%(gridSize-1)==gridSize-2)
        {
            X_BC(i,0)=30/pow(delta,2);
        }
    }

    Matrix<double,matSize,1> sol_0,ans;
    sol_0.setZero();
    ans.setZero();

    ans=mat.colPivHouseholderQr().solve(sol_0-Y_BC-X_BC);
   

    Matrix<double,gridSize+1,gridSize+1> actuallResult;
    actuallResult.setZero();

    for(int i=0;i<gridSize+1;i++)
    {
        for(int j=0;j<gridSize+1;j++)
        {
            if(j==0)
            {
                actuallResult(i,j)=40;
            }
            else if(j==gridSize)
            {
                actuallResult(i,j)=30;
            }
            else if(i==0 || i==gridSize)
            {
                
                actuallResult(i,j)=40-10*(j*delta);
            }
            else 
            {
                actuallResult(i,j)=ans((i-1)*(gridSize-1)+(j-1),0);
            }
        }
    }

    cout<<actuallResult;

    return 0;
}