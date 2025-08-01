GE_Time = [0.0026, 0.0058, 0.0078, 0.0179, 0.0608, 0.2929];

bicg_time = [0.0045, 0.0282, 0.0268, 0.0981, 0.7235, 6.5094]
bicg_iter = [127, 331, 549, 1159, 2268, 5063]

bicgstab_time = [0.0458, 0.0155, 0.0275, 0.1543, 0.9622, 16.665]
bicgstab_iter = [103.5, 222, 491.5, 1512, 2784, 9725]

bicgstabl_time = [0.0124, 0.0110, 0.0233, 0.3238, 1.5968, 26.9245]
bicgstabl_iter = [36.5, 80.25, 168.5, 447.25, 840, 3445]

SOR_bicg_time = [0.0051, 0.006, 0.0164, 0.0493, 0, 0]
SOR_bicg_iter = [52, 99, 182, 277, 0, 0]

SOR_bicgstab_time = [0.0073, 0.0085, 0.0108, 0.0408, 0.3367, 3.5745]
SOR_bicgstab_iter = [40.5, 77.5, 126.5, 209.5, 409, 1030]

SOR_bicgstabl_time = [0.0048, 0.0092, 0.0134, 0.0831, 0.6186, 4.7028]
SOR_bicgstabl_iter = [19.5, 33, 55.25, 99.5, 209.5, 420.5]

SOR_gmres_time = [0.0054, 0.006, 0.0297, 1.1025, 11.277, 48.8996]

ILU_bicg_time = [0.0045, 0.0058, 0.0102, 0.0419, 0.3679, 4.0326]
ILU_bicg_iter = [19, 33, 55, 126, 275, 789]

ILU_bicgstab_time = [0.0045, 0.0055, 0.0122, 0.0332, 0.3528, 2.5468]
ILU_bicgstab_iter = [13, 25, 47, 96, 269, 458]

ILU_bicgstabl_time = [0.0047, 0.0061, 0.0119, 0.049, 0.3473, 2.4465]
ILU_bicgstabl_iter = [6, 10, 20.5, 40.25, 84, 156]

ILU_gmres_time = [0.0058, 0.0096, 0.0132, 0.1746, 1.4124, 21.3812]

dotAmount = [81, 289, 1089, 4225, 16641, 66049];
dotAmount = log10(dotAmount);


%{
semilogy(dotAmount,ILU_bicg_iter, '-o');
hold on;
semilogy(dotAmount,ILU_bicgstab_iter, '-o');
hold on;
semilogy(dotAmount,ILU_bicgstabl_iter, '-o');
hold on;


legend('bicg', 'bicgstab','bicgstabl', 'Location','northwest');
xlabel('log10(dotAmount)');
ylabel('IterationCount');
%}



%{
semilogy(dotAmount,GE_Time, '-o');
hold on;
semilogy(dotAmount,ILU_bicg_time, '-o');
hold on;
semilogy(dotAmount,ILU_bicgstab_time, '-o');
hold on;
semilogy(dotAmount,ILU_bicgstabl_time, '-o');
hold on;
semilogy(dotAmount,ILU_gmres_time, '-o');
hold on;


legend('GE','bicg', 'bicgstab','bicgstabl', 'gmres', 'Location','northwest');
xlabel('log10(dotAmount)');
ylabel('Time(s)');
%}

basic = [0.0036, 0.0140, 0.0518, 0.2760, 1.3935]
bicgstabb = [0.0294, 0.0340, 0.0688, 0.0000, 3.3836]

dot = [1089, 4225, 16641, 66049,263169];
dot = log10(dot);

semilogy(dot,basic, '-o');
hold on;
semilogy(dot,bicgstabb, '-o');
hold on;

legend('A\b','bicgstab', 'Location','northwest');
xlabel('log10(dotAmount)');
ylabel('Time(s)');




