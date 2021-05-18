#include <stdio.h>
#include <string.h>

int main()
{
    char *buf = "hello world\n";
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    while(*buf)
    {
        printf("%c\n", *buf);
        buf++;
    }
    
    unsigned int *ptr = (unsigned int *)&matrix + ((4 * 4) - 1);

    printf("int from matrix: %d\n", *ptr);

    return 0;
}
