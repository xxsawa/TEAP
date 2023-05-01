

#include <stdio.h>
#include <stdlib.h>

void main(){

    int vstup;
    int ch;
    int q = 0;
    int a;
    int b;
    int kolko;
    scanf("%d", &kolko);

    
    while(2 == scanf("%d%c", &vstup, &ch)){  
        if (q == 0)
        {
            a = vstup + 1;
            q ++;
        }
        else
        {
            b = vstup + 2;
            q++;
            if (b > a)
            {
                printf("0\n");
                q = 0;
                continue;
            }
            
        }
        if (q == 2)
        {   
            int list1[2][300][2];
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    for (int p = 0; p < 2; p++) 
                    {
                        list1[0][j][p] = list1[1][j][p];
                        list1[1][j][p] = 0;
                    }
                }
                

                for (int j = 0; j < b; j++) 
                {
                    if(i == j && j < b-1)
                    {
                        if(j == b - 2)
                        {
                            list1[1][j][0] = 1; 
                            list1[1][j][1] = 0; 
                        } 
                        else
                        {
                            list1[1][j][0] = 1; 
                            list1[1][j][1] = 1; 
                        }
                    }
                    else if (j == b-1)
                    {
                        list1[1][j][0] = 0; 
                        list1[1][j][1] = 0; 
                    }
                    else if (j < i && a-j > i && j < b-1 && j > 0)
                    {
                        if (j == i-1 && i > 1)
                        {
                            list1[1][j][0] = (list1[0][j][0] + list1[0][j-1][0]) % 100000007;
                        }
                        if (j < i-1 && j > i-a && i > 1 && j > 0)
                        {
                            list1[1][j][0] = (list1[0][j][0] + list1[0][j-1][0] + list1[0][j+1][0]) % 100000007;
                        }
                        if (j == i-1 && i > 1 && j < b-2)
                        {
                            list1[1][j][1] = (list1[0][j][1] + list1[0][j-1][1]) % 100000007;
                        }
                        if (j < i-1 && j > i-a && i > 1 && j > 0 && j < b-2)
                        {
                            list1[1][j][1] = (list1[0][j][1] + list1[0][j-1][1] + list1[0][j+1][1]) % 100000007;
                        }
                    }
                }  
            }

            if (list1[0][1][0] - list1[0][1][1] < 1)
            {
                printf("%d\n", 100000007 + (list1[0][1][0] - list1[0][1][1]));
            }
            else
            {
                printf("%d \n",(list1[0][1][0] - list1[0][1][1]));
            }

            
            q = 0;
        }
    }
}