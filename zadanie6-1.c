

#include <stdio.h>

int num1;
int num2;

void rekurzia(int nejaky_arr[num1+1],int neznasam_c){
    if (neznasam_c == num1){
        for (int i = 0; i < num1; i++)
        {
            printf("%d ",nejaky_arr[i]);    
        }
        printf("\n");
    }
    else{
        for (int i = 0; i < num2; i++)
        {
            int temp[num1+1];

            for (int j = 0; j < neznasam_c; j++)
                {
                    temp[j] = nejaky_arr[j];
                }

            
            temp[neznasam_c] = i + 1;
            rekurzia(temp,neznasam_c+1);
             
            
        }
    }
}



int main()
{
  scanf("%d %d",&num1,&num2);
  int array[num1+1];
  rekurzia(array,0);

  return 0;
}