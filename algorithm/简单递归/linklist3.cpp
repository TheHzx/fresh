#include "slinklist.h"

linklist insert(linklist head, datatype x) {
	linklist p, q, pre; // q��Ҫ����Ľڵ�
	q = (linklist)malloc(sizeof(node));
	q->info = x;
	p = head;
	// ����ͷ�ڵ�
	if (p->info >= x) {
		head = q;
		q->next = p;
		return head;
	}
	pre = p, p = p->next;
	while (p && x >= p->info) { // �ҵ���һ�����ڵ��ڵ���
		pre = p;
		p = p->next;
	}
	// �����м�,���뵽p����
	if (pre->next) {
		q->next = pre->next;
		pre->next = q;
	}
	// ���һ����
	else if (pre->next == NULL) {
		pre->next = q;
		q->next = NULL;
	}
	return head;
}

int main() {
	datatype x;
	linklist head;
	printf("����һ���������е�����: \n");
	head = creatbyqueue();
	print(head);
	printf("������Ҫ�����ֵ:");
	scanf("%d", &x);
	head = insert(head, x);
	print(head);
	delList(head);
	return 0;
}