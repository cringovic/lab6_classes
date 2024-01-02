#include "queue.h"
static void put(Queue *this){
    Item* new = calloc(1, sizeof(Item));
    if (!new) return;
    new->c = calloc(1, 1);
    new->next=NULL;
    if (!this->head){
        this->head = new;
        this->tail = new;
    } else {
        this->tail->next = new;
        this->tail = new;
    }
}
static void update(Queue *this, char data){
    int lencur = strlen(this->tail->c);
    if (this->tail->c == NULL) this->tail->c = calloc(lencur+2, sizeof(char));
    else {
        this->tail->c = realloc(this->tail->c, lencur+2);
        this->tail->c[lencur+1] = 0;
    }; 
    this->tail->c[lencur] = data;
}
static void print(Queue *this){
    Item *ptr = this->head;
    while(ptr){
        printf("%s ", ptr->c);
        ptr = ptr->next;
    }
    printf("\n");
}
static void frees(Queue *this){
    Item *ptr = this->head, *ptr_prev = NULL;
    while(ptr){
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev->c);
        free(ptr_prev);
    }
    free(this);
}
static void insert_after_word(Queue *this, char* str, const char* str2){
    Item* current = this->head;
    while(current != NULL){
        if (!strcmp(current->c, str)){
            Item* new = calloc(1, sizeof(Item));
            new->c = strdup(str2);
            new->next = current->next;
            current->next = new;
            break;
        } else {
            current = current->next;
        }
    }
}
static void double_all_even(Queue *this){
    Item *current = this->head;
    while (current != NULL) {
        if (strlen(current->c)%2==0){
            Item *new = calloc(1, sizeof(Item));
            new->c = strdup(current->c);
            new->next = current->next;
            current->next = new;
            current = current->next->next;
        } else {
            current = current->next;
        }
    }
}
static void delete_elements(Queue *this, char *str) {
    if (this->head == NULL) { 
        return;
    }
    Item *current = this->head;
    Item *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->c, str) == 0) {
            Item *temp = current;
            if (prev == NULL) {
                this->head = current->next;
                if (this->head == NULL) {
                    this->tail = NULL;
                }
            } else {
                prev->next = current->next;
                if (prev->next == NULL) {
                    this->tail = prev;
                }
            }
            current = current->next;
            free(temp->c); 
            free(temp);  
        } else {
            prev = current;
            current = current->next;
        }
    }
}
static Queue* new(){
    Queue* b = calloc(1, sizeof(Queue));
    b->head = NULL;
    b->tail = NULL;

    b->put = &put;
    b->update = &update;
    b->print = &print;
    b->frees = &frees;
    b->delete_elements = &delete_elements;
    b->double_all_even = &double_all_even;
    b->insert_after_word = &insert_after_word;
    return b;
}
const struct QueueClass QueueConstructor = {.new = &new};