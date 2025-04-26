#include <stdio.h>
#include<string.h>
struct Question {
    char question[100];
    char options[4][50];
    int correctOption;
};

void loadQuestions(struct Question q[]);
void startQuiz(struct Question q[]);

int main() {
    struct Question q[5];
    loadQuestions(q);
    startQuiz(q);
    return 0;
}

void loadQuestions(struct Question q[]) {
    // Question 1
    strcpy(q[0].question, "What is the capital of France?");
    strcpy(q[0].options[0], "Paris");
    strcpy(q[0].options[1], "London");
    strcpy(q[0].options[2], "Berlin");
    strcpy(q[0].options[3], "Madrid");
    q[0].correctOption = 1;

    // Question 2
    strcpy(q[1].question, "Who is the founder of C language?");
    strcpy(q[1].options[0], "Dennis Ritchie");
    strcpy(q[1].options[1], "James Gosling");
    strcpy(q[1].options[2], "Bjarne Stroustrup");
    strcpy(q[1].options[3], "Guido van Rossum");
    q[1].correctOption = 1;

    // Question 3
    strcpy(q[2].question, "Which planet is known as Red Planet?");
    strcpy(q[2].options[0], "Mars");
    strcpy(q[2].options[1], "Earth");
    strcpy(q[2].options[2], "Venus");
    strcpy(q[2].options[3], "Jupiter");
    q[2].correctOption = 1;

    // Question 4
    strcpy(q[3].question, "Which data structure uses FIFO?");
    strcpy(q[3].options[0], "Stack");
    strcpy(q[3].options[1], "Queue");
    strcpy(q[3].options[2], "Tree");
    strcpy(q[3].options[3], "Graph");
    q[3].correctOption = 2;

    // Question 5
    strcpy(q[4].question, "What is H2O?");
    strcpy(q[4].options[0], "Oxygen");
    strcpy(q[4].options[1], "Hydrogen");
    strcpy(q[4].options[2], "Water");
    strcpy(q[4].options[3], "Helium");
    q[4].correctOption = 3;
}

void startQuiz(struct Question q[]) {
    int score = 0, answer;

    for (int i = 0; i < 5; i++) {
        printf("\nQ%d: %s\n", i + 1, q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q[i].options[j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        if (answer == q[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer is: %s\n", q[i].options[q[i].correctOption - 1]);
        }
    }

    printf("\nYour final score: %d out of 5\n", score);
}
