
#include "editor.h"

int main(int argc, char *argv[]) {

    if(argc == 1) /* No Command-line arguments */
    {
        printf("No file specified\n");
        return 0;
    }
    else
    {
        char *filename = *++argv;
        List *content = listCtor();
        FILE *fp = fopen(filename, "r");

        Point *CursorPos = pointCtor();
        system("cls");

        readFile(fp, content, CursorPos);
        fclose(fp);
        if(editContent(content, CursorPos) == 0)
        {
            fp = fopen(filename, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        deleteList(content);

    }

    return 0;
}
