// C++ code
// Programador: José Carlos
// 29/04/2022

const int pinoTemp = A0;
const int pinoBuzzer = 10;
const int ledRed = 11;
const int ledGreen = 12;
const int ledBlue = 13;

float temperatura;
float voltage;

void setup() {
  Serial.begin(9600);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);  
}

void loop() {
  delay(2000);
  int valor = analogRead(pinoTemp);
  voltage = valor * (5000 / 1024.0);
  temperatura = (voltage - 500) / 10;
  Serial.println(temperatura);
  
  if(isnan(temperatura)){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, HIGH);
  }else{
    if(temperatura > 30 && temperatura < 50 ){
      
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, HIGH);
      tone(pinoBuzzer, 100);
      
    }else if(temperatura > 50 && temperatura < 70 ){
      
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledBlue, LOW);
      tone(pinoBuzzer, 500);
      
    }else if(temperatura > 70){
      
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
      tone(pinoBuzzer, 1000);
    }
  }
}
