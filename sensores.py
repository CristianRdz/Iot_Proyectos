import serial
import time
hc05 = serial.Serial('COM5', 9600)
time.sleep(2)
while (True):
    texto = hc05.readline().decode('utf-8')
    print(texto)
hc05.close()