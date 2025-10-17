#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        struct node *t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = n;
    }
    printf("added %d\n", val);
}

void delBeg() {
    if (head == NULL) {
        printf("list empty\n");
        return;
    }
    struct node *temp = head;
    printf("removed %d\n", head->data);
    head = head->next;
    free(temp);
}

void delEnd() {
    if (head == NULL) {
        printf("list empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("removed %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *p = head;
    struct node *q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    printf("removed %d\n", p->data);
    q->next = NULL;
    free(p);
}

void display() {
    if (head == NULL) {
        printf("list empty\n");
        return;
    }
    struct node *t = head;
    printf("list: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    delBeg();
    display();
    delEnd();
    display();
    delBeg();
    display();
    delEnd();
    display();
    delBeg();
    return 0;
}


// code 2

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        struct node *t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = n;
        n->next = head;
    }
}

void deleteBeg() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
    struct node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    printf("Deleted %d\n", head->data);
    head = head->next;
    last->next = head;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *t = head;
    printf("List: ");
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    display();
    deleteBeg();
    display();
    return 0;
}

//code 3
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        struct node *t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = n;
        n->next = head;
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == head) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *p = head;
    struct node *prev = NULL;
    while (p->next != head) {
        prev = p;
        p = p->next;
    }
    printf("Deleted %d\n", p->data);
    prev->next = head;
    free(p);
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *t = head;
    printf("List: ");
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    insert(5);
    insert(10);
    insert(15);
    display();
    deleteEnd();
    display();
    return 0;
}
