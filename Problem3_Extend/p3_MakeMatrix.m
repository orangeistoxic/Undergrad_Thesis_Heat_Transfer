tic
length = 1;
flux = 4000;
k = 400;
h = 400;
initialCondition=20;
outsideTemp=20;

dx = 2^-10;

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

save('MatA(2^-10)', 'MatA');
save("b(2^-10)","b");

toc