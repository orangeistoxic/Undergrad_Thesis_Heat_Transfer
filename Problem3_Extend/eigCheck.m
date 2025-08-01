
length =1;

dx = 2^-7;

load("MatA(2^-7).mat");

dotAmount=((length/dx)+1)^2;

MatA = full(MatA);

U = sparse(dotAmount,dotAmount);
L = sparse(dotAmount,dotAmount);
D = sparse(dotAmount,dotAmount);

for i=1:dotAmount
    L(i, 1:i-1) = MatA(i,1:i-1);
    D(i,i) = MatA(i,i);
    U(i,i+1:dotAmount) = MatA(i,i+1:dotAmount);
end

Tg = inv(D-L) * U;
Tj = inv(D) * (L+U);

gEig = eigs(Tg);
jEig = eigs(Tj);

gP = max(gEig)
jP = max(jEig)

