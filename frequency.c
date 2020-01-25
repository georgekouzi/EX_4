#include "frequency.h"
struct Node
{
    int numOfWord;
    int isLeaf;
    struct Node *character[CHAR_SIZE];
};

void insert(struct Node *head, char *str)
{
    struct Node *curr = head;
    while (*str)
    {
        if (curr->character[*str - 'a'] == NULL)
        {
            struct Node *node = (struct Node *)malloc(sizeof(struct Node));
            node->isLeaf = 0;
            node->numOfWord = 0;
            for (int i = 0; i < CHAR_SIZE; i++)
                node->character[i] = NULL;
            curr->character[*str - 'a'] = node;
        }
        curr = curr->character[*str - 'a'];
        str++;
    }
    curr->isLeaf = 1;
    curr->numOfWord++;
}

int search(struct Node *head, char *str)
{
    if (head == NULL)
        return 0;

    struct Node *curr = head;
    while (*str)
    {
        curr = curr->character[*str - 'a'];
        if (curr == NULL)
            return 0;
        str++;
    }
    return curr->numOfWord;
}

void printAllWords(struct Node *root, char *wordArray, int pos)
{
    if (root == NULL)
    {
        return;
    }
    if (root->numOfWord != 0)
    {
        int num=root->numOfWord;
        printWord(wordArray, pos,num);
    }
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (root->character[i] != NULL)
        {
            wordArray[pos] = i + 'a';
            printAllWords(root->character[i], wordArray, pos + 1);
        }
    }
}
void printAllWordsrev(struct Node *root, char *wordArray, int pos)
{
    if (root == NULL)
    {
        return;
    }
    if (root->numOfWord != 0)
    {
        int num=root->numOfWord;
        printWordR(wordArray, pos,num);
    }
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (root->character[i] != NULL)
        {
            wordArray[pos] = i + 'a';
            printAllWordsrev(root->character[i], wordArray, pos + 1);
        }
    }
}
void printWord(char *arr, int pos,int num)
{
    printf(" ");
    for (size_t i = 0; i < pos; i++)
    {
        printf("%c", *(arr + i));
    }
    printf(" %d\n",num);
}
void printWordR(char *arr, int pos,int num)
{
    printf(" ");
    for (int i = 1; i <= pos; i++)
    { 
        printf("%c", *(arr + (pos-i)));
    }
printf(" %d\n",num);
}