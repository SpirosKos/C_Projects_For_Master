#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Simple linked-list insert in the end of the list.
 */

typedef struct address
{
    char data;
    struct address *next;
}info;

void slstore(struct address *i, struct address **last) {
    if (*last)
    {
        (*last)->next = i;
    }
    i->next = NULL;
    *last = i;
}

void display(struct address *t) {
    
    if (t == NULL)
    {
        printf("List is empty\n");
    }
    while (t)
    {
        printf(" %c\n", t->data);
        t = t->next;
    }
    
    return;
}

struct address *search(struct address *t, char n) {
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

int main(int argc, char const *argv[])
{

    info *last = NULL;
    info *start = NULL;
    char c;
    int y;
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
            scanf(" %c", &c);
            info *newInfo = malloc(sizeof(info));
            newInfo->data = c;
            if (start == NULL)
            {
                start = newInfo;
            }
            slstore(newInfo,&last);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            scanf(" %c", &c);
            info *p = start;
            info *d = search(start->next,c);
            sldelete(p,d,&start,&last);
            free(d);
            printf("\n Αφαιρεθηκε το στοιχειο %c \n", c);
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
