/* **
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，
 它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

将当前节点初始化为返回列表的哑节点。
将进位 carry 初始化为 0。
将 p 和 q 分别初始化为列表 l1 和 l2 的头部。
遍历列表 l1 和 l2 直至到达它们的尾端。
将 x 设为节点 p 的值。如果 p 已经到达 l1 的末尾，则将其值设置为 0。
将 y 设为节点 q 的值。如果 q 已经到达 l2 的末尾，则将其值设置为 0。
设定 sum = x + y + carry。
更新进位的值，carry = sum / 10。
创建一个数值为 (sum mod 10) 的新节点，并将其设置为当前节点的下一个节点，然后将当前节点前进到下一个节点。
同时，将 p 和 q 前进到下一个节点。
检查 carry = 1 是否成立，如果成立，则向返回列表追加一个含有数字 1 的新节点。
返回哑节点的下一个节点。
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
