// Autor: Daniel Sawa
// Ciel programu:
//
//
#include<stdio.h>

int sucet = 0;

int running_sum = 0;

int max_price = 0;
int sub = 0;

int a;
int b;

int main() {

    while (scanf("%d",&a) != EOF)
    {
        scanf("%d",&b);
        int main_arr[100 + 100*100 + 100];


        int vstup;


        int n = a+b;
        int running_sum_dva = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vstup);


            if (i == a)
            {
                for (int j = 0; j < a*b; j++)
                {
                    main_arr[i+j] = 1;
                }
            }
            
            if (i < a)
            {
                
                main_arr[i] = vstup;
                
                running_sum += vstup;
            }            
            else
            {   
                if (vstup > a)
                {
                    vstup = a;
                }       
                main_arr[i+a*b] = vstup;
                running_sum_dva += vstup;
                
            }
        }

        

        while (1)        
        { 
            
            int max_first = 0;
            int max_first_i;
            for (int i = 0; i < a; i++)
            {
                if (max_first < main_arr[i])
                {
                    max_first = main_arr[i];
                    max_first_i = i;
                }
            }
            if (max_first == 0)
            {
                break;
            }
            


            int max_second = 0;
            int max_second_i;
            for (int i = a + a*b; i < a + a*b + b; i++)
            {
                if (max_second < main_arr[i])
                {
                    max_second = main_arr[i];
                    max_second_i = i;
                }
            }
            if (max_second == 0)
            {
                break;
            }
            int i = a+(max_second_i- (a + a*b));
            while (i < a + a*b)
            {
                if (main_arr[i] == 1)
                {
                    sucet++;
                    main_arr[i]--;
                    main_arr[max_second_i]--;
                    main_arr[max_first_i]--;
                    break;
                }
                i+= 5;
            }
        }
        printf("%d %d\n",sucet, running_sum);
        running_sum = 0;
        sucet = 0;
        running_sum_dva = 0;
    }
}