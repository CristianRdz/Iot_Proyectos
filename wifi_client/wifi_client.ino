#include <SoftwareSerial.h>
SoftwareSerial SerialESP8266(12,13); // RX, TX

String server = "192.168.100.34";

//variables para enviar al servidor
int led=1;
int counter=0;

String cadena="";

void setup() {

  SerialESP8266.begin(9600);
  Serial.begin(9600);
  SerialESP8266.setTimeout(2000);
  
  //Verificamos si el ESP8266 responde
  SerialESP8266.println("AT");
  if(SerialESP8266.find("OK"))
    Serial.println("Respuesta AT correcto");
  else
    Serial.println("Error en ESP8266");

  //-----Configuración de red-------//Podemos comentar si el ESP ya está configurado

    //ESP8266 en modo estación (nos conectaremos a una red existente)
    SerialESP8266.println("AT+CWMODE=1");
    if(SerialESP8266.find("OK"))
      Serial.println("ESP8266 en modo Estacion");
      
    //Nos conectamos a una red wifi 
    SerialESP8266.println("AT+CWJAP=\"Totalplay-2.4G-9cd0\",\"tmVyxwb8jbuzUNcj\"\r\n");
    Serial.println("Conectandose a la red ...");
    SerialESP8266.setTimeout(10000); //Aumentar si demora la conexion
    if(SerialESP8266.find("OK"))
      Serial.println("WIFI conectado");
    else
      Serial.println("Error al conectarse en la red");
    SerialESP8266.setTimeout(2000);
    //Desabilitamos las conexiones multiples
    SerialESP8266.println("AT+CIPMUX=0");
    if(SerialESP8266.find("OK"))
      Serial.println("Multiconexiones deshabilitadas");
    
  //------fin de configuracion-------------------

  delay(1000);
  
}


void loop() {
  
    //otras operaciones
    // . . . 
  
  
  //---------enviamos las variables al servidor---------------------
  
      //Nos conectamos con el servidor:
      
      SerialESP8266.println("AT+CIPSTART=\"TCP\",\""+server+"\",80");
      if( SerialESP8266.find("OK"))
      {  
          Serial.println();
          Serial.println();
          Serial.println();
          Serial.println("ESP8266 conectado con el servidor...");             
    
          //Armamos el encabezado de la peticion http
          String peticionHTTP= "GET /led=";
          peticionHTTP=peticionHTTP+String(led);
          peticionHTTP=peticionHTTP+"Host: 192.168.100.34";
    
          //Enviamos el tamaño en caracteres de la peticion http:  
          SerialESP8266.print("AT+CIPSEND=");
          SerialESP8266.println(peticionHTTP.length());

          //esperamos a ">" para enviar la petcion  http
          if(SerialESP8266.find(">")) // ">" indica que podemos enviar la peticion http
          {
            Serial.println("Enviando HTTP . . .");
            SerialESP8266.println(peticionHTTP);
            if( SerialESP8266.find("SEND OK"))
            {  
              Serial.println("Peticion HTTP enviada:");
              Serial.println();
              Serial.println(peticionHTTP);
              Serial.println("Esperando respuesta...");
              
              boolean fin_respuesta=false; 
              long tiempo_inicio=millis(); 
              cadena="";
              
              while(fin_respuesta==false)
              {
                  while(SerialESP8266.available()>0) 
                  {
                      char c=SerialESP8266.read();
                      Serial.write(c);
                      cadena.concat(c);  //guardamos la respuesta en el string "cadena"
                  }
                  //finalizamos si la respuesta es mayor a 500 caracteres
                  if(cadena.length()>500) //Pueden aumentar si tenen suficiente espacio en la memoria
                  {
                    Serial.println("La respuesta a excedido el tamaño maximo");
                    
                    SerialESP8266.println("AT+CIPCLOSE");
                    if( SerialESP8266.find("OK"))
                      Serial.println("Conexion finalizada");
                    fin_respuesta=true;
                  }
                  if((millis()-tiempo_inicio)>10000) //Finalizamos si ya han transcurrido 10 seg
                  {
                    Serial.println("Tiempo de espera agotado");
                    SerialESP8266.println("AT+CIPCLOSE");
                    if( SerialESP8266.find("OK"))
                      Serial.println("Conexion finalizada");
                    fin_respuesta=true;
                  }
                  if(cadena.indexOf("CLOSED")>0) //si recibimos un CLOSED significa que ha finalizado la respuesta
                  {
                    Serial.println();
                    Serial.println("Cadena recibida correctamente, conexion finalizada");         
                    fin_respuesta=true;
                  }
              }
    
              
            }
            else
            {
              Serial.println("No se ha podido enviar HTTP.....");
           }            
          }
      }
      else
      {
        Serial.println("No se ha podido conectarse con el servidor");
      }

        
  //-------------------------------------------------------------------------------

  delay(5000); //pausa de 10seg antes de conectarse nuevamente al servidor (opcional)
}