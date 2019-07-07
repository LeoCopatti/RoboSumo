#include <NewPing.h>

//Motor A - Direita
#define VelMotorA 10
#define MotorA1 5
#define MotorA2 4

//Motor B - Esquerda
#define VelMotorB 11
#define MotorB1 3
#define MotorB2 2

//Sensores Infravermelhos
#define InfraFrente A4
#define InfraAtras A5

//Sensores Ultrassonicos
#define TriggerFrente 13
#define EchoFrente 12
#define TriggerEsquerda 7
#define EchoEsquerda 6
#define TriggerDireita 9
#define EchoDireita 8

//Velocidades - Foi necessario usar o const int pois os valores nao podem ser definidos com o #define
#define ReducaoVirada 70
const int VelocidadeMaxima = 255;
const int VelocidadeNormal = 110;

//Variaveis para o ultrassonico
long duracao;
int distancia;

NewPing sonarFrente(TriggerFrente, EchoFrente, 270);
NewPing sonarEsquerda(TriggerEsquerda, EchoEsquerda, 270);
NewPing sonarDireita(TriggerDireita, EchoDireita, 270); 

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
  Serial.begin(9600);
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
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorB1, HIGH);

  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB2, LOW);
  analogWrite(VelMotorB, VelocidadeMaxima);
  analogWrite(VelMotorA, VelocidadeMaxima);
}

int SensorSonar(int trigger,int echo)
{
 
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duracao = pulseIn(echo, HIGH);
   Serial.println( trigger );
  Serial.println(echo );
  distancia = duracao / 58.2;
   Serial.println(distancia);
  delay(5000);
  if (!distancia)
  {
    return 1000;
  }
  else
  {
    return distancia;
  }
}

int verificaSonar(int son)
{
  if (son == 1)
  {
    distancia = sonarFrente.ping_median(5);
    Serial.println(sonarFrente.convert_cm(distancia));
    return sonarFrente.convert_cm(distancia);
  }
  else if (son == 2)
  {
    distancia = sonarEsquerda.ping_median(5);
    delay(100);  
    Serial.println(sonarFrente.convert_cm(distancia));
    return sonarFrente.convert_cm(distancia);
  }
  else if (son == 3)
  {
    distancia = sonarDireita.ping_median(5);
    delay(100); 
    Serial.println(sonarFrente.convert_cm(distancia));
    return sonarFrente.convert_cm(distancia);
  }
  
}
void loop() {
delay(50);
 /* if (digitalRead(InfraFrente) == LOW)
  {
    Serial.println("Infra Frente");
    AndarRe();
    delay(1000);
    VirarEsquerda();
    delay(2000);
    AndarFrente();
  }
  else if (digitalRead(InfraAtras) == LOW)
  {
    Serial.println("Infra Atras");
    AcelerarMaximo();
    delay(1000);
  }
  else{*/
    if (verificaSonar(1) <= 15)
    {
      Serial.println("Frente ");
      AcelerarMaximo();
    }
    else if (verificaSonar(2) <= 15)
    {
      Serial.println("Esquerda ");
      VirarEsquerda();
    }
   /* else if (verificaSonar(3) <= 15)
    {
      Serial.println("Direita ");
      VirarDireita();
    }*/
    else
    {
      Serial.println("Else");
       AndarFrente();
    }
  //}
}
