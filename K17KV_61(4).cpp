#include<stdio.h>
#include<conio.h>
int main()
{
	int i , j , k , avail , count=0;
	int pages , ref_string[50] , frame[10] , frame_no;
	
	printf("\nEnter the number of pages:- ");
	scanf("%d",&pages);
	
	printf("\nEnter the reference string:- \n");
	for(i=1;i<=pages;i++)
	{
		scanf("%d",&ref_string[i]);
	}
	
	printf("\nEnter number of frames:- ");
	scanf("%d",&frame_no);
	
	
	for(i=0;i<frame_no;i++)
	{
		frame[i]= -1;
	}
	j=0;
	
	printf("Ref String      Page Frames         Replacement?        Page_Faults\n");
	printf("........................................................................\n\n");
	for(i=1;i<=pages;i++)
	{
		printf("%d\t\t",ref_string[i]);
		avail=0;
		for(k=0;k<frame_no;k++)
			if(frame[k]==ref_string[i])
			avail=1;
		if(avail ==1)
		{
			printf("\t\t\tNO");
		}
		if (avail==0)
		{
			frame[j]=ref_string[i];
			j=(j+1)%frame_no;
			count++;
			for(k=0;k<frame_no;k++)
			printf("%d ",frame[k]);
			printf("\t\t\tYES");
			printf("\t\t%d    ",count);
		}
		printf("\n");
	}
	printf("Total number of page faults are:- %d",count);
	return 0;
}
