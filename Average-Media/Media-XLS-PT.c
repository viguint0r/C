#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int Qtd_provas, Qtd_alunos, tipo, i, j;

    printf("Qual Tipo de Media Voce Dejesa Realizar?\n\nAritimetica - 1\nPonderada - 2\n");
    scanf("%i", &tipo);
    system("clear");
    system("cls");

    printf("Quantas Provas Foram Realizadas?\n");
    scanf("%i", &Qtd_provas);
    system("clear");
    system("cls");

    printf("Qual e a Quantidade de Alunos?\n");
    scanf("%i", &Qtd_alunos);
    system("clear");
    system("cls");

    float Media[Qtd_alunos], Notas[Qtd_alunos][Qtd_provas], Peso_provas[Qtd_provas], Media_final;
    char Aluno[Qtd_alunos][50];
    int temp = 0;

    switch (tipo) {
        case 1:
            for (i = 0; i < Qtd_alunos; i++) {
                printf("Digite o Nome do Aluno - %i\n", i + 1);
                scanf("%s", Aluno[i]);
                system("clear");
                system("cls");
                for (j = 0; j < Qtd_provas; j++) {
                    printf("Nota da Prova %i\n", j + 1);
                    scanf("%f", &Notas[i][j]);
                    system("clear");
                    system("cls");
                }
            }

            for (i = 0; i < Qtd_alunos; i++) {
                for (j = 0; j < Qtd_provas; j++) {
                    Media[i] = Media[i] + Notas[i][j];
                }
                Media[i] = Media[i] / Qtd_provas;
            }

            break;

        case 2:

            for (i = 0; i < Qtd_provas; i++) {
                printf("Digite o Peso da P%i\n", i + 1);
                scanf("%f", &Peso_provas[i]);
                system("clear");
                system("cls");
            }

            for (i = 0; i < Qtd_alunos; i++) {
                printf("Digite o nome do Aluno - %i\n", i + 1);
                scanf("%s", Aluno[i]);
                system("clear");
                system("cls");
                for (j = 0; j < Qtd_provas; j++) {
                    printf("Nota da Prova %i\n", j + 1);
                    scanf("%f", &Notas[i][j]);
                    system("clear");
                    system("cls");
                }
            }

            for (i = 0; i < Qtd_alunos; i++) {
                for (j = 0; j < Qtd_provas; j++) {
                    Media[i] = Media[i] + Notas[i][j] * Peso_provas[j];
                    temp = temp + Peso_provas[j];
                }
                Media[i] = Media[i] / temp;
            }

            break;
    }

    printf("Digite a Media Necessaria para aprovacao: ");
    scanf("%f", &Media_final);
    system("clear");
    system("cls");

    char saveChoice;

    printf("Deseja salvar os dados em um arquivo compativel com Excel? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        char fileName[100];
        printf("Insira o nome do arquivo Excel para salvar os dados: ");
        scanf("%99s", fileName);

        
        if (strstr(fileName, ".xls") == NULL) {
            strcat(fileName, ".xls");
        }

        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            printf("Nao foi possivel criar o arquivo para salvar.\n");
        } else {
            
            fprintf(file, "Nome");
            for (j = 0; j < Qtd_provas; j++) {
                fprintf(file, "\tProva %d", j + 1);
            }
            fprintf(file, "\tMedia\tAprovacao\n");

            for (i = 0; i < Qtd_alunos; i++) {
                fprintf(file, "%s", Aluno[i]);
                for (j = 0; j < Qtd_provas; j++) {
                    fprintf(file, "\t%.2f", Notas[i][j]);
                }
                fprintf(file, "\t%.2f", Media[i]);

                
                if (Media[i] >= Media_final) {
                    fprintf(file, "\tAPROVADO\n");
                } else {
                    fprintf(file, "\tREPROVADO\n");
                }
            }

            fclose(file);
            printf("Dados salvos em '%s'.\n", fileName);
        }
    } else {
        printf("Nao foi Possivel Salvar.\n");
    }

    return 0;
}
