#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    printf("Welcome.\nSelect a number to continue:\n");
    int c;
    while(1)
    {
        printf("1)Print current list.\n2)Add a task to the list.\n3)Exit.\nInput:\n>");
        scanf("%d[^\n]", &c);
        switch(c)
        {
            case 1: PrintTasks(); break;
            case 2: AddTask(); break;
            case 3: printf("\nQuitting...\nGOODBYE!\n"); goto exit; break;
            default: printf("\nINVALID! Try again.\n\n"); break;
        }
    }
    exit: return 0;
}

void PrintTasks() // Works
{
    char c;
    int lines = 0;
    FILE* fp;
    fp = fopen("TaskList.txt", "r");
    for(c = fgetc(fp); !(feof(fp));)
    {
        if(c == '\n') lines++;
        if(feof(fp)) break;
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    printf("\nPrinted task list with %d tasks.\n>Returning to menu...\n", lines);
}
void AddTask()
{
    char str[60];
    int ch;
    FILE* fp = fopen("TaskList.txt", "a"); // opens file for appending;
    printf("\nEnter task(line break to finish):\n>");
    scanf("%59s", str);
    fputs(&str, fp);
    fputc("\n", fp);
    fclose(fp);
}
