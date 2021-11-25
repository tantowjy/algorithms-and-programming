#include <stdio.h>
#include <stdlib.h>

int main()
{
    int index[100];
    int i, j, n, nasi;

    printf("Bubble Sort Descending\n");
    printf("Banyak data : ");
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        printf("Data ke-%d : ", i + 1);
        scanf("%d", &index[i]);
    }

    for (i = n - 1; i>=1; i--) //(A). Lengkapi syntax 
    {
        for (j = 1; j <= i; j++)
        {
            if (index[j - 1] <index[j]) //(B). Lengkapi syntax 
            {
                nasi = index[j-1]; //(C). Lengkapi opearsi 
                index[j - 1] = index[j];
                index[j] = nasi;
            }
        }
    }

    printf("\nHasil Sorting :\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d", index[i]); //(D). Lengkapi varibel 
        printf(" ");
    }

    return 0;
}
