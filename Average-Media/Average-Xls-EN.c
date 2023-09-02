#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int NumTests, NumStudents, type, i, j;

    printf("What type of average do you want to calculate?\n\nArithmetic - 1\nWeighted - 2\n");
    scanf("%i", &type);
    system("clear");
    system("cls");

    printf("How many tests were conducted?\n");
    scanf("%i", &NumTests);
    system("clear");
    system("cls");

    printf("What is the number of students?\n");
    scanf("%i", &NumStudents);
    system("clear");
    system("cls");

    float Average[NumStudents], Scores[NumStudents][NumTests], TestWeights[NumTests], FinalAverage;
    char StudentName[NumStudents][50];
    int temp = 0;

    switch (type) {
        case 1:
            for (i = 0; i < NumStudents; i++) {
                printf("Enter the name of student %i\n", i + 1);
                scanf("%s", StudentName[i]);
                system("clear");
                system("cls");
                for (j = 0; j < NumTests; j++) {
                    printf("Test score %i\n", j + 1);
                    scanf("%f", &Scores[i][j]);
                    system("clear");
                    system("cls");
                }
            }

            for (i = 0; i < NumStudents; i++) {
                for (j = 0; j < NumTests; j++) {
                    Average[i] = Average[i] + Scores[i][j];
                }
                Average[i] = Average[i] / NumTests;
            }

            break;

        case 2:

            for (i = 0; i < NumTests; i++) {
                printf("Enter the weight of Test %i\n", i + 1);
                scanf("%f", &TestWeights[i]);
                system("clear");
                system("cls");
            }

            for (i = 0; i < NumStudents; i++) {
                printf("Enter the name of student %i\n", i + 1);
                scanf("%s", StudentName[i]);
                system("clear");
                system("cls");
                for (j = 0; j < NumTests; j++) {
                    printf("Test score %i\n", j + 1);
                    scanf("%f", &Scores[i][j]);
                    system("clear");
                    system("cls");
                }
            }

            for (i = 0; i < NumStudents; i++) {
                for (j = 0; j < NumTests; j++) {
                    Average[i] = Average[i] + Scores[i][j] * TestWeights[j];
                    temp = temp + TestWeights[j];
                }
                Average[i] = Average[i] / temp;
            }

            break;
    }

    printf("Enter the required passing average: ");
    scanf("%f", &FinalAverage);
    system("clear");
    system("cls");

    char saveChoice;

    printf("Do you want to save the data in an Excel-compatible file? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        char fileName[100];
        printf("Enter the name of the Excel file to save the data: ");
        scanf("%99s", fileName);

        if (strstr(fileName, ".xls") == NULL) {
            strcat(fileName, ".xls");
        }

        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            printf("Failed to create the file for saving.\n");
        } else {

            fprintf(file, "Name");
            for (j = 0; j < NumTests; j++) {
                fprintf(file, "\tTest %d", j + 1);
            }
            fprintf(file, "\tAverage\tPass/Fail\n");

            for (i = 0; i < NumStudents; i++) {
                fprintf(file, "%s", StudentName[i]);
                for (j = 0; j < NumTests; j++) {
                    fprintf(file, "\t%.2f", Scores[i][j]);
                }
                fprintf(file, "\t%.2f", Average[i]);

                if (Average[i] >= FinalAverage) {
                    fprintf(file, "\tPASS\n");
                } else {
                    fprintf(file, "\tFAIL\n");
                }
            }

            fclose(file);
            printf("Data saved in '%s'.\n", fileName);
        }
    } else {
        printf("Unable to save.\n");
    }

    return 0;
}
