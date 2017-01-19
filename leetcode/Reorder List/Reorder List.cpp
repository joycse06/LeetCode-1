/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
#include <malloc.h>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* listnode_create(int val){
	ListNode *p = (ListNode*)malloc(sizeof *p);
	p->val = val;
	p->next = NULL;
	return p;
}

void list_destroy(ListNode *head){
	ListNode *next;
	if(!head) return;
	while(head){
		next = head->next;
		free(head);
		head = next;
	}
}

void listnode_append(ListNode *head, int val){
	if(!head) return;
	while(head->next){
		head = head->next;
	}
	head->next = listnode_create(val);
}

void print_list(ListNode *head){
	while(head){
		printf("[%d] ", head->val);
		head = head->next;
	}
	printf("\n");
}

/******************************************************/
static int count_length(ListNode *head){
	int len = 0;
	while(head){
		head = head->next;
		len++;
	}
	return len;
}

static ListNode* reverseList(ListNode *head){
	if(!head) return NULL;
	ListNode *prev, *next = head->next;
	head->next = NULL;
	while(next){
		prev = head;
		head = next;
		next = head->next;
		head->next = prev;
	}
	return head;
}

class Solution {
public:
    void reorderList(ListNode *head) {
        if(!head) return;
        int len = count_length(head), last_index;
        last_index = len >> 1;
        ListNode *last = head, *reversed_list, *p;
        for(int i = 0; i < last_index; ++i) last = last->next;
        reversed_list = last->next;
        last->next = NULL;
        reversed_list = reverseList(reversed_list);
        p = reversed_list;
        while(p){
        	reversed_list = reversed_list->next;
        	p->next = head->next;
        	head->next = p;
        	head = p->next;
        	p = reversed_list;
        }
    }
};

int main(){
	ListNode *head;
	head = listnode_create(1);
	listnode_append(head, 2);
	listnode_append(head, 3);
	listnode_append(head, 4);
	listnode_append(head, 5);
	listnode_append(head, 6);
	listnode_append(head, 7);
	print_list(head);
	Solution s;
	s.reorderList(head);
	print_list(head);
	return 0;
}