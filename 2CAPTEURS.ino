
#include "EmonLib.h"
#include  <virtuabotixRTC.h> 
#include <SD.h>
#include <SoftwareSerial.h>
#include <SPI.h>
                  // Utilisation des différentes librairies
             
EnergyMonitor emon1;
EnergyMonitor emon2;
// Créer une instance 

File myFile; // Déclarer le fichier
virtuabotixRTC myRTC(6, 7, 8); //Branchage de l'horloge CLK -> 6, DATA -> 7, RST -> 8
int pinCS = 4;
SoftwareSerial espSerial(5, 6);
String str;

void setup()
{
  Serial.begin(115200);
  espSerial.begin(115200);
  pinMode(pinCS, OUTPUT); 
  emon1.current(0, 49);  //  input pin, calibration. fct qui calcule le courant 
  emon2.current(1, 49);
    // secondes, minutes, hours, jour de la semaine (ex: lundi -> 1), jour, mois, année
  myRTC.setDS1302Time(00, 46, 11, 2, 04, 01, 2022);  //Initialise l'horodatage. Remettre en commentaire après avoir lancé le programme pour la 1re fois

}

void loop()
{
   myRTC.updateTime(); //Met à jour le temps
   
double courant1 = emon1.calcIrms(1480);  // Calcule le courant
double courant2 = emon2.calcIrms(1480);

  Serial.print("Current Date / Time: "); // Ecris "Current Date / Time: "
  Serial.print(myRTC.dayofmonth);    // Ecris le jour du mois       
  Serial.print("/"); // Séparation avec un "/"
  Serial.print(myRTC.month); // Ecris le mois  
  Serial.print("/"); // Séparation avec un "/"
  Serial.print(myRTC.year); // Ecris l'année  
  Serial.print(" ");// Séparation avec un espace
  Serial.print(myRTC.hours);  // Ecris l'heure
  Serial.print(":"); // Séparation avec ":"
  Serial.print(myRTC.minutes); // Ecris les minutes
  Serial.print(":"); // Séparation avec ":"
  Serial.print(myRTC.seconds); // Ecris les secondes
  Serial.println(" "); // Séparation avec un espace
  Serial.print("capteur 1: ");
  Serial.print(courant1); // Ecris la valeur du courant
  Serial.println(" A");
  Serial.print("capteur 2: ");
  Serial.print(courant2);
  Serial.println(" A");
  
  
if (SD.begin()) //Si la commande fonctionne,
  {
    Serial.println("La carte SD est prête à être utilisée."); // On écrit "La carte SD est prête à être utilisée."
   
  } else // Sinon
  {
    Serial.println("L'initialisation de la carte SD a échoué."); // Ecris "L'initialisation de la carte SD a échoué."
    return;
  }

  myFile = SD.open("TEST.txt",FILE_WRITE); // Création du dossier et on écrit 

  if (myFile) { // Si l'on a réussi à ouvrir le fichiet texte alors, 
  Serial.println("Writing to file..."); // On écrit "Writing to file..." sur le moniteur
  myFile.print(myRTC.dayofmonth); // Ecris l'horodatage sur le fichier texte       
  myFile.print("/");
  myFile.print(myRTC.month);
  myFile.print("/");
  myFile.print(myRTC.year);
  myFile.print(" ");
  myFile.print(myRTC.hours);
  myFile.print(":");
  myFile.print(myRTC.minutes);
  myFile.print(":");
  myFile.print(myRTC.seconds);
  myFile.println(" "); // Fin de l'écriture de l'horodatage sur le fichier texte
  myFile.print("capteur 1: ");
  if(courant1<=0.4){
    myFile.print(courant1);
  }
  else if(courant1>0.4 && courant1<=0.7){
    courant1=courant1-0.2;
    myFile.print(courant1);
  }
  else if(courant1>0.7 && courant1<=1.15){
    courant1=courant1-0.15;
    myFile.print(courant1);
  }
  else if(courant1>1.15 && courant1<=1.57){
    courant1=courant1-0.06;
    myFile.print(courant1);
  }
  else if(courant1>1.57 && courant1<=2){
    myFile.print(courant1);
  }
  else if(courant1>2 && courant1<=2.44){
    courant1=courant1+0.06;
    myFile.print(courant1);
  }
  else if(courant1>2.44 && courant1<=2.88){
    courant1=courant1+0.12;
    myFile.print(courant1);
  }
  else if(courant1>2.88 && courant1<=3.36){
    courant1=courant1+0.18;
    myFile.print(courant1);
  }
  else if(courant1>3.36 && courant1<=3.76){
    courant1=courant1+0.24;
    myFile.print(courant1);
  }
  else if(courant1>3.76 && courant1<=4.29){
    courant1=courant1+0.21;
    myFile.print(courant1);
  }
  else if(courant1>4.29 && courant1<=4.66){
    courant1=courant1+0.44;
    myFile.print(courant1);
  }
  else if(courant1>4.66 && courant1<=8.13){
    courant1=courant1+0.87;
    myFile.print(courant1);
  }
  // Ecris la valeur du courant
  myFile.println(" A");
  myFile.print("capteur 2: ");
  if(courant2<=0.4)
  {
    courant2=courant2-0.4;
    myFile.print(courant2);
  }
  else if(courant2>0.4 && courant2<=0.7)
  {
    courant2=courant2-0.2;
    myFile.print(courant2);
  }
  else if(courant2>0.7 && courant2<=1.15)
  {
    courant2=courant2-0.15;
    myFile.print(courant2);
  }
  else if(courant2>1.15 && courant2<=1.57)
  {
    courant2=courant2-0.06;
    myFile.print(courant2);
  }
  else if(courant2>1.57 && courant2<=2)
  {
    myFile.print(courant2);
  }
  else if(courant2>2 && courant2<=2.44)
  {
    courant2=courant2+0.06;
    myFile.print(courant2);
  }
  else if(courant2>2.44 && courant2<=2.88)
  {
    courant2=courant2+0.12;
    myFile.print(courant2);
  }
  else if(courant2>2.88 && courant2<=3.36)
  {
    courant2=courant2+0.18;
    myFile.print(courant2);
  }
  else if(courant2>3.36 && courant2<=3.76)
  {
    courant2=courant2+0.24;
    myFile.print(courant2);
  }
  else if(courant2>3.76 && courant2<=4.29)
  {
    courant2=courant2+0.21;
    myFile.print(courant2);
  }
  else if(courant2>4.29 && courant2<=4.66)
  {
    courant2=courant2+0.44;
    myFile.print(courant2);
  }
  else if(courant2>4.66 && courant2<=8.13)
  {
    courant2=courant2+0.87;
    myFile.print(courant2);
  }
 
  myFile.println(" A");
  myFile.close(); //Ferme le fichier
  Serial.println("Done.");  // Ecris sur le moniteur "Done."
  }
  else { //Sinon
  Serial.println("erreur test.txt"); // Ecris sur le moniteur "erreur test.txt"
  
Serial.println(courant1); 
Serial2.print(courant2);
str =String(courant1)+String(courant2);
espSerial.println(courant1);
espSerial.println(courant2);

}

delay(5000); //délai de 150 ms

}
