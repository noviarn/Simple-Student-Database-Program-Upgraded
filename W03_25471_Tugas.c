#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct
{
    char nim[15];
    char nama[100];
    char jurusan[50];
}Student;

typedef struct
{
    char nim[15];
    float tugas;
    float uts;
    float uas;
    float nakhir;
    char grade[2];
}Nilai;

void inputStudent(Student student[], Nilai nilai[], int i)
{
    FILE *fa1=fopen("dataMahasiswa.txt", "a");
    FILE *fa2=fopen("nilaiMahasiswa.txt", "a");

    system("cls");
    printf("  Insert Student Information  ");
    printf("\n------------------------------");
    printf("\nNIM\t\t: ");
    scanf("%s", student[i].nim);
    fflush(stdin);
    printf("Name\t\t: ");
    scanf("%[^\n]s", student[i].nama);
    fflush(stdin);
    printf("Major\t\t: ");
    scanf("%[^\n]s", student[i].jurusan);
    fflush(stdin);

    fprintf(fa1, "%s#%s#%s\n", student[i].nim, student[i].nama, student[i].jurusan);

    printf("\n  Insert Student Score  ");
    printf("\n------------------------------");
    printf("\nTask\t\t: ");
    scanf("%f", &nilai[i].tugas);
    printf("Mid Term\t: ");
    scanf("%f", &nilai[i].uts);
    printf("Final Term\t: ");
    scanf("%f", &nilai[i].uas);
    nilai[i].nakhir=(nilai[i].tugas*0.3)+(nilai[i].uts*0.3)+(nilai[i].uas*0.4);
    printf("%.2f\n", nilai[i].nakhir);
    if(nilai[i].nakhir>=85)
    {
        strcpy(nilai[i].grade, "A");
        printf("%s", nilai[i].grade);
    }
        else if(nilai[i].nakhir>=80 && nilai[i].nakhir<85)
        {
            strcpy(nilai[i].grade, "A-");
            printf("%s", nilai[i].grade);
        }
            else if(nilai[i].nakhir>=75 && nilai[i].nakhir<80)
            {
                strcpy(nilai[i].grade, "B+");
                printf("%s", nilai[i].grade);
            }
                else if(nilai[i].nakhir>=70 && nilai[i].nakhir<75)
                {
                    strcpy(nilai[i].grade, "B");
                    printf("%s", nilai[i].grade);
                }
                    else if(nilai[i].nakhir>=65 && nilai[i].nakhir<70)
                    {
                        strcpy(nilai[i].grade, "C+");
                        printf("%s", nilai[i].grade);
                    }
                        else if(nilai[i].nakhir>=60 && nilai[i].nakhir<65)
                        {
                            strcpy(nilai[i].grade, "C");
                            printf("%s", nilai[i].grade);
                        }
                            else if(nilai[i].nakhir>=55 && nilai[i].nakhir<60)
                            {
                                strcpy(nilai[i].grade, "D");
                                printf("%s", nilai[i].grade);
                            }
                                else if(nilai[i].nakhir<55)
                                {
                                    strcpy(nilai[i].grade, "E");
                                    printf("%s", nilai[i].grade);
                                }
    printf("%\nFinal Score\t: %.2f", nilai[i].nakhir);
    printf("%\nGrade\t\t: %s", nilai[i].grade);

    fprintf(fa2, "%s#%f#%f#%f#%.1f#%s\n", student[i].nim, nilai[i].tugas, nilai[i].uts, nilai[i].uas, nilai[i].nakhir, nilai[i].grade);

    fclose(fa1);
    fclose(fa2);

    getch();
    printf("\n\nInserting Data\n");
    getch();
    printf("\nNew student added\n");
    printf("Press any key to continue");
    i++;
    getch();
}

void showStudent(Student student[], int count_lines, int a)
{
    FILE *fss1=fopen("dataMahasiswa.txt", "r");

    while(!feof(fss1))
    {
        fscanf(fss1, "%[^#]#%[^#]#%[^\n]\n", student[a].nim, student[a].nama, student[a].jurusan);
        a++;
    }
    fclose(fss1);

    system("cls");
    printf("\t\t\tList of Student Information                \n");
    printf("---------------------------------------------------------------------------\n");
    printf("|No.|              Name              |         Major        |     NIM     |\n");
    printf("---------------------------------------------------------------------------\n");
    for(a=0;a<count_lines;a++)
    {
        printf("|%-2d | %-30s | %-20s | %-11s |\n", a+1, student[a].nama, student[a].jurusan, student[a].nim);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("\nPress any key to go back");
    getch();
}

void showScore(Nilai nilai[], int count_lines, int a)
{
    FILE *fss2=fopen("nilaiMahasiswa.txt", "r");

    while(!feof(fss2))
    {
        fscanf(fss2, "%[^#]#%f#%f#%f#%f#%s\n", nilai[a].nim, &nilai[a].tugas, &nilai[a].uts, &nilai[a].uas, &nilai[a].nakhir, nilai[a].grade);
        a++;
    }
    fclose(fss2);

    system("cls");
    printf("\t\t      List of Student Information                \n");
    printf("-----------------------------------------------------------------------\n");
    printf("|No.|     NIM     |  Task  | Mid Term | Final Term |  Total  |  Grade |\n");
    printf("-----------------------------------------------------------------------\n");
    for(a=0;a<count_lines;a++)
    {
        printf("|%-2d | %-11s | %-6.2f | %-8.2f | %-10.2f | %-7.2f | %-6s |\n", a+1, nilai[a].nim, nilai[a].tugas, nilai[a].uts, nilai[a].uas, nilai[a].nakhir, nilai[a].grade);
    }
    printf("-----------------------------------------------------------------------\n");
    printf("\nPress any key to go back");
    getch();
}

int main()
{
    int i=0, a, choose, count_lines=0;
    char chr;

    Student student[100];
    Nilai nilai[100];

    FILE *fp=fopen("dataMahasiswa.txt", "r");

    while(!feof(fp))
    {
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        chr = getc(fp);
    }
    fclose(fp);

    do
    {
        system("cls");
        printf("Welcome to Simple Student Database (%d/100)", count_lines);
        printf("\n1. Input new student");
        printf("\n2. Show all students");
        printf("\n3. Show all scores");
        printf("\n0. Exit");
        printf("\nChoose: ");
        scanf("%d", &choose);

        switch(choose)
        {
            case 1:
                    if(count_lines>=100)
                    {
                        printf("Database is full");
                        printf("\nPress any key to continue");
                        getch();
                    }
                    else
                    {
                        inputStudent(student, nilai, i);
                        count_lines++;
                    }
                    break;
            case 2:
                    showStudent(student, count_lines, a);
                    break;
            case 3:
                    showScore(nilai, count_lines, a);
                    break;
        }
    }while(choose!=0);

    return 0;
}
