#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h> //Biblio Bluetooth
PulseSensorPlayground pulseSensor;  // Creates an object
///Bluetooth
char inputByte;
char buffer[10];


int PinI = A0;
int PinM = A1;
int Sonido = 8;
int ledV = 6;
int ledR = 7;

int pulsoI;
int pulsoM;
unsigned long previousMicrosTriac1 = 0;
unsigned long previousMicrosTriac2 = 0;
const long intervalTriac1 = 1;
const long intervalTriac2 = 1;

volatile int BPM; // Pulsos por minutos
volatile boolean Pulso = false; // verdadero cuando la onda de pulso es alta, falsa cuando es baja
volatile boolean Qs = false; // Verdadero cuando el arduino busca un pulso del corazón



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // inicio serial a 9600 baudres
pinMode(PinI,INPUT);
pinMode(PinM,INPUT);
pinMode(Sonido, OUTPUT);

}

void loop() {
unsigned currentMicros = micros();
if(currentMicros - previousMicrosTriac1 >= intervalTriac1){
    previousMicrosTriac1 = currentMicros;
  pulsoM = analogRead(PinM);

  if (pulsoI >= 550){
    digitalWrite(ledV,HIGH);
    digitalWrite(ledR,LOW);
}
  else{
    digitalWrite(ledR,HIGH);
    digitalWrite(ledV,LOW);
}


}
if(currentMicros - previousMicrosTriac2 >= intervalTriac2){
  previousMicrosTriac2 = currentMicros;
  pulsoM = analogRead(PinM);

  if (pulsoM >= 550){
    digitalWrite(Sonido,HIGH);
  }
   else{
    digitalWrite(Sonido,LOW);
}
  int BPM = pulseSensor.getBeatsPerMinute();
  Serial.println(BPM); 

}
int BPM = pulseSensor.getBeatsPerMinute();
pulsoM = analogRead(PinM);
sprintf(buffer,"%d,%d",BPM,pulsoM);

//  Serial.println(buffer);
}
