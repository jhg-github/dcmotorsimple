close all
clear

%-- signal --

% T = readtable('../meas/step_current_adc/pwm_3500.csv', 'HeaderLines',1);
% start=8;
% finish=45;
% t_delay=3.5e-4;

T = readtable('../meas/step_current_adc/pwm_2700.csv', 'HeaderLines',1);
start=8;
finish=150;
t_delay=3.5e-4;

t = T{start:finish,1};
t = t - t_delay;
mA = T{start:finish,2};

input = ones(length(t),1)*max(mA);

s=tf('s');
G=1634/(s+1684);

% tau1 = 0.0006;
% G1=max(mA)/(tau1*s+1)
% tau2 = 0.0005;
% G2=max(mA)/(tau2*s+1)
% tau3 = 0.0004;
% G3=max(mA)/(tau3*s+1)

%-- plots --
hold on
plot(t,mA,'x')
% plot(t,input)
step(G*max(mA))
% step(G1)
% step(G2)
% step(G3)
% legend('mA','G1','G2','G3')
