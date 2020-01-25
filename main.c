#include "frequency.h"
struct Node
{
    int numOfWord;
    int isLeaf;
    struct Node *character[CHAR_SIZE];
};
int main(int argc,char* argv[])
{
    char* x=" ";
    if (argv[1]!=NULL)
    {
        x=argv[1];
    }
    char  w[word];
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    
    while (fscanf(stdin, "%s", w) != EOF)
    {
        insert(head, w);
    }
    if (x[0]!='r')
    {
        printAllWords(head, w, 0);
    }
    else
    {
       printAllWordsrev(head, w, 0);
    }
    free(head);
    return 0;
}