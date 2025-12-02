📡 ZigBee Tabanlı Kablosuz Mesafe Ölçüm Ağı
(Arduino UNO + E18-MS1PA2-IPX ZigBee Modülleri)

Bu proje, Sayın Hasan Serdar hocamızın direktifleriyle hazırlanmış Arduino tabanlı iki düğümün (Gönderici–Alıcı) ZigBee protokolü üzerinden haberleşmesini sağlayan basit ve işlevsel bir Kablosuz Sensör Ağı (WSN) uygulamasıdır. Gönderici düğüm, HC-SR04 ultrasonik sensör ile mesafeyi ölçer ve veriyi ZigBee üzerinden kablosuz olarak iletir. Alıcı düğüm ise gelen verileri işleyerek mesafe değişimlerini gerçek zamanlı olarak kullanıcıya bildirir.

🔧 Sistem Mimarisi
Gönderici Düğüm
HC-SR04 ultrasonik sensör ile mesafe ölçer
Ölçülen veriyi ZigBee ile kablosuz olarak gönderir
Arduino üzerinden sensör okuma ve paket iletim işlemleri yürütülür

Alıcı Düğüm
ZigBee modülünden gelen sensör verisini alır
Mesafe değişimini tespit eder
Seri port üzerinden kullanıcıya bilgi verir (uyarı/mesafe değeri)

📡 Kullanılan Donanımlar

Arduino UNO (Gönderici + Alıcı)
E18-MS1PA2-IPX ZigBee modülleri
HC-SR04 Ultrasonik Mesafe Sensörü
USB-TTL Dönüştürücü (ZigBee konfigürasyonu için)

🛠️ Özellikler

Güvenilir ZigBee haberleşmesi
Noktadan noktaya (point-to-point) veri iletimi
Gerçek zamanlı mesafe takibi
Düşük güç tüketimli WSN mimarisi
Basit, modüler ve geliştirilebilir altyapı

🚀 Kurulum

ZigBee modüllerini AT komutlarıyla Coordinator ve End Device olarak yapılandırın.
Gönderici düğüme HC-SR04 sensörünü bağlayın.
Arduino kodlarını sender/ ve receiver/ klasörlerinden yükleyin.
Alıcı tarafında Seri Monitör üzerinden gelen verileri takip edin.

![sender](https://github.com/user-attachments/assets/0c4bf1e3-42d1-4355-9e56-84be2e044ed6)
![receiver](https://github.com/user-attachments/assets/f5641086-799f-4071-ae43-5d514d7e3433)
