#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    char word[20];
    struct list *next;
} list_t;

void add_to_list(list_t **head, char *str)
{
    list_t *new = calloc(1, sizeof(list_t));
    strncpy(new->word, str, sizeof(new->word)-1);
    new->word[sizeof(new->word)] = '\0';
    new->next = *head;
    *head = new;
}

void print_list(list_t *head)
{
    while(head)
    {
        //printf("adr_next: %p id_word: %s \n", head->next, head->word);
        printf("%s ", head->word);
        head=head->next;
    }
    printf("\n");
}

void delete_list(list_t *head)
{
    list_t *ptr;
    while(head)
    {
        ptr = head->next;
        free(head);
        head = ptr;
    }
}

void swap_elements(list_t *a, list_t *b)
{
    if(a==NULL || b==NULL || a==b)
        return;
    
    char tmp[20];
    strcpy(tmp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, tmp);
}

void sort_list(list_t *head)
{
    if(head==NULL || head->next==NULL)
        return;
    
    int swapped;
    list_t *ptr1;
    list_t *lptr = NULL;
    do
    {
        swapped = 0;
        ptr1 = head;
        while(ptr1->next != lptr)
        {
            if(strcmp(ptr1->word, ptr1->next->word) > 0)
            {
                swap_elements(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main(void)
{
    list_t *head = NULL;

    char buff[1000];
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        char *token = strtok(buff, ". \t\n");
        while(token != NULL)
        {
            //printf("%s\n", token);
            add_to_list(&head, token);
            token = strtok(NULL, ". \t\n");
        }
    }

    sort_list(head);
    print_list(head);
    delete_list(head);

    return 0;
}