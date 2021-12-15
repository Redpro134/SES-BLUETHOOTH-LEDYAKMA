#include <SoftwareSerial.h>

#include <softwareserial.h>
int veri; //Bluetooth üzerinden okuduğumuz değişken.
int kirmiziPin = 9; //RGB Ledin kırmızı bacağının takılacağı pin
int yesilPin = 10; //RGB Ledin yeşil bacağının takılacağı pin       
int maviPin = 11; //RGB Ledin mavi bacağının takılacağı pin
void setup() {
  Serial.begin(9600); //Seri haberleşmeyi başlatıyoruz.
  pinMode(kirmiziPin, OUTPUT); //Kırmızı pinini OUTPUT olarak ayarlıyoruz.
  pinMode(yesilPin, OUTPUT); //Yeşl pinini OUTPUT olarak ayarlıyoruz.
  pinMode(maviPin, OUTPUT); //Mavi pinini OUTPUT olarak ayarlıyoruz.
}
void loop() {
  if (Serial.available()){ //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read(); //S& gt; 0eri haberleşmeden gelen veriyi okuyoruz.
  }
  if (veri == 'k') { //Seri haberleşmeden k harfi geldiğinde bu kısım çalışır.
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, LOW);
  } else if (veri == 'y') { //Seri haberleşmeden y harfi geldiğinde bu kısım çalışır.
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, HIGH);
  } else if (veri == 'm') { //Seri haberleşmeden m harfi geldiğinde bu kısım çalışır.
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, LOW);

    
  } else if (veri == 'a') { //Seri haberleşmeden a harfi geldiğinde bu kısım çalışır.
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, LOW);

    
  } else { //Seri haberleşmeden tanımlanmayan veri geldiğinde bu kısım çalışır.
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, HIGH);
  }
}
