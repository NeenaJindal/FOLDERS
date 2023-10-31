const int trigPin = A3;
const int echoPin = A2;

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13, OUTPUT);
digitalWrite(13, 1);
Serial.begin(9600);
}
long duration, distance;

void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;
Serial.print(distance);
delay(1000);

}
