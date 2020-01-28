#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct community {
    int info;
    char msg[100];
    struct community*back;
} LinkedList;
LinkedList *first = NULL, *last = NULL;
LinkedList *search(int), *del(nt), *read();
void show(LinkedList *);

main() {
    LinkedList *wbadd, *bb;
    int info, result;
    char choice;

    while(1) {
        puts("\nAdding\nListing\nSearching\nDeleting\nExit\nYour choice?");
        choice=getch();
        switch(choice) {
            case 'A': wbadd=read();
            if(wbadd!=NULL) add(wbadd);
            else puts("Memory is full for adding!\n");
            break;

            case 'L': result=list();
            if(result==-1) puts("Empty list!");
            break;

            case 'S': puts("Searching for:"); scanf("%d", &info);
            bb=search(info);
            if(bb==NULL) puts("Searching has not found");
            else show(bb);
            break;

            case 'D': puts("Will be delete:"); scanf("%d", &info);
            bb=del(info);
            if(bb!=NULL) puts("Deleted...");
            else puts ("The file does not exist!");
            break;

            case 'G': puts("Farewell!");
            exit(0);

            default: puts("Wrong choice!\n");
        }
    }
}
int add(LinkedList *bb) {
    if(first!=NULL) {
        last->back=bb;
        last=bb;
        last->back=NULL;
    }
    else {
        first=bb;
        last=first;
        first->back=NULL;
    } return 0;
}
int list() {
    LinkedList *p;
    p=first;
    if(p==NULL)
        return -1;
    while(p!=NULL) {
        show(p);
        p=p->back;
    }
    return 0;
}

LinkedList *search(int sf) {
    LinkedList *p;
    p=first;
    while(p!=NULL) {
        if(p->info==sf)
            return p;
        p=p->back;
    }
    return 0;
}

LinkedList *del(int wbd) {
    LinkedList *p, *prev;
    p=first;
    prev=NULL;
    while (p!=NULL) {
        if(wbd==p->info)
            break;
        prev=p;
        p=p->back;
    }
    if(p!=NULL) {
        if(prev==NULL) {
            if(first==last) {
                first=NULL;
                last=NULL;
            }
            else
                first=first->back;
        }
        else {
            prev->back=p->back;
            if(prev->back==NULL)
                last=prev;
        }
        free(p);
        return p;
    }
    else
        return NULL;
}

void show(LinkedList *wbr) {
    printf("information:%d, message:%s\n", wbr->info, wbr->msg);
}

LinkedList *read() {
    LinkedList *redd;
    redd=malloc(sizeof(LinkedList));
    if(redd==NULL)
        return NULL;
    puts("Add an information:");
    scanf("%d", &(redd->info);
    puts("Add a message:");
    scanf("%s", redd->msg);
    return redd;
}