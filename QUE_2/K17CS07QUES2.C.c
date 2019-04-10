#include<stdio.h>
#include<string.h>
void main()
{
	char p[10][5],temp[5];
	int a,b,pt[10],wt[10],totwt=0,pr[10],temp1,n;
	float avgwt;
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		printf("enter the process %d name:",a+1);
  		scanf("%s",&p[a]);
		printf("enter the process time:");
		scanf("%d",&pt[a]);
		printf("enter the priority:");
		scanf("%d",&pr[a]);
	}
  	for(a=0;a<n-1;a++)
	{
		for(b=a+1;b<n;b++)
		{
			if(pr[a]>pr[b])
			{
				temp1=pr[a];
				pr[a]=pr[b];
				pr[b]=temp1;
				temp1=pt[a];
				pt[a]=pt[b];
				pt[b]=temp1;
				strcpy(temp,p[a]);
				strcpy(p[a],p[b]);
				strcpy(p[b],temp);
			}
		}
	}
	wt[0]=0;
	for(a=1;a<n;a++)
	{
		wt[a]=wt[a-1]+wt[a-1];
		totwt=totwt+wt[a];
	}
	avgwt=(float)totwt/n;
	printf("p_name\t p_time\t priority\t \n");
	for(a=0;a<n;a++)
	{
	   printf(" %s\t %d\t %d\t \n" ,p[a],pt[a],pr[a]);
	}
	//printf("total waiting time=%d\n avg waiting time=%f",totwt,avgwt);
	
	int ts,pid[10],need[10],wt1[10],tat[10],a1,b1,n2,n1;
	int bt[10],flag[10],ttat=0,twt=0;
	float awt,atat;
	printf("\nEnter the number of Process \n");
	scanf("%d",&n);
	n1=n;
	printf("\n Enter the Timeslice \n");
 	scanf("%d",&ts);
 	for(a=1;a<=n;a++)
	{
   		printf("\n Enter the process ID %d",a);
		scanf("%d",&pid[a]);
   		printf("\n Enter the Burst Time for the process");
   		scanf("%d",&bt[a]);
   		need[a]=bt[a];
 	}
 	for(a=1;a<=n;a++)
	{
		flag[a]=1;
  		wt[a]=0;
 	}
 	while(n!=0)
	{
   		for(a=1;a<=n;a++)
   		{
     		if(need[a]>=ts)
     		{
       			for(b=1;b<=n;b++)
				{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=ts;
       			}
      			need[a]-=ts;
      			if(need[a]==0)
      			{
	 				flag[a]=0;
	 				n--;
       			}
     		}
     		else
    		{
       			for(b=1;b<=n;b++)
       			{
	  				if((a!=b)&&(flag[a]==1)&&(need[b]!=0))
	  				wt[b]+=need[a];
       			}
       			need[a]=0;
       			n--;
       			flag[a]=0;
  			}
 		}
	}
	for(a=1;a<=n1;a++)
	{
  		tat[a]=wt[a]+bt[a];
  		twt=twt+wt[a];
  		ttat=ttat+tat[a];
	}
	awt=(float)twt/n1;
	atat=(float)ttat/n1;
	printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
	for(a=1;a<=n1;a++)
	{ 
 		printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", ts,pid[a],bt[a],wt[a],tat[a]);
	}
	printf("\n The average Waiting Time=4.2f",awt);
	printf("\n The average Turn around Time=4.2f",atat);
}

