#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int PrintTasks()
{
    char c;
    int lines = 0;
    FILE* fp;
    fp = fopen("TaskList.txt", "r");
    while(1)
    {
        c = fgetc(fp);
        if(c == '\n') lines++;
        if(feof(fp)) break;
        printf("%c", c);
    }
    fclose(fp);
    printf("\nPrinted task list with %d tasks.\n", lines);
    return lines;
}
void AddTask(char Task[])
{
    FILE* fp;
    fp = fopen("TaskList.txt", "a");
    fputs(Task, fp);
    fputs(".\n", fp);
    fclose(fp);
}
int main()
{
    char str[60];
    int ch;
    PrintTasks();
    gets(str);
    AddTask(str);
    printf("\nPrinting new list...");
    PrintTasks();
    return 0;
}
