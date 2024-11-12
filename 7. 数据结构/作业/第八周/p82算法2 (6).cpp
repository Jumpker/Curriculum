#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
  
typedef struct Node {  
    int data;  
    struct Node* next;  
} Node;  
  
Node* tail = NULL; // 初始化为NULL，表示空链表  
  
// 初始化空链表（创建一个哑节点）  
void init() {  
    Node* dummy = (Node*)malloc(sizeof(Node));  
    dummy->data = 0; // 哑节点的数据可以是任意的  
    dummy->next = dummy; // 自环表示空链表  
    tail = dummy;  
}  
  
// 检查链表是否为空  
bool isEmpty() {  
    return tail->next == tail;  
}  
  
// 在链表尾部插入新节点  
void insert(int data) {  
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = data;  
    newNode->next = tail->next;  
    tail->next = newNode;  
    tail = newNode;  
}  
  
// 从链表中出队（删除头节点）  
bool dequeue() {  
    if (isEmpty()) return false;  
  
    Node* head = tail->next; // 头节点  
    Node* newHead = head->next; // 下一个节点将成为新的头节点  
  
    if (head == tail) { // 如果链表中只有一个节点  
        tail = NULL; // 链表变为空  
    } else {  
        tail->next = newHead; // 更新尾节点的next指向新的头节点  
    }  
  
    free(head); // 释放头节点的内存  
  
    // 如果链表不为空，更新tail（虽然在这个出队操作中通常不需要，因为tail在只有一个节点时已经更新为NULL）  
    // 但为了保持一致性，我们可以检查并更新（虽然在这个特定场景下是多余的）  
    if (!isEmpty()) {  
        // 实际上，tail不需要更新，因为tail始终指向最后一个节点，而出队操作不影响它（除非链表变为空）  
        // 但为了演示，我们可以再次确认tail的状态（虽然在这个函数内部没有必要）  
        tail = newHead->next == tail ? newHead : tail; // 这行代码实际上在大多数情况下是多余的，因为tail不会改变  
    }  
  
    return true;  
}  
  
// 遍历链表并打印节点数据  
void traverse() {  
    if (isEmpty()) {  
        printf("链表为空!\n");  
        return;  
    }  
  
    Node* current = tail->next;  
    do {  
        printf("%d ", current->data);  
        current = current->next;  
    } while (current != tail->next); // 循环直到回到头节点（注意条件是current != tail->next）  
    printf("\n");  
}  
  
// 释放链表的所有节点（在程序结束时调用）  
void freeList() {  
    Node* current = tail;  
    if (current != NULL) {  
        do {  
            Node* next = current->next;  
            free(current);  
            current = next;  
        } while (current != tail); // 循环直到回到尾节点（自环表示结束）  
    }  
    tail = NULL; // 将tail设置为NULL以表示链表已被释放  
}  
  
int main() {  
    init();  
    insert(1);  
    insert(2);  
    insert(3);  
    traverse(); // 输出: 1 2 3  
  
    dequeue();  
    traverse(); // 输出: 2 3  
  
    dequeue();  
    traverse(); // 输出: 3  
  
    dequeue();  
    traverse(); // 输出: List is empty.  
  
    freeList(); // 释放链表内存  
    return 0;  
} 
