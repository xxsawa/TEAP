

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

    char vstup[100];

    int arr2d[100][100];
    
    
    while(scanf("%s", &vstup) != EOF){
        memset(arr2d, 0, sizeof arr2d); 
        int pocitadlo = 0;

        if (vstup[1] == '<'){
            arr2d[0][pocitadlo++] = 1;
        }
        else{
            arr2d[0][pocitadlo++] = 0;
        }
            
        for (int i = 1; i < strlen(vstup) -2; i++){
            if (vstup[i] == '>' && vstup[i+1] == '>' || vstup[i] == '>' && vstup[i+1] == '<' || vstup[i] == '<' && vstup[i+1] == '<'){
                arr2d[0][pocitadlo++] = 1;
            }
            else
            {
                arr2d[0][pocitadlo++] = 0;
            }
            
            
        }
        if (vstup[strlen(vstup) -2] == '>'){
            arr2d[0][pocitadlo++] = 1;
        }
        else{
            arr2d[0][pocitadlo++] = 0;
        }

        
        for (int j = 2; j < (strlen(vstup)-1)/2+1; j++){
            pocitadlo = 0;
            for (int i = 0; i < (strlen(vstup)-j*2)+1; i++)
            {
                if (i == 0)
                {
                    if (vstup[(j-1)*2+1] == '<' && arr2d[j-2][i+1] || arr2d[j-2][0] && arr2d[0][(j-1)*2])
                    {
                        arr2d[j-1][pocitadlo++] = 1;
                        continue;
                    }

                    int od_zadu = j*2;
                    int counters = 0;
                    int koniec = 0;

                    while (j-2-((counters/2)-1) > 0)
                    {
                        od_zadu -= 2;
                        counters += 2;
                        if (arr2d[(counters/2)-1][i] && arr2d[j-2-((counters/2)-1)][i+counters])
                        {
                            arr2d[j-1][pocitadlo++] = 1;
                            koniec = 1;
                            break;
                        }
                    }
                    if (koniec)
                    {
                        continue;
                    }


                    arr2d[j-1][pocitadlo++] = 0;
                    
                }
                else if (i == strlen(vstup)-j*2)
                {
                    if (vstup[i] == '>' && arr2d[j-2][i+1] || arr2d[0][i] && arr2d[j-2][i+2])
                    {
                        arr2d[j-1][pocitadlo++] = 1;
                        continue;
                    }

                    int od_zadu = j*2;
                    int counters = 0;
                    int koniec = 0;

                    while (j-2-((counters/2)-1) > 0)
                    {
                        od_zadu -= 2;
                        counters += 2;
                        if (arr2d[(counters/2)-1][i] && arr2d[j-2-((counters/2)-1)][i+counters])
                        {
                            arr2d[j-1][pocitadlo++] = 1;
                            koniec = 1;
                            break;
                        }
                    }
                    if (koniec)
                    {
                        continue;
                    }
                    arr2d[j-1][pocitadlo++] = 0;
                    
                }
                else
                {
                    if (((vstup[i] == '<' && vstup[i+(j-1)*2+1] == '<' || vstup[i] == '>' && vstup[i+(j-1)*2+1] == '<' || vstup[i] == '>' && vstup[i+(j-1)*2+1] == '>') && arr2d[j-2][i+1]) || (arr2d[0][i] && arr2d[j-2][i+2]))
                    {
                        arr2d[j-1][pocitadlo++] = 1;
                        continue;
                    }

                    int od_zadu = j*2;
                    int counters = 0;
                    int koniec = 0;

                    while (j-2-((counters/2)-1) > 0)
                    {
                        od_zadu -= 2;
                        counters += 2;
                        if (arr2d[(counters/2)-1][i] && arr2d[j-2-((counters/2)-1)][i+counters])
                        {
                            arr2d[j-1][pocitadlo++] = 1;
                            koniec = 1;
                            break;
                        }
                    }
                    if (koniec)
                    {
                        continue;
                    }
                    

                    arr2d[j-1][pocitadlo++] = 0;

                }
            }
            // for (int i = 0; i < pocitadlo; i++)
            // {
            //     printf("%d ",arr2d[j-1][i]);
            // }
            // printf("\n");
        }


        for (int i = 0; i < ((strlen(vstup)-1)/2)+1; i++)
        {
            if (i == 0)
            {
                if (arr2d[((strlen(vstup)-1)/2)-1][i+1])
                {
                    printf("o.");
                }
                else
                {
                    printf("..");
                }
            }
            else if (i == (strlen(vstup)-1)/2)
            {
                if (arr2d[((strlen(vstup)-1)/2)-1][0])
                {
                    printf("o");
                }
                else
                {
                    printf(".");
                }
            }
            else if (arr2d[i-1][0] && arr2d[((strlen(vstup)-1)/2)-(1+i)][(i*2)+1])
            {
                printf("o.");
            }
            else
            {
                printf("..");
            }
        }
        printf("\n");
        
    }
}
