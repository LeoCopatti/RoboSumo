//Motor A - Direita
#define VelMotorA 11
#define MotorA1 12
#define MotorA2 13

//Motor B - Esquerda
#define VelMotorB 10
#define MotorB1 9
#define MotorB2 8

//Sensores Infravermelhos
#define InfraFrente 7
#define InfraAtras 6

//Sensores Ultrassonicos
#define TriggerFrente 5
#define EchoFrente 4
#define TriggerEsquerda 3
#define EchoEsquerda 2
#define TriggerDireita 1
#define EchoDireita 0

//Velocidades - Foi necessario usar o const int pois os valores nao podem ser definidos com o #define
#define ReducaoVirada 70
const int VelocidadeMaxima = 255;
const int VelocidadeNormal = 170;

void setup() {

  pinMode(VelMotorA, OUTPUT);
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(VelMotorB, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
  pinMode(InfraFrente, INPUT);
  pinMode(InfraAtras, INPUT);
  pinMode(TriggerDireita, OUTPUT);
  pinMode(TriggerEsquerda, OUTPUT);
  pinMode(TriggerFrente, OUTPUT);
  pinMode(EchoDireita, INPUT);
  pinMode(EchoEsquerda, INPUT);
  pinMode(EchoFrente, INPUT);

}

void VirarEsquerda(){
  analogWrite(VelMotorB, ReducaoVirada);
  analogWrite(VelMotorA, VelocidadeNormal);
}

void VirarDireita(){
  analogWrite(VelMotorA, ReducaoVirada);
  analogWrite(VelMotorB, VelocidadeNormal);
}

void AndarFrente(){
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorB1, HIGH);

  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB2, LOW);
  
  analogWrite(VelMotorB, VelocidadeNormal);
  analogWrite(VelMotorA, VelocidadeNormal);
}

void AndarRe(){  
  digitalWrite(MotorA2, HIGH);
  digitalWrite(MotorB2, HIGH);
  
  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorB1, LOW);
  
  analogWrite(VelMotorB, VelocidadeNormal);
  analogWrite(VelMotorA, VelocidadeNormal);
}

void AcelerarMaximo(){
  analogWrite(VelMotorB, VelocidadeMaxima);
  analogWrite(VelMotorA, VelocidadeMaxima);
}

void loop() {

}
