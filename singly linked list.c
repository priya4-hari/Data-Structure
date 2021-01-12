#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	};
	struct node *temp,*head,*newnode;
	void insertfirst();
	void insertmiddle();
	void insertlast();
	void deletefirst();
	void deletemiddle();
	void deletelast();
	void display();
	void len();
	void reverse();
	int isempty();
	struct node *createnewnode(int);
	void main()
	{
		int ch;
		while(1)
		{
			printf("1.insertfirst\n 2.insertmiddle\n 3.insertlast\n 4.deletefirst\n 5.deletemiddle\n 6.deletelast\n 7.display\n 8.len\n 9.reverse\n 10.exit\n");
			printf("enter choice:");
			scanf("%d",&ch);
			switch(ch)
			{
			case 1:insertfirst();
				break;
			case 2:insertmiddle();
				break;
			case 3:insertlast();
				break;
			case 4:deletefirst();
				break;
			case 5:deletemiddle();
				break;
			case 6:deletelast();
				break;
			case 7:display();
				break;
			case 8:len();
				break;
			case 9:reverse();
				break;
			case 10:exit(1);
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
		if(newnode!=NULL)
		{
			newnode->data=y;
			newnode->next=NULL;
			}
			else
			{	
				printf("not created!");
				}
				}
	void insertfirst()
	{
		int x;
		printf("enter the data:");
		scanf("%d",&x);
		newnode=createnewnode(x);
		if(isempty())
		{
			head=newnode;
			newnode->next=NULL;
			}
			else
			{
				newnode->next=head;
				head=newnode;
				}
				}
	void insertmiddle()
	{
		int x;
		printf("enter data:");
		scanf("%d",&x);
		newnode=createnewnode(x);
		if(isempty())
		{
			printf("list is empty");
			}
			else
			{
				int pos,i,count=0;
				printf("enter the pos:");
				scanf("%d",&pos);
				temp=head;
				while(temp!=NULL)
				{
					count++;
					temp=temp->next;
					}
				if(pos>count)
				{
					printf("cannot insert");
					}
				else
				{
					temp=head;
					for(i=1;i<pos;i++)
					{
						temp=temp->next;
						}
						newnode->next=temp->next;
						temp->next=newnode;
						}
						}
						}
		void insertlast()
		{
			int x;
			printf("enter the data:");
			scanf("%d",&x);
			newnode=createnewnode(x);
			if(isempty())
			{
				head=newnode;
				}
			else
			{
				temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					}
					newnode->next=NULL;
					temp->next=newnode;
					}
				}
		void deletefirst()
		{
			struct node *del;
			if(isempty())
			{
				printf("list is empty");
				}
			else
			{
				del=head;
				head=head->next;
				printf("deleted data is %d",del->data);
				free(del);
				}
				}
		void deletemiddle()
		{
			struct node *del;
			if(isempty())
			{
				printf("list is empty");
				}
			else
			{
				int i,pos,count=0;
				printf("enter pos:");
				scanf("%d",&pos);
				temp=head;
				while(temp!=NULL)
				{
					count++;
					temp=temp->next;
					}
				if(pos>count)
				{
					printf("out of memory");
					}
				else
				{
					temp=head;
					for(i=1;i<pos;i++)
					{
						temp=temp->next;
						}
						del=temp->next;
						temp->next=temp->next->next;
						printf("the deleted element is %d",del->data);
						free(del);
						}
						}
						}
			void deletelast()
			{
				struct node *del;
				if(isempty())
				{
					printf("list is empty");
					}
				else
				{
					temp=head;
					while(temp->next->next!=NULL)
					{
						temp=temp->next;
						}
						del=temp->next;
						temp->next=NULL;
						printf("the deleted element is %d",del->data);
						free(del);
						}
						}
			void len()
			{
				int count=0;
				temp=head;
				while(temp!=NULL)
				{
					++count;
					temp=temp->next;
					}
					printf("the count is %d",count);
					}
			void reverse()
			{
				struct node *current;
				struct node *prevnode;
				struct node *nextnode;
				prevnode=NULL;
				nextnode=current=head;
				while(nextnode!=NULL)
				{
					nextnode=nextnode->next;
					current->next=prevnode;
					prevnode=current;
					current=nextnode;
					}
					head=prevnode;
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
