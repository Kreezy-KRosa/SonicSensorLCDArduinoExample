//Sonic Sensor Example Code
//By Kreezy(KRosa) 1.15.2018
//Example Video @ https://youtu.be/cMXrbNFlgLI

//This example code is public domain

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,4,7,10,11,13);    //Pins connected to lcd screen 

int GLED = 5;                         //Green LED to Pin 5
int RLED = 3;                         //Red LED to Pin 3
int BLED = 6;                         //Blue LED to Pin 6 (Optional, only if using RGB LED)
int trigPin = 9;                      //Trigger pin to Pin 9
int echoPin = 8;                      //Echo pin to Pin 8
int BUZZ = 12;                        //Buzzer to Pin 12

void setup() {
  lcd.begin(16, 2);
  lcd.print("Demo by Kreezy");        //Startup screen 
  
  pinMode(GLED,OUTPUT);                
  pinMode(RLED,OUTPUT);               //Declaring LED pins as outputs
  pinMode(BLED,OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);           //Declaring the Trigger and Echo Pins
  pinMode(echoPin, INPUT);

  analogWrite(BLED,0);                //LED Test during bootup sequence

  analogWrite(RLED,255);
  analogWrite(GLED,0);
  delay(500);
    
  analogWrite(RLED,0);
  analogWrite(GLED,255);
  delay(500);
  
  analogWrite(RLED,255);
  digitalWrite(GLED,0);
  delay(500);
  
  analogWrite(RLED,0);
  analogWrite(GLED,255);
  delay(500);

  lcd.clear();
  lcd.print("Demo Ready");        //Demo is now ready to function
  delay(500);
  lcd.clear();

 }
 

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);     //Sending and Receiving Sonar frequencies  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 30) {                   //If the distance is less than 30cm 
    analogWrite(GLED,255);               //The Red LED is turn off and the Green LED will turn on
    analogWrite(RLED,0);
    tone(BUZZ, 100, 250);                //Also the Buzzer will sound
    }
  else {
    analogWrite(GLED,0);                 //If the distance is more than 30cm the Red LED will stay on
    analogWrite(RLED,255);
      }
  if (distance >= 200 || distance <= 0){  //Anything past 200cm will be out of range
    lcd.print("Out of range");            
  }
  else {
    lcd.setCursor(0, 0);                 //This will print the cm of anything that is in range
    lcd.print(distance);
    lcd.setCursor(6, 0);
    lcd.println(" cm");
      }
    delay(500);
  
}
  

