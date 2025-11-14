#include <SoftwareSerial.h>

SoftwareSerial zigbee(2, 3); // RX, TX (Göndericinin TX'i, buranın RX'i)

void setup() {
Serial.begin(9600); // Seri Monitör Hızı 9600 OLMALI!
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
} }
