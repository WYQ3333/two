//vs2013
//�ڶ��⣺����һ��������ת������������ÿ���ڵ������ƶ�k����λ������k�ǷǸ���
#include<stdio.h>
#include<Windows.h>
//����δд���Դ���

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
	if (head == NULL)
	{
		return NULL;//ͷ���Ϊ�գ����ؿ�ֵ
	}
	if (head->next == NULL)
	{
		return head;//ֻ��һ���ڵ㣬����������
	}
	struct ListNode *cur = NULL;//��������������������һ���ǿս��
	struct ListNode *pre = NULL;//��������cur��ǰһ���ڵ�
	int count = 0;//����������תcount��
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