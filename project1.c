#include <stdio.h>    // bai 7 chuong 7 trang 252
#include <stdlib.h>

typedef struct node{
	char ht[26];
	float td;
	struct node *next;
}NODE;

typedef struct list{
	NODE *lHead;
	NODE *lTail;
}LIST;

void Khoi_tao_list(LIST *l);
NODE *Khoi_tao_node();
void Them_vao_cuoi(LIST *l);
void Xuat_danh_sach(LIST *l);
void Khoi_tao_danh_sach_do(LIST *l1, LIST *l2);


int main(){
	LIST *l1, *l2;
    int n;
    printf("\nSo thi sinh trong dang sach: "); scanf("%d", &n);
    l1 = (LIST *) malloc(sizeof(LIST));
    Khoi_tao_list(l1);
    while(n--){
        if(l1->lHead == NULL){
            l1->lHead = l1->lTail = Khoi_tao_node();
        }
        else{
            l1->lTail->next = Khoi_tao_node();
            l1->lTail = l1->lTail->next;
        }
    }
    Xuat_danh_sach(l1);
    Them_vao_cuoi(l1);
    l2 = (LIST *) malloc(sizeof(LIST));
    Khoi_tao_list(l2);
    Khoi_tao_danh_sach_do(l1, l2);
    Xuat_danh_sach(l2);
    return 0;
}

void Khoi_tao_list(LIST *l){
	l->lHead = NULL;
	l->lTail = NULL;
}

NODE *Khoi_tao_node(){
	NODE *n;
	n = (NODE *) malloc(sizeof(NODE));
	getchar();
	printf("\nHo ten: "); gets(n->ht);
	printf("\nTong diem: "); scanf("%f", &n->td);
	n->next = NULL;
	return n;
}

void Them_vao_cuoi(LIST *l){
	if(l->lHead == NULL){
		l->lHead = l->lTail = Khoi_tao_node();
	}
	else{
		l->lTail->next = Khoi_tao_node();
		l->lTail = l->lTail->next;
	}
}

void Xuat_danh_sach(LIST *l){
	NODE *k;
    if(l->lHead == NULL){
        printf("\nDanh sach trong:");
        return;
    }
    k = l->lHead;
    while(1){
        printf("\nHo ten: %s", k->ht);
        printf("\nTong diem: %g", k->td);
        if(k->next == NULL){
            break;
        }
        k = k->next;
    }
}

void Khoi_tao_danh_sach_do(LIST *l1, LIST *l2){
    NODE *k;
    k = l1->lHead;
    while(1){
        if(k->td >= 15){
            if(l2->lHead == NULL){
                NODE *n;
                n = malloc(sizeof(NODE));
                (*n) = (*k);
                l2->lHead = l2->lTail = n;
                l2->lHead->next = NULL;
            }
            else{
                NODE *n;
                n = malloc(sizeof(NODE));
                (*n) = (*k);
                l2->lTail->next = n;
                l2->lTail = l2->lTail->next;
                l2->lTail->next = NULL;
            }
        }
        if(k->next == NULL){
            break;
        }
        k = k->next;
    }
}