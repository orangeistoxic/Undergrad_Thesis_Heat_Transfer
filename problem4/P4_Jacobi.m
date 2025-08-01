tic

length=1;
dx=10^-2;
dt=1;
flux=4000;
k=400;
h=400;
alpha=10^-4;
initialCondition=20;
outsideTemp=20;
dotLineAmount=(length/dx)+1; %101   
dotAmount=((length/dx)+1)^2; %10201

AD=sparse(dotAmount,dotAmount); %for t=n, Diagonal and Lower Matrix Part
ALU=sparse(dotAmount,dotAmount); % for t=n, Upper Matrix Part
B=sparse(dotAmount,dotAmount); %for t=n-1
next_time_step=zeros(dotAmount,1); %t=n
current_time_step=ones(dotAmount,1)*initialCondition; %Initial Condition and then for t=n-1
const=zeros(dotAmount,1); 
EqConst=zeros(dotAmount,1);%coefficient on the rightside of the Eq. (Equal to const+B*current_time_step)

for i=1:dotAmount
    if(i>=1 && i<=dotLineAmount) %C
        AD(i,i)=-3;
        ALU(i,i+dotLineAmount)=4;
        ALU(i,i+2*dotLineAmount)=-1;
    
    elseif(i>=dotAmount-dotLineAmount && i<=dotAmount) %B
        AD(i,i)=3;
        ALU(i,i-dotLineAmount)=-4;
        ALU(i,i-2*dotLineAmount)=1;
    elseif(mod(i,dotLineAmount)==1 && i~=1 && i~=dotAmount-dotLineAmount+1) %A
        AD(i,i)=3;
        ALU(i,i+1)=-4;
        ALU(i,i+2)=1;
        const(i,1)=2*flux*dx/k;
    elseif(mod(i,dotLineAmount)==0 && i~=dotLineAmount && i~=dotAmount) %D
        AD(i,i)=-3-(2*h*dx/k);
        ALU(i,i-1)=4;
        ALU(i,i-2)=-1;
        const(i,1)=-2*h*dx*outsideTemp/k;
    else %Governing Eq.
        AD(i,i)=(-2*dx*dx/(alpha*dt))-4;
        ALU(i,i+1)=1;
        ALU(i,i-1)=1;
        ALU(i,i+dotLineAmount)=1;
        ALU(i,i-dotLineAmount)=1;

        B(i,i)=(-2*dx*dx/(alpha*dt))+4;
        B(i,i+1)=-1;
        B(i,i-1)=-1;
        B(i,i+dotLineAmount)=-1;
        B(i,i-dotLineAmount)=-1;
    end
end

AD_Inverse=inv(AD);
ADLU=AD_Inverse*ALU;

iterationTime=70000; %s converge in 60000s
maxTempEveryIteration=zeros(iterationTime/dt,1); % 1000


for i=1:iterationTime/dt                %calculate

    EqConst=(const+B*current_time_step);

    %Jacobi Iteration
    
    Before_J = current_time_step;
    error = 1; %1 mean nothing, just a big number
    JI=0;
    while(error>=10^-10)
        
        After_J=AD_Inverse*EqConst - ADLU*Before_J;
        error=0;
        for j=1:dotAmount
            error=error+((After_J(j)-Before_J(j))/Before_J(j))^2;
        end
        error=sqrt(error);
        Before_J=After_J;
        JI=JI+1;
    end
    disp("Jacobi Iteration NO." + i + " Complete, total " + JI + " Iteration.");

    next_time_step = After_J;

    %Find out the max Temperature in this Time Step.
    
    maxTemp=max(current_time_step);
    maxTempEveryIteration(i,1)=maxTemp;
    current_time_step=next_time_step;

end

result=zeros(dotLineAmount,dotLineAmount);

for i=1:dotAmount             %restore the matrix
    rem=mod(i,dotLineAmount);
    if rem == 0
        result(((i-rem)/dotLineAmount),dotLineAmount)=next_time_step(i,1);
    else
        result(((i-rem)/dotLineAmount)+1,rem)=next_time_step(i,1);
    end
    
end

toc