import serial, time
arduino = serial.Serial('COM3', 9600)
time.sleep(2)
while (True):
    texto = arduino.readline().decode('utf-8')
    
arduino.close()