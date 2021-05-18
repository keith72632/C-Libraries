/**************************************************************************************
 *                                 Linked Lists                                       *
 *************************************************************************************/

#include <stdio.h>
#include <stdint.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"

//Node structure is padded to 24 bytes. Use this to pack
//#pragma pack(1)

//packed should make the size of node 17 bytes
struct node {
    struct node *next;
    struct node *prev;
    uint8_t     data;
    uint8_t     isTrue;
}__attribute__((packed));

void initNode(struct node *node, uint8_t data, struct node *prev, struct node *next, uint8_t isTrue)
{
    node->data = data;
    node->next = next;
    node->prev = prev;
    if(isTrue) node->isTrue = 1;
}

void *findTrue(struct node *head)
{
    struct node *buf = head;
    while(buf != NULL)
    {
        if(buf->isTrue) return buf;
        buf = buf->next;
    }
    return NULL;
}

int main()
{
    struct node first, second, third;

    initNode(&first, 11, NULL, &second, 0);
    initNode(&second, 22, &first, &third, 0);
    initNode(&third, 33, &second, NULL, 1);

    printf("Data from first node    : %d\n", first.data);
    printf("Data from second node   : %d\n", second.data);
    printf("Data from third node    : %d\n", third.data);
    printf("\n");

    printf("Size of node structure  : %lu\n", sizeof(struct node));

    //While the size of node is 17 byte, compiler aligns each node 20 bytes apart
    printf("Address of first node   : %s%p%s\n", KRED, &first, KNRM);
    printf("Address of second node  : %s%p%s\n", KGRN, &second, KNRM);
    printf("Address of third node   : %s%p%s\n", KYEL, &third, KNRM);

    printf("Address of first.prev   : %p\n", first.prev);
    printf("Address of first.next   : %s%p%s (second node)\n", KGRN, first.next, KNRM);

    printf("Address of second.prev  : %s%p%s (first node)\n", KRED, second.prev, KNRM);
    printf("Address of second.next  : %s%p%s (third node)\n", KYEL, second.next, KNRM);

    printf("Address of third.prev   : %s%p%s (second node)\n", KGRN, third.prev, KNRM);
    printf("Address of third.next   : %p\n", third.next);

    //find node with true boolian
    struct node *new = (struct node *)findTrue(&first);
    if(new != NULL) printf("Value of data from node: %d\n", new->data);



    return 0;
}
