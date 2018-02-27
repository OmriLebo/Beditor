#include <conio.h>
#include <windows.h>
#include "linkedlist.h"

#define ZERO 0
#define NLINE 10
#define ENTERKEY 13
#define SPACEKEY 32
#define BACKSPACEKEY 8
#define TAB 9
#define ESC 27

#define ARROWKEY 224
#define ARROWUPKEY 72
#define ARROWDOWNKEY 80
#define ARROWRIGHTKEY 77
#define ARROWLEFTKEY 75

#define yKey 121
#define YKey 89
#define nKey 110
#define NKey 78

#define TRUE 1
#define FALSE 0

typedef struct ScreenPos_s
{
    int x;
    int y;
    int index;
}Point;

Point * pointCtor();
void printListChars(List *list);
void displayContent(List *list);
int lineLen(List *content, int line);
int readFile(FILE *fp, List *content, Point *CursorPos);
int editContent(List *content, Point *CursorPos);
int saveToFile(FILE *fp, List *content);
int getHeight(List *content);
int getIndex(List *content, Point *CursorPos);
