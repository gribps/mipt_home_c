#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
/*
typedef struct list 
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
*/
uint64_t findMaxBlock(list *head)
{
    if(head==NULL)
        return 0;
    
    size_t max_size = 0;
    uint64_t addr;
    list *curr = head;
    while(curr != NULL)
    {
        if(max_size < curr->size)
        {
            max_size = curr->size;
            addr = curr->address;
        }
        //list *tmp = curr->next;
        //free(curr);
        //curr = tmp;
        curr = curr->next;
    }
    return addr;
}
/*
int main(void)
{
    int size_list;
    scanf(" %d ", &size_list);

    list *top = NULL;

    for(int i=0; i<size_list; i++)
    {
        list *ptr = malloc(sizeof(list));
        scanf(" %llu %d ", &ptr->address, &ptr->size);
        ptr->next = top;
        top = ptr;
    }

    printf("%llu\n", findMaxBlock(top));

    return 0;
}
    */