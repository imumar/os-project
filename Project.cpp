#include<stdio.h>
int main()
{
    int ariv[15],p[15],prio[15],i,j,n=3,temp;
    printf("Total Number of students(i.e processes) is 10");
    printf("\nEnter arrival Time of each student and number of gifts each one has(i.e arrival time and priority of each process)\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]:\n",i+1);
        printf("Arrival Time:");
        scanf("%d",&ariv[i]);
        printf("Number of gifts:");
        scanf("%d",&prio[i]);
        p[i]=i+1;           //increments process number
    }
    
    for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
            //Sorting according to time of arrival
			if(ariv[i]>ariv[j])
			{
				temp=p[j];			//first three lines for sorting in p array, middle three for sorting in ariv array and last three for sorting in prio array
				p[j]=p[i];
				p[i]=temp;
				
				temp=ariv[j];
				ariv[j]=ariv[i];
				ariv[i]=temp;
				
				temp=prio[j];
				prio[j]=prio[i];
				prio[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ariv[i]==ariv[j])
			{
				if (prio[i]<prio[j])
				{
				temp=p[j];		
				p[j]=p[i];
				p[i]=temp;
				
				temp=ariv[j];
				ariv[j]=ariv[i];
				ariv[i]=temp;
				
				temp=prio[j];
				prio[j]=prio[i];
				prio[i]=temp;
	
				}
			}
		}
	}

	printf("\nProcess\t    Arrival Time \t\tPriority");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\t\t  %d  \t\t%d",p[i],ariv[i],prio[i]);
    }
    
	printf("\nThe order of execution will be(Students will be attended in the following order)\n" );		//prints order of execution
	printf("< ");
	for(i=0;i<n;i++)
	{
		printf("  p%d",p[i]);
	}
	printf(" >");
}
