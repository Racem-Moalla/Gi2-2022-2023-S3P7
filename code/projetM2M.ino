

// Définition des numéros de port
const int trigPin = A13;  // Trigger (emission)
const int echoPin = A14;  // Echo    (réception)

// Variables utiles
long duree;   // durée de l'echo
int distance; // distance
int sensorG = A9;
int sensorM = A5;
int sensorD = A3;

#define VG  3
#define AG  2
#define RG  4
#define VD  6
#define AD 5
#define RD  7

int seuil=200;
int erreur=0;
int first=0;
int partie=1;
void setup() {
Serial.begin(9600);
 pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE
pinMode(echoPin, INPUT);  // Configuration du port de l'Echo  comme une ENTREE
  pinMode(sensorG, INPUT);
  pinMode(sensorM, INPUT);
  pinMode(sensorD, INPUT);
  pinMode(VD,OUTPUT);
  pinMode(AD,OUTPUT);
  pinMode(RD,OUTPUT);
  pinMode(VG,OUTPUT);
  pinMode(AG,OUTPUT);
  pinMode(RG,OUTPUT);  
}

void loop() {
  Serial.print(color(sensorG));
  Serial.print(' ');
  Serial.print(color(sensorM));
  Serial.print(' ');
  Serial.print(color(sensorD));
  Serial.println(' ');
  if(partie==1)
  partie1();
  else if(partie==2)
  partie2();
  else if(partie==3)
  partie3();
  else if(partie==4)
  partie4();
 
}
void partie1(){

  if (color(sensorG)=='b'){
       
      tournerLeft(65,65);

    }  
    
     else if (color(sensorM)=='b'){
      avancer(65,65);

    }
    else if (color(sensorD)=='b'){
          tournerRight(65,65);
    }
    else if ((color(sensorG)=='w')&&(color(sensorG)=='w')&&(color(sensorG)=='w')){
          tournerRight(65,65);
    }

 if(distanceOBS()<10)
    {
    while(distanceOBS()<10)
    {
      avancer(0,0);delay(2000);
    }
    partie=2;
    }
}
void partie2(){

   
      if (color(sensorD)=='b'){
          tournerRight(65,65);
    }
     else if (color(sensorM)=='b'){
      avancer(60,60);

    }
  else if (color(sensorG)=='b'){
       
      tournerLeft(60,60);

    } 
    else if ((color(sensorG)=='w')&&(color(sensorG)=='w')&&(color(sensorG)=='w')){
          avancer(60,60);
    }

 if(distanceOBS()<10)
    {
    while(distanceOBS()<10)
    {
      avancer(0,0);delay(2000);
    }
    partie=3;
    }
}
void partie3(){

  if (color(sensorG)=='b'){
       
      tournerLeft(65,65);

    }  
    
     else if (color(sensorM)=='b'){
      avancer(65,65);

    }
    else if (color(sensorD)=='b'){
          tournerRight(65,65);
    }
    else if ((color(sensorG)=='w')&&(color(sensorG)=='w')&&(color(sensorG)=='w')){
      avancer(65,65);delay(200);
          while((color(sensorG)=='w')&&(color(sensorG)=='w')&&(color(sensorG)=='w')){
          avancer(65,65);

          //partie=4;
    }


}
}
void partie4(){

  if (color(sensorG)=='b'){
       
      tournerLeft(65,65);

    }  
    
     else if (color(sensorM)=='b'){
      avancer(65,65);

    }
    else if (color(sensorD)=='b'){
          tournerRight(65,65);
    }
    else if ((color(sensorG)=='w')&&(color(sensorG)=='w')&&(color(sensorG)=='w')){
          tournerRight(65,65);
    }


}

char color(int cap){

  if (analogRead(cap)>seuil){
    return 'b';
  }
  else{
    return 'w';  
   }
  
}





int distanceOBS(){
  // Émission d'un signal de durée 10 microsecondes
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Écoute de l'écho 
  duree = pulseIn(echoPin, HIGH);

  // Calcul de la distance
  distance = duree*0.034/2;

 // Affichage de la distance dans le Moniteur Série
 Serial.print("Distance : ");
 Serial.print(distance);
 Serial.println("cm");
 return  distance;
}
 void avancer(int vitesseG,int vitesseD){
              digitalWrite(AG,HIGH);
              digitalWrite(RG,LOW);
              analogWrite(vitesseG,vitesseD);
              digitalWrite(AD,HIGH);
              digitalWrite(RD,LOW);
              analogWrite(vitesseG,vitesseD);
            }


void tournerRight(int vitesseG,int vitesseD)
{
  digitalWrite(AG,1);
  digitalWrite(RG,0);
  analogWrite(vitesseG,vitesseD);
  digitalWrite(AD,0);
  digitalWrite(RD,1);
  analogWrite(vitesseG,vitesseD);
 
}




void tournerLeft(int vitesseG,int vitesseD)
{
  digitalWrite(AG,0);
  digitalWrite(RG,1);
  analogWrite(vitesseG,vitesseD);
  digitalWrite(AD,1);
  digitalWrite(RD,0);
  analogWrite(vitesseG,vitesseD);
}
