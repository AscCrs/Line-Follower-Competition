#include  <Arduino.h>

// Declaración de los pines que controlarana los motores
int Motor1A = 3;   // IN1
int Motor1B = 2;   // IN2
int Motor2C = 7;   // IN3
int Motor2D = 8;   // IN4
int infPin = 6;    // Izquierdo - pin de infrarojos utilizado como entrada digital
int infPin1 = 10;   // Derecho
int valorInf = 0;  // Valor inicial de la lectura digital de los infrarrojos
int valorInf1 = 0;

// Declaración del método para avanzar
void Avanzar(){
    digitalWrite(Motor1A, HIGH);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2C, HIGH);
    digitalWrite(Motor2D, LOW);
}

// Declaración del método para girar a la derecha
void girarDerecha(){
    digitalWrite(Motor1A, HIGH);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2C, LOW);
    digitalWrite(Motor2D, LOW);
}

// Declaración del método para girar a la izquierda
void girarIzquierda(){
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2D, LOW);
    digitalWrite(Motor2C, HIGH);
}

// Declaración del método para detener el vehiculo en caso de detectar una línea negra
void Stop(){
    digitalWrite(Motor1A, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2D, LOW);
    digitalWrite(Motor2C, LOW);
    delay(500);
}

// Configuración de los sensores y los pines
void setup() {
  pinMode(infPin, INPUT);
  pinMode(infPin1, INPUT);
  pinMode(Motor1A, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2D, OUTPUT);
  pinMode(Motor2C, OUTPUT);
  digitalWrite(Motor1A, LOW);
  digitalWrite(Motor1B, LOW);
  digitalWrite(Motor2D, LOW);
  digitalWrite(Motor2C, LOW);
}

// Ejecución continua de todos los métodos
void loop() {
  valorInf = digitalRead(infPin);   // Valor de entrada para el infrarrojo izquierdo
  valorInf1 = digitalRead(infPin1); // Valor de entrada para el infrarrojo derecho
  
  if (valorInf == 0 && valorInf1 == 0) { // Avance 
    Avanzar();
  }

  if(valorInf == 0 && valorInf1 == 1){ // Gira hacia la derecha
    girarDerecha();
  }

  if (valorInf == 1 && valorInf1 == 0) { // Gira hacia la izquierda
    girarIzquierda();
  }

  if (valorInf == 1 && valorInf1 == 1) { // STOP
    Stop();
  }
}