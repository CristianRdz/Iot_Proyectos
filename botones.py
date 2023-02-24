import serial
import time
arduino = serial.Serial('COM3', 9600)
time.sleep(2)
sumatoria = 0
while (True):
    texto = arduino.readline().decode('utf-8')
    if "Suma total:" in texto:
        suma = int(texto.split(":")[1].strip())
    arduino.write(("Enciendete: " + str(suma) + "\n").encode())
    print("Enciendete: " + str(suma))
    if (texto == 'exit'):
        print('Saliendo...')
        break
arduino.close()
