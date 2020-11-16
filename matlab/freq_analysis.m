close all
clear

%-- signal --
T = readtable('../meas/step_current_3/pwm_1100_short.csv', 'HeaderLines',2);
start=137146;
finish=524000;
t = T{:,1};
t=t(start:finish);
v = T{:,3};
v=v(start:finish);
mA = v/0.05;

%-- downsampled --
period=2489;
first=850;
mA_down=mA(first:period:end);
t_down=t(first:period:end);

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

% subplot(1,2,1)
hold on
plot(t,mA)
title('mA')
% plot(t,mA_filtered)
% title('mA filtered')
% plot(t,mA_filtered_iir)
% title('mA filtered iir')
plot(t_down,mA_down,'x', 'MarkerSize',20)
title('mA downsampled')
legend('mA','mA downsampled')

figure
plot(t_down,mA_down)
title('mA downsampled')

% subplot(1,2,2)
% plot(f,P1) 
% title('mA spectrum [dB]')
