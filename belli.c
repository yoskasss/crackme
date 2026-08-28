#include <stdio.h>
#include <string.h>

int main() {
    // Geçerli lisans anahtarımızı tanımlıyoruz
    char gecerli_lisans[] = "ABCD-1234-EFGH-5678";
    char girilen_lisans[50];

    printf("Lutfen lisans anahtarinizi girin: ");
    
    // Kullanıcıdan lisans anahtarını alıyoruz
    // scanf, boşluk karakterine kadar olan kısmı alır
    scanf("%49s", girilen_lisans); 

    // Girilen anahtar ile geçerli anahtarı karşılaştırıyoruz
    // strcmp fonksiyonu iki metin aynıysa 0 döndürür
    if (strcmp(girilen_lisans, gecerli_lisans) == 0) {
        printf("Lisans dogrulandi! Programa erisim saglandi.\n");
    } else {
        printf("HATA: Gecersiz lisans anahtari. Erisim reddedildi.\n");
    }

    return 0;
}
