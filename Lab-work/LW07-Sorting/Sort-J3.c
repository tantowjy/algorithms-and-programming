#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char index[100];
    int i, j, n, x;

    printf("Masukkan Kalimat : ");
    gets(index);
    n = strlen(index);
    
    for (i = n - 1; i>=1; i--) 
    {
        for (j = 1; j <= i; j++)
        {
            if (index[j - 1] > index[j])
            {
                x = index[j-1];
                index[j - 1] = index[j];
                index[j] = x;
            }
        }
    }

    printf("\nOutput :\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%c", index[i]); 
        printf(" ");
    }

    return 0;
}
