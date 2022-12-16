#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    FILE* FP;
    FP = fopen("TaskCache.txt", "r");
    int c;
    int x = 0;
    while(1)
    {
        c = fgetc(FP);
        if(feof(FP)) break;
        printf("%c", c);

    }
    fclose(FP);
    return 0;

}
