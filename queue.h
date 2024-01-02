#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef QUEUE_H
#define QUEUE_H
typedef struct Item{
    char* c;
    struct Item* next;
} Item;
typedef struct Queue{
    Item* head;
    Item* tail;
    void (*put)(struct Queue *this);
    void (*update)(struct Queue *this, char data);
    void (*print)(struct Queue *this);
    void (*frees)(struct Queue *this);
    void (*delete_elements)(struct Queue *this, char* str);
    void (*double_all_even)(struct Queue *this);
    void (*insert_after_word)(struct Queue *this, char* str, const char* str2);
} Queue;
extern const struct QueueClass{
    Queue* (*new)();
} QueueConstructor;
#endif