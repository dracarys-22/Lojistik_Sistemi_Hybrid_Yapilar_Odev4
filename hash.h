#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int paketID;
    char bilgi[50];
    int dolu; 
} HashNode;

// Tip B Hash: Numara tek (1) olduğu için
int hashFonksiyonu(int id) {
    return (id * 31 + 7) % TABLE_SIZE;
}

// Açık Adresleme: Çakışma 0-4 arası (1) olduğu için
void ekle(HashNode tablo[], int id, char* veri) {
    int index = hashFonksiyonu(id);
    while (tablo[index].dolu == 1) {
        index = (index + 1) % TABLE_SIZE; // Bir sonraki boş yere bak
    }
    tablo[index].paketID = id;
    strcpy(tablo[index].bilgi, veri);
    tablo[index].dolu = 1;
}
#endif