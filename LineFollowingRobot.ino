/*
  Author: Lauren Crist
  Date: Spring 2021
  Description: Arduino code for controlling a line-following robot with 5 line sensors (sens1 to sens5) and two motors (enA, enB) with two input pins each (in1, in2, in3, in4).
*/

const int sens1 = A0;  // Analog input for left-most sensor
const int sens2 = A1;  // Analog input for middle-left sensor
const int sens3 = A2;  // Analog input for middle sensor
const int sens4 = A3;  // Analog input for middle-right sensor
const int sens5 = A4;  // Analog input for right-most sensor
const int in1 = 2;     // Motor input pin 1
const int enA = 3;     // Motor enable pin A
const int in2 = 4;     // Motor input pin 2
const int enB = 5;     // Motor enable pin B
const int in3 = 7;     // Motor input pin 3
const int in4 = 8;     // Motor input pin 4

void setup() {
  Serial.begin(9600);
  
  // Set sensor pins as INPUT
  pinMode(sens1, INPUT);
  pinMode(sens2, INPUT);
  pinMode(sens3, INPUT);
  pinMode(sens4, INPUT);
  pinMode(sens5, INPUT);
  
  // Set motor control pins as OUTPUT
  pinMode(in1, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Read sensor values
  int val1 = analogRead(sens1);
  int val2 = analogRead(sens2);
  int val3 = analogRead(sens3);
  int val4 = analogRead(sens4);
  int val5 = analogRead(sens5);
  
  // Print sensor values to Serial Monitor
  Serial.println("-----------------");
  Serial.print("Left-most: ");
  Serial.println(val1);
  Serial.print("Middle Left: ");
  Serial.println(val2);
  Serial.print("Middle: ");
  Serial.println(val3);
  Serial.print("Middle Right: ");
  Serial.println(val4);
  Serial.print("Right: ");
  Serial.println(val5);

  // Determine the robot's movement based on sensor values
  if (val1 >= 975 && val5 >= 975) {
    straight(); // Go straight
  }
  else if (val2 < 900) {
    left(); // Turn left
  }
  else if (val4 < 790) {
    right(); // Turn right
  }
}

void straight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);

  analogWrite(enA, 50);
  analogWrite(enB, 70);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);

  analogWrite(enA, 100);
  analogWrite(enB, 50);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);

  analogWrite(enA, 50);
  analogWrite(enB, 80);
}
