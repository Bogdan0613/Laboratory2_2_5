#include <iostream>
using namespace std;

struct dict {
    struct dict *left,*right;
    char word[10];
    char meaning[20];
    int request_num;
}*Root1=NULL, *Root2=NULL;

typedef struct dict dictionary1;
typedef struct dict dictionary2;
int check(char[],char[]);
void insert(dictionary1 *);
void Search();
void view(dictionary1 *);

void insert_new(dictionary2* temp);
void view_new(dictionary2 *);

void print_tree(dictionary2 *root);
void print_t(dictionary2 *root, int space);


int check(int a, int b){
    int c = 0;
    if(a > b){
        c = 1;
    }
    else if(b > a){
        c = -1;
    }
    else
        c=0;

    if(c == 1)
        return 1;
    else if(c == -1)
        return -1;
    else
        return 0;
}

void insert(dictionary1 *temp){
    int flag=0;
    dictionary1 *ptr,*par;
    ptr=Root1;

    if(Root1==NULL)
        Root1=temp;
    else{
        while(ptr!=NULL ){
            if(check(temp->request_num,ptr->request_num)>0){
                par=ptr;
                ptr=ptr->right;
            }

            else if(check(temp->request_num,ptr->request_num)<0)
            {
                par=ptr;
                ptr=ptr->left;
            }
            else if(check(temp->request_num,ptr->request_num)==0){
                flag=1;
                cout << "Word exists!";
                break;
            }

        }
        if(flag==0 && ptr==NULL){

            if(check(par->request_num,temp->request_num)==1)
                par->left=temp;
            else if(check(par->request_num,temp->request_num)==-1)
                par->right=temp;
        }

    }

}

void Search(){
    int flag=0;
    dictionary1 *ptr;
    ptr=Root1;
    int w;
    cout << "Enter the number of the requests:";
    cin >> w;
    while(ptr!=NULL && flag==0){
        if(check(w,ptr->request_num)>0)
            ptr=ptr->right;
        else if(check(w,ptr->request_num)<0)
            ptr=ptr->left;
        else if(check(w,ptr->request_num)==0){
            flag=1;
            cout << "Word:"<<ptr->word<<endl;
            cout << "Meaning:"<<ptr->meaning;
            ptr->request_num++;
        }

    }
    if(flag==0)
        cout << "Word not found!";
}

void insert_max(dictionary1 *ptr){
    if(Root1==NULL)
        cout << "Empty dictionary!"<<endl;

    else if(ptr !=NULL){
        insert_max(ptr->right);
        dictionary2* temp;
        temp=(dictionary2*)malloc(sizeof(dictionary2));
        temp->left=NULL;
        temp->right=NULL;
        strcpy(temp->word, ptr->word);
        temp->request_num = ptr->request_num;
        strcpy(temp->meaning, ptr->meaning);
        insert_new(temp);
        insert_max(ptr->left);
    }
}


void view(dictionary1 *ptr){
    if(Root1==NULL)
        cout << "Empty dictionary!"<<endl;

    else if(ptr !=NULL){
        view(ptr->right);

        cout << ptr->word << endl;
        cout << ptr->meaning << endl;
        cout << ptr->request_num << endl;

        view(ptr->left);
    }

}

int main() {
    int ch;
    dictionary1 *temp1;
    while(ch!=4){
        cout << "\n1.Search\n2.Add a word\n3.View\n4.Build new tree\n5.Exit\nYour choice please..";
        cin >> ch;
        switch (ch) {
            case 1: Search();break;
            case 2:
                temp1=(dictionary1*)malloc(sizeof(dictionary1));
                temp1->left=NULL;
                temp1->right=NULL;
                cout << "Enter word:";
                cin >> temp1->word;
                cout << "Enter the meaning of the word:";
                cin >> temp1->meaning;
                cout << "Enter the number of the requests:";
                cin >> temp1->request_num;
                insert(temp1);
                break;
            case 3:
                view(Root1);
                cout << endl<<"-------------------------------------"<<endl;
                print_tree(Root1);
                view_new(Root2);
                cout << endl<<"-------------------------------------"<<endl;
                print_tree(Root2);
                break;
            case 4:
                insert_max(Root1);
                view_new(Root2);
                cout << endl<<"-------------------------------------"<<endl;
                print_tree(Root2);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

void insert_new(dictionary2 *temp){
    int flag=0;
    dictionary2 *ptr,*par;
    ptr=Root2;

    if(Root2==NULL)
        Root2=temp;
    else{
        while(ptr!=NULL ){
            if(check(temp->request_num,ptr->request_num)>0){
                par=ptr;
                ptr=ptr->right;
            }

            else if(check(temp->request_num,ptr->request_num)<0)
            {
                par=ptr;
                ptr=ptr->left;
            }
            else if(check(temp->request_num,ptr->request_num)==0){
                flag=1;
                cout << "Word exists!";
                break;
            }

        }
        if(flag==0 && ptr==NULL){

            if(check(par->request_num,temp->request_num)==1)
                par->left=temp;
            else if(check(par->request_num,temp->request_num)==-1)
                par->right=temp;
        }

    }

}

void print_t(dictionary2 *root, int space)
{
    int counter = 10;
    if (root == NULL)
        return;
    space += counter;

    print_t(root->right, space);
    cout<<endl;
    for (int i = counter; i < space; i++)
        cout<<" ";
    cout<<root->word<<"\n";

    print_t(root->left, space);
}


void print_tree(dictionary2 *root)
{

    print_t(root, 0);
}

void view_new(dictionary2 *ptr){
    if(Root2==NULL)
        cout << "Empty dictionary!"<<endl;

    else if(ptr !=NULL){
        view_new(ptr->left);

        cout << ptr->word << endl;
        cout << ptr->meaning << endl;
        cout << ptr->request_num << endl;

        view_new(ptr->right);
    }
}
