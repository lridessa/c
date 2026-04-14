#include "stdio.h"
#include "stdlib.h"
typedef struct xs{
    int data;
	struct xs *next;
}ListNode;
ListNode* create(int a[],int n){
    ListNode *hd=(ListNode *)malloc(sizeof(ListNode)),*r=hd;
    for(int i=0;i<=n-1;i++){
	    r->next=(ListNode *)malloc(sizeof(ListNode));
		r->next->data=a[i];
        r=r->next;
	}
	r->next=NULL;
	return hd;
}
void print(ListNode *hd){
    ListNode *p=hd->next;
	while(p!=NULL){
	    printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void sfkj(ListNode *hd){
    ListNode *p=NULL;
	while(hd!=NULL){
	    p=hd;
		hd=hd->next;
		free(p);
	}
}
/********************************/
void qjj(ListNode *ha,ListNode *hb)
{
    ListNode *pa=ha->next,*pb,*pc=ha,*pd;
    while(pa!=NULL)
    {
        int found=0;
        pb=hb->next;
        while(pb!=NULL)
        {
            if(pb->data==pa->data)
            {
                found=1;
                break;
            }
            pb=pb->next;
        }
        if(!found)
        {
            pd=pa;
            pa=pa->next;
            pc->next=pa;
            free(pd);
        }
        else
        {
            pc=pa;
            pa=pa->next;
        }
    }
        
}
/********************************/
void main(){  
    int a[5]={2,4,6,8,3},b[8]={1,2,3,4,5,6};
    ListNode *heada=create(a,5),*headb=create(b,6);
    qjj(heada,headb);
    print(heada);
    sfkj(heada);sfkj(headb);
}