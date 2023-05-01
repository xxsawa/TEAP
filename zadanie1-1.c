

// Autor: Daniel Sawa
// Ciel programu:
//
//
#include <stdio.h>

int main(){    
    char ch;

    

    int vstup, i = 0,j = 0;


    
// 1234 3 4 1000 200 4 30
// 20 4 5 10 10 10 10 10
// 1234 3 4 6 16 3 1000 200 4 30
// 1234 3 4 6 16 3 1000 35 200 4 3
// 50 8 10 3 7 1 2 8 9 10 4 10 6
    int nosnost,zmesti;
    int sucet = 0;

    
    int na_moste[10] = {0};


    while(2 == scanf("%d%c", &vstup, &ch)){
        if(i == 0){
            nosnost = vstup;
        }
        else if(i == 1){
            zmesti = vstup;
        }
        else if (i > 2)
        {
            if (na_moste[0] == 0)
            {
                
                na_moste[0] = vstup;
                sucet += vstup;
                
            }
            else
            {   
                if (vstup < na_moste[j])
                {
                    if (j+1 < zmesti)
                    {
                        na_moste[j+1] = vstup;
                        j++;
                        sucet += vstup;
                    }
                    
                }
                else if (vstup >= na_moste[0])           // insert(0,vstup)             
                {
                    int temp = na_moste[0];
                    int temp1 = na_moste[0];
                    int temp2 = na_moste[j];
                    for (int k = 1; k < 10; k++)
                    {
                        temp = na_moste[k];
                        na_moste[k] = temp1;
                        temp1 = temp;
                    }
                    na_moste[0] = vstup;                // insert(0,vstup)
                    sucet += vstup;
                    if (j > zmesti-1 || j == zmesti-1)
                    {
                        j = zmesti-1;
                        sucet-= temp2;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    for (int k = 0; k < j+1; k++)
                    {
                        
                        if (vstup > na_moste[k])
                        {
                            int temp = na_moste[k];
                            int temp1 = na_moste[k];
                            int temp2 = na_moste[j];
                            for (int l = k+1; l < zmesti; l++)
                            {
                                temp = na_moste[l];
                                na_moste[l] = temp1;
                                temp1 = temp;
                            }
                            na_moste[k] = vstup;
                            sucet += vstup;
                            if (j > zmesti-1 || j == zmesti-1)
                            {
                                j = zmesti-1;
                                sucet-= temp2;
                            }
                            else
                            {
                                j++;
                            }
                            break;
                        }   
                    }   
                }   
            }
            if (j > 9)
            {
               j = 8;
            }            
        }



        i++;
        
        
        if(ch == '\n'){    
            if(sucet > nosnost){
                printf("NIE\n");
            }else{
                printf("ANO\n");
            }
            
            sucet = 0;
            for (int i = 0; i < 10; i++)
            {
                na_moste[i] = 0;
            }
            i = 0;
            j = 0;
            
        }
        
    }
}

