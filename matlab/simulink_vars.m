Ts = 1/50

s = tf('s');
tau = 5;
G=1/(tau*s^2+s)
hold on
step(G)
step(1/s)
step( (1/s) - G )
 