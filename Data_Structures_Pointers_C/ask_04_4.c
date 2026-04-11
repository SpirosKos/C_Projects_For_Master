#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>     for windows greek letters for vscode.

#define MAX 7 
#define TRUE 1
#define FALSE 0

typedef struct myNode{
    float data;
    struct myNode *next;
}node;

typedef struct {
    node *front;
    node *rear;
    int counter;
}Queue;

int increment(Queue *s, int max) {
    if (s->counter < max - 1)
    {
        s->counter++;
    }else s->counter = 0;
    return s->counter;
}

int empty(Queue *x) {
    if (x->front == NULL)
    {
        return TRUE;
    }
    return FALSE;
};


float dequeue(Queue *s) {

    node *temp = s->front;
    float tmp;

    if (empty(s))
    {
        printf("Stack Underflow"); exit(1);
    }

    if (s->counter == 1)
    {
        tmp = s->front->data;
        s->front = s->rear = NULL;
        s->counter--;
        free(temp);
        return tmp;
    }else {
        temp = s->front;
        tmp = s->front->data;
        s->front = temp->next;
        s->rear->next = s->front;
        s->counter--;
        free(temp);
        return tmp;
    }
}

void enqueue(Queue *s, float x) {
    if (s->counter == MAX - 1)
    {
        printf("Γεματη λιστα"); exit(1);
    }

    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Stack overflow."); exit(1);
    }
    if (empty(s))
    {
        newNode->data = x;
        s->front = s->rear = newNode->next = newNode;
        s->counter++;
    }else
        {
        newNode->data = x;
        newNode->next = s->front;
        s->rear->next = newNode;
        s->rear = newNode;
        s->counter++;
        }
    }

int main(int argc, char const *argv[])
{
    // SetConsoleOutputCP(65001);   // Comment out to use with vscode in windows for GreekLetters.

    struct myNode *n = NULL;
    Queue q = {NULL,NULL,0};
    
    int y;
    float x,s;
    int counter =0;

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
            scanf("%f", &x);
            enqueue(&q,x);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            // scanf("%d", q);
            s = dequeue(&q);
            printf("\n Αφαιρεθηκε το στοιχειο %.2f \n", s);
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
