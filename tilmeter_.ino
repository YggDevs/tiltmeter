
#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h> 

Servo servo1;
Servo servo2; 
int pos = 0; 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
byte ip[] = { 192, 168, 200, 80 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 192, 168, 200, 80 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

void setup() {

  Serial.begin(9600);
 
  servo1.attach(7);
  servo2.attach(6);

 
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.println(Ethernet.localIP());
}

void loop() {
 
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
       
        if (readString.length() < 100) {
          
          readString += c;
          //Serial.println(c);
         }
         if (c == '\n') {          
           Serial.println(readString); 
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println(F("<div style='text-align:center;'>"));
           client.println(" <button href=\"/?button1on\"\"> Rotar izquierda servo 1</button>client.println("
           client.println(" <br />client.println("
           client.println(" <button href=\"/?button1off\"\">Rotar derecha servo 1  </button><br />client.println("
           client.println(" <br />client.println("
           client.println(" <br />client.println("
           client.println(" <button href=\"/?button2off\"\">Rotar izquierda servo 2 </button>client.println("
           client.println(" <br />client.println("
           client.println("    <button href=\"/?button2off\"\">Rotar derecha servo 2 </button><br />client.println("
           client.println("  <br />client.println("
           client.println("  <br />client.println("
           client.println(" <button href=\"/?button3on\"\">Rotar izquierda servo 3 </button>client.println("
           client.println("  <br />client.println("
           client.println("  <button href=\"/?button3off\"\">Rotar derecha servo 3 </button><br />client.println("
           client.println("  <p>version-v</p>client.println("
           client.println(" <br />client.println("
           client.println(F("</div>\n</body></html>"));


           delay(1);
          
           client.stop();
       
           if (readString.indexOf("?button1on") >0){
              
                   servo2.write(200);
                     delay(10); 
                   servo2.write(90);
           }



      
           if (readString.indexOf("?button1off") >0){
               
                   servo2.write(45);
                     delay(10); 
                   servo2.write(90);
           }





           
          if (readString.indexOf("?button2on") >0){     //boton de la izquierda

                   servo1.write(200);
                     delay(10); 
                   servo1.write(90);  
                                 }


           if (readString.indexOf("?button2off") >0){   //boton de la derecha
                  servo1.write(45);
                     delay(10); 
                   servo1.write(90);
           }



             if (readString.indexOf("?button3on") >0){     //boton de la izquierda

                   servo1.write(200);
                     delay(10); 
                   servo1.write(90);  
                                 }


           if (readString.indexOf("?button3off") >0){   //boton de la derecha
                  servo1.write(45);
                     delay(10); 
                   servo1.write(90);
           }

          
            readString="";  
           
         }
       }
    }
}


  }
