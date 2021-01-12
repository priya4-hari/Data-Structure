#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
	};
	struct node *head,*newnode,*last,*temp;
	void insertfirst();
	void insertmiddleatpos();
	void insertmiddleafterpos();
	void insertlast();
	void createlist();
	int isempty();
	void display();
	struct node *createnewnode(int);
	void main()
	{
		int ch;
		while(1)
		{
			printf("\n1.insertfirst \n2.insertmiddleatpos \n3.insertmiddleafterpos \n4.insertlast \n5.createlist 6.display\n 7.exit");
			printf("enter choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:insertfirst();
					break;
				case 2:insertmiddleatpos();
					break;
				case 3:insertmiddleafterpos();
					break;
				case 4:insertlast();
					break;
				case 5:createlist();
					break;
				case 6:display();
					break;
				case 7:exit(1);
					break;
					}
					}
					}
		int isempty()
		{
			if(head==NULL)
				return 1;
				else
					return 0;
					}
		struct node *createnewnode(int y)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			if(newnode==NULL)
			{
				printf("newnode not created!");
				}
				else
				{
					newnode->data=y;
					newnode->prev=NULL;
					newnode->next=NULL;
					}
					}
		void insertfirst()
		{
			int x;
			printf("enter data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			if(isempty())
			{
				head=last=newnode;
				}
				else
				{
					last=head;
					last->prev=newnode;
					newnode->next=last;
					head=newnode;
					}
					}
		void insertmiddleatpos()
		{
			int i=1,count=0,pos,x;
			printf("enter data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			printf("enter pos:");
			scanf("%d",&pos);
			temp=head;
			while(temp!=NULL)
			{
				++count;
				temp=temp->next;
				}
			if(isempty())
			{
				printf("list is empty");
				}
			else if(pos==1)
			{
				insertfirst();
				}
			else if(pos<=count)
			{
					temp=head;
					while(i<pos-1)
					{
						temp=temp->next;
						i++;
						}
						newnode->prev=temp;
						newnode->next=temp->next;
						temp->next=newnode;
						newnode->next->prev=newnode;
						}
			else
			{
				printf("out of range");
				}
						}
		void insertmiddleafterpos()
		{
			int i=1,count=0,pos,x;
			printf("enter data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			printf("enter pos:");
			scanf("%d",&pos);
			temp=head;
			while(temp!=NULL)
			{
				++count;
				temp=temp->next;
				}
			if(isempty())
			{
				printf("list is empty");
				}
			else if(pos<=count)
			{
				temp=head;
					while(i<pos)
					{
						temp=temp->next;
						i++;
						}
						newnode->prev=temp;
						newnode->next=temp->next;
						temp->next=newnode;
						newnode->next->prev=newnode;
						}
			else
			{
				printf("out of range");
				}
						}
		
		void insertlast()
		{
			int x;
			printf("enter data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			if(isempty())
			{
				head=last=newnode;
				}
			else
			{
				last->next=newnode;
				newnode->prev=last;
				last=newnode;
				}
				}
		void createlist()
		{
			int x;
			printf("enter data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			if(isempty())
			{
				head=last=newnode;
				}
				else
				{
					last->next=newnode;
					newnode->prev=last;
					last=newnode;
					}
					}
		void display()
		{
			temp=head;
			while(temp!=NULL)
			{
				printf("%d",temp->data);
				temp=temp->next;
				}
				}
