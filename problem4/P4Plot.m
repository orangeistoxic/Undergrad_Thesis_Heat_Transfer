%making plot
%{
x=linspace(0,1000,dotLineAmount); %convert meter into mm
y=linspace(0,1000,dotLineAmount);
[X,Y]=meshgrid(x,y);

mesh(X,Y,result');

colormap jet;
abr=colorbar;
abr.Label.String='Celsius';
xlabel('x(mm)');
ylabel('y(mm)');
%}

%making maxTemp Plot

t=linspace(0,iterationTime,iterationTime/dt);
plot(t,maxTempEveryIteration);
yline(45);
text(25000,43,'Max Temperture in every Iteration');

