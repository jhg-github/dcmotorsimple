import pandas
import matplotlib.pyplot as plt

raw = pandas.read_csv('NewFile0_clipped.csv')
t=raw['Time']
ch1=raw['X(CH1)']
ch2=raw['X(CH2)']*5
ch2_avg=ch2.rolling(10000).mean()
# print(ch2)
# print(ch2_avg)
plt.plot(t,ch1)
plt.plot(t,ch2)
plt.plot(t,ch2_avg)
plt.show()