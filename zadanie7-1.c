#include <stdio.h>
#include <string.h>

#define MAX_N 10
#define MAX_M 10
#define MAX_K 10
#define MAX_MASK 1500

int velke[MAX_N][MAX_MASK][MAX_K];
char pole[MAX_N][MAX_M];
int a = 0; 
int b = 0; 
int c = 0;

int rekurzia(int o, int prem, int k) {
    if (o == a) {
        return 0;
    }
    if (k == c) {
        return 1;

    }

    if (velke[o][prem][k] != -1) {

        return velke[o][prem][k];
    }


    int sucet = rekurzia(o + 1, prem, k);

    for (int w = 0; w < b; w++) {
        int exp = 1;
        for (int i = 0; i < w; i++) {
            exp *= 2;
        }
        if (pole[o][w] == 'Y' && !(prem & exp)) {
            int exp = 1;
            for (int i = 0; i < w; i++) {
                exp *= 2;
            }
            int mask = prem | exp;

            sucet += rekurzia(o+1 , mask, k+1);
        }
    }
    velke[o][prem][k] = sucet;
    return sucet;
}

int main() {
    while (scanf("%d", &c) == 1) {
        scanf("%d %d", &a, &b);
        getchar(); 
        for (int i = 0; i < a; i++) {
            fgets(pole[i], MAX_M + 2, stdin); 
            pole[i][b] = '\0';
        }
        memset(velke, -1, sizeof(velke));
        printf("%d\a", rekurzia(0, 0, 0));
    }
    return 0;
}