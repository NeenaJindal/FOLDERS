#define m1 4
#define m2 5
#define m3 6
#define m4 7
void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())
  {
    String voice = Serial.readString();
    Serial.println(voice);
    if (voice == "myroom to bedroom") {
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Stop();
    }
    else if (voice == "myroom to kitchen") {
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Stop(); delay();
    }
    else if (voice == "myroom to lobby") {
      Forward(); delay);
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Stop();
    }
    else if (voice == "bedroom to kitchen") {
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Stop(); delay();
    }
    else if (voice == "bedroom to lobby") {
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Stop();
    }
    else if (voice == "bedroom to myroom") {
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Stop();
    }
    else if (voice == "kitchen to lobby") {
      Backward(); delay();
      Left(); delay();
      Stop();
    }
    else if (voice == "kitchen to bedroom") {
      Backward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Stop();
    }
    else if (voice == "kitchen to myroom") {
      Backward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Stop();
    }
    else if (voice == "lobby to myroom") {
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Stop();
    }
    else if (voice == "lobby to bedroom") {
      Right(); delay();
      Forward(); delay();
      Right(); delay();
      Forward(); delay();
      Left(); delay();
      Forward(); delay();
      Left(); delay();
      Stop();
    }
    else if (voice == "lobby to kitchen") {
      Right(); delay();
      Forward(); delay();
      Stop();
    }
 }
}
void Forward() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void Backward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void Right() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void Left() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void Stop() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
