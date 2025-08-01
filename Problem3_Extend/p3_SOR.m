tic

length = 1;
initialCondition=20; % did't used.

dx = 2^-6;
load("MatA(2^-6).mat");
load("b(2^-6).mat");

dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2; 

result = 0*ones(dotAmount, 1);

%Actually Calculate
w =1.7; %maybe try different coefficient???

D = sparse(dotAmount, dotAmount);
wU = sparse(dotAmount, dotAmount);
wL = sparse(dotAmount,dotAmount);

for i=1:dotAmount
    D(i,i) = MatA(i,i);
    wL(i,1:i) = w.*MatA(i,1:i);
    wL(i,i) = 0;
    wU(i,i+1:dotAmount) = w.*MatA(i,i+1:dotAmount);

end

DwL = D + wL;
wUw1D = wU + (w-1).*D;
wb = w.*b;

beforeResult = result;
error = 1;
iterationCount =0;

while(error > 5*10^-6)
    result = DwL\(wb - wUw1D*beforeResult);

    error = norm(result - beforeResult);
    
    %disp("error = " + error);
    beforeResult = result;
    iterationCount = iterationCount +1;

end

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