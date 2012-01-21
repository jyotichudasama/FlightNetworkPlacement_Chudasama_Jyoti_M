/*
Kids are playing a game of Elimination. The rules of the game are
a) Suppose there are M kids. They stand in a circle and pick a random number N which is less than M.
b) They start counting from 1 to N and the kid at position N is eliminated. They resume counting from position N + 1 starting
from 1.
c) This continues until there is only one kid left. The last Kid standing is declared the Winner.
Write an algorithm which, given values of M and N, identifies the position which would make her the winner.
*/

#include<conio.h>
#include<stdio.h>
#include<iostream.h>

#define MAX 50

//using namespace std;

int a[MAX];

struct node
{
  int info;
  struct node *link;
};


struct node* elim_player(struct node* temp,int N,int M)
{
	int i,cnt;
	struct node *pre;
	if(N==1)	// Special Case for N=1 as we have to remove first node from Current list every time
	{
		pre = temp->link;	// Pre points to 2nd node in Current list
		cout<<"\n Player at positon  "<<(temp->info)<<" is eliminated.";
		for(i=0;i<M;i++)
		{
			temp = temp->link;
		}
		temp->link = pre;	// Setting link for Circular list last to first after deletion
		temp = temp->link;	// Now temp at N+1 position
	}
	
	else
	{
		for(cnt = 1;cnt<N;cnt++)
		{
			pre = temp;
			temp = (temp->link);	// traversing in list
		}
		
		(pre->link) = (temp->link);
		cout<<"\n Player at positon  "<<(temp->info)<<" is eliminated.";
		temp = (temp->link);	//(N+1)th element
	}
	
	return temp;
	
}

void find_winner(int M,int N)
{
	struct node *start,*add,*temp;
	int i,cnt = 1;
	
	// Creating List that indicates M position
	start=new node;		// First node
	if(start=='\0')
	{
		cout<<"\n No Free Node...\n";
	}	
	else
	{
		start->info = 1;	// Storing 1 indicating position 1
		temp = start;
		(temp->link)=start;		// This is done as we want Circle, i.e. Circular List
		
		for(i=2;i<=M;i++)
		{		
			add=new node;
			if(add=='\0')
			   cout<<"\n No Free Node...\n";
			else
			{				
				(add->info)=i;		// i is stored as info
				(add->link)=(temp->link);	// Linking new node at the end of the list of existing nodes
				(temp->link)=add;			// Done
				temp = add;		// Temp is now pointing to newly added node.
			}				
		}
	}
	// List is created.
	
	// Now eliminating one by one.
	temp = start;	// For first pass, we will start from 1.
	while(cnt != M)
	{
		temp = elim_player(temp,N,M);		// temp is updated to point N+1 player for next passes
		cnt += 1;		// Counter for counting no.of passes. 
	}
	
	/* When cnt = M, there is only one player remains in game. He/She is winner & is pointed by temp */
	cout<<"\n\n Player at position "<<(temp->info)<<" is winner.\n";
	
}

int main()
{
	int M,N;	
	
	clrscr();
	cout<<"****************************************";	
	cout<<"\n\n   IMPLEMENTATION OF ELIMINATION GAME\n\n";
	cout<<"****************************************\n";
	while(M != 0)
	{
		cout<<"\n Enter number of players.(Maximum"<<MAX<<", Enter 0 to exit): ";
		cin>>M;
		if(M == 0)
		{
			cout<<"\n Exiting...";
			break;
		}
		if(M < 2 || M > MAX)
		{
			cout<<"\n Invalid Input. Try Again.\n";
		}	
		else
		{
			cout<<"\n Enter value for elimination.(Must be less than "<<M<<"): ";	// N must be less than M
			cin>>N;
			if(N>=M)
				cout<<"\n Invalid Data. Try Again.\n";
			else
				find_winner(M,N);
		}
	}
	
	return 1;
}