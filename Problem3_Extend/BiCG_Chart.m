resSize = size(resvec);
semilogy(0:resSize-1,resvec,'.','LineWidth', 1);
yline(10^-6);
xlabel('Iteration number')
ylabel('Relative residual')