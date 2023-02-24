import serial
import time
hc05 = serial.Serial('COM5', 9600)
time.sleep(2)
while (True):
    texto = input('Ingrese texto: ')
    hc05.write((texto.encode()))
hc05.close()
