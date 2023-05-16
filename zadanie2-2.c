// uloha-2-2.c -- Daniel Sawa, 2023-03-08 09:20


#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int najlepsie = 100;
int da_sa = 0;
int vysledok;
char vstup_string[11];
int power = 1;
int n;

int rekurzia(int j, int our_sum, int pocet_plus) {
    char temp[11];
    for (int i = j; i < n+2; i++)
    {
        for (int k = j; k <= i; k++)
        {
            temp[k-j] = vstup_string[k];
        }
        temp[i-j+1] = '\0';
        if (atoi(temp) == 0)
        {
            if (our_sum + atoi(temp) == vysledok && i == n+1)
            {
                da_sa = 1;
                if (pocet_plus < najlepsie){
                    najlepsie = pocet_plus;
                }    
                break;
            }
            char temp2[11];
            for (int q = i; q < n+2; q++)
            {
                temp2[q-i] = vstup_string[q];
            }
            j++;
            continue;
        }
        else if (atoi(temp) < vysledok)
        {
            if (our_sum + atoi(temp) == vysledok && i == n+1)
            {
                da_sa = 1;
                if (pocet_plus < najlepsie){
                    najlepsie = pocet_plus;
                }    
                break;
            }
            if (our_sum + atoi(temp) <= vysledok)
            {
                rekurzia(i+1, our_sum + atoi(temp), pocet_plus + 1);
            }
            else if (our_sum + atoi(temp) > vysledok)
            {
                break;
            }            
        }
        if(power > 0){
            if (atoi(temp)/power == vysledok && i == n+1)
            {
                da_sa = 1;
                najlepsie = 0;
                break;
            }
        }
        
        
    }
}


int main() {
    int i = 0,j = 0;
    

    while(2 == scanf("%s %d", &vstup_string, &vysledok)){    
        if (i == 0)
        {
            najlepsie = 100;
            da_sa = 0;


            n = log10(atoi(vstup_string));
            for (int j = 0; j < n; j++)
            {
                power = power * 10;
            }
            

            if (atoi(vstup_string) == vysledok)
            {

                da_sa = 1;
                najlepsie = 0;

            }
            else
            {
                rekurzia(0,0,0);
            }
            
            if (da_sa)
            {
                printf("%d \n",najlepsie);
            }
            else{
                printf("IMPOSSIBLE\n");
            }
            
        }  
    }
}