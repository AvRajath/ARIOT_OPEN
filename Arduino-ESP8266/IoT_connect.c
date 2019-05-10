#include <ESP8266WiFi.h>
//include firebase library to communicate with cloud
#include <FirebaseArduino.h>

//definition of all our parameters such as WIFI password and ID and also the Firebase Credentials
#define WIFI_SSID "Aiswarya's iPhone"
#define WIFI_PASSWORD "0309reddy1997"
#define FIREBASE_HOST "ariot-5cdcc.firebaseio.com"
#define FIREBASE_AUTH "yKyBR3QppTh6BGlhRZB4GtyJewEPc3ds3J3jBcQe"
//Please do not use the above credentials for your purpose as its only for our prototype.

//Relay pin definition
int relay_1 = 4;
int relay_2 = 2;

void setup()
{
Serial.begin(115200); //set baud rate

pinMode(relay_1, OUTPUT); //set relay pin as output pins
pinMode(relay_2, OUTPUT);

  delay(2000);
  Serial.println('\n');
  
  wifiConnect(); //establish connection with the WIFI network

  //Set up connection with firebase using the tokens
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  delay(10);
}

//string definition to store the status
String stats_app1,stats_app2;
void loop()
{  
//get the status of Appliance-1 from the database
stats_app1=Firebase.getString("Appliance-1");
delay(500);
//get the status of Appliance-2 from the database
stats_app2=Firebase.getString("Appliance-2");
delay(500);
Serial.print(stats_app1 + "\n");
Serial.print(stats_app2 + "\n");
 //Condition to check if firebase application failed to communicate
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());
      //if failed then reset the ESP to connect again
      ESP.reset();  
      return;
  }
  delay(1000);

//analogWrite(LED1, Firebase.getString("LED1").toInt());

//If status of Appliance-1 is "OFF" then change the relay-1 mode to high 
//which then disconnects the device from power source
if(stats_app1=="OFF")
{
  digitalWrite(relay_1,HIGH);
}
else
{
  digitalWrite(relay_1,LOW);
}
delay(10);
//If status of Appliance-2 is "OFF" then change the relay-2 mode to high
//which then disconnects the device from power source
if(stats_app2=="OFF")
{
  digitalWrite(relay_2,HIGH);
}
else
{
  digitalWrite(relay_2,LOW);
}
delay(10);
//Re-establish the connection to WIFI if it gets disconnected

if(WiFi.status() != WL_CONNECTED)
{
  wifiConnect();
}
delay(10);

}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}