# need to bind the port using
# > sudo rfcomm bind rfcomm0 00:21:13:01:40:7A
#
# on windows the port should probably be something like 'COM1' -> TODO

import serial

s = serial.Serial()
s.baudrate=38400
s.port='COM4'
s.open()

if s.is_open:
    s.write(b'l')
else:
    print("Unable to connect to serial connection")