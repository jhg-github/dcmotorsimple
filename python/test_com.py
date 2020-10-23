import serial
import struct
import matplotlib.pyplot as plt 


ser = serial.Serial('/dev/ttyACM0', 115200, timeout=100)
ser.flushInput()
ser.flushOutput()
serBuffer = ser.read(4000)
# print(serBuffer)

# serBuffer = struct.unpack('>H', serBuffer)
sub_fmt = '<f'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_bytes = []
while offset < 4000:
    serBuffer_bytes.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size
print(serBuffer_bytes)
plt.plot(serBuffer_bytes,'.') 
plt.show()
