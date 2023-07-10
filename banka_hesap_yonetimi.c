#include <stdio.h>
#include <stdlib.h>

struct BankaHesabi {
    char isim[50];
    int hesapNumarasi;
    double bakiye;
};

void kayitOlustur(struct BankaHesabi *hesaplar, int *toplamHesap) {
    printf("Isim: ");
    scanf("%s", hesaplar[*toplamHesap].isim);
    printf("Hesap Numarasi: ");
    scanf("%d", &hesaplar[*toplamHesap].hesapNumarasi);
    printf("Baslangic Bakiyesi: ");
    scanf("%lf", &hesaplar[*toplamHesap].bakiye);
    
    (*toplamHesap)++;
}

void hesaplariListele(struct BankaHesabi *hesaplar, int toplamHesap) {
    for (int i = 0; i < toplamHesap; i++) {
        printf("Hesap Numarasi: %d\n", hesaplar[i].hesapNumarasi);
        printf("Isim: %s\n", hesaplar[i].isim);
        printf("Bakiye: %.2lf\n\n", hesaplar[i].bakiye);
    }
}

int hesapBul(struct BankaHesabi *hesaplar, int toplamHesap, int hesapNumarasi) {
    for (int i = 0; i < toplamHesap; i++) {
        if (hesaplar[i].hesapNumarasi == hesapNumarasi) {
            return i;
        }
    }
    return -1;
}

void bakiyeGoruntule(struct BankaHesabi *hesaplar, int toplamHesap, int hesapNumarasi) {
    int hesapIndexi = hesapBul(hesaplar, toplamHesap, hesapNumarasi);
    if (hesapIndexi != -1) {
        printf("Hesap Numarasi: %d\n", hesaplar[hesapIndexi].hesapNumarasi);
        printf("Isim: %s\n", hesaplar[hesapIndexi].isim);
        printf("Bakiye: %.2lf\n", hesaplar[hesapIndexi].bakiye);
    } else {
        printf("Hesap bulunamadi!\n");
    }
}

void bakiyeGuncelle(struct BankaHesabi *hesaplar, int toplamHesap, int hesapNumarasi, double miktar) {
    int hesapIndexi = hesapBul(hesaplar, toplamHesap, hesapNumarasi);
    if (hesapIndexi != -1) {
        hesaplar[hesapIndexi].bakiye += miktar;
        printf("Bakiye guncellendi.\n");
    } else {
        printf("Hesap bulunamadi!\n");
    }
}

int main() {
    struct BankaHesabi hesaplar[100];
    int toplamHesap = 0;
    
    int secim;
    int hesapNumarasi;
    double miktar;
    
    while (1) {
        printf("1. Kayit Olustur\n");
        printf("2. Hesaplari Listele\n");
        printf("3. Bakiye Goruntule\n");
        printf("4. Bakiye Guncelle\n");
        printf("0. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                kayitOlustur(hesaplar, &toplamHesap);
                break;
            case 2:
                hesaplariListele(hesaplar, toplamHesap);
                break;
            case 3:
                printf("Hesap Numarasi: ");
                scanf("%d", &hesapNumarasi);
                bakiyeGoruntule(hesaplar, toplamHesap, hesapNumarasi);
                break;
            case 4:
                printf("Hesap Numarasi: ");
                scanf("%d", &hesapNumarasi);
                printf("Miktar: ");
                scanf("%lf", &miktar);
                bakiyeGuncelle(hesaplar, toplamHesap, hesapNumarasi, miktar);
                break;
            case 0:
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
