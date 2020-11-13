close all
clear

%-- signal --
T = readtable('../meas/step_current_2/NewFile2.csv', 'HeaderLines',2);
start=163000;
finish=360000;
t = T{:,1};
t=t(start:finish);
t = downsample(t,100)
v = T{:,3}/10;
v=v(start:finish);
v = downsample(v,100)
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

%-- lowpass filter --
fc = 100/(Fs/2);
nfir = 100;
hl_k = fir1(nfir,fc);
mA_filtered = filter(hl_k,1,mA);
[b,a] = butter(2,fc);
mA_filtered_iir = filter(b,a,mA);

%-- plots --
figure

subplot(1,2,1)
hold on
plot(t,mA)
title('mA')
plot(t,mA_filtered)
title('mA filtered')
plot(t,mA_filtered_iir)
title('mA filtered iir')
legend('mA','fir','iir')

subplot(1,2,2)
plot(f,P1) 
title('mA spectrum [dB]')
