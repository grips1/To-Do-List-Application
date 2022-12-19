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
        if(c == '.') lines++;
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
    int ch;printf("\n %s", str);
    AddTask(str);
    PrintTasks("TaskList.txt");printf("\n %s", str);
    AddTask(str);
    PrintTasks("TaskList.txt");
    PrintTasks();
    printf("Enter your task: ");
    gets(str);
    AddTask(str);
    PrintTasks();
    return 0;
}
