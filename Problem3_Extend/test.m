clear all;

dx = 2^-8;
load("MatA(2^-8).mat");
load("b(2^-8).mat");
length =1;
dotLineAmount=(length/dx)+1;   
dotAmount=((length/dx)+1)^2;
ini = ones(dotAmount,1)*20;

%{
m=8000;
MatA = randn(m,m);
b =randn(m,1);
%}
tic 
GE = MatA\b;

toc

tic
[ll, uu] = ilu(MatA);
[gm,FLAG, RELRES, ITER, RESVEC] = bicgstab(MatA, b, 10^-6,1000,ll ,uu,ini);

toc

subplot(2,1,1); bar(GE);
subplot(2,1,2); bar(gm);

figure(3);
plot(RESVEC, 'LineWidth',[2]);
