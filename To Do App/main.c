#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    printf("Welcome.\nSelect a number to continue:\n");
    char c;
    while(1)
    {
        if(!(c == '\n')) printf("1)Print current list.\n2)Add a task to the list.\n3)Exit.\nInput:");
        switch(c = getchar())
        {
            case '1': PrintTasks(); break;
            case '2': AddTask(); break;
            case '3': printf("Quitting...\nGoodbye."); goto exit;
            default: printf("\nInvalid input, try again.\n");
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
    printf("\nPrinted task list with %d tasks.\nReturning to menu.\n", lines);
}
void AddTask()
{
    char str[60];
    int ch;
    FILE* fp = fopen("TaskList.txt", "a"); // opens file for appending;
    for(int index = 0; (ch = getchar()) != '.'; index++)
    {
        fputs(ch, fp);
    }
    fputc("\n", fp);
    fclose(fp);
}