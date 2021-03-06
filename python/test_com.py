import serial
import struct
import matplotlib.pyplot as plt 
import statistics 
import numpy as np
import time


DATA_SIZE_BYTES = 2
N = 8000*DATA_SIZE_BYTES*2  # 2 buffers, adc and output
Fs = 20000

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=10)
time.sleep(0.2) # added because it returns from serial.Serial before the port is really opened so the 
                # following functions wouldn't have any effect
ser.flushInput()
ser.flushOutput()
serBuffer = ser.read(N)
# print(serBuffer)

sub_fmt = '<h'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_uint = []
while offset < N:
    serBuffer_uint.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size

middle_index=len(serBuffer_uint)//2
adcBuffer=serBuffer_uint[:middle_index]
outBuffer_uint=serBuffer_uint[middle_index:]



# print('mean', statistics.mean(serBuffer_uint))
# print('stdev', statistics.stdev(serBuffer_uint))
# plt.plot(serBuffer_uint,'.') 

# mavg4 = np.convolve(serBuffer_uint, np.ones((4,))/4, mode='valid')
# print('mean4', statistics.mean(mavg4))
# print('stdev4', statistics.stdev(mavg4))
# plt.plot(mavg4,'.') 

# mavg8 = np.convolve(serBuffer_uint, np.ones((8,))/8, mode='valid')
# print('mean8', statistics.mean(mavg8))
# print('stdev8', statistics.stdev(mavg8))
# plt.plot(mavg8,'.') 

t = [ i/Fs for i in range(len(adcBuffer))]
mA = [ ((((i * 3300) / 4096) / 16) / 0.05) for i in adcBuffer]
# output = [ i - 1800 for i in outBuffer_uint]
output = outBuffer_uint

rows=[]
for i in range(len(t)):
    rows.append('{};{}\n'.format(t[i],mA[i]))

# filename = 'pwm_100.csv'

# with open(filename, mode='w', newline='') as log_file:
#     log_file.write('t [s]; current [mA]\n')
#     log_file.writelines(rows)   

plt.step(t,output, label='output', where='post')
# plt.plot(t,mA,'.-', label='mA') 
plt.plot(t,adcBuffer,'.-', label='adcBuffer') 
plt.tight_layout()
plt.grid()
plt.legend()
plt.show()