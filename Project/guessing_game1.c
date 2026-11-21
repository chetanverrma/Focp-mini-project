#include <stdio.h>      
#include <stdlib.h>     // rand() aur srand() functions ke liye
#include <time.h>       

void playGame()
{
    int level, secretNumber, guess;  // Difficulty, secret number aur player ka guess
    int attempts, maxAttempts, range; // Attempts, maximum attempts aur number range
    int score = 0;                  

    printf("\n===== SELECT DIFFICULTY =====\n"); 
    printf("1. Easy\n");                       
    printf("2. Medium\n");                     
    printf("3. Hard\n");                        
    printf("Enter your choice: ");            
    scanf("%d", &level);                      

    // Switch se difficulty level select karna
    switch (level)
    {
        case 1:                 
            range = 50;          
            maxAttempts = 10;    
            break;              

        case 2:                  
            range = 100;        
            maxAttempts = 7;     
            break;              

        case 3:                  
            range = 200;         
            maxAttempts = 5;     
            break;               

        default:                 
            printf("Invalid choice!\n"); 
            return;             
    }

    secretNumber = rand() % range + 1;

    printf("\n===== NUMBER QUEST =====\n"); 
    printf("Guess the secret number between 1 and %d.\n", range); 
    printf("You have %d attempts.\n", maxAttempts);

    for (attempts = 1; attempts <= maxAttempts; attempts++)
    {
        printf("\nAttempt %d: Enter your guess: ", attempts); 
        scanf("%d", &guess); 


        if (guess == secretNumber)
        {
            printf("\nCongratulations! You guessed correctly!\n"); 
            // Remaining attempts ke basis par score calculate karna
            score = (maxAttempts - attempts + 1) * 10;

            printf("Attempts used: %d\n", attempts); 
            printf("Your score: %d\n", score);      
            return;                                 
        }

        else if (guess < secretNumber)
        {
            printf("Too Low! Try a higher number.\n"); 
        }

        else
        {
            printf("Too High! Try a lower number.\n"); 
        }

       
        printf("Attempts remaining: %d\n", maxAttempts - attempts);
    }

    
    printf("\nGAME OVER!\n"); 
    printf("The secret number was: %d\n", secretNumber); 
    printf("Your score: 0\n");
}


int main()
{
    int choice;      

    srand(time(0));   

    do
    {
        printf("\n============================\n");
        printf("       NUMBER QUEST\n");            // Game name
        printf("============================\n"); 
        printf("1. Start Game\n");                  
        printf("2. Exit\n");                        
        printf("Enter your choice: ");             
        scanf("%d", &choice);                      


        switch (choice)
        {
            case 1:              
                playGame();      
                break;          

            case 2:              
                printf("\nThanks for playing Number Quest!\n"); 
                break;           

            default:            
                printf("\nInvalid choice! Try again.\n"); 
        }

    } while (choice != 2); // Jab tak choice 2 nahi hoti, menu repeat hoga

    return 0; 
}