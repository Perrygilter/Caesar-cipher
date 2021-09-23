#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int rotate_right(int ch)
{
    if (ch == 'z')
        return 'a';
    if (ch == 'Z')
        return 'A';
    ch++;
    return ch;
}
int rotate_left(int ch)
{
    if (ch == 'a')
        return 'z';
    if (ch == 'A')
        return 'Z';
    ch--;
    return ch;
}
int encode(int ch, int shift)
{
    if (shift == 0)
        return ch;
    if (shift > 0)
    {
        for (int i = 1; i <= shift; i++)
        {
            ch = rotate_right(ch);
        }
        return ch;
    }
    else
    {
        for (int i = 1; i <= -shift; i++)
        {
            ch = rotate_left(ch);
        }
        return ch;
    }
}
int main()
{
    char letter[100];
    int shift;
    int check = 1;
    while (check)
    {
        clrscr();
        printf("nhap chuoi: ");
        fflush(stdin);
        gets(letter);
        printf("nhap shift: ");
        scanf("%d", &shift);
        for (int i = 0; letter[i] != '\0'; i++)
        {
            if (letter[i] >= 'a' && letter[i] <= 'z')
            {
                letter[i] = encode(letter[i], shift);
            }
            if (letter[i] >= 'A' && letter[i] <= 'Z')
            {
                letter[i] = encode(letter[i], shift);
            }
        }
        printf("\n%s\n", letter);
        printf("cont? (1:cop; 0:drop) : ");
        scanf("%d", &check);
    }

    return 0;
}