clear all ; close all; 

%% Input

%% Air property
nu = 1.516e-5 ;
Pr = 0.73 ;
kf = 0.02514 ;
alpha = 2.074e-5 ;
rho = 1.204 ;
Cp = 1007 ;
v= 2 ;

%% Geometry property
a = 0.22e-2 ;
b = 1.76e-2 ;
D = 4*a*b/(2*a+2*b) ;
A = a*b ;

%% Parameter choice, 0.1~-0.3
gamma = -0.127;

%% Calculation
ReD = v*D/nu ;
Xin = 0.05*ReD*D*Pr ;
L= 0.05 ;
Gz = (L/D/ReD/Pr)^-1 ;
Pe = L*v/alpha ;
eps = a/b ; 
ReSqrtA = v/nu*A^0.5 ;
GzSqrtA = (L/A^0.5/ReSqrtA/Pr)^-1 ;


Lstar = linspace(0.001,10,10000) ;
aveNuversLstar = 0.*Lstar;
xi = L/ReSqrtA/A^0.5 ;

C1 =3.66 ;
C2 = 1.5 ;
C3 = 0.501 ;
C4 = 2 ;
g = 0.886/(1+(1.909*Pr^(1/6))^4.5)^(2/9) ;
m = 2.27 + 1.65*Pr^(1/3) ;


% Calculate AveNu vers Difference (entry) length
xi = Lstar*Pr/A ;
CfReSqrtA = ( (12/eps^0.5/(1+eps)/(1-192*eps/pi^5*tanh(pi/2/eps)))^2 + 3.44^2./xi).^0.5;
entryA = C2*C3*(CfReSqrtA./Lstar).^(1/3);
entryB = C1*CfReSqrtA/8/pi^0.5/eps^gamma ;
entryC = C4*g./Lstar.^0.5 ;

% Plot AveNu vers Difference (entry) length
aveNuversLstar = ((entryA.^5+entryB.^5).^(m/5) + entryC.^m ) .^(1/m) ;
loglog (Lstar, aveNuversLstar)
grid on;
xlabel('Gz^{-1}') ;
ylabel('aveNu') ;

% Calculate AveNu and Aveh in this case
Lstar = GzSqrtA^-1 ;
xi = Lstar*Pr/A ;
CfReSqrtA = ( (12/eps^0.5/(1+eps)/(1-192*eps/pi^5*tanh(pi/2/eps)))^2 + 3.44^2/xi)^0.5;
entryA = C2*C3*(CfReSqrtA/Lstar)^(1/3);
entryB = C1*CfReSqrtA/8/pi^0.5/eps^gamma ;
entryC = C4*g/Lstar^0.5 ;
aveNu = ((entryA.^5+entryB.^5).^(m/5) + entryC.^m ) .^(1/m) ;
aveh = aveNu*kf/A^0.5 ;