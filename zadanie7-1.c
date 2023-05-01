

#include <stdio.h>

int k_tic;
int sucet = 0;

char vstup[11][14];

int prejdete[11][11];

int n;
int m;

int pripocitaj;

int ani_mv;



void ideme_pocitat(int cisla[], int level, int kde[]){
    if (level == k_tic)
    {
        pripocitaj++;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int je_v = 0;
        for (int j = 0; j < level; j++)
        {
            if (i == cisla[j])
            {
                je_v = 1;
            }
            
        }


        if (je_v == 0 && vstup[kde[level]-1][i] == 'Y')
        {
            int temp[10];

            for (int j = 0; j < level; j++)
                {
                    temp[j] = cisla[j];
                    
                }
            temp[level] = i;
            ideme_pocitat(temp,level+1,kde);
             
        }
        
    }
    
}



void rekurzia(int nejaky_arr[],int neznasam_c, int skadzi){
    if (neznasam_c == k_tic){
        int cisla[10];
        pripocitaj = 0;

        
        for (int i = 0; i < ani_mv; i++)
        {
            int zhoda = 1;
            for (int j = 0; j < k_tic; j++)
            {

                if (strcmp(vstup[prejdete[i][j]] , vstup[nejaky_arr[j]]))
                {
                    zhoda = 0;
                }
                
            }
            
            if (zhoda)
            {
                sucet += prejdete[i][11];
                return;
            }
            
        }
        
        ideme_pocitat(cisla,0,nejaky_arr);
        for (int j = 0; j < k_tic; j++)
        {
            prejdete[ani_mv][j] = nejaky_arr[j];
        }
        prejdete[ani_mv][11] = pripocitaj;
        
        sucet += pripocitaj;
        ani_mv++;
    }
    else{
        for (int i = skadzi; i < n; i++)
        {
            int temp[k_tic+1];

            for (int j = 0; j < neznasam_c; j++)
                {
                    temp[j] = nejaky_arr[j];
                }

            
            temp[neznasam_c] = i + 1;
            rekurzia(temp,neznasam_c+1,i+1);
             
            
        }
    }
}



int main()
{

    while (scanf("%d",&k_tic) != EOF)
    {
                
        scanf("%d %d",&n, &m);

        

        for (int i = 0; i < n; i++)
        {
            char c[12];
            scanf("%s",&c);
            strcpy(vstup[i],c);
            vstup[i][n] = '\0';
        }

        int array[k_tic+1];
        rekurzia(array,0,0);
        printf("%d\n",sucet);
        sucet = 0;
        ani_mv = 0;
    }
  return 0;
}