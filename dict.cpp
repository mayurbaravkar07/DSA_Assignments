#include<iostream>

using namespace std;

class list
{
	public:
		int key;
		long value;
		list *next;
};

class KeyPair
{
	public:
	int key;
    long value;
	list *next,*head,*temp,*val,*previous;
};

KeyPair KEY[50];




list *create(int k, long val)
{
	list *p=new list;
	p->key=k;
	p->value=val;
	p->next=NULL;
	return p;
}

int function(int num)
{
	int n=121,index;
	index=num%n;
	return index;
}


void insert(int n, int m, long h)
{
	if(KEY[n].key==0)
	{
		KEY[n].key=m;
		KEY[n].value=h;
	}
	else
	{
		list *p=create(m,h);
		if(KEY[n].head==NULL)
		{
			KEY[n].head=p;
		}
		else
		{
			KEY[n].temp=KEY[n].head;
			while(KEY[n].temp->next!=NULL)
				KEY[n].temp=KEY[n].temp->next;
			KEY[n].temp->next=p;
		}
		KEY[n].val=KEY[n].head;
	}
}

void searching(int z)
{
	char c;
	KEY[z].temp=KEY[z].head;
	{
	
	c='n';
	while(c!='y')
	{
		
		cout<<KEY[z].temp->key<<endl;
        cout<<KEY[z].temp->value<<endl;
        KEY[z].temp=KEY[z].temp->next;
        cout<<"is this correct?"<<endl;
        cin>>c;

	}
	}
}

list *head1(int k)
{
	return KEY[k].head;
}



void deletion(int k)
{
	if(KEY[k].head ==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	else
	{
	    
		KEY[k].temp=KEY[k].head;
        // KEY[k].temp=KEY[k].val;
		
		while(KEY[k].temp!=NULL)
    	{
    		KEY[k].previous=KEY[k].temp;
			cout<<KEY[k].temp->key<<endl;
			cout<<KEY[k].temp->value<<endl;
			cout<<"Do you want to delete?"<<endl;
			char c;
			cin>>c;
     		if(c=='y')
    		{
				KEY[k].previous->next=KEY[k].temp->next;
				KEY[k].temp->next=NULL;
				KEY[k].previous->next=KEY[k].temp->next;
			    delete KEY[k].temp;
				cout<<"Deleted"<<endl;
				break;
			}
			KEY[k].temp=KEY[k].temp->next;  
		}

	}
}



int main()
{
	int j;
	for (j=0;j<50;j++)
	{
		KEY[j].key= 0;
		KEY[j].value=0;
	}
	int c;
	while (1)
	{
		cout<<"1. Insertion"<<endl;
		cout<<"2. Searching"<<endl;
		cout<<"3. Deletion"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>c;
		switch(c)
		{
			case 1:
				{
					int k;
					long v;
					cout<<"Enter the Key:-"<<endl;
					cin>>k;
					cout<<"Enter the value:-"<<endl;
					cin>>v;
					int z;
					z=function(k);
					insert(z,k,v);
					break;
				}
				
			case 2:
				{
					char d;
					int k,z;
					cout<<"Enter the key to be searched:-"<<endl;
					cin>>k;
					z=function(k);
					cout<<KEY[z].key<<endl;
					cout<<KEY[z].value<<endl;
					cout<<"is the information correct?"<<endl;
					cout<<"Press 'n' or 'N' to continue, 'e' to exit and 'y' or 'Y' if correct info"<<endl;
					cin>>d;
					if(d=='e')
					{
						exit(1);
				    }
				    else if(d=='y')
				    {
				    	break;
					}
					else
					{
						searching(z);
						
					}
					break;
				}
			case 3:
				{
					
					char d;
					int k,m;
					cout<<"Enter the key to be deleted"<<endl;
					cin>>k;
					m=function(k);
				    cout<<KEY[m].key<<endl;
                    cout<<KEY[m].value<<endl;
                	cout<<"Do you want to delete the following info?"<<endl;
                	cin>>d;
                	if(d=='n')
                	{
                // 	                    	    KEY[m].key=0;
                // 		 KEY[m].value=0;
                // 		 break;
                		 deletion(m);
                	     break;
                	}
                	else
                	{

                // 		deletion(m);
                	   // break;
                	    KEY[m].key=0;
                		KEY[m].value=0;
                		break;
                		 
                	}
                	    
                }
				
			case 4:
				exit(1);
		}
	}

}
