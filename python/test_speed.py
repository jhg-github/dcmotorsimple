import serial
import struct
import matplotlib.pyplot as plt 
import statistics 
import numpy as np


DATA_SIZE_BYTES = 2
N = 8000*DATA_SIZE_BYTES*1  # 1 buffers, speed
Fs = 1000

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=20)
ser.read_all()
ser.flushInput()
ser.flushOutput()
serBuffer = ser.read(N)
# print(serBuffer)

sub_fmt = '<H'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_uint = []
while offset < N:
    serBuffer_uint.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size

# middle_index=len(serBuffer_uint)//2
# encoder=serBuffer_uint[:middle_index]
# outBuffer_uint=serBuffer_uint[middle_index:]
encoder=serBuffer_uint


t = [ i/Fs for i in range(len(encoder))]
encoder_diff = np.diff(encoder)
encoder_diff = np.insert(encoder_diff,0,0)
encoder_diff = encoder_diff.tolist()
print(type(encoder_diff))
# mA = [ ((((i * 3300) / 4096) / 16) / 0.05) for i in adcBuffer_uint]
# output = [ i - 1800 for i in outBuffer_uint]
# output = outBuffer_uint

# rows=[]
# for i in range(len(t)):
    # rows.append('{};{}\n'.format(t[i],mA[i]))
# filename = 'pwm_100.csv'
# with open(filename, mode='w', newline='') as log_file:
#     log_file.write('t [s]; current [mA]\n')
#     log_file.writelines(rows)   

plt.plot(t,encoder,'.-') 
plt.plot(t,encoder_diff,'.-') 
# plt.step(t,output, where='post')
plt.tight_layout()
plt.grid()
plt.show()