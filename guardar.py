import serial

#archivo = open('Documentos/datos.txt', 'w')
SerialArduino = serial.Serial('/dev/ttyACM0', baudrate=9600)

while True:
    lectureSensor = SerialArduino.readline().decode('utf-8')
    print(lectureSensor)
    #archivo.write(lectureSensor)
    with open('/home/karel-slgd/Documentos/planta.txt', 'a') as f:
        f.write(lectureSensor)
        f.close()       
    