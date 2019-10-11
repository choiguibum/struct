#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
typedef struct link {
	struct node* tail;//����� ���κ�
	struct node* head;//����� ù�κ�
}Linkedlist;

typedef struct node {
	int data; //������ ����
	node* nextadd;//���� ����� �ּ� ���� ������
}Node;

int empty(Linkedlist* L) {
	if (L->head == NULL)
		return 1;
	else
		return 0;
}
void push(Linkedlist *L, int idata) {
	node* newnode = (node*)malloc(sizeof(node));//����� ����
	if (newnode == NULL) {
		printf("�������� �����Ͽ����ϴ�.\n");
		return;
	}
	newnode->data = idata;
	newnode->nextadd = NULL;
	if ((empty(L) == 1))//���� �����
		L->head = L->tail = newnode;
	else {
		L->tail->nextadd = newnode;
		L->tail = newnode;
	}
	count++;
}
void pop(Linkedlist* L) {
	node* pop = (node*)malloc(sizeof(node));
	pop->data = NULL;
	pop->nextadd = NULL;
	if (empty(L)) {
		printf("ť��������ϴ�. : %d\n", empty(L) - 2);
	}
	else{
		pop = L->head;
		L->head = pop->nextadd;
		printf("ť�� �����Ǿ����ϴ� : %d\n", pop->data);
	}
	count--;
	if (count < 0)
		count = 0;
	free(pop);
}
void allprint(Linkedlist* L) {
	printf("���� �Էµ� ť : ");
	node* all = L->head;
	while (all != NULL) {
		printf("%3d", all->data);
		all = all->nextadd;
	}
	printf("\n");
}
void front(Linkedlist *L) {
	node* front = L->head;
	if (empty(L) == 1)
		printf("%d\n", -1);
	else
		printf("���� �տ� �ִ� ���� : %d\n",front->data);
}
void back(Linkedlist* L) {
	node* back = L->tail;
	if (empty(L) == 1)
		printf("%d\n", -1);
	else
		printf("���� �ڿ� �ִ� ���� : %d\n", back->data);
}
void size(Linkedlist *L) {
	printf("ť�� ����ִ� ������ �� : %d\n", count);
}
void InitQueue(Linkedlist* L) {
	L->head = NULL;
	L->tail = NULL;
}
int main(){
	Linkedlist* L = (Linkedlist*)malloc(sizeof(Linkedlist)); //�����ͺ��� L�� ���� �޸��Ҵ�
	if (L == NULL) printf("�޸��Ҵ翡 �����Ͽ����ϴ�.\n");
	InitQueue(L);
	const char *command[1000] = {"push","pop", "size","empty","front","back","exit"};
	char a[100];
	unsigned int number;
	do {
		printf("��ɾ �Է��� �ּ���(push, pop, size, empty, front, back, exit)\n");
		scanf("%s", a);
		if (strcmp(a, command[0]) == 0) {
			printf("������ ������ �Է��� �ּ���\n");
			scanf("%d", &number);
			push(L, number);
			allprint(L);
		}
		else if (strcmp(a, command[1]) == 0) {
			pop(L);
			allprint(L);
		}
		else if (strcmp(a, command[2]) == 0) {
			size(L);
			allprint(L);
		}
		else if (strcmp(a, command[3]) == 0) {
			printf("ť ���� Ȯ�� :  %d\n", empty(L));
			allprint(L);
		}
		else if (strcmp(a, command[4]) == 0) { 
			front(L);
			allprint(L); 
		}
		else if (strcmp(a, command[5]) == 0) {
			back(L);
			allprint(L);
		}
	} while (strcmp(a, command[6]) != 0);
	free(L);	
	return 0;
}