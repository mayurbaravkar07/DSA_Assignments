#include<iostream>
#include<string.h>
using namespace std;

struct node{
    int value;
    node* next;

}*hashTable[10];



class telephoneDirectory {
public:

    //Filling all null values to the hashTable
    void hashing(){
        for (int i = 0; i < 10; i++) {
        hashTable[i]=NULL;
        }
    }

    ///HashFunction for for mapping key to the table size

    int hashFunction(int value){
        return value%10;
    }

     node* createNode(int value){
        node *temp=new node;
        temp->next=NULL;
        temp->value=value;
         return temp;
    }

    void insertElement(int value){
        int hashValue=hashFunction(value);
        //Creating the new node
        node *temp=new node;
        node *head=new node;
        head=createNode(value);
        temp=hashTable[hashValue];

        ///if that item is the first value then we are storing in the hashtable
        if(temp==NULL){
            hashTable[hashValue]=head;
        }else{
            ///if that value is not the first one traverse and append it to the last
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=head;

        }
    }

    void deleteElement(int value){
        int hashValue=hashFunction(value);
        node *entry=hashTable[hashValue];
        if (entry==NULL){
            cout<<"Element not in the telePhone Directory";
        }

        ///if the value that we have to delecte is the first one
        if (entry->value==value){
            hashTable[hashValue]=entry->next;
            return;
        }
        //traverse till we don't find the target value
        while (entry->next->value!=value){
            entry=entry->next;
        }
        entry->next=entry->next->next;
    }

    bool searchElement(int value){
        int hashValue=hashFunction(value);
        node*entry=hashTable[hashValue];

        if (entry->value==value){
            return true;
        }
        while (entry->next!=NULL){
            if (entry->value==value){
                return true;
            }
            entry=entry->next;
        }
        return false;
    }

    void print()
    {
        for(int i=0 ; i< 10; i++)
        {
            node * temp=new node;
            temp=hashTable[i];
            cout<<"a["<<i<<"] : ";
            while(temp !=NULL)
            {
                cout<<" ->"<<temp->value;
                temp=temp->next;
            }
            cout<<"\n";
        }
    }





};
int main()
{
    int ch;
    int data,search,del;
    telephoneDirectory h;
    do
    {
        cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\nEnter phone no. to be inserted : ";
                cin>>data;
                h.insertElement(data);
                break;
            case 2:h.print();
                break;
            case 3:cout<<"\nEnter the no to be searched : ";
                cin>>search;

                if (h.searchElement(search) == -1)
                {
                    cout<<"No element found at key ";
                    continue;
                }
                break;
            case 4:cout<<"\nEnter the phno. to be deleted : ";
                cin>>del;
                h.deleteElement(del);
                cout<<"Phno. Deleted"<<endl;
                break;
        }
    }while(ch!=5);
    return 0;

}







//compelted