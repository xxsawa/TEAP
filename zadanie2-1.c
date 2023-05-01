// Autor: Daniel Sawa
// Ciel programu:
//
//
#include <stdio.h>

int main() {
    int vstup;
    char c;
    int i = 0,j = 0,k = 0;
    int od;
    int do_;
    int kolko_v = 0;

    int tahy[50];

    while (scanf("%d%c", &vstup, &c) != EOF) {
        if (i == 1)
        {
            tahy[j] = vstup;
            j++;
        }
        if (i == 2)
        {
            if(k == 0){
                od = vstup;
                k++;
            }
            else{
                do_ = vstup;
                k = 0;
                char tabulka[100000] = {NULL};

                for (int k = 1; k < do_+1; k++)
                {
                    for (int q = 0; q < j; q++)
                    {
                        if(k - tahy[q] == 0){
                            tabulka[k] = 'V';
                            if (k >= od)
                            {
                                kolko_v++;
                            }
                            
                            
                            break;
                        }
                        else if(k - tahy[q] > 0){
                            if(tabulka[k - tahy[q]]){
                                if(tabulka[k - tahy[q]] == 'V'){
                                    tabulka[k] = 'P';
                                }
                                if(tabulka[k - tahy[q]] == 'P'){
                                    tabulka[k] = 'V';
                                    if (k >= od)
                                    {
                                        kolko_v++;
                                    }
                                    break;
                                }
                                if(tabulka[k - tahy[q]] == 'R'){
                                    tabulka[k] = 'R';
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else if(k - tahy[q] < 0){
                            break;
                        }
                    }
                }


            }
        }
        if (c == '\n') {
            i++;
            if(i == 3){
                printf("%d\n",kolko_v);
                kolko_v = 0;
                i = 0;
                j = 0;
            }
        }
    }

    

    return 0;
}