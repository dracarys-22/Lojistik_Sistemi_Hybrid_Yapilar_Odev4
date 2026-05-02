#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "graph.h"

int main() {
    HashNode* tablo = (HashNode*)calloc(TABLE_SIZE, sizeof(HashNode));
    int matris[SEHIR_SAYISI][SEHIR_SAYISI] = {0};
    int ziyaret[SEHIR_SAYISI] = {0};

    // Bellek İzleme için 5 Veri Girişi[cite: 1]
    ekle(tablo, 101, "Istanbul Paketi");
    ekle(tablo, 102, "Ankara Paketi");
    ekle(tablo, 103, "Izmir Paketi");
    ekle(tablo, 104, "Bursa Paketi");
    ekle(tablo, 105, "Antalya Paketi");

    // Graf Baglantilari
    matris[0][1] = 1; matris[1][2] = 1;

    printf("--- Bellek Adresleri (Rapor Icin) ---\n");
    for(int i=0; i<5; i++) {
        printf("Paket %d RAM Adresi: %p\n", tablo[i].paketID, (void*)&tablo[i]);
    }

    printf("\n--- DFS Gezinmesi ---\n"); 
    DFS(matris, ziyaret, 0);

    free(tablo);
    return 0;
}