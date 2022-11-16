#include <stdio.h>

int main(void)
{
    char    str[] = "Hello World!";
    int i;

    while(!str[i])
    {
        printf("%c", str[i]);
        i++;
    }
}