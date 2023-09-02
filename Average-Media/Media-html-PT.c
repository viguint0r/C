#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int Qtd_provas, Qtd_alunos, tipo, i, j;

    printf("Qual Tipo de Media Voce Deseja Realizar\n\nAritmetica - 1\nPonderada - 2\n");
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

    printf("Digite a Media necessaria para aprovacao: ");
    scanf("%f", &Media_final);
    system("clear");
    system("cls");

    char saveChoice;

    printf("Voce deseja salvar os dados em um arquivo HTML? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        char fileName[100];
        printf("Entre com um nome para o arquivo: ");
        scanf("%99s", fileName);

        
        if (strstr(fileName, ".html") == NULL) {
            strcat(fileName, ".html");
        }

        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            printf("Nao foi Possivel criar o arquivo.\n");
        } else {
            
            fprintf(file, "<html>\n<head>\n<style>\n");
            fprintf(file, "td.aprovado { color: green; }\n");
            fprintf(file, "td.reprovado { color: red; }\n");
            fprintf(file, "table { border-collapse: collapse; width: 50%%; }\n");
            fprintf(file, "th, td { border: 1px solid black; padding: 8px; text-align: left; }\n");
            fprintf(file, "</style>\n</head>\n<body>\n");

            
            fprintf(file, "<table>\n<tr><th>Nome</th>");
            for (j = 0; j < Qtd_provas; j++) {
                fprintf(file, "<th>Prova %d</th>", j + 1);
            }
            fprintf(file, "<th>Media</th><th>Aprovacao</th></tr>\n");

            for (i = 0; i < Qtd_alunos; i++) {
                fprintf(file, "<tr><td>%s</td>", Aluno[i]);
                for (j = 0; j < Qtd_provas; j++) {
                    fprintf(file, "<td>%.2f</td>", Notas[i][j]);
                }
                fprintf(file, "<td>%.2f</td>", Media[i]);

                
                if (Media[i] >= Media_final) {
                    fprintf(file, "<td class=\"aprovado\">APROVADO</td></tr>\n");
                } else {
                    fprintf(file, "<td class=\"reprovado\">REPROVADO</td></tr>\n");
                }
            }

            fprintf(file, "</table>\n</body>\n</html>\n");
            fclose(file);
            printf("Dados salvos em '%s'.\n", fileName);
        }
    } else {
        printf("Nao foi possivel salvar os dados.\n");
    }

    return 0;
}
