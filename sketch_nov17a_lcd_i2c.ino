#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WebSocketClient.h>
const char* ssid     = "80 dqh 2.2 2.4G";
const char* password = "80duongquangham";
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
int const den1 = D5;
int const den2 = D6;
void setup() {
  Serial.begin(9600);
  lcd.begin(20,4); 
  lcd.backlight();  
 // lcd.setCursor(0, 0);
 // lcd.print("Test Line 1");
 // lcd.setCursor(0, 1);
 // lcd.print("Test line 2");
  lcd.setCursor(0, 2);
  lcd.print("Test Line 3");
  lcd.setCursor(0,3);
  lcd.print("Test Line 4");
  delay(10);
  // We start by connecting to a WiFi network
  pinMode(den1, OUTPUT); 
  pinMode(den2, OUTPUT); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED){
    delay(500); 
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  setup_RTC();
}
void loop() {
  loop_RTC();
}
