import serial

SerialArduino = serial.Serial('/dev/ttyACM0', baudrate=9600)

while True:
    lectureSensor = SerialArduino.readline().decode('ascii')
    print(lectureSensor)

SerialArduino.close()