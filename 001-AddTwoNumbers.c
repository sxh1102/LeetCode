/* **
 * ���������ǿ���������ʾ�����Ǹ�������λ����������ʽ�洢��
 ���ǵ�ÿ���ڵ�ֻ�洢�������֡���������ӷ���һ���µ�����
����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ��
ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

����ǰ�ڵ��ʼ��Ϊ�����б���ƽڵ㡣
����λ carry ��ʼ��Ϊ 0��
�� p �� q �ֱ��ʼ��Ϊ�б� l1 �� l2 ��ͷ����
�����б� l1 �� l2 ֱ���������ǵ�β�ˡ�
�� x ��Ϊ�ڵ� p ��ֵ����� p �Ѿ����� l1 ��ĩβ������ֵ����Ϊ 0��
�� y ��Ϊ�ڵ� q ��ֵ����� q �Ѿ����� l2 ��ĩβ������ֵ����Ϊ 0��
�趨 sum = x + y + carry��
���½�λ��ֵ��carry = sum / 10��
����һ����ֵΪ (sum mod 10) ���½ڵ㣬����������Ϊ��ǰ�ڵ����һ���ڵ㣬Ȼ�󽫵�ǰ�ڵ�ǰ������һ���ڵ㡣
ͬʱ���� p �� q ǰ������һ���ڵ㡣
��� carry = 1 �Ƿ������������������򷵻��б�׷��һ���������� 1 ���½ڵ㡣
�����ƽڵ����һ���ڵ㡣
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>


struct ListNode 
{
	int val;
	struct ListNode *next;
}List;
typedef struct ListNode *ListPnt;


void CreateList(struct ListNode* list, int val)
{
	struct ListNode* snode;
	snode->val = val;
	snode->next = NULL;
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->next = snode;
}

ListPnt addTwoNumbers(ListPnt list1, ListPnt list2)
{
	ListPnt list, pnode;
	list = (ListPnt)malloc(sizeof(struct ListNode));
	
	pnode = list;

	ListPnt p, q;
	p = list1;
	q = list2;

	int carry = 0;
	int x = 0;
	int y = 0;
	int sum = 0;

	while (p != NULL || q != NULL)
	{
		if (p == NULL)
		{
			x = 0;
		}
		else
		{
			x = p->val;
		}
		if (q == NULL)
		{
			y = 0;
		}
		else
		{
			y = p->val;
		}

		sum = x + y + sum;
		carry = sum / 10;
		
		pnode->val = sum % 10;
		list->next = pnode;
		list = list->next;

		if (p != NULL)
		{
			p = p->next;
		}
		if (q != NULL)
		{
			q = q->next;
		}
		
	}

	if (carry == 1)
	{
		ListPnt s = (ListPnt)malloc(sizeof(struct ListNode));
		s->val = carry;
		list->next = s;
	}
	return list->next;
}

int main()
{
	struct ListNode* list1 = NULL;
	struct ListNode* list2 = NULL;
	struct ListNode* list = NULL;
	int i = 0;
	int j = 0;
	int A[10];
	int B[10];

	while (getchar() != '\n')
	{
		scanf("%d", &A[i]);
		printf("aaaa\n");
		insertList(list1, A[i]);
		printf("bbbb\n");
		i++;
	}
	while (getchar() != '\n')
	{
		scanf("%d", &B[j]);
		insertList(list2, B[j]);
		j++;
	}

	list = addTwoNumbers(list1, list2);

	while (&list != NULL)
	{
		printf("%d ", list->val);
	}

	getchar();

	return 0;
}
