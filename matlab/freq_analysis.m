%-- signal --
T = readtable('../meas/step_current_2/NewFile1.csv', 'HeaderLines',54);
t = T{100:201,1};
v = T{100:201,3}/10;
mA = v/0.05;

%-- common --
Ts = t(2)-t(1)
Fs = 1/Ts
L = length(t);

%-- signal fft --
f = Fs*(0:(L/2))/L;
Xm = fft(mA);
P2 = 20*log10(abs(Xm/L));
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

%-- plots --
figure

subplot(1,2,1)
plot(t,mA)
title('mA')

subplot(1,2,2)
plot(f,P1) 
title('mA spectrum [dB]')