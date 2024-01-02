#include "process.h"
int process(Queue* que){
    char c;
    int flag = 0, menu = 0;
    printf("Choose:\n[1] Add to string\n[2] Insert after a word\n[3] Delete all elements with word\n[4] Double all even strings\n[5] Exit\n[1/2/3/4/5] ");
    if (scanf("%d", &menu) == EOF) {
        que->frees(que);
        return -1;
    }
    scanf("%*c");
    if (menu == 1){
        que->put(que);
        while((c = getchar()) != '\n'){ 
            if (c == EOF){
                que->frees(que);
                return 0;
            }
            if (c == ' ' || c == '\t') {flag = 1; continue;}
            if (flag) { flag = 0; que->put(que);}
            que->update(que, c);
        }
        printf("\033[H\033[2J");
        que->print(que);
        return 0;
    }
    else if (menu == 2) {
        printf("\033[H\033[2J");
        if (que->head == NULL) {
            printf("Queue is empty!\n");
            return 0;
        }
        char* strin1 = calloc(1000, 1);
        char* strin2 = calloc(1000, 1);
        printf("\033[H\033[2J");
        printf("Type which word to type after and word itself: ");
        if(scanf("%999[^\n ] %999[^\n ]", strin1, strin2) == EOF) {
            que->frees(que);
            return -1;
        }
        que->insert_after_word(que, strin1, strin2);
        que->print(que);
        free(strin1);
        free(strin2);
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    else if (menu == 3) {
        printf("\033[H\033[2J");
        if (que->head == NULL) {
            printf("Queue is empty!\n");
            return 0;
        }
        char* strin = calloc(1000, 1);
        que->print(que);
        printf("Type which word to delete: ");
        if(scanf("%999[^\n ]", strin) == EOF) return -1;
        que->delete_elements(que, strin);
        que->print(que);
        while((c = getchar()) != '\n' && c != EOF);
        free(strin);
        return 0;
    }
    else if (menu == 4){
        printf("\033[H\033[2J");
        if (que->head == NULL) {
            printf("Queue is empty!\n");
            return 0;
        }
        que->double_all_even(que);
        que->print(que);
        return 0;
    } else {
        que->frees(que);
        return -1;
    }
}