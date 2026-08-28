#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Belirlenen kurallara uygun rastgele lisans üreten fonksiyon
void lisans_uret(char *anahtar) {
    // Kural 3: İlk karakter mutlaka harf olmalı (Rastgele büyük harf seçiyoruz)
    anahtar[0] = 'A' + (rand() % 26); // A'dan Z'ye rastgele bir harf
    
    // Toplamı 20 olacak şekilde 7 adet rakam belirlemeliyiz
    // (İlk karakter harf, 5. karakter tire olduğu için geriye 7 hane kalıyor)
    int rakamlar[7] = {0}; // Başlangıçta tüm rakamları 0 yapıyoruz
    int toplam = 0;
    
    // Kural 4: Rakamların toplamı tam olarak 20 olana kadar rastgele dağıt
    while (toplam < 20) {
        int rastgele_indeks = rand() % 7; // 0 ile 6 arasında rastgele bir hane seç
        
        // Bir rakam tek haneli (en fazla 9) olabileceği için kontrol ediyoruz
        if (rakamlar[rastgele_indeks] < 9) {
            rakamlar[rastgele_indeks]++;
            toplam++;
        }
    }
    
    // Şimdi belirlediğimiz harfi, tireyi ve rakamları anahtara yerleştiriyoruz
    // Format: XRRR-RRRR (X: Harf, R: Rakam)
    
    anahtar[1] = '0' + rakamlar[0]; // Rakamı karakter yapıp (ASCII) atıyoruz
    anahtar[2] = '0' + rakamlar[1];
    anahtar[3] = '0' + rakamlar[2];
    
    // Kural 2: 5. karakter (indeks 4) tire '-' olmalı
    anahtar[4] = '-';
    
    anahtar[5] = '0' + rakamlar[3];
    anahtar[6] = '0' + rakamlar[4];
    anahtar[7] = '0' + rakamlar[5];
    anahtar[8] = '0' + rakamlar[6];
    
    // Kural 1: Toplam 9 karakter olmalı. 
    // Metnin bittiğini belirtmek için 10. sıraya (indeks 9) bitiş karakterini ekliyoruz.
    anahtar[9] = '\0';
}

int main() {
    // Rastgele sayı üretecini (seed) o anki zamanla başlatıyoruz ki 
    // program her çalıştığında farklı sayılar üretsin
    srand(time(NULL));
    
    char lisans[10]; // 9 karakter + '\0' (bitiş karakteri)
    
    printf("--- Gecerli Lisans Uretici (Keygen) ---\n\n");
    
    // Örnek olarak 5 adet farklı ve geçerli lisans üretelim
    for (int i = 1; i <= 5; i++) {
        lisans_uret(lisans);
        printf("%d. Uretilen Gecerli Lisans: %s\n", i, lisans);
    }
    
    return 0;
}
