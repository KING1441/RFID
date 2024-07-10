#include <IRremote.h>
#define IR_RECEIVE_PIN 7

int LedPin = 8;
int LedPin2 = 11;
int LedPin3 = 12;


void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN);
  Serial.begin(115200);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  if(IrReceiver.decode()){
    IrReceiver.resume();
    print();

    if(IrReceiver.decodedIRData.command == 21){//BTN +
      digitalWrite(LedPin, HIGH);
    }
    if(IrReceiver.decodedIRData.command == 7){//BTN -
      digitalWrite(LedPin, LOW);
    }
    if(IrReceiver.decodedIRData.command == 94){//btn 3
      digitalWrite(LedPin2, HIGH);
    }
    if(IrReceiver.decodedIRData.command == 8){//BTN 4
      digitalWrite(LedPin2, LOW);
    }
    if(IrReceiver.decodedIRData.command == 12){//BTN 1
      digitalWrite(LedPin3, HIGH);
      digitalWrite(LedPin2, LOW);
    }
    if(IrReceiver.decodedIRData.command == 24){//BTN 2
      digitalWrite(LedPin3, LOW);
      digitalWrite(LedPin2, HIGH);
    }
  }
}

void print(){
  Serial.println("------------");
  Serial.print("ID: ");
  Serial.println(IrReceiver.decodedIRData.command);
  Serial.println("------------");
  Serial.println("");
  Serial.println("");
}
