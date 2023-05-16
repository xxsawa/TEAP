// Autor: Daniel Sawa
// Ciel programu:
//
//
#include<stdio.h>

int vysledne_pole[11];
int vysledny_sum = 10000;
int vstup_size;

int hamburger[11][11] ; //= {{1, 5, 3, 20, 3, 6, 20, 4, 50, 6},
// {6, 4, 9, 20, 5, 4, 5, 6, 7, 8},
// {6, 20, 4, 50, 6, 6, 20, 4, 50, 6},
// {1, 3, 4, 5, 6, 6, 4, 9, 20, 5},
// {4, 5, 6, 7, 8, 6, 4, 9, 20, 5},
// {10, 50, 3, 20, 3, 6, 20, 4, 50, 6},
// {6, 40, 9, 20, 5, 4, 5, 6, 7, 8},
// {6, 20, 4, 50, 6, 6, 20, 4, 50, 6},
// {10, 3, 4, 5, 6, 6, 4, 9, 20, 5},
// {4, 5, 6, 7, 8, 6, 4, 9, 20, 5}};


void rekurzia(int kde,int pole[],int sucet, int velkost_pola){
    if (velkost_pola == vstup_size){
        
        if (sucet < vysledny_sum)
            {
            for (int i = 0; i < velkost_pola; i++)
            {
                vysledne_pole[i] = pole[i];
            }
            vysledny_sum = sucet;
            
        }
    }

    for (int i = 0; i < vstup_size; i++)
    {
        int je_v = 0;
        for (int j = 0; j < velkost_pola; j++)
        {
            if (i + 1 == pole[j])
            {
                je_v = 1;
            }                
        }

        if (je_v == 0)
        {
            int temp[11];

            for (int j = 0; j < velkost_pola; j++)
            {
                temp[j] = pole[j];
            }
            temp[velkost_pola] = i+1;
            rekurzia(i,temp,sucet + hamburger[kde][i],velkost_pola+1);
            
        }
        
    }
        
        
        
}


int main() {
    int vstup;
    char c;
    char v;
    int i =0,j = 0;

    scanf("%d",&vstup_size);

    while (scanf("%d", &vstup) != EOF) {
        hamburger[i][j] = vstup;
        j++;
        printf("%d ",vstup);
        if (j == vstup_size) {
            printf("\n");
            i ++;
            j = 0;
        }
        if (i == vstup_size)
        {
            break;
        }
        

    }



    int pole[11] = {1,0,0,0,0,0,0,0,0};
    rekurzia(0,pole,0, 1);
    printf("%d\n",vysledny_sum);
    for (int i = 0; i < vstup_size; i++)
    {
        printf("%d ",vysledne_pole[i]);
    }
    
}