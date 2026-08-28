#include <stdio.h>
#include <string.h>
#include <ctype.h> // isalpha ve isdigit fonksiyonları için

// Lisans kontrol fonksiyonu (Geçerliyse 1, değilse 0 döndürür)
int lisans_kontrol(const char *anahtar) {
    // Kural 1: Uzunluk tam olarak 9 karakter olmalı
    if (strlen(anahtar) != 9) {
        return 0; 
    }

    // Kural 2: 5. karakter (indeks 4) tire '-' olmalı
    if (anahtar[4] != '-') {
        return 0;
    }

    // Kural 3: İlk karakter harf olmalı
    if (!isalpha(anahtar[0])) {
        return 0;
    }

    // Kural 4: İçindeki rakamların toplamı 20 olmalı
    int toplam = 0;
    for (int i = 0; i < 9; i++) {
        if (isdigit(anahtar[i])) {
            // Karakteri tam sayıya çevir (ASCII tablosuna göre '0' çıkarılarak)
            toplam += anahtar[i] - '0'; 
        }
    }

    if (toplam != 20) {
        return 0;
    }

    return 1; // Tüm kuralları geçti
}
int uygulama(){
  printf("Uygulamaya başarıyla eriştin.");
  return 0;
}
int main() {
    char girilen_lisans[50];

    // Geçerli bir örnek: A550-5500 (5+5+0+5+5+0+0 = 20)
    printf("Lisans anahtarini girin (Ornek: A550-5500): ");
    scanf("%49s", girilen_lisans);

    if (lisans_kontrol(girilen_lisans)) {
        printf("Lisans dogrulandi! Programa erisim saglandi.\n");
        uygulama();
    } else {
        printf("HATA: Gecersiz lisans. Anahtar kurallara uymuyor.\n");
    }

    return 0;
}
