#include <NewPing.h>
#include <Servo.h>
#define TRIG_PIN A3
#define ECHO_PIN A2
#define MAX_DISTANCE 200
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
int M1_p = 4;
int M1_n = 5;
int M2_p = 6;
int M2_n = 7;
Servo myservo;
int distance = 100;
void setup() {
  myservo.attach(11);
  myservo.write(115);
  digitalWrite(13, HIGH);
  delay(100);
  Serial.begin(9600);
}
char val;
void loop() {
  int lookRight()
  {
    myservo.write(50);
    delay(500);
    int distance = readPing();
    delay(100);
    return distance;
  }

  int lookLeft()
  {
    myservo.write(170);
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115);
    return distance;
    delay(100);
  }

  int readPing() {
    delay(70);
    int cm = sonar.ping_cm();
    if (cm == 0)
    {
      cm = 250;
    }
    return cm;
  }

  void moveStop() {
    digitalWrite(M1_p, LOW);
    digitalWrite(M2_p, LOW);
    digitalWrite(M1_n, LOW);
    digitalWrite(M2_n, LOW);
  }

  void moveForward() {
    digitalWrite(M1_p, HIGH);
    digitalWrite(M2_p, HIGH);
    digitalWrite(M1_n, LOW);
    digitalWrite(M2_n, LOW);
  }

  void moveBackward() {
    digitalWrite(M1_n, HIGH);
    digitalWrite(M2_n, HIGH);
    digitalWrite(M1_p, LOW);
    digitalWrite(M2_p, LOW);
  }

  void turnRight() {
    digitalWrite(M1_n, HIGH);
    digitalWrite(M2_p, HIGH);
    digitalWrite(M1_p, LOW);
    digitalWrite(M2_n, LOW);
  }

  void turnLeft() {
    digitalWrite(M1_p, HIGH);
    digitalWrite(M2_n, HIGH);
    digitalWrite(M1_n, LOW);
    digitalWrite(M2_p, LOW);
  }
  void obstacleavoiding(){
    int distanceR = 0;
    int distanceL =  0;
    delay(40);

    if (distance <= 15)
    {
      moveStop();
      delay(100);
      moveBackward();
      delay(1000);
      moveStop();
      delay(200);
      distanceR = lookRight();
      delay(200);
      distanceL = lookLeft();
      delay(200);

      if (distanceR >= distanceL)
      {
        myservo.write(115);
        turnRight();
        delay(800);
      } else
      {
        myservo.write(115);
        turnLeft();
        delay(800);
      }
    } else
    {
      moveForward();
    }
    distance = readPing();

  }
}
