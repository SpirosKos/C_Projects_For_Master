#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Double linked-list, insert in the end of the list.
 */

typedef struct address
{
    double data;
    struct address *next;
    struct address *prior;
}info;

void dlstore(struct address *i, struct address **last) {
    if (*last)
    {
        (*last)->next = i;
        i->prior = *last;
    }else i->prior = NULL;

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
        printf(" %lf\n", t->data);
        t = t->next;
    }
    
    return;
}

struct address *search(struct address *t, double n) {
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

void dldelete(struct address *p, struct address **start, struct address **last) {
    if (p->prior)
    {
        (p->prior)->next = p->next;
        if (p->next)
        {
            (p->next)->prior = p->prior;  
        }else *last = p->prior;
    }else {
        if (p->next)
        {
            (p->next)->prior = NULL;
        }
        *start = p->next;
    }
    return;
}

int main(int argc, char const *argv[])
{

    info *last = NULL;
    info *start = NULL;
    double c;
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
            scanf(" %lf", &c);
            info *newInfo = malloc(sizeof(info));
            newInfo->data = c;
            if (start == NULL)
            {
                start = newInfo;
            }
            dlstore(newInfo,&last);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            scanf(" %lf", &c);
            info *p = search(start,c);
            dldelete(p,&start,&last);
            free(p);
            printf("\n Αφαιρεθηκε το στοιχειο %lf \n", c);
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
