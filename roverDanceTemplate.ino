/*
 * Things you need to do: 
 *    1) Define your pins
 *    2) Setup scanning of a card into the buffer variable
 *    3) Set the HIGH and LOW values in the functions
 *    4) ???
 *    5) Profit
 */

// Tune to your motors by getting your robot to go straight
const int speedA = 255;
const int speedB = 255;

// Add your pin numbers here
const int enA = ;
const int enB = ;
const int in1 = ;
const int in2 = ;
const int in3 = ;
const int in4 = ;

// Drive time is how long we will spin the motors for
const int driveTime = 400;
const int offTime = 150;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {

  // This is where our values from our will come in
  byte buffer1[18];

  // This is used to write out the string of commands at the end
  String value = "";
  for (uint8_t i = 0; i < 16; i++)
  {
    // This runs our decision based on each character we read in
    switch (buffer1[i]){
      case 'f':
        Serial.println("forward");
        forward();
        break;
      case 'b':
        Serial.println("backward");
        backward();
        break;
      case 'l':
        Serial.println("left");
        left();
        break;
      case 'r':
        Serial.println("right");
        right();
        break;
      default:
        Serial.println("No");
        delay(100);
        break;
      }
    value += (char)buffer1[i];
  }
  value.trim();
  Serial.println(value);
  delay(1000);
}

// I am feeling nice and will only delete the values for the movement functions
// You will need to put in the states for them
void off(){
  // Enable pins will be a number between 0 - 255
  analogWrite(enA, );
  analogWrite(enB, );

  // In pins will either be HIGH or LOW
  digitalWrite(in1, );
  digitalWrite(in2, );
  digitalWrite(in3, );
  digitalWrite(in4, );
  delay(offTime);
}
void forward() {
  // We will use the speeds we calibrated
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, );
  digitalWrite(in2, );
  digitalWrite(in3, );
  digitalWrite(in4, );

  delay(driveTime);
  off();
}
void backward() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, );
  digitalWrite(in2, );
  digitalWrite(in3, );
  digitalWrite(in4, );

  delay(driveTime);
  off();
}
void left() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, );
  digitalWrite(in2, );
  digitalWrite(in3, );
  digitalWrite(in4, );

  delay(driveTime);
  off();
}
void right() {
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
  
  digitalWrite(in1, );
  digitalWrite(in2, );
  digitalWrite(in3, );
  digitalWrite(in4, );

  delay(driveTime);
  off();
}
