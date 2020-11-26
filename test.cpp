
#include <stdio.h>
#include <cmath>


int main()
{
    int top, bottom;

    scanf("%d %d", &top, &bottom);

    if (top > bottom)
    {
        int space = 0;
        int row = top / 2 - bottom / 2 + 1;
        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < space; i++)
            {
                printf(" ");
            }
            for (int i = 0; i < top; i++)
            {
                printf("*");
            }
            printf("\n");
            space++;
            top -= 2;
        }
    }
    else
    {
        int space = bottom / 2 - top / 2;
        int row = space + 1;
        for (int j = 0; j < row; j++)
        {
            for (int i = 0; i < space; i++)
                printf(" ");
            for (int i = 0; i < top; i++)
                printf("*");

            space--;
            top += 2;
            printf("\n");
        }
    }
}