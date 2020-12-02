close all
clear

%-- signal --

Ts = 1/20000;

T = readtable('../meas/step_current_adc/pwm_3500.csv', 'HeaderLines',1);
start=8;
finish=8000;
t_delay=3.5e-4;
pwm =3500-1800;
gain = 1.7035

% T = readtable('../meas/step_current_adc/pwm_2700.csv', 'HeaderLines',1);
% start=8;
% finish=150;
% t_delay=3.5e-4;
% pwm=2700-1800;
% gain = 1.8822

% T = readtable('../meas/step_current_adc/pwm_2000.csv', 'HeaderLines',1);
% start=8;
% finish=150;
% t_delay=3.5e-4;
% pwm=2000-1800;
% gain = 1.6200

% T = readtable('../meas/step_current_adc/pwm_1600.csv', 'HeaderLines',1);
% start=8;
% finish=150;
% t_delay=3.5e-4;
% pwm=1800-1600;
% gain = 1.4900

% T = readtable('../meas/step_current_adc/pwm_900.csv', 'HeaderLines',1);
% start=8;
% finish=100;
% t_delay=3.5e-4;
% pwm=1800-900;
% gain = 1.7900

% T = readtable('../meas/step_current_adc/pwm_100.csv', 'HeaderLines',1);
% start=8;
% finish=150;
% t_delay=3.5e-4;
% pwm=1800-100;
% gain = 1.6912


t = T{start:finish,1};
t = t - t_delay;
mA = T{start:finish,2};
adc = (((mA*0.05)*16)*4096)/3300;

input = ones(length(t),1)*pwm;
gain = max(adc) / pwm


s=tf('s'); 
gain = 1.7
tau = 0.0006;
G=gain/(tau*s+1)

%-- plots --
hold on
% plot(t,mA,'x')
plot(t,adc)
plot(t,input)
% step(G*pwm)
% step(G1)
% step(G2)
% step(G3)
% legend('mA','G1','G2','G3')
