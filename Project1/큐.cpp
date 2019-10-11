#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
typedef struct link {
	struct node* tail;//노드의 끝부분
	struct node* head;//노드의 첫부분
}Linkedlist;

typedef struct node {
	int data; //데이터 저장
	node* nextadd;//다음 노드의 주소 저장 포인터
}Node;

int empty(Linkedlist* L) {
	if (L->head == NULL)
		return 1;
	else
		return 0;
}
void push(Linkedlist *L, int idata) {
	node* newnode = (node*)malloc(sizeof(node));//새노드 생성
	if (newnode == NULL) {
		printf("노드생성에 실패하였습니다.\n");
		return;
	}
	newnode->data = idata;
	newnode->nextadd = NULL;
	if ((empty(L) == 1))//최초 노드라면
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
		printf("큐가비었습니다. : %d\n", empty(L) - 2);
	}
	else{
		pop = L->head;
		L->head = pop->nextadd;
		printf("큐가 삭제되었습니다 : %d\n", pop->data);
	}
	count--;
	if (count < 0)
		count = 0;
	free(pop);
}
void allprint(Linkedlist* L) {
	printf("현재 입력된 큐 : ");
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
		printf("가장 앞에 있는 정수 : %d\n",front->data);
}
void back(Linkedlist* L) {
	node* back = L->tail;
	if (empty(L) == 1)
		printf("%d\n", -1);
	else
		printf("가장 뒤에 있는 정수 : %d\n", back->data);
}
void size(Linkedlist *L) {
	printf("큐에 들어있는 정수의 수 : %d\n", count);
}
void InitQueue(Linkedlist* L) {
	L->head = NULL;
	L->tail = NULL;
}
int main(){
	Linkedlist* L = (Linkedlist*)malloc(sizeof(Linkedlist)); //포인터변수 L에 대한 메모리할당
	if (L == NULL) printf("메모리할당에 실패하였습니다.\n");
	InitQueue(L);
	const char *command[1000] = {"push","pop", "size","empty","front","back","exit"};
	char a[100];
	unsigned int number;
	do {
		printf("명령어를 입력해 주세요(push, pop, size, empty, front, back, exit)\n");
		scanf("%s", a);
		if (strcmp(a, command[0]) == 0) {
			printf("삽입할 정수를 입력해 주세요\n");
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
			printf("큐 공백 확인 :  %d\n", empty(L));
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