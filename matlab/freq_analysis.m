close all
clear

%-- signal --
T = readtable('../meas/step_current_3/pwm_1100_long.csv', 'HeaderLines',2);

% % '../meas/step_current_3/pwm_1100_short.csv'
% start=137146;
% finish=524000;

% '../meas/step_current_3/pwm_1100_long.csv'
start=162147;
finish=524200;
first=3330;
adjust=-5;

t = T{:,1};
t=t(start:finish);
v = T{:,3};
v=v(start:finish);
mA = v/0.05;

%-- downsampled --
Ts = t(2)-t(1)
Fs = 1/Ts
period=Fs/20000+adjust;
mA_down=mA(first:period:end);
t_down=t(first:period:end);


% %-- lowpass filter --
% fc = 100/(Fs/2);
% nfir = 100;
% hl_k = fir1(nfir,fc);
% mA_filtered = filter(hl_k,1,mA);
% [b,a] = butter(2,fc);
% mA_filtered_iir = filter(b,a,mA);

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

