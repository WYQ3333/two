//vs2013
//第二题：给定一个链表，旋转链表，将联保的每个节点向右移动k个单位，其中k是非负数
#include<stdio.h>
#include<Windows.h>
//此题未写测试代码

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (head == NULL)
	{
		return NULL;//头结点为空，返回空值
	}
	if (head->next == NULL)
	{
		return head;//只有一个节点，返回它本身
	}
	struct ListNode *cur = NULL;//遍历，用来找链表的最后一个非空结点
	struct ListNode *pre = NULL;//用来保存cur的前一个节点
	int count = 0;//代表向右旋转count步
	while (count < k)
	{
		cur = head;
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		cur->next = head;
		head = cur;
		count++;
	}
	return head;
}