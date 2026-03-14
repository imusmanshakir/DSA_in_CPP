#include <stdio.h>
int main()
{
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (j <= 2 || j >= 5)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}