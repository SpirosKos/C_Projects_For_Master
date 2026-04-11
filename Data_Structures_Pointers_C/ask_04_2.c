#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>     // Comment out to use with vscode in windows for GreekLetters.

#define FALSE 0
#define TRUE 1

struct StackNode {
    char ch; 
    struct StackNode *next;
};

// Ελεγχει αν ειναι null;
int empty(struct StackNode *st) {
    if ( st == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

//Αφαιρει τον αντιστοιχο χαρακτηρα και χρησιμοποιει tmp για να δειξει το προηγουμενο node
char pop(struct StackNode **ps) {
    struct StackNode *temp = *ps;
    char tmp;
    if (empty(*ps))
    {
        printf("Stack underflow."); exit(1);
    }
    temp = *ps;
    tmp = temp->ch;
    *ps = temp->next;
    free(temp);
    return tmp;
}

//Pusharei νεο χαρακτηρα με δημιουργια νεου node στην μνημη.
void push(struct StackNode **ps, char ch) {
    struct StackNode *new_node = malloc(sizeof(struct StackNode));

    if (new_node == NULL)
    {
        printf("Stack overflow"); exit(1);
    }else 
    new_node->ch = ch;
    new_node->next = *ps;
    *ps = new_node;
}



int main() {

    // SetConsoleOutputCP(65001);   // Comment out to use with vscode in windows for GreekLetters.

    struct StackNode *st;
    st = NULL;
    char ch;
    int counter = 0;

    printf("Δωστε μαθηματικες εκφρασεις, για τερματισμο Enter + Ctrl+Z: \n");
    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            push(&st,ch);
            break;
        case ')':
            if (!empty(st) && pop(&st) == '(')
            {
                break;
            }else push(&st,ch);
        case '}':
            if (!empty(st) && pop(&st) == '{')
            {
                break;
            }else push(&st,ch);
        case ']':
            if (!empty(st) && pop(&st) == '[')
            {
                break;
            }else push(&st,ch);
        default:
            break;
        }
    }
    if (empty(st))
    {
        printf("Σωστος Υπολογισμος.");
    }else printf("Λαθος Υπολογισμος.");
    
    return 0;
}

