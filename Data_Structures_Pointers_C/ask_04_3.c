#include <stdlib.h>
#include <stdio.h>
// #include <windows.h> // Comment out to use with vscode in windows for GreekLetters.

#define MAX 6   // Max θεσεις 5
#define TRUE 1
#define FALSE 0

typedef struct queue {
    int items[MAX];
    int front, rear;
}q;

int empty(q *c) {
    if (c->front == c->rear)
    {
        return TRUE;
    }
    return FALSE;
}

int increment(int a,int max) {
    if (a < max - 1)
    {
        a++;
    }else a = 0;
    return a;
}

void insert(q *c, int x){
    int h;
    h = increment(c->rear, MAX);
    if (h != c->front)
    {
        c->rear = h; c->items[c->rear] = x;
    }else {
        printf(" queue overflow"); exit(1);
    }
    return;
}

int sremove(q *c) {
    if (empty(c))
    {
        printf("Empty queue"); return 0;
    }else{
        c->front = increment(c->front,MAX);
        return c->items[c->front];
    }
}


int main(int argc, char const *argv[])
{

    // SetConsoleOutputCP(65001);       // Comment out to use with vscode in windows for GreekLetters.
    
    
    struct queue q;
    q.front = 0; q.rear = 0;
    int y,x,s;
    int i = q.front;
    do
    {
        printf(
            "Διαλεξτε απο τις παρακατω επιλογες: \n"
            "1.Εισαγωγη\n"
            "2.Εξαγωγη\n"
            "3.Ελεγχος FIFO\n"
            "4.Εξοδος\n"
            );
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Δωσε στοιχειο για εισαγωγη: ");
            scanf("%d", &x);
            insert(&q,x);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            scanf("%d", q);
            s = sremove(&q);
            printf("\n Αφαιρεθηκε το στοιχειο %d \n", s);
            break;
        case 3:
            if (empty(&q))
            {
                printf("Η ουρα ειναι αδεια.");
            }else {
                printf("Η ουρα εχει στοιχεια: ");
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Λαθος επιλογη.Επελεξε ξανα.");
            break;
        }
        
        
    } while (1);
    
    return 0;
}
