/*
This is some basic code that works...okay
You will need to adjust your speeds, adjust your pin numbers
Then optimise. This will also not necessarily handle a maze, but this should be a good starting point
*/

#include <QTRSensors.h>

// Define our qtr
QTRSensors qtr;
const uint8_t SensorCount = 4;
uint16_t sensorValues[SensorCount];

// Set your speeds, I dropped my speeds for the sake of linefollowing
const int speedA = 135;//245;
const int speedB = 145;//255;

// Motor pins
const int enA = 6;
const int enB = 3;
const int in1 = 7;
const int in2 = 8;
const int in3 = 5;
const int in4 = 4;

// Motor Function delay time
const int delayTime = 10;

void setup() {
  // Setup our qtr object
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3}, SensorCount);

  // Callibration, stolen from the RC example
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
  
  Serial.begin(9600);                                           
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  delay(1000);
}

void loop() {

  // Get a calibrated position for our line.
  // Value 0 = seen or last seen by sensor 1
  // Value 3000 = seen or last seen by sensor 4
  uint16_t position = qtr.readLineBlack(sensorValues);
  
  //qtr.read(sensorValues);
  qtr.readCalibrated(sensorValues);
  
  // print out raw sensor values and the position
  for (uint8_t i = 0; i < SensorCount; i++)
  {  
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  // Check where we should go, we should be aiming to be at 1500...
  if(position < 1800 && position > 1200){
        Serial.println("forward");
        forward();
  } else if(position >= 1800){
        Serial.println("right");
        right();
  } else if(position <= 1200){
        Serial.println("left");
        left();
  }
}

// We turn the motors off after each direction to slow things down a bit
void off(){
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forward() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(delayTime);
  off();
}
void backward() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(delayTime);
  off();
}
void left() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(delayTime);
  off();
}
void right() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(delayTime);
  off();
}
