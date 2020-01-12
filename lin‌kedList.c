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

