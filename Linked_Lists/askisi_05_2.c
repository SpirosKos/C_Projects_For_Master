#include <stdio.h>
#include <stdlib.h>

/**
 * Linked-List Program that inserts and sorts from Higher to smaller number.Deletes and Display on demand also.
 */

typedef struct address {
    int data;
    struct address *next;
}info;

void sls_store(struct address *p, struct address **start, struct address **last) {
    struct address *current = (*start);
    int tmp;

    if (*last == NULL)
    {
        *last = p;
        *start = p;
        (*last)->next = NULL;
        return;
    }
    if (p->data >= (*start)->data)
    {
        p->next = *start;
        *start = p;
        return;
    }
    if (p->data < (*start)->data)
    {
        while (current->next != NULL && p->data < current->next->data)
        {
            current = current->next;   
        }
        p->next = current->next;
        current->next = p;
        if (p->next == NULL)
        {
            *last = p;
        }
        
        return;
    }
}

void display(struct address *p) {
    
    if (p == NULL)
    {
        printf("List is empty.\n");
    }

    while(p){
        printf("::%d::\n", p->data);
        p = p->next;
    }
    return;
}

void sldelete(struct address *p, struct address *d, struct address **start, struct address **last) {
    if (p)
    {
        p->next = d->next;
    }else {
        *start = d->next;
    }
    if (d == *last && p)
    {
        *last = p;
    }
    return;
}

struct address *search(struct address *t, int n) {
    while (t)
    {
        if (n == t->data)
        {
            return t;
        }
        t = t->next;
    }

    return NULL;
}

int main(int argc, char const *argv[])
{

    info *last = NULL;
    info *start = NULL;
    int y, c;
    do
    {
        printf(
            "Διαλεξτε απο τις παρακατω επιλογες: \n"
            "1.Εισαγωγη\n"
            "2.Διαγραφη στοιχειου\n"
            "3.Εκτυπωση λιστας\n"
            "4.Εξοδος\n"
            );
        scanf("%d", &y);
        switch (y)
        {
        case 1:
            printf("Δωσε στοιχειο για εισαγωγη: ");
            scanf("%d", &c);
            info *newInfo = malloc(sizeof(info));
            newInfo->data = c;
            sls_store(newInfo, &start, &last);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            scanf("%d", &c);
            info *p = start;
            info *d = search(start->next,c);
            sldelete(p, d, &start, &last);
            free(d);
            printf("\n Αφαιρεθηκε το στοιχειο %d \n", c);
            break;
        case 3:
            display(start);
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
