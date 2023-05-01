#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

int main() {
    int vstup;
    char c;
    int i = 0,j = 0;

    int umin_par[2] = {0,0};
    int umin_nep[2] = {0,0};
    int umax_par[2] = {0,0};
    int umax_nep[2] = {0,0};

    int goals;
    int lenght;

    int done = 0;
    int p1 = 0;
    int p2 = 0;

    int result = 10000;

    while (scanf("%d%c", &vstup, &c) != EOF) {

        if (j % 2 == 0){
            i++;
            if (i % 2 == 0){
                goals = vstup;
            }
            else{
                lenght = vstup;
            }       
            
        }
        else if (done)
        {
            
        }
        else{
            if (i == 0){
                umin_par[0] = vstup;
                umin_nep[0] = vstup;
                p1 = vstup;
                p2 = vstup;
            }
            

            if (vstup >= umax_par[0] && i % 2 == 0){
                umax_par[0] = vstup;
                umax_par[1] = i;
                if (abs(umax_par[0] - umin_par[0] >= goals)){
                    if ((int)(ceil(MIN(umin_par[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_par[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_par[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_par[1])/2.0 + 1));
                    }    
                    
                    done = 1;
                }
            }
            if (vstup >= umax_nep[0] && i % 2 == 1){
                umax_nep[0] = vstup;
                umax_nep[1] = i;
                if (abs(umax_nep[0] - umin_par[0] >= goals)){
                    if ((int)(ceil(MIN(umin_par[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_par[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_par[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_par[1])/2.0 + 1));
                    }    
                    
                    done = 1;
                }
            }

            if (vstup < umin_par[0] && i % 2 == 0){
                umin_par[0] = vstup;
                umin_par[1] = i;
                if (abs(umax_par[0] - umin_par[0]) >= goals){
                    if ((int)(ceil(MIN(umin_par[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_par[1])/2.0) + 1) < result)
                    {
                        result = (int)(ceil(MIN(umin_par[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_par[1])/2.0) + 1);
                    }     
                    done = 1;
                }
                if (abs(umax_nep[0] - umin_par[0]) >= goals){
                    if ((int)(ceil(MIN(umin_par[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_par[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_par[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_par[1])/2.0 + 1));
                    }    
                    done = 1;
                }
                
            }




            
            if (vstup >= umax_par[0] && i % 2 == 0){
                umax_par[0] = vstup;
                umax_par[1] = i;
                if (abs(umax_par[0] - umin_nep[0] >= goals)){
                    if ((int)(ceil(MIN(umin_nep[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_nep[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_nep[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_nep[1])/2.0 + 1));
                    }    
                    
                    done = 1;
                }
            }
            if (vstup >= umax_nep[0] && i % 2 == 1){
                umax_nep[0] = vstup;
                umax_nep[1] = i;
                if (abs(umax_nep[0] - umin_nep[0] >= goals)){
                    if ((int)(ceil(MIN(umin_nep[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_nep[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_nep[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_nep[1])/2.0 + 1));
                    }    
                    
                    done = 1;
                }
            }

            if (vstup < umin_nep[0] && i % 2 == 1){
                umin_nep[0] = vstup;
                umin_nep[1] = i;
                if (abs(umax_par[0] - umin_nep[0]) >= goals){
                    if ((int)(ceil(MIN(umin_nep[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_nep[1])/2.0) + 1) < result)
                    {
                        result = (int)(ceil(MIN(umin_nep[1],umax_par[1])/2.0) + ceil(abs(umax_par[1] - umin_nep[1])/2.0) + 1);
                    }     
                    done = 1;
                }
                if (abs(umax_nep[0] - umin_nep[0]) >= goals){
                    if ((int)(ceil(MIN(umin_nep[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_nep[1])/2.0 + 1)) < result)
                    {
                        result = (int)(ceil(MIN(umin_nep[1],umax_nep[1])/2.0) + ceil(abs(umax_nep[1] - umin_nep[1])/2.0 + 1));
                    }    
                    done = 1;
                }
                
            }

            if (abs(p1 - umax_par[0]) >= goals)
            {
                result = ceil(i/2.0) + 1;
            }
            


            if (done == 1)
            {
                printf("%d\n",result);
            }
            
            if(i == lenght -1 && done == 0){
                printf("toto%d\n",lenght);
            }
            
            i++;
            p1 = p2;
            p2 = vstup;
        }
        if (c == '\n') {
            printf("%d %d \n",umin_par[0] ,umin_nep[0]);
            j++;
            i = 0;
            done = 0;
            result = 10000;
            umin_par[0] = 0;
            umin_nep[0] = 0;
            umax_par[0] = 0;
            umax_nep[0] = 0;
            umin_par[1] = 0;
            umin_nep[1] = 0;
            umax_par[1] = 0;
            umax_nep[1] = 0;
                 
        }
    }
}