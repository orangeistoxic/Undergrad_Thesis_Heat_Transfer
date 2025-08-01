%設定矩陣
A=sparse(661,661);
next_time_step=zeros(661,1);
current_time_step=ones(661,1)*20; %Initial Condition
const=zeros(661,1);

%設定係數
flux=20000;
dx=0.2*10^-3;
dy=0.2*10^-3;
dt=0.04*10^-3;
k=237;
kf=237;
alpha=0.097*10^-3;
h=41.5978;
infin=20;

%設定第一行 1~100
for q=1:101        %F
    A(q,q+101)=1;
end


%設定第二行 102~202
for q=102                 %A
    A(q,q+1)=1;
    const(q,1)=40000*dx/k;
end

for q=202                          %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end


for q=103:201                   %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+101)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

%設定第三行 203~303
for q=203                 %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=303                           %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

for q=204:302                 %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+101)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

%設定第4行 304~404
for q=304                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=404                          %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end 
for q=305:403                 %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+101)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

%設定第5行 405~505
for q=405                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=505                         %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

for q=406:504                   %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+101)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

%設定第6行 506~606
for q=506                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=507:515                %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+101)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

for q=516:606                       %D
    A(q,q-101)=(-kf/dy)/((-kf/dy)-h);
    const(q,1)=-h*infin/((-kf/dy)-h);
end

%設定第7行 607~617
for q=607                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=608:616                %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+11)=(dt*alpha/dx^2);
    A(q,q-101)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

for q=617                         %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

%設定第8行 618~628
for q=618                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=619:627                %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+11)=(dt*alpha/dx^2);
    A(q,q-11)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

for q=628                         %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

%設定第9行 629~639
for q=629                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=630:638                %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+11)=(dt*alpha/dx^2);
    A(q,q-11)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

for q=639                         %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

%設定第10行 640~650
for q=640                  %A
    A(q,q+1)=1;
    const(q,1)=flux*dx/k;
end

for q=641:649                %interior
    A(q,q+1)=(dt*alpha/dx^2);
    A(q,q-1)=(dt*alpha/dx^2);
    A(q,q+11)=(dt*alpha/dx^2);
    A(q,q-11)=(dt*alpha/dx^2);
    A(q,q)=-4*(dt*alpha/dx^2)+1;
end

for q=650                         %CE
    A(q,q-1)=(kf/dy)/((kf/dy)-h);
    const(q,1)=-h*infin/((kf/dy)-h);
end

%設定第11行 651~661
for q=651:661
    A(q,q-11)=1;
end

%計算並記錄矩陣

%TMaxMatrixH49=zeros(15000000,1);
%t=linspace(0.04,600,15000000);
%res=zeros(1000000,1);

%25000次為一秒
for q=1:25000*200 %10min
    %Tmax=0;
    next_time_step=A*current_time_step+const;
    
    for r=1:661
        %if next_time_step(r)>TMaxMatrixH49(q)
            %TMaxMatrixH49(q)=next_time_step(r);
        %end
        %res(q)=res(q)+(abs(next_time_step(r)-current_time_step(r))/next_time_step(r));
    end
    
    current_time_step=next_time_step;
end


%plot(t,TMaxMatrixH49);

%{
semilogy(t,res);
hold on;
plot(t,10^-6);
%}

%%{
bot_grid=zeros(101,6);
top_grid=zeros(11,6);

for q=1:101
    bot_grid(q,1)=next_time_step(q);
end
for q=102:202
    bot_grid(q-101,2)=next_time_step(q);
end
for q=203:303
    bot_grid(q-202,3)=next_time_step(q);
end
for q=304:404
    bot_grid(q-303,4)=next_time_step(q);
end
for q=405:505
    bot_grid(q-404,5)=next_time_step(q);
end
for q=506:606
    bot_grid(q-505,6)=next_time_step(q);
end

for q=1:11
    top_grid(q,1)=bot_grid(q,6);
end

for q=607:617
    top_grid(q-606,2)=next_time_step(q);
end
for q=618:628
    top_grid(q-617,3)=next_time_step(q);
end
for q=629:639
    top_grid(q-628,4)=next_time_step(q);
end
for q=640:650
    top_grid(q-639,5)=next_time_step(q);
end
for q=651:661
    top_grid(q-650,6)=next_time_step(q);
end

x=linspace(0,20,101);
y=linspace(0,1,6);
[X,Y]=meshgrid(x,y);

mesh(X,Y,bot_grid');

hold on;

x=linspace(0,2,11);
y=linspace(1,2,6);
[X,Y]=meshgrid(x,y);

mesh(X,Y,top_grid');

colormap jet;
abr=colorbar;
clim([40 65]);
abr.Label.String='Celsius';
xlabel('x(mm)');
ylabel('y(mm)');

%}
