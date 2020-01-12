#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

tydef struct community {
    int info;
    char msg[100];
    struct community *back;
} 

Linkedlist;
Linkedlist 
*first=NULL; 
*last=NULL;

Linkedlist *back(int), *delete(int), *readKeyboard();
void writeScreen(Linkedlist *);

main() {
    Linkedlist *add, *sth;
    int info, result;
    char chosen;
    
    while(1) {
        puts("\nAdding\nListing\nSearching\nDeleting\nOut\nWhat's your election?");
        chosen=getch();
        switch(chosen) {
            case 'A': add=readKeyboard();
            if(add!=NULL) add(add);
            else puts("Memory is full for adding.\n");
            break;
            
            case 'L': result=Listing();
            if(result==-1) puts("Empty List !");
            break;
            
            case 'S': puts("Looked up:"); scanf("%d", &info);
            sth=Searching(info);
            if(sth==NULL) puts("No searches found.");
            else writeScreen(sth);
            break;
            
            case 'D': puts("Will be deleted:"); scanf("%d", &info);
            sth=delete(info);
            if(sth!=NULL) puts("Deleted...");
            else puts("No deletion is requested.");
            break;
            
            case 'O': puts("Goodbye!");
            exit(0);
            default: puts("Wrong choice!!!\n");
        }
    }
}

int add(Linkedlist *sth) {
    if(first!=NULL) {
        last->back=NULL;
    }
    else {
        first=sth;
        last=sth;
        first->back=NULL;
    }
    return 0;
}

int Listing() {
    Linkedlist *p;
    p=first;
    if(p==NULL)
        return -1;
    
    while(p!=NULL) {
        writeScreen(p);
        p=p->back;
    }
    return 0;
}

Linkedlist *Searching(int lp) {
    Linkedlist *p;
    p=first;
    while(p!=NULL) {
        if(p->info=lp)
            return p;
        p=p->back;
    }
    return NULL;
}

Linkedlist *delete(int wd) {
    Linkedlist *p, *previous;
    p=first;
    previous=NULL;
    
    while(p!=NULL) {
        if(wb==p->info)
            break;
        previous=p;
        p=p->back;
    }
    
    if(p!=NULL) {
        if(previous==NULL) {
            if(first==last) {
                first=NULL;
                last=NULL;
            }
            else
                first=first->back;
        }
        else {
            previous->back=p->back;
            if(previous->back==NULL)
                last=previous;
        }
        free(p);
        return p;
    }
    else
        return NULL;
}

void writeScreen(Linkedlist *wr) {
    printf("info:%d, msg:%s\n", wr->info, wr->msg);
}

Linkedlist *readKeyboard() {
    Linkedlist *r;
    r=malloc(sizeof(Linkedlist));
    if(r==NULL)
        return NULL;
    
    puts("Please add an information:");
    scanf("%d", &(r->info));
    puts("Please write a message:");
    scanf("%s", r->msg);
    return r;
}
