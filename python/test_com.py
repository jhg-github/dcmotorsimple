import serial
import struct

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=10)
serBuffer = ser.read(2000)
# serBuffer = struct.unpack('>H', serBuffer)
sub_fmt = '<H'
sub_size = struct.calcsize(sub_fmt)
offset = 0
serBuffer_bytes = []
while offset < 2000:
    serBuffer_bytes.append( struct.unpack_from(sub_fmt, serBuffer, offset)[0] )
    offset += sub_size
print(serBuffer_bytes)
