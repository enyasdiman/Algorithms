#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct community {
    int info;
    char msg[100];
    struct community *left, *right;
} Tree;
Tree *root=NULL;
Tree *search(), *del(), *read();
void show(), add(), list();

main() {
    Tree *new, *address;
    int info, amount;
    char choice;

    while (1) {
    puts("\nAdding\nListing\nSearching\nDeleting\nAmount\nExit\nYour choice?");
    choice=getch();
        switch(choice) {
            case 'A': new=read();
            add(root, new);
            break;
            case 'L': if(root!= NULL)
                list(root);
            else
                puts("Empty list!");
            break;
            case 'S': puts("Searching for:"); scanf("%d", &info);
            address=search(root, info);
            if(address==NULL)
                puts("Does not found");
            else show(address);
            break;
            case 'A': amount=count(root, 0);
            printf("Record count=%d\n", amount);
            break;
            case 'D': puts("Will be delete:"); scanf("%d", &info);
            address=del(root, info);
            if(address!=NULL)
                puts("Deleted");
            else
                puts("The file does not exist");
            break;
            case 'G': puts("Farewell!");
            exit(0);
            default: puts("Wrong choice!");
        }
    }
}

void add(Tree *root, Tree *new) {
    if(root==NULL)
        root=new;
    else {
        if(new->info <= root->info) {
            if(root->left==NULL)
                root->left=new;
            else add(root->left, new);
        } else {
            if(root->right==NULL)
                root->right=new;
            else add(root->right, new);
        }
    }
}

void list(Tree *root) {
    if(root!=NULL) {
        list(root->left);
        show(root);
        list(root->right);
    }
}

Tree *search(Tree *root, int wbs) {
    while(root!=NULL && root->info!=wbs) {
        if(wbs<root->info)
            root=root->left;
        else
            root=root->right;
    } return root;
}

Tree *del(Tree *root, int wbd) {
    Tree *qa, *q, *qc, *sa, *s;
    if(root==NULL) return NULL;
    q=root;
    qa=NULL;
    while(q!=NULL && q->info!=wbd) {
        qa=q;
        if(wbd<=q->info)
            q=q->left;
        else
            q=q->right;
    } if(q==NULL)
        return NULL;
    if(q->left!=NULL && q->right!=NULL) {
        s=q->left;
        sa=q;
        while(s->right!=NULL) {
            sa=s;
            s=s->right;
        } q->info=s->info;
        strcpy(q->msg, s->msg);
        q=s;
        qa=sa;
    }
    if(q->left!=NULL)
        qc=q->left;
    else
        qc=q->right;
    if(q==root)
        root=qc;
    else {
        if(qc==qa->left)
            qa->left=qc;
        else
            qa->right=qc;
    } free(q); return q;
}
int count(Tree *root, int amount) {
    if(root==NULL) return amount;
    amount++;
    amount=count(root->left, amount);
    amount=count(root->right, amount);
    return amount;
}
void show(Tree *data) {
    printf("information:%d, message,%s\n", data->info, data->msg);
}
Tree read() {
    Tree *new;
    new=malloc(sizeof(Tree));
    if(new==NULL) {
        puts("Memory is full");
        return NULL;
    }
    puts("Enter an information:");
    scanf("%d", &(new->info));
    puts("Enter a message:");
    scanf("%s", new->msg);
    new->right=NULL;
    new->left=NULL;
    return new;
}