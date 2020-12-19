close all
clear

%-- signal --

Ts = 0.02;

T = readtable('pos_v15.csv', 'HeaderLines',1);
start=1;
finish=100;
t = T{start:finish,1};
enc = T{start:finish,2};
v = 15
input = ones(length(t),1)*v;

s=tf('s');
G=2100/(s^2+4*s)
[Y, Tsim, X] = lsim(G,input,t);

%-- plots --
hold on
plot(t,enc)
plot(t,Y)
legend('enc','G')
