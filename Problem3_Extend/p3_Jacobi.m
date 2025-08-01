tic
%{
length = 1;
flux = 4000;
k = 400;
h = 400;
initialCondition=20;
outsideTemp=20;

dx = 2^-3;

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

MatA = sparse(dotAmount, dotAmount);
res = zeros(dotAmount, 1);
b = zeros(dotAmount, 1);


for i=1:dotLineAmount
    %c
    MatA(i, i) = -3;
    MatA(i, i+dotLineAmount) = 4;
    MatA(i, i+2*dotLineAmount) = -1;
    disp("Part C " + i + "Done!");
end

disp("Part C Done!");
for j=1:dotLineAmount-2

    pfS = j*dotLineAmount;

    %a
    b(pfS+1, 1) = flux*dx*2/k;
    MatA(pfS+1, pfS+1) = 3;
    MatA(pfS+1, pfS+1+1) = -4;
    MatA(pfS+1, pfS+1+2) = 1;

    %d
     b(pfS+dotLineAmount, 1) = -2*h*dx*outsideTemp/k;
     MatA(pfS+dotLineAmount, pfS+dotLineAmount) = -3-2*h*dx/k;
     MatA(pfS+dotLineAmount, pfS+dotLineAmount-1) = 4;
     MatA(pfS+dotLineAmount, pfS+dotLineAmount-2) = -1;

     %G-Equation
     for i=2:dotLineAmount-1
        MatA(pfS+i, pfS+i) = -4;
        MatA(pfS+i, pfS+i-1) = 1;
        MatA(pfS+i, pfS+i+1) = 1;
        MatA(pfS+i, pfS+i-dotLineAmount) = 1;
        MatA(pfS+i, pfS+i+dotLineAmount) = 1;
     end
    disp("Part " + j + " Done!");
end

%b
for i=dotLineAmount*(dotLineAmount-1)+1 : dotAmount
    MatA(i, i) = 3;
    MatA(i, i-dotLineAmount) = -4;
    MatA(i, i-2*dotLineAmount) = 1;
end
disp("Part B Done!");
disp("Matrix A done!");
%}




length = 1;
initialCondition=20; % did't used.

dx = 2^-3;
load("MatA(2^-3).mat");
load("b(2^-3).mat");

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

res = 0*ones(dotAmount, 1);


%Actually Calculate
LUA = -MatA;
DA = sparse(dotAmount,dotAmount);

for i=1:dotAmount
    DA(i,i) = LUA(i,i);
    LUA(i,i) = 0;
end


beforeRes = res;
error = 1;
iterationCount =0;

while(iterationCount < 100)
    res = DA\(b + LUA*beforeRes);
    
    error = norm(res - beforeRes);
    
    disp("error = " + error);
    beforeRes = res;
    iterationCount = iterationCount +1;
end


%rebiuld Matrix
grid = zeros(dotLineAmount, dotLineAmount);

for i=1:dotAmount
    rem=mod(i,dotLineAmount);
    if rem == 0
        grid(((i-rem)/dotLineAmount),dotLineAmount)=res(i,1);
    else
        grid(((i-rem)/dotLineAmount)+1,rem)=res(i,1);
    end
end
a = full(MatA);
toc