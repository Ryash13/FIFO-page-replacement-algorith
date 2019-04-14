#include<stdio.h>
#include<conio.h>

int main()
{
	int i , j , k , np , ref[50] , fn , frame[10] , count = 0 , avail;
	printf("Enter the number of pages:- ");
	scanf("%d",&np);
	printf("\nEnter the reference string:- \n");
	for(i=0;i<np;i++)
	{
		scanf("%d",&ref[i]);
	}
	printf("\nEnter the number of frames:- ");
	scanf("%d",&fn);
	
	for(i=0;i<np;i++)
	{
		frame[i] = -1;
	}
	k=0;
	printf("Ref String\tPage Framne");
	printf("\n.........................\n");
	for(i=0;i<np;i++)
	{
		printf("%d\t",&ref[i]);
		avail = 0;
		for(j=0;j<fn;j++)
		{
			if(frame[j]==ref[i])
			{
				avail = 1;
			}
		}
		if(avail == 0)
		{
			frame[k]=ref[i];
			k=(k+1)%fn;
			count++;
			for(j=0;j<fn;j++)
			{
				printf("%d\t",frame[k]);
			}
		}
		printf("\n");
	}
	printf("Total number of page faults are:- %d",count);
	return 0;
}
