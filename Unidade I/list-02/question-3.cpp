#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int invert(char *str, int beg, int end)
{
    char aux;
    printf("%c", aux);

    if (beg < end)
    {
        aux = str[beg];
        str[beg] = str[end];
        str[end] = aux;

        if (str[beg] != str[end])
            return 0;

        invert(str, (beg + 1), (end - 1));
    }
    return 1;
}

void clean(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            str[i] = ' ';
        }
    }

    for (int i = 0, position = 0; i < strlen(str); i++, position++)
    {
        if (str[position] == ' ')
            position++;
        str[i] = str[position];
    }

    for (int i = 0, position = 0; i < strlen(str); i++, position++)
    {
        if (str[position] == ',')
            position++;
        str[i] = str[position];
    }
}

int main()
{

    char *str = (char *)malloc(sizeof(char));

    printf("Digite um palindromo: \n");
    scanf("%s", str);

    clean(str);

    int result = invert(str, 0, strlen(str) - 1);

    if (result == 1)
        printf("Ã‰ um palindromo\n");
    else
        printf("NÃ£o um palindromo\n");

    free(str);

    return 0;
}