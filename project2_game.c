#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char y, char c);

int main()
{
    char you, comp;
    srand(time(0));
    int number = rand() % 100 + 1;

    if (number <= 33)
    {
        comp = 'r';
    }
    else if (number > 33 && number <= 66)
    {
        comp = 'p';
    }
    else if (number > 66 && number <= 100)
    {
        comp = 's';
    }

    printf("Enter 'r' for rock, 'p' for paper & 's' for scissor: ");
    scanf("%c", &you);
    if (you != 'r' && you != 'p' && you != 's')
    {
        printf("No such choice, Please enter correct choice\n");
    }
    int g = game(you, comp);

    printf("You chose '%c' , Computer chose '%c'\n", you, comp);
    if (g == 0)
    {
        printf("DRAW!!\n");
    }
    else if (g == 1)
    {
        printf("YOU WON!!\n");
    }
    else if (g == -1)
    {
        printf("YOU LOSE!!\n");
    }

    return 0;
}

int game(char y, char c)
{
    if (y == c) //same choices
    {
        return 0;
    }
    //possibile choices
    // r p
    // p s          // ofcourse vice versa of these choices as well
    // s r
    if (y == 'p' && c == 'r') //returns 1 when user wins else returns -1
    {
        return 1;
    }
    else if (y == 'r' && c == 'p')
    {
        return -1;
    }
    if (y == 'r' && c == 's')
    {
        return 1;
    }
    else if (y == 's' && c == 'r')
    {
        return -1;
    }
    if (y == 's' && c == 'p')
    {
        return 1;
    }
    else if (y == 'p' && c == 's')
    {
        return -1;
    }
}