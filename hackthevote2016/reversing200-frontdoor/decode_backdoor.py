import struct

s = ""
for n in (0x69910E35, 0x50C20A33, 0x4F937913, 0x22F23A77):
    s += struct.pack("<I", n ^ 0x22F23A77)
    
print repr(s)

s = ""
for n in (0x1D, 0x61, 0x36, 0x3E, 0x66, 0x27, 0x14, 0x62, 0x62, 0x61, 0x36, 0x3E):
    s += chr(n ^ 0x55)
    
print repr(s)