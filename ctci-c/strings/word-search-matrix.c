//gcc -o word-search-matrix word-search-matrix.c  --std=c99
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int prompt_for(char *buffer, size_t buflen);
static int search_direction(char array[18][18], char *string, int length, int X, int Y, int dx, int dy);
static int search_from(char array[18][18], char *string, int length, int X, int Y);

int main(void)
{
    int X, Y, length;
    char array[18][18], string[50];

    printf("WORDSEARCH SOLVER - PRESS CTRL-C TO QUIT\n\n");
// Reading file to array.
    FILE *wsch = fopen("wrdsearch.txt", "r");
    if (!wsch)
    {
        printf("Error! File did not open.\n");
        return 1;
    }
    for (Y = 0; Y < 18; Y++)
    {
        for (X = 0; X < 18; X++)
        {
            fscanf(wsch, " %c", &array[Y][X]);
            array[Y][X] = toupper(array[Y][X]);
        }
    }
    fclose(wsch);
// Reading file to array.  END

    printf("   ");
    for (X = 0; X < 18; X++)
        printf("%-2d", X);
    printf("\n______________________________________\n");
    for (Y = 0; Y < 18; Y++)
    {
        printf("%-2d|", Y);
        for (X = 0; X < 18; X++)
            printf("%c ", array[Y][X]);
        printf("\n");
    }
//Print array

    while ((length = prompt_for(string, sizeof(string))) != EOF)
    {
        printf("Searching for: [%s]\n", string);

        int count = 0;
        for (Y = 0; Y < 18; Y++)
        {
            for (X = 0; X < 18; X++)
            {
                if (array[Y][X] == (string[0]) && search_from(array, string, length, X, Y))
                    count++;
            }
        }

        printf("Found %s %d times\n", string, count);
    }

    printf("\n");
    return 0;
}

static int prompt_for(char *buffer, size_t buflen)
{
    printf("\nPlease enter the word to be searched: ");
    if (fgets(buffer, buflen, stdin) == 0)
        return EOF;
    size_t length = strlen(buffer);
    if (buffer[length-1] == '\n')
        buffer[--length] = '\0';
    if (length == 0)
        return EOF;
    for (size_t i = 0; i < length; i++)
        buffer[i] = toupper(buffer[i]);
    return length;
}

static int search_from(char array[18][18], char *string, int length, int X, int Y)
{
    struct yx { int dy; int dx; } directions[] =
    {
        { +1, 0 }, { -1, 0 }, { +1, +1 }, { -1, +1 },
        { 0, +1 }, { 0, -1 }, { -1, -1 }, { +1, -1 },
    };
    enum { num_directions = sizeof(directions) / sizeof(directions[0]) };
    int count = 0;

    for (int i = 0; i < num_directions; i++)
    {
        if (search_direction(array, string, length, X, Y, directions[i].dx, directions[i].dy))
            count++;
    }
    return count;
}

static int search_direction(char array[18][18], char *string, int length, int X, int Y, int dx, int dy)
{
    for (int i = 1; i < length; i++)
    {
        int x = X + i * dx;
        int y = Y + i * dy;
        if (x < 0 || x >= 18 || y < 0 || y >= 18)
            return 0;
        if (array[y][x] != string[i])
            return 0;
    }

    printf("Found word %s starting at (%d,%d) to (%d,%d)\n",
           string, Y, X, Y + (length - 1) * dy, X + (length - 1) * dx);
    /* Validating search! */
    char *pad = "";
    for (int i = 0; i < length; i++)
    {
        int x = X + i * dx;
        int y = Y + i * dy;
        printf("%s%c (%d,%d)", pad, array[y][x], y, x);
        pad = ", ";
    }
    putchar('\n');

    return 1;
}
