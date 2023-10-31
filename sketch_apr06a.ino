int M1 = 8;
int M2 = 9;
int M3 = 10;
int M4 = 11;
int M5 = 12;
int M6 = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(M5, OUTPUT);
  pinMode(M6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Forward");
  digitalWrite(M1, 1);
  digitalWrite(M2, 1);
  digitalWrite(M3, 0);
  digitalWrite(M4, 1);
  digitalWrite(M5, 0);
  digitalWrite(M6, 1);
  delay(5000);

  Serial.println("Backward");
  digitalWrite(M1, 1);
  digitalWrite(M2, 0);
  digitalWrite(M3, 1);
  digitalWrite(M4, 0);
  digitalWrite(M5, 1);
  digitalWrite(M6, 1);
  delay(5000);

  Serial.println("Right");
  digitalWrite(M1, 1);
  digitalWrite(M2, 1);
  digitalWrite(M3, 0);
  digitalWrite(M4, 0);
  digitalWrite(M5, 1);
  digitalWrite(M6, 1);
  delay(5000);

  Serial.println("Left");
  digitalWrite(M1, 1);
  digitalWrite(M2, 0);
  digitalWrite(M3, 1);
  digitalWrite(M4, 1);
  digitalWrite(M5, 0);
  digitalWrite(M6, 1);
  delay(5000);

  Serial.println("Stop");
  digitalWrite(M1, 0);
  digitalWrite(M2, 0);
  digitalWrite(M3, 0);
  digitalWrite(M4, 0);
  digitalWrite(M5, 0);
  digitalWrite(M6, 0);
  delay(3000);
}
