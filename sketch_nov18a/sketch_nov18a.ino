#include <SoftwareSerial.h>
SoftwareSerial BT1(2,3); // RX | TX
int n1=0;

void setup()
  {Serial.begin(9600);
   BT1.begin(9600);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   }



void loop() 
{ while (BT1.available() >0 )
  {char c = BT1.read();
  if (c == 71) 
  {Serial.println("peticion web enviada");
   delay(500);
   servidor();
     }
 }
 
}



void escribir(String text)
{BT1.print("AT+CIPSEND=0,");  
 BT1.println(text.length());
 if (BT1.find(">"))             // Si se recibe el mensaje
 {Serial.println(text);
  BT1.println(text);            //mandamos el mensaje por el wifi 
  delay(10);
  while ( BT1.available() > 0 ) 
  {if (  BT1.find("SEND OK") )  //buscamos "ok" y luego salimos
   break; 
  }
 }
}

void servidor(void) 
    { escribir("<!DOCTYPE HTML>");
      escribir("<html>");                                                  //una pagina web necesita esto <HTML> y </HTML> es el inicio y fin del documento
      escribir("<head><title>Prueba arduino esp8266 html :)</title>");    //nombre de la pestaña que llevara la pagina
      escribir("<meta http-equiv=\"refresh\" content=\"10\"></head>");    //tiempo para refrescar la pagina web
      escribir("<body><h1> <FONT SIZE=\"5\" COLOR=\"red\"> ejemplos </h1>");                              //titulo del inicio de la pagina
      escribir(" <BODY BGCOLOR=\"black\"> ");  
      escribir("<a href=\"https://hetpro-store.com/TUTORIALES/wp-content/uploads/2016/05/PAGINA.png\" target=\"_blank\"><img src=\"https://hetpro-store.com/TUTORIALES/wp-content/uploads/2016/05/PAGINA.png\"  WIDTH=500 HEIGHT=500 BORDER=0  /></a><br /><br />");
      //Cargamos una imagen 
                              
         for (int n1 = 0; n1 < 3; n1++) 
         { int lectura = analogRead(n1);
            escribir("<FONT FACE=\"Arial\" SIZE=\"5\" COLOR=\"blue\"> entrada del sensor </FONT>"); //escribimos y cambiamos el tamaño, letra y color
            escribir("(a");
            escribir( String(n1));  
            escribir(")");
            escribir(" es ");
            escribir(String(lectura));  //imprimimos la variable
            escribir("<br />");
            escribir("<br />");
          }

           for (int n2 = 8; n2 < 10; n2++) 
         { int estado = digitalRead(n2) ;
            escribir("<FONT FACE=\"Arial\" SIZE=\"5\" COLOR=\"green\"> entrada digital </FONT>"); //escribimos y cambiamos el tamaño, letra y color
            escribir("(pin");
            escribir( String(n2));  
            escribir(")");
            escribir(" es ");
            escribir(String(estado));  //imprimimos la variable
            escribir("<br />");
            escribir("<br />");
          }
            
            escribir("<DIV align=\"center\"><A HREF=\"http://www.hetpro.com\" target=\"_blank\">hetpro.com</a><BR></DIV>");

       delay(1);
       BT1.println("AT+CIPCLOSE=0");
       //delay(500);
    }
