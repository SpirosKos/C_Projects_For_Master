#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Double linked-list, insert in the end of the list, with a link Node connection, Insert,Delete,Search,Display.
 */

typedef struct address
{
    char str[21];
    uintptr_t link;
}Node;

void dlstore(struct address *i, Node **start, Node **current) {

    uintptr_t first = 0;
    uintptr_t last = 0;
    if (*start == NULL)
    {
        *start = i;
        *current = i;
        i->link = (uintptr_t)(first) -(uintptr_t) (last);
    }else {
        i->link = (uintptr_t)(0) -(uintptr_t) (*current);
        (*current)->link = (*current)->link +(uintptr_t)(i);
        *current = i;
    }
}

void dldelete(Node *i, Node **start, Node **next) {
    Node *next_node, *prev = NULL, *cur = *start;
    if (*start == NULL)
    {
        printf("List is empty.Enter data.");
        return;
    }
    if (i->link == 0)
    {
        *start = NULL;
        *next = NULL;
        free(i);
        return;
    }

    while (cur != i)
    {
        next_node = (Node *)((uintptr_t)prev + (uintptr_t)cur->link);
        prev = cur;
        cur = next_node;
    }
    next_node = (Node *)((uintptr_t)prev + (uintptr_t)cur->link);

    if (prev == NULL)
    {
        *start = next_node;
    }else {
        prev->link = prev->link - (uintptr_t)cur + (uintptr_t)next_node;
    }
    
    if (next_node == NULL)
    {
        *next = prev;
    }else     next_node->link = next_node->link + (uintptr_t)cur - (uintptr_t) prev;

    free(cur);
    return;
}


void display(Node **start) {
    Node *next_node, *prev = NULL, *cur = *start;
    if (*start == NULL)
    {
        printf("List is empty\n");
    }

    printf("List:\n");
    while (cur != NULL)
    {   
        printf("\t %s\n", cur->str);
        next_node = (Node *)((uintptr_t)prev + (uintptr_t)cur->link);
        prev = cur;
        cur = next_node;
    }
    return;
}

struct address *search(Node **start, const char *str) {
    Node *next_node, *prev=NULL, *cur = *start;
    while (cur != NULL)
    {
        if (strcmp(str, cur->str) == 0)
        {
            return cur;
        }
        next_node = (Node *)((uintptr_t)prev + (uintptr_t)cur->link);
        prev = cur;
        cur = next_node;
    }

    return NULL;
}


int main(int argc, char const *argv[])
{
    Node *start = NULL;
    Node *last = NULL;

    int y;
    char tmp_str[21];
    char tmp[21];
    do
    {
        printf(
            "Choose one of the options below: \n"
            "1.Insert\n"
            "2.Delete of a string\n"
            "3.Display of list\n"
            "4.Search for string\n"
            "5.Exit\n"
            );
        scanf(" %d", &y);
        switch (y)
        {
        case 1:
            printf("Give a string for input:");
            getchar();
            fgets(tmp_str,21,stdin);
            tmp_str[strcspn(tmp_str,"\n")] = '\0';
            Node *newNode = malloc(sizeof(Node));
            strcpy(newNode->str, tmp_str);
            dlstore(newNode, &start, &last);
            printf("\nInserted String: %s \n", tmp_str);
            break;
        case 2:
            printf("Give a string to delete: ");
            getchar();
            fgets(tmp_str,21,stdin);
            tmp_str[strcspn(tmp_str,"\n")] = '\0';
            Node *d = search(&start,tmp_str);
            if (d != NULL)
            {
                dldelete(d,&start, &last);

            }
            if (d)
            {
                printf("\n Αφαιρεθηκε το στοιχειο %s \n", tmp_str);
            }
            break;
        case 3:
            display(&start);
            break;
        case 4:
            printf("Give a string to search:");
            getchar();
            fgets(tmp_str,21,stdin);
            tmp_str[strcspn(tmp_str,"\n")] = '\0';
            Node *p =search(&start, tmp_str);
            if (p != NULL)
            {
                printf("String Found %s in Memory Address %p", p->str, p);
            }else printf("Does not exist.");
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong choice.Choose again.");
            break;
        }
        
    } while (1);
    return 0;
}
