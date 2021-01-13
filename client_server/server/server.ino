//This is the code for the server node 
#include <WiFi.h>

const char* ssid     = "Shivam Singh";
const char* password = "123456789";

WiFiServer server(80);

void setup() {

    // put your setup code here, to run once:

   Serial.begin(115200);
    pinMode(2,OUTPUT);
    digitalWrite(2,HIGH);
    delay(1000);
    digitalWrite(2,LOW);
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite(2,HIGH);
        delay(2000);
        digitalWrite(2,LOW);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address of server: ");
    Serial.println(WiFi.localIP());
    server.begin();
}


void loop() {

    // put your main code here, to run repeatedly:
    //delay(2000);
    WiFiClient client1 = server.available();   // listen for incoming clients

    
    if (client1) {                             // if you get a client,
    digitalWrite(2,HIGH);
    Serial.println("new client");           // print a message out the serial port

    while (client1.connected()) {            // loop while the client's connected
      if (client1.available()) {             // if there's bytes to read from the client,
        String c = client1.readString();
        Serial.print("Message from client: ");
        Serial.println(c);
      }
    }

    // close the connection:

    client1.stop();

    Serial.println("client disonnected");
    digitalWrite(2,LOW);
  }
}
