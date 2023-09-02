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

    printf("How many students are there?\n");
    scanf("%i", &NumStudents);
    system("clear");
    system("cls");

    float Average[NumStudents], Scores[NumStudents][NumTests], TestWeights[NumTests], FinalAverage;
    char StudentName[NumStudents][50];
    int temp = 0;

    switch (type) {
        case 1:
            for (i = 0; i < NumStudents; i++) {
                printf("Enter the name of student - %i\n", i + 1);
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
                printf("Enter the name of student - %i\n", i + 1);
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

    printf("Do you want to save the data in an HTML file? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        char fileName[100];
        printf("Enter a name for the file: ");
        scanf("%99s", fileName);

        
        if (strstr(fileName, ".html") == NULL) {
            strcat(fileName, ".html");
        }

        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            printf("Failed to create the file.\n");
        } else {
            
            fprintf(file, "<html>\n<head>\n<style>\n");
            fprintf(file, "td.passed { color: green; }\n");
            fprintf(file, "td.failed { color: red; }\n");
            fprintf(file, "table { border-collapse: collapse; width: 50%%; }\n");
            fprintf(file, "th, td { border: 1px solid black; padding: 8px; text-align: left; }\n");
            fprintf(file, "</style>\n</head>\n<body>\n");

            
            fprintf(file, "<table>\n<tr><th>Name</th>");
            for (j = 0; j < NumTests; j++) {
                fprintf(file, "<th>Test %d</th>", j + 1);
            }
            fprintf(file, "<th>Average</th><th>Pass/Fail</th></tr>\n");

            for (i = 0; i < NumStudents; i++) {
                fprintf(file, "<tr><td>%s</td>", StudentName[i]);
                for (j = 0; j < NumTests; j++) {
                    fprintf(file, "<td>%.2f</td>", Scores[i][j]);
                }
                fprintf(file, "<td>%.2f</td>", Average[i]);

                
                if (Average[i] >= FinalAverage) {
                    fprintf(file, "<td class=\"passed\">PASSED</td></tr>\n");
                } else {
                    fprintf(file, "<td class=\"failed\">FAILED</td></tr>\n");
                }
            }

            fprintf(file, "</table>\n</body>\n</html>\n");
            fclose(file);
            printf("Data saved in '%s'.\n", fileName);
        }
    } else {
        printf("Unable to save the data.\n");
    }

    return 0;
}
