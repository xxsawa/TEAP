// Autor: Daniel Sawa
// Ciel programu:
//
//
#include<stdio.h>

int main() {
    char ch;

    int vstup, i = 0;
    int sucet = 0;
    int n;
    int *pole_vstupu;

    



    while(2 == scanf("%d%c", &vstup, &ch)){
        if(i == 0){
            n = vstup;
            pole_vstupu = (int*)malloc(n * sizeof(int));
        }
        else{
            int j = i-2;
            while (j >= 0 && pole_vstupu[j] > vstup) {
                pole_vstupu[j + 1] = pole_vstupu[j];
                j = j - 1;
            }
            pole_vstupu[j + 1] = vstup;
        }
        i++;
        if(ch == '\n'){    
            i = 0;
            int pocitadlo = 0;
            int pocet_kamionov = 0;
            int od_zadu = 0;
            
            for (int j = n-1; j > 0; j--)
            {
                if (pole_vstupu[j] >= 200)
                {
                    pocet_kamionov++;
                    pocitadlo++;
                }
                else
                {
                    if(j <= od_zadu){
                        break;
                    }
                    pocet_kamionov++;

                    if (pole_vstupu[j] + pole_vstupu[od_zadu] > 300)
                    {
                        pocitadlo++;
                        continue;
                    }
                    pocitadlo += 2;
                    od_zadu++;   
                }
            }
            if (n - pocitadlo == 1)
            {
                pocet_kamionov++;
            }
            
            printf("%d \n",pocet_kamionov);
        }
        else if(ch == '$'){
            break;
        }
    }
}