#include<stdio.h>
#include<stdlib.h>

int main()
{
	int choice,pid,f_pid,w_pid,e_pid,id,status;
	char *argv[3];
	printf("\n\n---***---***---MENU---***---***---\n\n");
	printf("1.PS\n2.Fork\n3.Wait\n4.execv\n5.Join\n6.Exit\n\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n**---PS---**\n\n");
			printf("Currently Running Processes are : \n\n");
			system("ps");
			printf("\n\n");
			break;
			
		case 2:
			printf("\n**---FORK---**\n\n");
			f_pid=fork();
			if(f_pid>0)
			{
				printf("Parent Process ID : %d",getppid());
			}
			else if(f_pid==0)
			{
				printf("\n\nChild Process ID : %d\n\n",getpid());
			}
			else
			{
				printf("\nERROR\n\n");
			}
			break;
		
		case 3:
			printf("\n**---Wait---**\n\n");
			w_pid=fork();
			if(w_pid>0)
			{	
				printf("Parent Process ID : %d",getppid());
				id=wait(&status);
				printf("\n\nProcess Terminated with ID : %d\n\n",id);
			}
			else if(w_pid==0)
			{
				printf("Child Process ID : %d\n\n",getpid());
			}
			else
			{
				printf("\nERROR\n\n");
			}
			break;
		
		case 4:
			printf("\n**---EXECV---**\n\n");
			e_pid=fork();
			if(e_pid>0)
			{
				printf("Parent Process ID : %d",getppid());
				printf("\n\nOpening Firefox\n");
				execv("/usr/bin/firefox",argv);
			}
			else if(e_pid==0)
			{
				printf("\nChild Process ID : %d\n\n",getpid());
			}
			else
			{
				printf("\nERROR\n\n");
			}
			break;
		
		case 5:
			printf("\n**---EXECV---**\n\n");
			printf("File(test1.txt) :\n\n");
			system("cat test1.txt");
			printf("\n\nFile(test2.txt) :\n\n");
			system("cat test2.txt");
			printf("\nBefore Joining -> ");
			printf("File(join.txt) :\n\n");
			system("cat join.txt");
			system("join test1.txt test2.txt > join.txt");
			printf("\n\nAfter Joining -> ");
			printf("File(join.txt) :\n\n");
			system("cat join.txt");
			break;	
		
		case 6:
			printf("\n\nBYE...! HAVE A GREAT DAY.\n\n");
			break;
		
		default:
			printf("\n\nSORRY...! You Entered Wrong Choice.\n\n");
	}
}
