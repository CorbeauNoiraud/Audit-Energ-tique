//#include "DHT.h"
#include <SoftwareSerial.h>
//#define DHTPIN 2

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11 // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

SoftwareSerial espSerial(5, 6);
//DHT dht(DHTPIN, DHTTYPE);
String str;

void setup(){
Serial.begin(115200);
espSerial.begin(115200);
//dht.begin();
delay(2000);
}
void loop()
{
//float h = dht.readHumidity();
// Read temperature as Celsius (the default)
//float t = dht.readTemperature();
//Serial.print("H: ");
//Serial.print(h); 
//Serial.print("% ");
//Serial.print(" T: ");
//Serial.print(t); 
//Serial.println("C");
float courant1 = 9;
float courant2 = 3.2;
 if(courant1>0.4 && courant1<=0.7){
    courant1=courant1-0.2;
    
  }
  else if(courant1>0.7 && courant1<=1.15){
    courant1=courant1-0.15;
   
  }
  else if(courant1>1.15 && courant1<=1.57){
    courant1=courant1-0.06;
    
  }

  else if(courant1>2 && courant1<=2.44){
    courant1=courant1+0.06;

  }
  else if(courant1>2.44 && courant1<=2.88){
    courant1=courant1+0.12;

  }
  else if(courant1>2.88 && courant1<=3.36){
    courant1=courant1+0.18;

  }
  else if(courant1>3.36 && courant1<=3.76){
    courant1=courant1+0.24;

  }
  else if(courant1>3.76 && courant1<=4.29){
    courant1=courant1+0.21;

  }
  else if(courant1>4.29 && courant1<=4.66){
    courant1=courant1+0.44;

  }
  else if(courant1>4.66 && courant1<=8.13){
    courant1=courant1+0.87;

  }
  // Ecris la valeur du courant

  if(courant2<=0.4)
  {
    courant2=courant2-0.4;

  }
  else if(courant2>0.4 && courant2<=0.7)
  {
    courant2=courant2-0.2;

  }
  else if(courant2>0.7 && courant2<=1.15)
  {
    courant2=courant2-0.15;

  }
  else if(courant2>1.15 && courant2<=1.57)
  {
    courant2=courant2-0.06;

  }

  else if(courant2>2 && courant2<=2.44)
  {
    courant2=courant2+0.06;

  }
  else if(courant2>2.44 && courant2<=2.88)
  {
    courant2=courant2+0.12;

  }
  else if(courant2>2.88 && courant2<=3.36)
  {
    courant2=courant2+0.18;

  }
  else if(courant2>3.36 && courant2<=3.76)
  {
    courant2=courant2+0.24;

  }
  else if(courant2>3.76 && courant2<=4.29)
  {
    courant2=courant2+0.21;

  }
  else if(courant2>4.29 && courant2<=4.66)
  {
    courant2=courant2+0.44;

  }
  else if(courant2>4.66 && courant2<=8.13)
  {
    courant2=courant2+0.87;

  }
 
Serial.println(courant1); 
Serial.println(courant2);
str =String(courant1)+String(courant2);
espSerial.println(courant1);
espSerial.println(courant2);
delay(5000);
} 
