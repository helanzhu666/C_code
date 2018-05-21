#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
   int val;
   struct ListNode *next;
}LNode;

//β�巨��������ͷ��� 
LNode* CreatLinkList(int a[],int n){
	LNode *head,*p,*t;
	head=NULL;
	int i;
	for(i=0;i<n;i++){
		p=(LNode *)malloc(sizeof(LNode));
		p->val=a[i];
		p->next=NULL;
		if(!head){
			head=t=p;
		}else{
			t=t->next=p;
		}
	}
	return head;
} 

//������� 
void Print(LNode *head){
	LNode *p;
	for(p=head;p!=NULL;p=p->next){
		printf("%d\t",p->val);
	}
	printf("\n");
}

//ɾ��������k���ڵ� 
LNode * DelNode(LNode *head,int n){
	LNode *p,*t,*del;
	if(head->next==NULL){
        return NULL;
    }
	int i;
	p=head;
	for(i=0;i<n;i++){
		p=p->next;
	}
	if(p!=NULL){
		for(t=head;p->next!=NULL;t=t->next,p=p->next){
		;
		}
		t->next=t->next->next;
	}
	else{
        head->val=head->next->val;
		head->next=head->next->next;
	}	
	return head;
} 

//�������� 
LNode *reverse(LNode *head){
	LNode *p,*t;
	p=head;
    if(p){
	    p=head;
	    t=head->next;
	    while(t){
		    p->next=t->next;
		    t->next=head;
		    head=t; 
		    t=p->next;
	    }
    }
	return head;
}

//�ж������Ƿ��л�
int hasCycle(LNode *head){
	LNode *p,*t;
	if(head==NULL){
		return 0;
	}
    t=p=head;
	while(p!=NULL&&p->next!=NULL){
        t=t->next;
        p=p->next->next;
        if(t==p){
            return 1;
        }
	}
    return 0;
} 

//������ڽڵ�
int firstCycleNode(LNode *pHead){
    ListNode *p,*t,*m,*q;
	int len=0,i,x;
	p=t=pHead;
	if(pHead==NULL){
		return NULL; //������ 
	}
	while(p!=NULL&&p->next!=NULL){
	    t=t->next;
	    p=p->next->next;
	    if(t==p){
	    for(m=p->next;m!=NULL;m=m->next){
            len++;
            if(m==p){
                break;
               }
            } 
             p=pHead;
            for(i=0;i<len;i++){
                p=p->next;
            }
            q=pHead;
            while(q!=p){
                q=q->next;
                p=p->next;
            }
            return q;
		}
	}
    return NULL;
    }
}
int firstCycleNode2(ListNode *pHead){
	ListNode *p,*q,*t;
	p=q=pHead;
	if(pHead==NULL){
		return NULL; //������ 
	}
	while(p!=NULL&&p->next!=NULL){
	    t=t->next;
	    p=p->next->next;
	    if(t==p){
	   		t=pHead;
			while(t!=p){
				t=t->next;
				p=p->next;
			}	
        	return p;
		}
	}
	return NULL;
}
 
//ɾ��ĳһ���ڵ㣬����Ҫͷָ��
void deleteNode(LNode* node){
    node->val=node->next->val;
    node->next=node->next->next;
}
int main(){
	int a[]={1,2,3,4,5,6};
	LNode *head;
	head=CreatLinkList(a,6);
	Print(head);
//	DelNode(head,1);
//	head=reverse(head);
//	int n=hasCycle(head);	
//	Print(head);
//	printf("%d\n",n);
	int n=firstCycleNode(head);
	printf("%d\n",n);
	return 0;
}
