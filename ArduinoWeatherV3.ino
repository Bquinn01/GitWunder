#include "config.h"
AdafruitIO_Feed *servo_feed = io.feed("Happy LCD");
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      3
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay for half a second

// our servo # counter
uint8_t servonum = 0;

AdafruitIO_Feed *counter = io.feed("counter");

void setup() {
   Serial.begin(9600);

    while(! Serial);

Serial.print("Connecting to Adafruit IO");

   if (counter->exists()) {
   handleMessage(counter->lastValue());
 }

  io.connect();
 //weather1_feed->onMessage(handleMessage);

    while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);

     Serial.println();
  Serial.println(io.statusText());
  
    pixels.begin();
  
   pwm.begin();
   pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
   delay(10);
}
 





  

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  //pulselength = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
  
    pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
  
  
}


 void loop() {
io.run();
}
void handleMessage(AdafruitIO_Data *data) {

 Serial.print("received <- ");
 Serial.println(data->value());
}



// subscribe not publish
//if( current==(SanFranscisco){
//get from Weatherfeed1}


//void handleMessage(AdafruitIO_Data *data) {
// RAIN
if (data == 10 || data == 11 || data == 12 || data == 13){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 224);
pwm.setPWM(5, 0, 224);
for(int i=0;i<NUMPIXELS;i++)
pixels.setPixelColor(i, pixels.Color(50,55,55)); 
pixels.show();
delay(delayval);

}
else
//DAY CLOUDY
if (data == 2 || data == 3 || data == 4 || data == 5 || data == 6){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 331);
pwm.setPWM(5, 0, 331);
for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(150,155,155)); 
 pixels.show();
 delay(delayval);
}
}
else
//DAY CLEAR
if (data == 1){
pwm.setPWM(0, 0, 600); 
pwm.setPWM(1, 0, 600);
pwm.setPWM(3, 0, 600); 
pwm.setPWM(4, 0, 600);
pwm.setPWM(5, 0, 439);

for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(255,250,250)); 
 pixels.show();
 delay(delayval);
}
}
else
// windy Snow
if (data == 18 || data == 19 || data == 20 || data == 21 || data == 24){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 546);
for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(15,10,20)); 
 pixels.show();
 delay(delayval);
}
}
else
// Hot
if (data == 7){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 546);
for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(15,10,20)); 
 pixels.show();
 delay(delayval);
}
}
else
// Cold
if (data == 8){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 546);
for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(15,10,20)); 
 pixels.show();
 delay(delayval);
}
}
else
// Cold
if (data == 14 || data == 15){
pwm.setPWM(0, 0, 170); 
pwm.setPWM(1, 0, 170);
pwm.setPWM(3, 0, 170); 
pwm.setPWM(4, 0, 170);
pwm.setPWM(5, 0, 546);
for(int i=0;i<NUMPIXELS;i++){
 pixels.setPixelColor(i, pixels.Color(15,10,20)); 
 pixels.show();
 delay(delayval);
}
}
if (data==weather1){
  pwm.setPWM(6,0.224);
}
else
if (data==weather2){
  pwm.setPWM(6,0.331);
}
else
if (data==weather3){
  pwm.setPWM(6,0.439);
}
else
if (data==weather4){
  pwm.setPWM(6,0.546);
}



