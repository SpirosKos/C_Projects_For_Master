#include <stdio.h>
#include <stdlib.h>
// #include <windows.h> // Comment out to use with vscode in windows for GreekLetters.

#define FALSE 0
#define TRUE 1
#define MAX 100 // Για μέγιστο μέγεθος 100 στοιχεία ακέραιου τύπου

struct stack {
    char items[MAX]; 
    int top;
};

int empty(struct stack *s) {
    if (s->top == -1)
    {
        return TRUE;
    }
    
    return FALSE;
}

int pop(struct stack *s) {
    if (empty(s))
    {
        printf("Stack underflow."); exit(1);
    }
    return s->items[s->top--];    
}

int push(struct stack *s, char x) {
    if (s->top == MAX - 1)
    {
        printf("Stack overflow"); exit(1);
    }else 
       return s->items[++(s->top)] = x;
}



int main() {
    // SetConsoleOutputCP(65001); // Comment out to use with vscode in windows for GreekLetters.

    struct stack s;
    char ch;
    int counter = 0;
    s.top = -1;

    printf("Δωστε μαθηματικες εκφρασεις, για τερματισμο Enter + Ctrl+Z: \n");
    while ((ch = getchar()) != EOF)
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            push(&s,ch);
            break;
        case ')':
            if (!empty(&s) && pop(&s) == '(')
            {
                break;
            }else push(&s,ch);
        case '}':
            if (!empty(&s) && pop(&s) == '{')
            {
                break;
            }else push(&s,ch);
        case ']':
            if (!empty(&s) && pop(&s) == '[')
            {
                break;
            }else push(&s,ch);
        default:
            break;
        }
    }
    if (empty(&s))
    {
        printf("Σωστος Υπολογισμος.");
    }else printf("Λαθος Υπολογισμος.");
    
    return 0;
}

