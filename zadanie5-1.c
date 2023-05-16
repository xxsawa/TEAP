#include <stdio.h>

int main() {
    int vstup;
    char c;
    int i = 0,j = 0;

    int list1[2][50][2] = {};

    int goals;
    int lenght;
    int p1, p2;
    int done;


    while (scanf("%d%c", &vstup, &c) != EOF) {

        if (j % 2 == 0)
        {
            i++;
            if (i % 2 == 0)
            {
                goals = vstup;
            }
            else
            {
                lenght = vstup;
            }
                for (int k = 0; k < lenght; k++)
                {
                    list1[0][k][0] = -1;
                    list1[0][k][1] = 0;
                    list1[1][k][0] = -1;
                    list1[1][k][1] = 0;
                }       
            
        }
        else
        {
            if (i == 0)
            {
                p1 = vstup;
            }
            if (i == 1)
            {
                p2 = vstup;
            }
            

            if (i > 1){
                if(list1[0][i-2][0] >= 0){
                    list1[0][i-1][0] = abs(p1 - p2) + list1[0][i-2][0];
                    list1[0][i-1][1] += list1[0][i-2][1] + 1;
                    if (list1[1][i-2][0] >= 0){
                        if (abs(p1 - p2) + list1[1][i-2][0] > list1[0][i-1][0]){
                            list1[0][i-1][0] = abs(p1 - p2) + list1[1][i-2][0];
                            list1[0][i-1][1] += list1[1][i-2][1] + 1;
                        }
                    }
                }
                else {
                    list1[0][i-1][0] = abs(p1 - p2);
                    list1[0][i-1][1] += 2;
                }            
                if (list1[0][i-2][0] >= 0){
                    list1[1][i][0] = abs(p1 - vstup) + list1[0][i-2][0];
                    list1[1][i][1] = list1[0][i-2][1] + 1;
                    if (list1[1][i-1][0] >= 0){
                        if (abs(p1 - vstup) + list1[1][i-2][0] > list1[1][i][0]){
                            list1[1][i][0] = abs(p1 - vstup) + list1[1][i-2][0];
                            list1[1][i][1] = list1[1][i-2][1] + 1;
                        }
                        if (abs(p1 - vstup) + list1[1][i-2][0] == list1[1][i][0]){
                            if (list1[1][i][1] > list1[1][i-2][0]+1)
                            {
                                list1[1][i][1] = list1[1][i-2][1] + 1;
                            }
                            
                            
                        }
                        
                    }
                }
            
                else{
                    list1[1][i][0] = abs(p1 - vstup);
                    list1[1][i][1] += 2;
                }

                if (list1[1][i][0] >= goals && done == 0){
                    printf("%d\n",list1[1][i][1]);
                    done = 1;
                }

                

                if (list1[0][i-1][0] >= goals && done == 0){
                    printf("%d\n",list1[0][i-1][1]);
                    done = 1;
                }
                p1 = p2;
                p2 = vstup;

            }
            for (int q = 0; q < 2; q++)
            {
                for (int k = 0; k < lenght; k++)
                {
                    printf("[%d %d]",list1[q][k][0],list1[q][k][1]);
                }  
                printf("\n");
            }
            printf("\n");
            
   
            if (i == lenght-1 && done == 0){
                if (list1[1][i-1][0] + abs(p1-p2) >= goals)
                {
                    printf("%d\n",list1[1][i-1][1]+1);
                }
                else
                {
                    printf("%d\n",lenght);
                }
                
                
            }
            i++;
        }
        if (c == '\n') {
            j++;
            i = 0;
            done = 0;

                 
        }
    }
}