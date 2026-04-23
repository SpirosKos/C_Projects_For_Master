#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Double linked-list, insert in the end of the list.
 */

typedef struct address
{
    float data;
    struct address *next;
    struct address *prior;
}info;

void dlstore(struct address *i, struct address **start,struct address **last) {
    struct address *current = *start;
    if (*last == NULL){
        *last = i;
        *start = i;
        (*last)->next = NULL;
        return;
    }

    if (i->data <= (*start)->data)
    {
        i->next = *start;
        i->prior = NULL;
        (*start)->prior=i;
        *start = i;
        return;
    }

    if (i->data > (*start)->data)
    {
        while (current->next != NULL && i->data > current->next->data)
        {
            current = current->next;   
        }
        i->next = current->next;
        i->prior = current;

        if (i->next != NULL)
        {
            (i->next)->prior = i;
        }else (*last) = i;
        
        current->next = i;
        return;
    }
}

void display(struct address *t) {
    
    if (t == NULL)
    {
        printf("List is empty\n");
    }
    while (t)
    {
        printf(" %f\n", t->data);
        t = t->next;
    }
    
    return;
}

struct address *search(struct address *t, float n) {
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
    float c;
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
            scanf(" %f", &c);
            info *newInfo = malloc(sizeof(info));
            newInfo->data = c;
            if (start == NULL)
            {
                start = newInfo;
            }
            dlstore(newInfo, &start,&last);
            printf("\n OK \n");
            break;
        case 2:
            printf("Δωσε στοιχειο για εξαγωγη: ");
            scanf(" %f", &c);
            info *p = search(start,c);
            dldelete(p,&start,&last);
            free(p);
            printf("\n Αφαιρεθηκε το στοιχειο %f \n", c);
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
