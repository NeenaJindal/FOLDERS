int M1_p = 4;
int M1_n = 5;
int M2_p = 6;
int M2_n = 7;
char val;
int IR_r = A0;
int IR_l = A1;
const int trigPin = 10;
const int echoPin = 9;
int pathfollowing = 0;
#include<Servo.h>
#include<NewPing.h>
#define MAX_DISTANCE 200
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
Servo myservo;
int pos = 90;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(M1_p, OUTPUT);
  pinMode(M1_n, OUTPUT);
  pinMode(M2_p, OUTPUT);
  pinMode(M2_n, OUTPUT);
  pinMode(IR_r, INPUT);
  pinMode(IR_l, INPUT);
  Serial.begin(9600);
  myservo.attach(2);
  myservo.write(90);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
}
long distance, distance1, distance2;
void loop()
{
  takedistance();
  if (distance < 5)
  {
    stopthis();
    myservo.write(pos + 90);
    delay(500);
    distance1 = takedistance();
    delay(500);
    myservo.write(pos - 90);
    distance2 = takedistance();
    delay(500);
    myservo.write(90);
    if (distance1 > distance2)
      right();
    delay(5000);
    if (distance2 > distance1)
      left();
    delay(5000);
  }
  stopthis();
  distance = 200;
  if (pathfollowing == 1)
  {
    if (analogRead(IR_l == 0) && analogRead(IR_r == 0))
    {
      forward();
    }
    else if (analogRead(IR_l == 1) && analogRead(IR_r == 0))
    {
      right();
    }
    else if (analogRead(IR_l == 0) && analogRead(IR_r == 1))
    {
      left();
    }
    else if (analogRead(IR_l == 1) && analogRead(IR_r == 1))
    {
      stopthis();
    }
  }
  while (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
  }
  if (val == 'F')
  {
    forward();
  }
  else if (val == 'B')
  {
    backward();
  }
  else if (val == 'R')
  {
    right();
  }
  else if (val == 'L')
  {
    left();
  }
  else if (val == 'S')
  {
    stopthis();
  }
}
void forward()
{
  digitalWrite(M1_p, HIGH);
  digitalWrite(M2_p, HIGH);
  digitalWrite(M1_n, LOW);
  digitalWrite(M2_n, LOW);
}
void backward()
{
  digitalWrite(M1_n, HIGH);
  digitalWrite(M2_n, HIGH);
  digitalWrite(M1_p, LOW);
  digitalWrite(M2_p, LOW);
}
void left()
{
  digitalWrite(M1_p, HIGH);
  digitalWrite(M2_n, HIGH);
  digitalWrite(M1_n, LOW);
  digitalWrite(M2_p, LOW);
}
void right()
{
  digitalWrite(M1_n, HIGH);
  digitalWrite(M2_p, HIGH);
  digitalWrite(M1_p, LOW);
  digitalWrite(M2_n, LOW);
}
void stopthis()
{
  digitalWrite(M1_p, LOW);
  digitalWrite(M2_p, LOW);
  digitalWrite(M1_n, LOW);
  digitalWrite(M2_n, LOW);
  pos = 90;
  myservo.write(pos);
}
long takedistance()
{
  delay(50);                     
  //Serial.print("Ping: ");
  distance = sonar.ping_cm();
  //Serial.print(sonar.ping_cm()); 
  //Serial.println("cm\n");
  delay(1000);
  return distance;
}
