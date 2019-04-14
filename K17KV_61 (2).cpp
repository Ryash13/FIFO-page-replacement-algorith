#include<stdio.h>
#include<stdlib.h>

struct fnode
{
	int pno;
}frames[5];


int i,n,pfct=0,pno,p,flag=0,len;

		
int page_found(int pno)
{ 
     
	for(i=0;i<n;i++)
	{
		if(frames[i].pno==pno)
		{
			return i;
		}
		return 0;
	}
}

main()
{  
    int ref_str[len];
		printf("\nEnter number of page reference:- ");
	    scanf("%d",&len);
	   printf("\nEnter the reference string:- ");
	   for(p=0;p<len;p++)
	   {	   	
	   	printf("\nEnter string reference %d :-\t",p);
	   	scanf("%d",ref_str[p]);	
		fflush(stdin);   	
	   }
	
	printf("\nEnter number of frames:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		frames[i].pno = -1;
	}
	printf("\nPAGE NUMBER     PAGE FRAMES     PAGE FAULT     PAGE FAULT COUNT\n");
	printf("...................................................................\n");
	for(p=0;p<len;p++)
	{
		pno = ref_str[p];
		flag = 0;
		if(page_found(pno)==0)
		{
			frames[pfct%n].pno = pno;
			pfct++;
			flag = 1;
		}
		printf("\n%5d\t\t",pno);
		for(i=0;i<n;i++)
		{
			printf("%d ",frames[i]);
		}
		if(flag==1)
			printf("\t\tYES");
		else
			printf("\t\tNO");
		
		printf("\t\t%d",pfct);
	}
	printf("\n..............................................\n");
	printf("Total no of page faults are:- %d",pfct);
}
