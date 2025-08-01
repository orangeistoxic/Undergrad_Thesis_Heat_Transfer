tic

length = 1;
initialCondition=20; % did't used.

dx = 2^-8;
load("MatA(2^-8).mat");
load("b(2^-8).mat");

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

res = 0*ones(dotAmount, 1);

%Actually Calculate
DL = sparse(dotAmount,dotAmount);
U = sparse(dotAmount,dotAmount);

for i=1:dotAmount
    DL(i,1:i) = MatA(i,1:i);
    U(i,i+1:dotAmount) = -MatA(i,i+1:dotAmount);
end

beforeRes = res;
error = 1;
iterationCount =0;

while(error > 5*10^-6)
    
    res = DL\(U*beforeRes + b);

    error = norm(res - beforeRes);
    
    %disp("error = " + error);
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

toc
