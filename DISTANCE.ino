const int trig = D1;
const int echo = D2;
long dur;
int dis;
void setup() {
  // put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, 0);
delayMicroseconds(2);
digitalWrite(trig, 1);
delayMicroseconds(10);
digitalWrite(trig, 0);
dur = pulseIn(echo, 1);
dis = dur*0.034/2;
Serial.println(dis);
delay(1000);
}
