```c

/**
 Projeto Arduino - Robô 
 MazeRunnerBot
  @authores Reginaldo , Anderson e Ryan
*/

// Uso da biblioteca Distance-Sensor by Tin Dao (HC-SR04)
#include <DistanceSensor.h>

constexpr int TrigPin = 2; //Pino Trig do sensor
constexpr int EchoPin = 3; //Pino Echo do sensor
DistanceSensor<TrigPin, EchoPin> sensor;

void setup() {
  //Motor 1
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  // Motor 2
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //Incialização do sensor HC-SR04
  sensor.begin();
  //Iniciar a comunicação serial (teste e calibração do sensor)
  Serial.begin(9600);

}

void loop() {
  // Testar o motor 1
  //digitalWrite(5, LOW); //digitalWrite(pino, 0 ou LOW); (equivale ao GND)
  //analogWrite(6, 255); //analogWrite(pino, valor); PWM (0 a 255) relacionado a velocidade
  // Testar o motor 2
  //digitalWrite(9, LOW); //digitalWrite(pino, 0 ou LOW); (equivale ao GND)
  //analogWrite(10, 255); //analogWrite(pino, valor); PWM (0 a 255)
  // Uso do sensor
  int distancia = sensor.tick();
  if (distancia == sensor.NREADY) {
    return;
  }
  // Teste do sensor
  Serial.println(distancia);
  if(distancia < 10 && distancia != -2) {
  parar();
  delay(500);  
  girarEsquerda();
  delay(350);
  } else {
    moverFrente();
  }

}


//Funções para movimentação do robô
void moverFrente(){
  digitalWrite(5, LOW); //motor 1
  analogWrite(6, 255);  //motor 1
  digitalWrite(9, LOW); //motor 2
  analogWrite(10, 255); //motor 2
}

void parar(){
  digitalWrite(5, LOW); //motor 1
  analogWrite(6, LOW);  //motor 1
  digitalWrite(9, LOW); //motor 2
  analogWrite(10, LOW); //motor 2
}

void moverRe(){
  digitalWrite(6, LOW); //motor 1
  analogWrite(5, 255);  //motor 1
  digitalWrite(10, LOW); //motor 2
  analogWrite(9, 255); //motor 2
}

void girarEsquerda(){
  digitalWrite(6, LOW); //motor 1
  analogWrite(5, 255);  //motor 1
  digitalWrite(9, LOW); //motor 2
  analogWrite(10, 255); //motor 2
}

void girarDireita(){
  digitalWrite(5, LOW); //motor 1
  analogWrite(6, 255);  //motor 1
  digitalWrite(10, LOW); //motor 2
  analogWrite(9, 255); //motor 2
}```
