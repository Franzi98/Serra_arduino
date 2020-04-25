#include <LiquidCrystal_I2C.h>

#include <Mouse.h>

#include <Stepper.h>

#define pin_pompa 8
#define sensore_uno A0

int umidita=0;
bool POMPA;
bool GIORNO;
int luce;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(pin_pompa, OUTPUT);
  pinMode(sensore_uno, INPUT);
  digitalWrite(pin_pompa,LOW);
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  // put your setup code here, to run once:

}

void loop(){
  leggi_umidita();
  infoschermo();
  if(POMPA){
    digitalWrite(pin_pompa, HIGH);
    }
    else{
      digitalWrite(pin_pompa, LOW);
      }
  }  
void leggi_umidita(){
    umidita=1024-analogRead(sensore_uno);
    umidita=map(umidita, 0, 1024, 0, 100);
    if(umidita<50){
      POMPA=true;
      } else {
        POMPA=false;
        }
  }
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
    delay(1000);
  }
