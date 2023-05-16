#include <stdio.h>
#include <stdlib.h>

struct node {
    int done;
    struct node *left;
    struct node *right;
};

struct node* createNode(int done) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->done = done;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* root = NULL;
int najlepsie = 10000;

void rekurzia_na_strome(char slovo[], int i, struct node* actual_node, int pocet_iter){
    if (slovo[0] == "0") {
        return;
    }
    if (i == strlen(slovo)-1 )
    {
        if (pocet_iter < najlepsie)
        {
            najlepsie = pocet_iter +1;  
        }
        
            
    }

    int j = i;

    while (j < strlen(slovo) - 1)
    {
        if (slovo[j+1] == '0')
        {
            if (actual_node->left)
            {
                actual_node = actual_node->left;
            }
            else
            {
                break;
            }
        }
        else
        {
           if (actual_node->right)
            {
                actual_node = actual_node->right;
                if (actual_node->done)
                {                    
                    if (j+2 == strlen(slovo))
                    {
                        if (pocet_iter < najlepsie)
                        {
                            najlepsie = pocet_iter+1;  
                            break;
                        }
                    }
                    
                    rekurzia_na_strome(slovo, j+2, root,pocet_iter + 1);
                }
                
            }
            else
            {
                if (actual_node->done)
                {
                    rekurzia_na_strome(slovo, j+1, root,pocet_iter + 1);
                }
                
                break;
            }
        }
        
        j++;
    }
}

void reverseString(char str[]) {
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    root = createNode(1);
    for (int i = 1; i < 22; i++)
    {
        struct node* actual_node = root;
        long long new_num = (long long) pow(5,i)/2;
        int j = 0;
        while (new_num > 0) {
            int next_num = new_num % 2;


            if (next_num == 0){
                if (!actual_node->left){
                    actual_node->left = createNode(0);
                }
                actual_node = actual_node->left;
            }
            else{
                if (!actual_node->right){
                    if (j == (2*i)-1)
                    {
                        actual_node->right = createNode(1);
                    }
                    else
                    {
                        actual_node->right = createNode(0);
                    }                    
                }
                actual_node = actual_node->right;
            }
            new_num /= 2;
            j++;
            
        }
    }
    char vstup[50];
    char ch;
    while(2 == scanf("%s%c", &vstup, &ch)){ 
        if (ch == '\n')
        {
            reverseString(vstup);
            rekurzia_na_strome(vstup,0,root,0);

            if (najlepsie == 10000)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d",najlepsie);
            }
            najlepsie = 10000;
        }
    }
}
