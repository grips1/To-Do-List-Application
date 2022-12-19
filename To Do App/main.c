#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int PrintTasks(char* filename)
{
    char c;
    int lines = 0;
    FILE* fp;
    fp = fopen(filename, "r");
    while(1)
    {
        c = fgetc(fp);
        if(c == '.') lines++;
        if(feof(fp)) break;
        printf("%c", c);
    }
    fclose(fp);
    printf("\n\nPrinted task list with %d tasks.\n", lines);
    return lines;
}

int main()
{
    PrintTasks("TaskList.txt");
    return 0;
}
