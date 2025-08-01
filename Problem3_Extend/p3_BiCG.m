tic

length = 1;
initialCondition=20; % did't used.

dx = 2^-8;
load("MatA(2^-8).mat");
load("b(2^-8).mat");

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

%Actually Calculate

%preCondition: SOR
%preConMat = (1/1.9) * diag(diag(MatA)) + tril(MatA, -1);

%preCondition: ILU
[ll, uu] = ilu(MatA);

[result, flag, relres, iter,resvec] = bicg(MatA, b, 10^-6,1000000, ll, uu);


%rebiuld Matrix
grid = zeros(dotLineAmount, dotLineAmount);

for i=1:dotAmount
    rem=mod(i,dotLineAmount);
    if rem == 0
        grid(((i-rem)/dotLineAmount),dotLineAmount)=result(i,1);
    else
        grid(((i-rem)/dotLineAmount)+1,rem)=result(i,1);
    end
end



toc