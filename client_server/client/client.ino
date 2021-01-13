#include <WiFi.h>

const char* ssid     = "Shivam Singh";
const char* password = "123456789";
const char* host = "192.168.43.20";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
    delay(1000);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("connecting to ");
    Serial.println(host);
    WiFiClient client1;
    
    const int httpPort = 80;
    
    if (!client1.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }
    int a=6;
    client1.println(a);
    
    client1.stop();
    delay(5000);
}
