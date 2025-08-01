tic

length = 1;
initialCondition=20;

dx = 2^-8;
load("MatA(2^-8).mat");
load("b(2^-8).mat");

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

res = ones(dotAmount, 1);


%Actually Calculate
res=MatA\b;


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