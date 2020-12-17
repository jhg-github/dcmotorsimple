import serial
import struct
import matplotlib.pyplot as plt 
import statistics 
import numpy as np

DATA_SIZE_N = 8000
DATA_SIZE_BYTES = 2
N = DATA_SIZE_N*DATA_SIZE_BYTES
N2 = DATA_SIZE_N*4  # 1 buffers, speed
Fs = 500

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=30)
time.sleep(0.2) # added because it returns from serial.Serial before the port is really opened so the 
                # following functions wouldn't have any effect
ser.flushInput()
ser.flushOutput()
serBuffer = ser.read(N+N2)
# print(serBuffer)

sub_fmt = '<H'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_uint = []
while offset < N:
    serBuffer_uint.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size

sub_fmt = '<f'
sub_size = struct.calcsize(sub_fmt)
serBuffer_float = []
while offset < N+N2:
    serBuffer_float.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size


# middle_index=len(serBuffer_uint)//2
# encoder=serBuffer_uint[:middle_index]
# outBuffer_uint=serBuffer_uint[middle_index:]
encoder=serBuffer_uint


t = [ i/Fs for i in range(len(encoder))]
encoder_diff = np.diff(encoder)
encoder_diff = np.insert(encoder_diff,0,0)
encoder_diff = encoder_diff.tolist()
for i,value in enumerate(encoder_diff):
    if value < 0:
        encoder_diff[i]=0
print(type(encoder_diff))
# mA = [ ((((i * 3300) / 4096) / 16) / 0.05) for i in adcBuffer_uint]
# output = [ i - 1800 for i in outBuffer_uint]
# output = outBuffer_uint

# rows=[]
# for i in range(len(t)):
#     rows.append('{};{}\n'.format(t[i],encoder_diff[i]))
# filename = 'speed_50.csv'
# with open(filename, mode='w', newline='') as log_file:
#     log_file.write('t [s]; speed [encoder diff @ 500Hz]\n')
#     log_file.writelines(rows)   

# plt.plot(t,encoder,'.-') 
plt.plot(t,encoder_diff,'.-') 
plt.plot(t, np.convolve(encoder_diff, np.ones(50)/50, mode='full')[:DATA_SIZE_N])
plt.plot(t,serBuffer_float,'.-') 
plt.plot(t, np.convolve(serBuffer_float, np.ones(50)/50, mode='full')[:DATA_SIZE_N])
# plt.step(t,output, where='post')
plt.tight_layout()
plt.grid()
plt.show()