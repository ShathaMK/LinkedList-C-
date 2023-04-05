#include <iostream>
using namespace std;

struct Node
{
int info;
Node *link;
};
Node *temp=NULL, *cur=NULL , *head=NULL ,*tail=NULL,*pos=NULL;

void InsertFront()
{
temp=new Node;
cout<<"Enter Integer Data:\n";
cin>>temp->info;
temp->link=NULL;
if(head==NULL)//EMPTY
{
head=temp;
tail=temp;
}
else
{
temp->link=head;//insert a value;
head=temp;
}

}

void InsertRear()
{
temp=new Node;
cout<<"Enter Integer data:\n";
cin>>temp->info;
temp->link=NULL;
if(head==NULL)//EMPTY
{
head=temp;
tail=temp;
}
else
{
tail->link=temp;//insert a value
tail=temp;
}
}

void Deletefront()
{
temp=head;
if(head==NULL)
{
cout<<"List is empty!!\n";
}
else
{
if(temp->link==NULL)//last element
{
head=NULL;
tail=NULL;
}
else
{
head=head->link;//point to the next node
}
cout<<"Deleted:\n"<<temp->info;
delete temp;//delete it
}
cout<<endl;
}

void DeleteRear()
{
cur=head;
temp=tail;
if(head==NULL)
{
cout<<"List is Empty!!\n";
}
else
{
if(cur->link==NULL)//last element
{
head=NULL;
tail=NULL;
}
else
{
while(cur->link!=tail)//look for the node before the last element
{
cur=cur->link;
}
tail=cur;//assign tail to current
cur->link=NULL;//the last element will point to null
}
cout<<"Deleted:\n"<<temp->info;
delete temp;//delete the element
}
cout<<endl;
}

void PrintForward()
{
cur=head;
if(head==NULL)
{
cout<<"List is Empty!!\n";
}
else
{
cout<<"List display:\n";
while(cur)//walkthrough every element
{
cout<<cur->info<<"->";
cur=cur->link;
}
    cout <<endl;
}
}

void InsertMiddle()
{
cout<<"Enter the position to insert the new node:"<<endl;
int position;
cin>>position;
cur=head;
for(int i=0;i<position-1 &&cur;i++)
{
cur=cur->link;
}
if(cur)
{
temp=new Node;
cout<<"Enter integer data:\n";
cin>>temp->info;
temp->link=cur->link;
cur->link=temp;
}
else
return;
}

Node* Search()
{
cur=head;
cout<<"Enter the item to be seached:\n";
int item;
cin>>item;
while(cur)
{
if(cur->info==item)
{
cout<<"Item found\n";
return cur;
}
cur=cur->link;
}
if(cur==NULL)
cout<<"Item is not found in the list\n";
return cur;
}

void DeleteBySearching()
{
temp=Search();
if(temp)
{
cur=head;
while(cur->link!=temp)
{
cur=cur->link;
}
if(cur==head)
{
head=head->link;
}
else if(cur==tail)
{
tail=cur;
cur->link=NULL;
}
else
{
cur->link=temp->link;
}
cout<<"Deleted:\n"<<temp->info;
delete temp;
cout<<endl;
}
}
void Swap(){
    cur=head;
  
   
    if (head==NULL) {
        cout <<"Empty";
    }
    else{
        while(cur->link!=NULL){
            pos=cur;
            cur=cur->link;
        }
       
    }
    if (head==cur){//1 element
        return;
    }
    else if (head->link==cur)//2 element
    {
        temp=head;
        head=cur;
        head->link=temp;
        temp->link=NULL;
     
        }
    else{//more than two element
        temp=head;
        head=cur;
        head->link=temp->link;
        pos->link=temp;
        temp->link=NULL;
      
    }
    cout<<endl;
}
int CountNodes(){
    temp=head;
    int i=0;
    while (temp!=NULL) {
        i++;
        temp=temp->link;
    }
        return i;
    
}
int main()
{
int choice;
do
{
cout<<"1: Enter item at front\n";
cout<<"2: Enter item at rear\n";
cout<<"3: Delete item from front\n";
cout<<"4: Delete item from rear\n";
cout<<"5: Print list in forward Direction\n";
cout<<"6: Enter item at Middle\n";
cout<<"7: Search an item\n";
cout<<"8: Delete by Searching\n";
cout<<"9: Swap Last and First Node\n";
cout<<"10: Count Number of Nodes\n";
cout<<"11: Exit\n";
cout<<"Enter your choice: \n";
cin>>choice;

switch(choice)
{
case 1:
InsertFront();
break;
case 2:
InsertRear();
break;
case 3:
Deletefront();
break;
case 4:
DeleteRear();
break;
case 5:
PrintForward();
break;
case 6:
InsertMiddle();
break;
case 7:
Search();
break;
case 8:
DeleteBySearching();
break;
case 9:
Swap();
break;
case 10:
cout<<"No. of nodes:"<<CountNodes()<<endl;
break;
case 11:
cout<<"Exiting program\n";
break;
default:
cout<<"Error! wrong choice\n";
  
}
   
}while(choice!=11);
return 0;
}
