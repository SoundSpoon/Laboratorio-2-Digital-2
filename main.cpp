
#include <Arduino.h>
#include <stdint.h>

// defino lo que voy a usar en la progra
#define led1 16     
#define led2 4     
#define led3 15    
#define led4 2
#define b1 19      
#define b2 18  
#define swt 35    

// declaro variables
int contando = 0;  
bool lecturab1;
bool lecturab2;
bool eb1 = LOW;
bool eb2 = HIGH;
bool cambio;
unsigned long antesb1 = 0; 
unsigned long antesb2 = 0;
const unsigned long retraso = 100; 


void leds(int pos);
void binario(int pos2);

void setup() {
  // leds como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // botones como entradas
  pinMode(b1, INPUT_PULLDOWN);  
  pinMode(b2, INPUT_PULLUP);
  pinMode(swt, INPUT);  

  // funcion para prender leds con switch case (Ver hasta abajo)
  leds(contando);
  binario(contando);
}

void loop() {
  unsigned long tiempo = millis(); // Guardar el tiempo
  cambio = digitalRead(swt);
if (cambio == LOW)
{
    // Avanzar en los leds
  lecturab1 = digitalRead(b1);
  if (lecturab1 == HIGH && eb1 == LOW && (tiempo - antesb1 > retraso)) {
    contando = (contando + 1) % 4;     
    leds(contando);              
    antesb1 = tiempo;
  }
  eb1 = lecturab1;

  // Retroceder en los leds
  lecturab2 = digitalRead(b2);
  if (lecturab2 == LOW && eb2 == HIGH && (tiempo - antesb2 > retraso)) {
    contando = (contando - 1 + 4) % 4;  
    leds(contando);             
    antesb2 = tiempo;
  }
  eb2 = lecturab2;
}
else{
      // Avanzar en los leds binario
  lecturab1 = digitalRead(b1);
  if (lecturab1 == HIGH && eb1 == LOW && (tiempo - antesb1 > retraso)) {
    contando = (contando + 1) % 15;     
    binario(contando);              
    antesb1 = tiempo;
  }
  eb1 = lecturab1;

  // Retroceder en los leds binario
  lecturab2 = digitalRead(b2);
  if (lecturab2 == LOW && eb2 == HIGH && (tiempo - antesb2 > retraso)) {
    contando = (contando - 1 + 15) % 15;  
    binario(contando);             
    antesb2 = tiempo;
  }
  eb2 = lecturab2;
}



}

// función que escoje cual prender y cual no
void leds(int modo) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  switch (modo) {
    case 0:
      digitalWrite(led1, HIGH);
      break;
    case 1:
      digitalWrite(led2, HIGH);
      break;
    case 2:
      digitalWrite(led4, HIGH);
      break;
    case 3:
      digitalWrite(led3, HIGH);
      break;
  }
}
void binario(int modo2) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  switch (modo2) {
    case 0:
      digitalWrite(led1, HIGH);
      break;
    case 1:
      digitalWrite(led2, HIGH);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
      break;
    case 3:
      digitalWrite(led4, HIGH);
      break;
    case 4:
      digitalWrite(led4, HIGH);
      digitalWrite(led1, HIGH);
    break;
    case 5:
      digitalWrite(led4, HIGH);
      digitalWrite(led2, HIGH);
    break;
    case 6:
      digitalWrite(led4, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
    break;
    case 7:
      digitalWrite(led3, HIGH);
    break;
    case 8:
      digitalWrite(led3, HIGH);
      digitalWrite(led1, HIGH);
    break;
    case 9:
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
    break;
    case 10:
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
    break;
    case 11:
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    break;
    case 12:
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led1, HIGH);
    break;
    case 13:
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
    break;
    case 14:
      digitalWrite(led4, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led1, HIGH);
    break;
  }
}