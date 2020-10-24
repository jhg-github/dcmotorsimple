import serial
import struct
import matplotlib.pyplot as plt 
import statistics 
import numpy as np


N = 10000

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=100)
ser.flushInput()
ser.flushOutput()
serBuffer = ser.read(4*N)
# print(serBuffer)

# serBuffer = struct.unpack('>H', serBuffer)
sub_fmt = '<f'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_bytes = []
while offset < 4*N:
    serBuffer_bytes.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size

# print(serBuffer_bytes)
serBuffer_bytes=serBuffer_bytes[:8000]

print('mean', statistics.mean(serBuffer_bytes))
print('stdev', statistics.stdev(serBuffer_bytes))
plt.plot(serBuffer_bytes,'.') 

mavg4 = np.convolve(serBuffer_bytes, np.ones((4,))/4, mode='valid')
print('mean4', statistics.mean(mavg4))
print('stdev4', statistics.stdev(mavg4))
plt.plot(mavg4,'.') 

mavg8 = np.convolve(serBuffer_bytes, np.ones((8,))/8, mode='valid')
print('mean8', statistics.mean(mavg8))
print('stdev8', statistics.stdev(mavg8))
plt.plot(mavg8,'.') 

plt.show()

# blablabla