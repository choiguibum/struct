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
	node* previous;//���� ��带 ����Ŵ
	node* nextadd;//���� ��带 ����Ŵ
}Node;

int empty(Linkedlist* L) {
	if (L->head == NULL)
		return 1;
	else
		return 0;
}
void head_push(Linkedlist* L, int idata) {
	node* newnode = (node*)malloc(sizeof(node));//����� ����
	if (newnode == NULL) {
		printf("�������� �����Ͽ����ϴ�.\n");
		return;
	}
	newnode->data = idata;
	newnode->nextadd = L->head;
	if ((empty(L) == 1))//���� �����
		L->tail = newnode;
	else 
		L->head->previous = newnode;
	L->head = newnode;
	newnode->previous = NULL;
	count++;
}
void tail_push(Linkedlist* L, int idata) {
	node* newnode = (node*)malloc(sizeof(node));//����� ����
	if (newnode == NULL) {
		printf("�������� �����Ͽ����ϴ�.\n");
		return;
	}
	newnode->data = idata;
	newnode->previous = L->tail;
	if ((empty(L) == 1))//���� �����
		L->head = newnode;
	else 
		L->tail->nextadd = newnode;
	L->tail = newnode;
	newnode->nextadd = NULL;
	count++;
}
void freeMem(Node* DeleteNode) {
	free(DeleteNode);
	DeleteNode = NULL;
}
void head_pop(Linkedlist* L) {
	node* pop = (node*)malloc(sizeof(node));
	pop->data = NULL;
	pop->nextadd = NULL;
	if (empty(L)) {
		printf("ť��������ϴ�. : %d\n", empty(L) - 2);
	}
	else {
		pop = L->head;
		L->head = pop->nextadd;
		printf("ť�� �����Ǿ����ϴ� : %d\n", pop->data);
	}
	count--;
	if (count < 0)
		count = 0;
	free(pop);
}
void tail_pop(Linkedlist* L) {
	node* pop = (node*)malloc(sizeof(node));
	pop->data = NULL;
	pop->previous = NULL;
	if (empty(L)) {
		printf("ť��������ϴ�. : %d\n", empty(L) - 2);
	}
	else {
		pop = L->tail;
		L->tail = pop->previous;
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
	for (int i = 0; i < count; i++) {
		printf("%3d", all->data);
		all = all->nextadd;
	}
	printf("\n");
}
void front(Linkedlist* L) {
	node* front = L->head;
	if (empty(L) == 1)
		printf("%d\n", -1);
	else
		printf("���� �տ� �ִ� ���� : %d\n", front->data);
}
void back(Linkedlist* L) {
	node* back = L->tail;
	if (empty(L) == 1)
		printf("%d\n", -1);
	else
		printf("���� �ڿ� �ִ� ���� : %d\n", back->data);
}
void size(Linkedlist* L) {
	printf("ť�� ����ִ� ������ �� : %d\n", count);
}
void InitQueue(Linkedlist* L) {
	L->head = NULL;
	L->tail = NULL;
}
int main() {
	Linkedlist* L = (Linkedlist*)malloc(sizeof(Linkedlist)); //�����ͺ��� L�� ���� �޸��Ҵ�
	if (L == NULL) printf("��ũ�帮��Ʈ������ �����Ͽ����ϴ�.\n");
	InitQueue(L);
	const char* command[100] = { "hpush","tpush","hpop","tpop","size","empty","front","back","exit" };
	char a[100];
	int number;
	do {
		printf("��ɾ �Է��� �ּ���(hpush, tpush, hpop, tpop ,size, empty, front, back, exit)\n");
		scanf("%s", a);
		if (strcmp(a, command[0]) == 0) {
			printf("������ ������ �Է��� �ּ���\n");
			scanf("%d", &number);
			head_push(L, number);
			allprint(L);
		}
		else if (strcmp(a, command[1]) == 0) {
			printf("������ ������ �Է��� �ּ���\n");
			scanf("%d", &number);
			tail_push(L, number);
			allprint(L);
		}
		else if (strcmp(a, command[2]) == 0) {
			head_pop(L);
			allprint(L);
		}
		else if (strcmp(a, command[3]) == 0) {
			tail_pop(L);
			allprint(L);
		}
		else if (strcmp(a, command[4]) == 0) {
			size(L);
			allprint(L);
		}
		else if (strcmp(a, command[5]) == 0) {
			printf("ť ���� Ȯ�� :  %d\n", empty(L));
			allprint(L);
		}
		else if (strcmp(a, command[6]) == 0) {
			front(L);
			allprint(L);
		}
		else if (strcmp(a, command[7]) == 0) {
			back(L);
			allprint(L);
		}
		else if (strcmp(a, command[8]) == 0)
			break;
	} while (1);
	free(L);
	return 0;
}