#include "process.h"
#include "queue.h"
int main(){
    Queue* c = QueueConstructor.new();
    while(process(c) != -1){};
    return 0;
}