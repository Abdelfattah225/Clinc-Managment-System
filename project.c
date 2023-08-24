/*
 ============================================================================
 Author      : Abdelfattah moawed Abdelfattah
 Description : porject clinc managment system by using linked list
 object 	 : main
 date 		 : 20 / 8 / 2023
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Null ((void*)0)


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef  float f32;
typedef  double f64;

s32	arr[5]={0};



typedef struct Node Node;
struct Node
{
	u8 nnn[15];
	u8 Name[15];
	u8 Age ;
	u8 Gender[6];
	u32 ID ;
	u32 Slot;
	Node*Next;
	Node*Pervious;
};

Node*pfirst;   // first block in linked list 
Node*plast;	   // last block in linked list





// func inputs are (data of patient name , age ,gender and id)
// func output is address of new block 
Node* Create( const u8 *name, u8 age ,const u8 *gender,u32 id)
{
	Node*new;
	new = (Node*)malloc(sizeof(Node));
	strcpy(new->Gender,gender);    // to copy stirng form name to new->Gender
	new->Age=age;
	strcpy(new->nnn,name);
	new->ID=id;
	new->Next=Null;                // by default next of any new block are Null
	new->Pervious=Null;				// by default Pervious of any new block are Null
	new->Slot;
		

}






// func to add any block to linked list 
// func input is address of block
// no output 
void Add(Node*node)
{
	if(pfirst==Null)       // if linked list is empty
	{
		pfirst=plast=node;
	}
	else					// if linked list is not empty at list one block 
	{
		plast->Next=node;       // first, we put address of new block in Next of last block 
		node->Pervious=plast;    // After that,we put address of last block in pervious of new block
		plast=node;				// finally , we put address of new block in last block
	}
}






/* func to search if id of patient exist in linked list or Not ?
	if it exist the func will return its address 
	if not it will return Null
*/

// func input is only id of patient
// func out is address of patient if exist or Null if Not 
Node* Search(u32 id)
{
	Node*psearch=pfirst;   // we made a new Node named it (psearch) and put address of frist in it 
	while(psearch!=Null	)	// Even first's address doesn't change with time 
	{
		if(psearch->ID==id)
			return psearch;
		else
		{
			psearch=psearch->Next;
		}
	}
	return Null;
}





/* func to print data of all patient added before*/
// NO input and No output
void print(void)
{
	Node*print=pfirst;    // we made a new Node named it (print) and put address of frist in it 
	u8 i=0;					// Even first's address doesn't change with time
	if(print==Null)
		{
			printf("List is Empty\n");       // if linked list has no block , it will print list is empty 
		}
	else
		{
			while(print!=Null)
			{
				
				printf("patient number %d\n",i+1);
				printf("Name 	: %s\n",print->nnn);
				printf("Age 	: %d\n",print->Age);
				printf("Gender	: %s\n",print->Gender);
				printf("ID 		: %d\n\n",print->ID);
				printf("==============================================================\n");
				print=print->Next;
				i++;
			}
		}
}





/* func to print data of a patient added before*/
// take adress of patient's block as a input and No output
void print_one_patient(Node*node)
{
				Node*print=node;
				printf("Name 	: %s\n",print->nnn);
				printf("Age		: %d\n",print->Age);
				printf("Gender  : %s\n",print->Gender);
				printf("ID 		: %d\n\n",print->ID);
}




// func to reserve a slot with a doctor it take address of patient that he need to reserve
// and show avilable solts 
// and ask him what is the time that he need ?
void Reserve(Node*node)
{
	int s;
	printf("Avilable solts : \n");
	if(arr[0]==0)
		printf("1- 2pm to 2:30pm\n");
	else
		printf("1- booked up\n");
	if(arr[1]==0)
		printf("2- 2:30pm to 3pm\n");
	else
		printf("2- booked up\n");
	if(arr[2]==0)
		printf("3- 3pm to 3:30pm\n");
	else
		printf("3- booked up\n");
	if(arr[3]==0)
		printf("4- 4pm to 4:30pm\n");
	else
		printf("4pm- booked up\n");
	if(arr[4]==0)
		printf("5- 4:30pm to 5pm\n");
	else
		printf("5- booked up\n");
	printf("Enter number of slot that you need(1-5) : ");
	scanf("%d",&s);
	if((s<=5)&&(s>=1))
	{
	node->Slot=s;
	arr[s-1]=s;
	printf("Reservation done\n");
		printf("==============================================================\n");	
	}
	else
	{
		printf("Invalid number \n");
			printf("==============================================================\n");	
	}
	
}




// func to show for user the avilable slots today
void view_reservation(void)
{
	printf("Avilable solts : \n");
	if(arr[0]==0)
		printf("1- 2pm to 2:30pm\n");
	else
	{
		printf("1- booked up \n"); 
			
	}
	if(arr[1]==0)
		printf("2- 2:30pm to 3pm\n");
	else
	{
		
			printf("2- booked up \n"); 
	}
	if(arr[2]==0)
		printf("3- 3pm to 3:30pm\n");
	
	else
	{
		
			printf("3- booked up \n"); 
	}
	if(arr[3]==0)
		printf("4- 4pm to 4:30pm\n");
	else
	{
		printf("4- booked up \n"); 
	}
	if(arr[4]==0)
		printf("5- 4:30pm to 5pm\n");
	else
	{
			printf("5- booked up \n"); 
	}
}





// func for admin to cancel any reservation 
void Cancel_reservation(Node*node)
{
	for(u8 i=0 ; i<5 ;i++)
	{
		if(node->Slot==arr[i])
		{
			arr[i]=0;
			printf("Reservation cancelled\n");
				printf("==============================================================\n");	
		}
	
	}
}






// func to eidt data of any patient added before 
void Edit_patient(Node*node,const u8 *newname , u8 newage ,const u8 *newgender)
{
	strcpy(node->nnn,newname);
	node->Age=newage;
	strcpy(node->Gender,newgender);
	
	
}

void main(void)
{
	u8 mode;
	u32 password;
	u8 choice;
	const u8 name[15];
	const u8 nnn[15];
	u8 age;
	const u8 gender[6];
	u32 id;
	printf("---------------------------------------------------------------\n");
	printf("--------------------- Welcome to our clinc --------------------\n");
	printf("---------------------------------------------------------------\n\n");
	printf("for Admin mode enter 1 : \n");
	printf("for User mode enter 2 : \n");
	printf("to exist enter 0 : \n");
	printf("==============================================================\n");
	scanf("%d",&mode);
while(mode!=0)
{
	if(mode==1)
	{
		// if user enter password 3 times, program will exist
		u32 c=1;
		while(c<4)
			{
				printf("Enter password : ");
				scanf("%d",&password);
				if(password==1234)
				{
					printf("correct password \n");
					printf("==============================================================\n");
					break;
				}
				else
				{
					if(c<3)
					{printf("please try again \n");
				printf("==============================================================\n");
					c++;}
					else{
						printf("incorrect password \n");
						printf("==============================================================\n");
						c++;
					}
				}
			}
			if(password==1234)  // after enter correct password admin's list will be appear
			{
				
				printf("==============================================================\n");
				printf("welcome to Admin's list \n\n");
				printf("To Add new patient record enter 1 : \n");
				printf("To Edit patient record enter 2 : \n");
				printf("To Reserve a slot with the doctor enter 3 : \n");
				printf("To Cancel reservation enter 4 : \n");
				printf("To view all patients enter 5 \n");
				printf("to Back enter 0 : \n");
				printf("==============================================================\n");
				
				scanf("%d",&choice);
				while(choice!=0)
				{
					if(choice==1)
					{
						printf("please enter patient's ID : ");
						scanf("%d",&id);
						Node*search=Search(id);
						if(search!=Null)
						{
								printf("ID Already exist \n");
								printf("==============================================================\n");
						}
						else
						{
							printf("please enter patient's Gender (male or female) : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%s",gender);
							
							
							printf("please enter patient's Age : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%d",&age);
							
							
							printf("please enter patient's Name : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%s",nnn);
							
							Add(Create(nnn,age,gender,id));
							printf("The patient has been registered successfully\n");
							printf("==============================================================\n");
						}
						
					}
					else if(choice==2)
					{
						printf("please enter patient's ID : ");
						scanf("%d",&id);
						Node*search=Search(id);
						if(search!=Null)
						{
								printf("please enter patient's Gender (male or female) : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%s",gender);
							
							
							printf("please enter patient's Age : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%d",&age);
							
							
							printf("please enter patient's Name : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%s",nnn);
							
							Edit_patient(search,nnn,age,gender);
							printf("Patient data has been modified\n");
							printf("==============================================================\n");
						}
						else
						{

							printf("ID doesn't exist \n");
							printf("==============================================================\n");
						}
					}
					else if(choice==3)
					{
						printf("please enter patient's ID : ");
						scanf("%d",&id);
						Node*search=Search(id);
						if(search==Null)
						{
							printf("ID doesn't exist \n");
							printf("==============================================================\n");	
						}
						else
						{
							Reserve(search);
						}
						
						
					}
					else if(choice==4)
					{
						printf("please enter patient's ID : ");
						scanf("%d",&id);
						Node*search=Search(id);
						if(search==Null)
						{
							printf("ID doesn't exist \n");
							printf("==============================================================\n");
						}
						else
						{
							Cancel_reservation(search);
						}
					}
					else if(choice==5)
					{
						print();
					}
					else 
					{
						printf("Invalid choice please try again\n");
						printf("==============================================================\n");
					}
					printf("\nAdmin's list please choose number :\n ");
					printf("To Add new patient record enter 1 : \n");
					printf("To Edit patient record enter 2 : \n");
					printf("To Reserve a slot with the doctor enter 3 : \n");
					printf("To Cancel reservation enter 4 : \n");
					printf("To view all patients enter 5 \n");
					printf("to Back enter 0 : \n");
					printf("==============================================================\n");
					scanf("%d",&choice);
				}
				
			}
	}
	else if (mode==2)
	{
		printf("Enter 1 to view patient record \n");
		printf("Enter 2 to view today's reservations \n");
		printf("Enter 0 to back  \n");
		printf("==============================================================\n");
		scanf("%d",&mode);
		if(mode==1)
		{
			u32 ID;
		printf("Enter your ID: ");
		scanf("%d",&ID);
		Node*search=Search(ID);
			if(search==Null)
			{
				printf("ID doesn't exist \n");
				printf("==============================================================\n");
			}
			else{
					
					print_one_patient(search);
					printf("==============================================================\n");
				}
		}		
		else if(mode==2)
		{
			
			view_reservation();
								printf("==============================================================\n");

		}
		else if(mode==0)
		{
					printf("Welcome \n");
					printf("for Admin mode enter 1 : \n");
					printf("for User mode enter 2 : \n");
					printf("to exist enter 0 : \n");
					printf("==============================================================\n");
		}
		else{
			printf("Invalid choice please try again\n");
			printf("==============================================================\n");
		}
	}
		else
		{
			printf("Invalid choice please try again\n");
			printf("==============================================================\n");
		}
			printf("Welcome to main list,please enter number : \n");
			printf("for Admin mode enter 1 : \n");
			printf("for User mode enter 2 : \n");
			printf("to exist enter 0 : \n");
	     	printf("==============================================================\n");
			scanf("%d",&mode);
	
}
if(mode==0)
printf("Thank You\nGood Bye");

}



















