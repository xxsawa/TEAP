// Autor: Daniel Sawa
// Ciel programu:
//
//
#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) {
        return 1;
    }
    else if (x > y) {
        return -1;
    }
    else {
        return 0;
    }
}


int main() {
    int a;
    int b;

    while (scanf("%d",&a) != EOF)
    {
        scanf("%d",&b);


        int vstup;
        int arr1[100];
        int arr2[100];

        int n = a+b;
        int sucet = 0;

        int running_sum = 0;
        int running_sum2 = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vstup);

            
            if (i < a)
            {
                
                arr1[i] = vstup;
                
                running_sum += vstup;
            }            
            else
            {      
                if (vstup > a)
                {
                    vstup = a;
                }
                
                arr2[i-a] = vstup;
                running_sum2 += vstup;

            }
        }


        if (running_sum > running_sum2)
        {
            printf("0\n");
            continue;
        }
        


        qsort(arr1, a, sizeof(int), compare);    

        qsort(arr2, b, sizeof(int), compare);  

        while (arr1[0] != 0)
        {
            // for (int i = 0; i < a; i++) {
            //     printf("%d ", arr1[i]);
            // }
            // printf("\n");

            // for (int i = 0; i < b; i++) {
            //     printf("%d ", arr2[i]);
            // }
            // printf("\n");
            // printf("\n");
            // printf("\n");

            int stop = 0;

            if (arr1[0] > b)
            {
                sucet = 0;
                break;
            }
            

            for (int i = 0; i < arr1[0]; i++)
            {
                arr2[i]--;
                sucet++;
                if (arr2[i]<0)
                {
                    stop = 1;
                    break;
                }
                
            }
            if (stop)
            {
                sucet = 0;
                break;
            }
            

            arr1[0] = 0;
            
            qsort(arr1, a, sizeof(int), compare);    

            qsort(arr2, b, sizeof(int), compare);  
        }
        printf("%d \n",sucet == running_sum);
        sucet = 0;
        running_sum = 0;

    }


}
