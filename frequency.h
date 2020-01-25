
#include <stdio.h>
#include <stdlib.h>
#define CHAR_SIZE 26
#define word 256
struct Node;
void insert(struct Node *head, char *str);
int search(struct Node *head, char *str);
void printAllWords(struct Node *root, char *wordArray, int pos);
void printAllWordsrev(struct Node *root, char *wordArray, int pos);
void printWord(char *arr, int pos,int num);
void printWordR(char *arr, int pos,int num);
