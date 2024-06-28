#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
const char *words[] = {
    "giraffe", "pineapple", "oxygen", "bicycle", "nightmare",
    "pyramid", "galaxy", "thunder", "elephant", "mystery",
    "kangaroo", "astronaut", "chocolate", "umbrella", "dinosaur",
    "watermelon", "butterfly", "saxophone", "jazz", "harmony",
    "adventure", "blizzard", "champion", "discovery", "ecosystem"
};

int main()
{
    printf("Welcome to the hangman type game\n");
    printf("Please press 1 to start: ");
    int start = 0;
    scanf("%d", &start);
    while(start != 1)
    {
        scanf("%d", &start);
    }
    srand(time(NULL));
    int wordChoiceIndex = rand() % 10;
    char *wordChoice = words[wordChoiceIndex];
    int sizeOfWord = strlen(wordChoice);
    printf("A word has been chosen\n");
    char guessed[sizeOfWord];
    for(int i = 0; i <sizeOfWord; i++)
    {
        guessed[i] ='_';
    }
    guessed[sizeOfWord] = '\0';
    printf("You have 5 lives. Try to guess letters.\n");
    int lives = 5;
    char guess;
    int correctGuess;
    int alreadyGuessed;
    while(lives != 0 && strcmp(guessed, wordChoice) != 0)
    {
        correctGuess = 0;
        alreadyGuessed = 0;
        printf("Lives: %d\n", lives);
        printf("%s\n", guessed);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        for (int i = 0; i < sizeOfWord; i++)
        {
            if (guessed[i] == guess)
            {
                alreadyGuessed = 1;
                break;
            }
        }
        if (alreadyGuessed == 1)
        {
            printf("You have already guessed the letter %c.\n", guess);
            continue;
        }
        for (int i = 0; i < sizeOfWord; i++)
        {
            if (guess == wordChoice[i])
            {
                guessed[i] = wordChoice[i];
                correctGuess = 1;
            }
        }
        if (correctGuess == 0)
        {
            lives--;
            printf("There isn't letter %c in the word.", guess);
        }

    }
    if(lives == 0)
    {
        printf("\nYou sadly lost. The word was %s. Better luck next time!\n", wordChoice);
    }
    else
    {
        printf("You win! The word is %s", guessed);
    }
    return 0;
}
