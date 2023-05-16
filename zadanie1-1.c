#include <stdio.h>


void quicksort_descending(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] > pivot) {
            i++;
        }
        while (arr[j] < pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quicksort_descending(arr, left, j);
    quicksort_descending(arr, i, right);
}

int main() {
    int a,b,c;
    while (scanf("%d",&a) != EOF)    
    {    
    scanf("%d",&b);
    scanf("%d",&c);

    
    int numbers[10];
    int count = 0;

    for (int i = 0; i < c; i++) {
        int num;
        scanf("%d", &num);

        if (count < b) {
            numbers[count] = num;
            count++;
        } else {
            int smallest_idx = 0;
            for (int j = 1; j < b; j++) {
                if (numbers[j] < numbers[smallest_idx]) {
                    smallest_idx = j;
                }
            }

            if (num > numbers[smallest_idx]) {
                numbers[smallest_idx] = num;
            }
        }
        quicksort_descending(numbers, 0, count - 1);
        }
        int sucet = 0;
        for (int j = 0; j < count; j++)
        {
           sucet += numbers[j];
        }
        if (sucet<=a)
        {
            printf("ANO\n");
        }
        else
        {
           printf("NIE\n");
        }
        
        
        
    }
    return 0;
}