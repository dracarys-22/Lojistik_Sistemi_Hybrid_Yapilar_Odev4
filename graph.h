#ifndef GRAPH_H
#define GRAPH_H

#define SEHIR_SAYISI 5

// Sondan 2. rakam (9) tek olduğu için DFS
void DFS(int matris[SEHIR_SAYISI][SEHIR_SAYISI], int ziyaret[], int sehir) {
    ziyaret[sehir] = 1;
    printf("Sehir %d ziyaret edildi. Adres: %p\n", sehir, (void*)&ziyaret[sehir]);

    for (int i = 0; i < SEHIR_SAYISI; i++) {
        if (matris[sehir][i] == 1 && !ziyaret[i]) {
            DFS(matris, ziyaret, i);
        }
    }
}
#endif