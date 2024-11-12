#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
  
typedef struct Node {  
    int data;  
    struct Node* next;  
} Node;  
  
Node* tail = NULL; // ��ʼ��ΪNULL����ʾ������  
  
// ��ʼ������������һ���ƽڵ㣩  
void init() {  
    Node* dummy = (Node*)malloc(sizeof(Node));  
    dummy->data = 0; // �ƽڵ�����ݿ����������  
    dummy->next = dummy; // �Ի���ʾ������  
    tail = dummy;  
}  
  
// ��������Ƿ�Ϊ��  
bool isEmpty() {  
    return tail->next == tail;  
}  
  
// ������β�������½ڵ�  
void insert(int data) {  
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = data;  
    newNode->next = tail->next;  
    tail->next = newNode;  
    tail = newNode;  
}  
  
// �������г��ӣ�ɾ��ͷ�ڵ㣩  
bool dequeue() {  
    if (isEmpty()) return false;  
  
    Node* head = tail->next; // ͷ�ڵ�  
    Node* newHead = head->next; // ��һ���ڵ㽫��Ϊ�µ�ͷ�ڵ�  
  
    if (head == tail) { // ���������ֻ��һ���ڵ�  
        tail = NULL; // �����Ϊ��  
    } else {  
        tail->next = newHead; // ����β�ڵ��nextָ���µ�ͷ�ڵ�  
    }  
  
    free(head); // �ͷ�ͷ�ڵ���ڴ�  
  
    // �������Ϊ�գ�����tail����Ȼ��������Ӳ�����ͨ������Ҫ����Ϊtail��ֻ��һ���ڵ�ʱ�Ѿ�����ΪNULL��  
    // ��Ϊ�˱���һ���ԣ����ǿ��Լ�鲢���£���Ȼ������ض��������Ƕ���ģ�  
    if (!isEmpty()) {  
        // ʵ���ϣ�tail����Ҫ���£���Ϊtailʼ��ָ�����һ���ڵ㣬�����Ӳ�����Ӱ���������������Ϊ�գ�  
        // ��Ϊ����ʾ�����ǿ����ٴ�ȷ��tail��״̬����Ȼ����������ڲ�û�б�Ҫ��  
        tail = newHead->next == tail ? newHead : tail; // ���д���ʵ�����ڴ����������Ƕ���ģ���Ϊtail����ı�  
    }  
  
    return true;  
}  
  
// ����������ӡ�ڵ�����  
void traverse() {  
    if (isEmpty()) {  
        printf("����Ϊ��!\n");  
        return;  
    }  
  
    Node* current = tail->next;  
    do {  
        printf("%d ", current->data);  
        current = current->next;  
    } while (current != tail->next); // ѭ��ֱ���ص�ͷ�ڵ㣨ע��������current != tail->next��  
    printf("\n");  
}  
  
// �ͷ���������нڵ㣨�ڳ������ʱ���ã�  
void freeList() {  
    Node* current = tail;  
    if (current != NULL) {  
        do {  
            Node* next = current->next;  
            free(current);  
            current = next;  
        } while (current != tail); // ѭ��ֱ���ص�β�ڵ㣨�Ի���ʾ������  
    }  
    tail = NULL; // ��tail����ΪNULL�Ա�ʾ�����ѱ��ͷ�  
}  
  
int main() {  
    init();  
    insert(1);  
    insert(2);  
    insert(3);  
    traverse(); // ���: 1 2 3  
  
    dequeue();  
    traverse(); // ���: 2 3  
  
    dequeue();  
    traverse(); // ���: 3  
  
    dequeue();  
    traverse(); // ���: List is empty.  
  
    freeList(); // �ͷ������ڴ�  
    return 0;  
} 
