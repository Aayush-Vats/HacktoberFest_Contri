#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number, guess, i = 0;
    srand(time(0));
    number = rand() % 100 + 1; // this line generates a rndom number between 1 to 100
    //printf("The random number is %d\n", number); // if we want to prin the random number
    do //because then only the user will get atleast one attempt
    {
        printf("Guess a number between 1 to 100: ");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Lower number please!\n");
        }
        else if (guess < number)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("You guessed the number in %d attempts\n", i);
        }
        i++;
    } while (guess != number);
    return 0;
}