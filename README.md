# Dungeon-Adventure

Bu proje, C++ kullanılarak yazılmış metin tabanlı macera oyunudur. Oyuncular düşmanları yenerek ve ganimetler toplayarak zindanda ilerler.

## Oyun Mekanikleri

1. Komut

Oyun metin tabanlı olduğundan oyuncu bazı komutları kullanarak oyunu oynar.

Ana menü:
s -- Oyuncunun sağlık, saldırı gücü, envanteri gibi özelliklerini gösterir.
r -- Oyuncu gidebileceği zindan odalarının bilgisini görüntüler
cX -- X 1 ya da 2 olacak şekilde oyuncunun hangi odayı seçtiği belirlenir. (c1: 1. oda, c2: 2. oda)
q -- Oyundan çıkış yapılır.

Savaş:
X -- Oyuncu odadaki düşmanın başındaki sayıyı girerek hangi düşmana vuracağını seçer. (1: 1. düşman, 2: 2.düşman ...)
 
2. Envanter Sistemi:

Oyuncunun 6 slotluk bir envanteri vardır: Kask, Göğüs Zırhı, Silah, Kalkan, Pantolon, Bot.
Her dönüşten sonra oyuncunun seviyesine göre bir öğe düşebilir ve oyuncu bu öğeyi alıp almamaya karar verir.
Eğer alınan öğe aynı türden bir öğe ile değiştirilirse, eski öğe envanterden çıkar ve yeni öğe eklenir.

3. Düşmanlar

Oyunda çeşitli düşmanlar bulunur, her biri farklı sağlık, saldırı ve savunma değerlerine sahiptir.
Oyun tur bazlı ilerler, ilk önce oyuncu bir düşmanı seçer ve vurur daha sonra ölmeyen bütün düşmanlar oyuncuya vurur.

4. Seviye

Düşmanlar yenildiğinde oyuncu deneyim puanı kazanır ve seviye atlar.
Oyuncunun karşılaştığı düşmanların gücü ve sayısı ayrıca düşen eşyalar seviyeye göre belirlenir.

### Lisans

Bu proje, MIT Lisansı ile lisanslanmıştır.