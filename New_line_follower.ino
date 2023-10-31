#define R A0
#define L A1
#define M1_p 4
#define M1_n 5
#define M2_p 6
#define M2_n 7
int valr = 1;
int vall = 1;
void setup(){
  pinMode(R, INPUT);
  pinMode(L, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  Serial.begin(9600);
}
void loop(){
  valr = digitalRead(R);
  vall = digitalRead(L);
  Serial.print("RIGHT=");
  Serial.println(valr);
  Serial.print("LEFT=");
  Serial.println(vall);
  delay(10);
  if((valr == 1) && (vall == 1)){
    moveStop();
  }
  if((valr == 0) && (vall == 0)){
    moveForward();
  }
  if((valr == 0) && (vall == 1)){
    turnRight();
  }
  if((valr == 1) && (vall == 0)){
    turnLeft();
  }
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
void moveStop() {
  digitalWrite(M1_p, LOW);
  digitalWrite(M2_p, LOW);
  digitalWrite(M1_n, LOW);
  digitalWrite(M2_n, LOW);
}
