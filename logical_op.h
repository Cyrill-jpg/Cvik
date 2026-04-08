//
// Created by cyrill on 2026-04-08.
//

#ifndef UNTITLED_LOGICAL_OP_H
#define UNTITLED_LOGICAL_OP_H


typedef struct {
    unsigned char size;
    int *element;
}SETOFINT;


SETOFINT *soi_intersection(SETOFINT *a, SETOFINT *b) {
    int *temp = malloc(sizeof(int)*(a->size+b->size));
    if (temp == NULL) return NULL;
    int s = 0;
    int i = 0, j = 0;
    do {
        if (a->element[i] == b->element[j]) {
            temp[s] = a->element[i];
            s++;
            i++;j++;
        }
        else {
            if (a->element[i] > b->element[j]) j++;
            else i++;
        }
    }while (i < a->size && j < b->size);

    SETOFINT *c = malloc(sizeof(SETOFINT));
    if (c == NULL) return NULL;
    c->size = s;
    c->element = malloc(sizeof(int)*s);
    if (c->element == NULL) return NULL;
    for (int k = 0; k < s; k++) {
        c->element[k] = temp[k];
    }
    free(temp);
    return c;
}

SETOFINT *soi_union(SETOFINT *a, SETOFINT *b) {
    int *temp = malloc(sizeof(int)*(a->size+b->size));
    if (temp == NULL) return NULL;
    int s = 0;
    int i = 0, j = 0;
    do {
        if (a->element[i] == b->element[j]) {
            temp[s] = b->element[j];
            s++;
            i++;j++;
        }
        else {
            if (a->element[i] > b->element[j]) {
                temp[s] = b->element[j];
                s++;
                j++;

            }

            else {
                temp[s] = a->element[i];
                s++;
                i++;
            }
        }
    }while (i < a->size && j < b->size);
    if (i >= a->size) for (j; j< b->size; j++) {
        temp[s] = b->element[j];
        s++;
    }
    else for (i; i< a->size; i++) {
        temp[s] = a->element[i];
        s++;
    }
    SETOFINT *c = malloc(sizeof(SETOFINT));
    if (c == NULL) return NULL;
    c->size = s;
    c->element = malloc(sizeof(int)*s);
    if (c->element == NULL) return NULL;
    for (int k = 0; k < s; k++) {
        c->element[k] = temp[k];
    }
    free(temp);
    return c;
}

SETOFINT *soi_difference(SETOFINT *a, SETOFINT *b) {
    int *temp = malloc(sizeof(int)*(a->size+b->size));
    if (temp == NULL) return NULL;
    int s = 0;
    int i = 0, j = 0;
    do {
        if (a->element[i] == b->element[j]) {
            i++;j++;
        }
        else {
            if (a->element[i] < b->element[j]) {
                temp[s] = a->element[i];
                s++;
                i++;
            }
            else j++;
        }
    }while (i < a->size && j < b->size);

    if (i < a->size) for (i; i< a->size; i++) {
        temp[s] = a->element[i];
        s++;
    }
    SETOFINT *c = malloc(sizeof(SETOFINT));
    if (c == NULL) return NULL;
    c->size = s;
    c->element = malloc(sizeof(int)*s);
    if (c->element == NULL) return NULL;
    for (int k = 0; k < s; k++) {
        c->element[k] = temp[k];
    }
    free(temp);
    return c;
}

SETOFINT *soi_sym_difference(SETOFINT *a, SETOFINT *b) {
    int *temp = malloc(sizeof(int)*(a->size+b->size));
    if (temp == NULL) return NULL;
    int s = 0;
    int i = 0, j = 0;
    do {
        if (a->element[i] == b->element[j]) {
            i++;j++;
        }
        else {
            if (a->element[i] < b->element[j]) {
                temp[s] = a->element[i];
                s++;
                i++;
            }
            else {
                temp[s] = b->element[j];
                s++;
                j++;
            }
        }
    }while ( i < a->size && j < b->size);
    if (i >= a->size) for (j; j< b->size; j++) {
        temp[s] = b->element[j];
        s++;
    }
    else for (i; i< a->size; i++) {
        temp[s] = a->element[i];
        s++;
    }
    SETOFINT *c = malloc(sizeof(SETOFINT));
    if (c == NULL) return NULL;
    c->size = s;
    c->element = malloc(sizeof(int)*s);
    if (c->element == NULL) return NULL;
    for (int k = 0; k < s; k++) {
        c->element[k] = temp[k];
    }
    free(temp);
    return c;
}

void show() {
    SETOFINT a, b;
    SETOFINT *c;
    int n, m;
    printf("Size of first set: ");
    scanf("%d", &n);
    a.size = n;
    a.element = malloc(sizeof(int)*n);
    if (a.element == NULL) return;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a.element[i]);
    }
    printf("Size of second set: ");
    scanf("%d", &m);
    b.size = m;
    b.element = malloc(sizeof(int)*m);
    if (b.element == NULL) return;
    for (int i = 0; i < m; i++) {
        scanf("%d", &b.element[i]);
    }
    printf("Union: ");
    c = soi_union(&a,&b);
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->element[i]);
    }
    free(c);
    printf("\nIntersection: ");
    c = soi_intersection(&a,&b);
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->element[i]);
    }
    free(c);
    printf("\nDifference A/B: ");
    c = soi_difference(&a,&b);
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->element[i]);
    }
    free(c);
    printf("\nDifference B/A: ");
    c = soi_difference(&b,&a);
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->element[i]);
    }
    free(c);
    printf("\nSym Difference: ");
    c = soi_sym_difference(&a,&b);
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->element[i]);
    }
    free(c->element);
    free(c);
    free(a.element);
    free(b.element);

}

#endif //UNTITLED_LOGICAL_OP_H