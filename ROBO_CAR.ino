#define M1_p 9
#define M1_n 10
#define M2_p 11
#define M2_n 12

char val;
void setup()
{
  Serial.begin(9600);
  pinMode(M1_p, OUTPUT);
  pinMode(M1_n, OUTPUT);
  pinMode(M2_p, OUTPUT);
  pinMode(M2_n, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  
}

void loop()
{
  moveForward();
  delay(5000);
  moveBackward();
  delay(5000);
  turnRight();
  delay(5000);
  turnLeft();
  delay(5000);
  moveStop();
  delay(3000);
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
  digitalWrite(8, HIGH);
  digitalWrite(13, HIGH);
}
void moveBackward() {
  digitalWrite(M1_n, HIGH);
  digitalWrite(M2_n, HIGH);
  digitalWrite(M1_p, LOW);
  digitalWrite(M2_p, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(13, HIGH);
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
