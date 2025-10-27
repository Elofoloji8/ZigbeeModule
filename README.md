# ZigbeeModule

alıcı:

#include <SoftwareSerial.h>

SoftwareSerial zigbee(2, 3); // RX, TX (Göndericinin TX'i, buranın RX'i)

void setup() {
  Serial.begin(9600);  // Seri Monitör Hızı 9600 OLMALI!
  zigbee.begin(9600);
  Serial.println("Alici hazir...");
}

void loop() {
  if (zigbee.available()) {
    String s = zigbee.readStringUntil('\n'); // '\n' karakterine kadar oku
    
    // String'in başındaki/sonundaki gereksiz boşlukları temizle
    s.trim(); 
    
    // Sadece geçerli bir veri (boş olmayan) varsa yazdır
    if (s.length() > 0) {
      // Gelen veri zaten "MESAFE:XX.XXcm" formatında olduğu için direkt yazdırabiliriz:
      Serial.println("Gelen Veri: " + s);
    }
  }
}


Verici:
#include <SoftwareSerial.h>

#define trigPin 8
#define echoPin 7
SoftwareSerial zigbee(2, 3); // RX, TX  (10 = RX from ZigBee, 15 = TX to ZigBee)

void setup() {
  Serial.begin(9600);      // PC'ye bilgi için
  zigbee.begin(9600);     // ZigBee ile haberleşme
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(100);
}

void loop() {
  long duration;
  float distanceCm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // timeout 30 ms
  if (duration == 0) {
    distanceCm = -1; // no echo
  } else {
    distanceCm = (duration / 2.0) * 0.0343;
  }

  // Gönderilecek string
  String out = "MESAFE:" + String(distanceCm, 2) + "cm";
  zigbee.println(out);   // ZigBee'ye gönder
  Serial.println("Gonderildi -> " + out); // PC'ye log

  delay(500); // yarım saniye
}



