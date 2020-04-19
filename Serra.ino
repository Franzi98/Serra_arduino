#include <LiquidCrystal_I2C.h>

#include <Mouse.h>

#include <Stepper.h>

/*
 * 
 * 0 ~300 : dry soil ( terreno asciutto )
 * 300~700 : humid soil ( terreno umido )
 * 700~950 : in water ( in acqua )
 *  A0= umidità terreno

 */
#define rele 12
#define sensore_uno A0
byte statorele;
int umidita=0;
bool POMPA;
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(rele, OUTPUT);
  pinMode(sensore_uno, INPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  // put your setup code here, to run once:

}

void loop() {
  umidita=analogRead(sensore_uno);
  umidita=map(umidita, 1023, 275, 0 , 100);
  if (umidita<70) {
    digitalWrite(rele,LOW);
    statorele=HIGH;
    Serial.print("Umidità:");
    Serial.print(umidita);
    Serial.println("%");
    stato_pompa();
    infoschermo();
    
  }
   else {
    digitalWrite(rele,HIGH);
    statorele=LOW;
    Serial.print("Umidità:");
    Serial.print(umidita);
    Serial.println("%");
    stato_pompa();
    infoschermo();
   }
   delay(10000);
  }
  // put your main code here, to run repeatedly:

void infoschermo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Umidita ");
  lcd.print(umidita);
  lcd.print(" %");
  lcd.setCursor(0,1);
  lcd.print("Stato pompa: ");
  if (POMPA==true){
    lcd.print("ON");
  }
  else{
    lcd.print("OFF");
    }
  }
void stato_pompa(){
  if(statorele==HIGH){
    POMPA=true;
    }
    else{
      POMPA=false;
      }
  

}
  