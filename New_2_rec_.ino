// Arduino mega

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(48, 49);
const byte address[6] = "85236";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

int data[7];

void loop(){
  if (radio.available()) {
    radio.read(&data, sizeof(data));
    for(int i=0; i<7; i++){        //important
      Serial.print(data[i]);
      Serial.print(" ");
    }
    Serial.println("");
  }

int BUTTON1 = data[0];
int BUTTON2 = data[1];
int BUTTON3 = data[2];
int BUTTON4 = data[3];
int BUTTON5 = data[4];
int BUTTON6 = data[5];
int BUTTON7 = data[6];

}
