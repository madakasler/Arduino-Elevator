const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const unsigned char ssdlut[] = {0b00111111, 0b00000110,
                                0b01011011,
                               };
const int lutsize = 3;
#include <Servo.h>
#include <TM1637.h>



// Include the library:
#include <TM1637Display.h>

// defines pins numbers
const int trigPin = 11;
const int echoPin = 10;
#define CLK 5
#define DIO 6

// Create display object of type TM1637Display:
TM1637Display display = TM1637Display(CLK, DIO);

// Create array that turns all segments on:
const uint8_t data[] = {0xff, 0xff, 0xff, 0xff};

// Create array that turns all segments off:
const uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
// defines variables
long duration;
int distance;



Servo servo;
Servo servo_usi;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int angle = 0;
int cpos = 0;
boolean level1 = true;
boolean level2 = false;
boolean level3 = false;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  DDRA = 0b11111111;
  servo.attach(9);
    servo_usi.attach(8);
     servo_usi.write(155);
  // attach the signal pin of servo to pin9 of arduino
  Serial.begin(9600);
   display.clear();
   
  delay(1000);


}
void loop() {


  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  display.setBrightness(7);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;



  if (buttonState1 != lastButtonState1 || buttonState2 != lastButtonState2 || buttonState3 != lastButtonState3) {
    if (level1 == true) {
      if (buttonState1 == LOW) {
       
        level1 = true;
        level2 = false;
        level3 = false;
         display.clear();
         delay(500);
         display.showNumberDec(0);
         delay(500);
         servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);   
   
 
       
     
      }
      if (buttonState2 == LOW) {
        Serial.println("moving from level 1 to level 2");
        //myStepper.step(3050);
        level1 = false;
        level2 = true;
        level3 = false;
        display.clear();
        delay(500);
        display.showNumberDec(0);
        delay(500);

        servo.write(0);
        delay(2500);
        servo.write(90);
        delay(500);
         display.showNumberDec(1);
        delay(500);
         servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
      if (buttonState3 == LOW) {
       
        level1 = false;
        level2 = false;
        level3 = true;
      display.clear();
         delay(500);
          display.showNumberDec(0);
          delay(500);

        servo.write(0);
        delay(4000);
        servo.write(90);
         delay(500);
         display.showNumberDec(1);
        delay(500);
         display.showNumberDec(2);
        delay(500);
       servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
    }
    else if (level2 == true) {
      if (buttonState1 == LOW) {
       
        level1 = true;
        level2 = false;
        level3 = false;
        display.clear();
         delay(500);
          display.showNumberDec(1);
          delay(500);


         servo.write(180);
        delay(2000);
        servo.write(90);
        delay(500);
          display.showNumberDec(0);
        delay(500);
         servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
      if (buttonState2 == LOW ) {
       
        level1 = false;
        level2 = true;
        level3 = false;
         display.clear();
       delay(500);
          display.showNumberDec(1);
        delay(500);
         servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
      if (buttonState3 == LOW) {
        
        level1 = false;
        level2 = false;
        level3 = true;
         display.clear();
       delay(500);
          display.showNumberDec(1);
        delay(500);
        servo.write(0);
        delay(2000);
        servo.write(90);
            delay(500);
          display.showNumberDec(2);
        delay(500);
         servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
    }


    else if (level3 == true ) {
      if (buttonState1 == LOW) {
        
        level1 = true;
        level2 = false;
        level3 = false;

          display.clear();
       delay(500);
          display.showNumberDec(2);
        delay(500);
        servo.write(180);
        delay(4000);
        servo.write(90);
         delay(500);
         display.showNumberDec(1);
        delay(500);
         display.showNumberDec(0);
        delay(500);
      servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
      if (buttonState2 == LOW) {

       
        level1 = false;
        level2 = true;
        level3 = false;
          display.clear();
       delay(500);
          display.showNumberDec(2);
        delay(500);
       servo.write(180);
        delay(2000);
        servo.write(90);
           delay(500);
          display.showNumberDec(1);
        delay(500);
        servo_usi.write(60);
         delay(5000);
         servo_usi.write(155);
         delay(500);
      }
      if (buttonState3 == LOW) {
      
        level1 = false;
        level2 = false;
        level3 = true;
      display.clear();
       delay(500);
          display.showNumberDec(2);
        delay(500);
        delay(500);
        servo_usi.write(155);
         delay(5000);
         servo_usi.write(60);
         delay(500);
       

      }
    }
  }
lastButtonState1 = buttonState1;
lastButtonState2 = buttonState2;
lastButtonState3 = buttonState3;


}
