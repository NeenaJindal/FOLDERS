int m1 = 4;
int m2 = 5;
int m3 = 6;
int m4 = 7;
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
  if(voice == "forward")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
   }
   if(voice == "backward")
  {
    digitalWrite(m2, HIGH);
    digitalWrite(m1, LOW);
    digitalWrite(m4, HIGH);
    digitalWrite(m3, LOW);
   }
   if(voice == "left")
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
   }
   if(voice == "right")
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
   }
  else if(voice == "stop")
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
 }
}
