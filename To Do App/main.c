#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

void PrintTasks() // Works
{
    char c;
    int lines = 0;
    FILE* fp;
    fp = fopen("TaskList.txt", "r");
    while(c = fgetc(fp))
    {
        if(c == '\n') lines++;
        if(feof(fp)) break;
        printf("%c", c);
    }
    fclose(fp);
    printf("\nPrinted task list with %d tasks.\nReturning to menu.\n", lines);
}

void AddTask()
{
    scanf("\n");
    char str[60];
    scanf("%[^\n]%*s", str);
    FILE* fp = fopen("TaskList.txt", "a"); // opens file for appending
    fputs(str, fp);
    fputc('\n', fp);
    fclose(fp);
}

int main()
{
    printf("Welcome.\nSelect a number to continue:\n");
    char c;
    while(1)
    {
        printf("1)Print current list.\n2)Add a task to the list.\n3)Exit.\nInput:");
        switch(c = getchar())
        {
            case '1': PrintTasks(); break;
            case '2': AddTask(); break;
            case '3': printf("Quitting...\nGoodbye."); goto exit;
            default: printf("\nInvalid input, try again.\n");
        }
        scanf("\n");
    }
    exit: return 0;
}


