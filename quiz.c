#include <stdio.h>
#include <string.h>

struct Question
{
    char question[100];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
};

int main()
{
    struct Question questions[5];
    int score = 0;
    char answer;
    int i;

    // Reading questions from the file
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        fgets(questions[i].question, 100, file);
        fgets(questions[i].optionA, 100, file);
        fgets(questions[i].optionB, 100, file);
        fgets(questions[i].optionC, 100, file);
        fgets(questions[i].optionD, 100, file);
        fscanf(file, "%c\n", &questions[i].correctAnswer);
    }

    fclose(file);

    // Quiz begins
    printf("IT Quiz Program\n");
    printf("Welcome to the IT Quiz!\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s", questions[i].question);
        printf("A. %s", questions[i].optionA);
        printf("B. %s", questions[i].optionB);
        printf("C. %s", questions[i].optionC);
        printf("D. %s", questions[i].optionD);
        printf("Enter your answer: ");
        scanf(" %c", &answer);
        if (answer == questions[i].correctAnswer)
        {
            printf("Correct answer!\n");
            score++;
        }
        else
        {
            printf("Incorrect answer.\n");
        }
    }

    // Quiz ends
    printf("Quiz ends!\n");
    printf("Your score: %d out of 5\n", score);

    return 0;
}
