#include <Servo.h> //Servo Motorumuzun Kütüphanesi
#include <LiquidCrystal.h> //LCD Ekranımızın Kütüphanesi

//Pinlerimizin girislerini belirledim...
const int echoPin = 6; 
const int trigPin = 7;
const int buzzerPin = 8;
const int servoPin = 9;
const int ledPin = 13;

//"Long" tipinde suremizi ve "int" tipinde uzaklik degiskenlerimizi tanimladim...
long sure;
int uzaklik;

//LCD'mizin baglanti pinlerini belirledim...
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//"cm" cinsinden ultrasonik sensorumuzun maks. ve min. olcecegi mesafeleri belirledim...
int maximumRange = 30;
int minimumRange = 0;

//Servomuzu kodumuzda kullanmak icin "myServo" isminde bir degisken tanimladim...
Servo myServo;
int pos = 0; //Servo motorun pozisyonunu belirtmek icin "pos" isminde bir degisken tanimladim.

void setup() {
 pinMode(trigPin, OUTPUT);      //"trig" pini CİKİS
 pinMode(echoPin, INPUT);       //"echo" pini GİRİS
 pinMode(buzzerPin,OUTPUT);     //"buzzer" pini CİKİS
 pinMode(ledPin, OUTPUT);       //"led" pini CİKİS
 lcd.begin(16,2);               //lcd ekranimizi hazirliyoruz...
 myServo.attach(servoPin);      //Servomuzu "attach" fonksiyonu ile hazirliyoruz...
}

//Dongu program kodlarimiz...
void loop() {
  for(pos=0; pos<=175; pos+=5){                        //Servo motor pozisyonu 0 dereceden 175 dereceye +5 derece artarak ilerlesin.
    myServo.write(pos);                                //"pos" degiskeninin degerini servo motorumuza bildirdim...
    
    int olcum = mesafe(maximumRange, minimumRange);    //"olcum" isminde bir degisken tanimlayip bunu "mesafe" ismindeki degiskenin degerine esitledim. 
    melodi(olcum*10);                                  //"melodi" ismindeki degiskenimizin degerini "olcum" degiskeninden gelen degerin 10 katı olarak belirledim
                                                       //Bu deger buzzer'ın ses hızına etki edecektir!

    
    digitalWrite(trigPin,LOW);                         //HC-SR04 sensorunun trig pinini sifirladim...
    delayMicroseconds(5);                              //Gecikme suresi
    digitalWrite(trigPin,HIGH);                        //Trig pininden sinyal cikisi
    delayMicroseconds(10);                             //Gecikme suresi
    digitalWrite(trigPin,LOW);                         //Trig pini sifirladik.
    sure = pulseIn(echoPin,HIGH);                      //Echo pini 5V olunca buraya kadar gecen sureyi olcer.
    uzaklik = sure * 0.0345/2;                         //Ses hizi/sesin gidis+donusu(2)

    lcd.clear();                                       //LCD yi baslangicta sifirlariz.
    lcd.setCursor(0,0);                                //LCD 1. Satiri hazirlariz...
    lcd.print("Uzaklik:");                             //"Uzaklik:" ismini yazdiririz...
    lcd.setCursor(0,1);                               
    lcd.print(uzaklik);
    lcd.print("cm");
    
    delay(15);
  }

  for(pos=175; pos>=0; pos-=5){                        //Servo motor pozisyonu 175 dereceden 0 dereceye -5 derece azalarak ilerlesin.
    myServo.write(pos);
    
    int olcum = mesafe(maximumRange, minimumRange);
    melodi(olcum*10);
  
    digitalWrite(trigPin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    sure = pulseIn(echoPin,HIGH);
    uzaklik = sure * 0.0345/2;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Uzaklik:");
    lcd.setCursor(0,1);
    lcd.print(uzaklik);
    lcd.print("cm");
    
    delay(15);
  }
}

int mesafe(int maxRange,int minRange){
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH); //Echo pini 5V olunca buraya kadar gecen sureyi olcer.
  distance = sure / 58.2;
  delay(50);

  if(distance >= maxRange || distance <= minRange)
  return 0;
  return distance;
}


int melodi(int dly){
  tone(buzzerPin, 880);                   //Buzzer'dan cikan ses siddetini belirledik.
  digitalWrite(ledPin,HIGH);              //Buzzer her calistiginda ledimiz calissin.
  delay(dly);                             //Gecikme süresi.
  noTone(buzzerPin);                      //Buzzer calisiyorsa dursun.
  digitalWrite(ledPin,LOW);               //Buzzer calismadigindan ledimiz sonsun...
  delay(dly);
  
}
