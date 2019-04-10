/* Ten  students  (a,b,c,d,e,f,g,h,i,j)  are  going  to  attend  an  event.  There  are  l
ots  of  gift 
shops, they all are going to the gift shops and randomly picking the gifts. After picking the gifts 
they  are  randomly  arriving  in  the  billing  counter.  The  accountant  gives  the  preference  to  that 
student who has maximum number of gifts. Create a
C or Java program to define order of billed 
students? */
#include<stdio.h>
#include<string.h>
void main()
{
	char p[10][5],temp[5];
	int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
	float avgwt;
	printf("Enter no of Student:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter Students %d name:",i+1);
  		scanf("%s",&p[i]);
		printf("enter process time:");
		scanf("%d",&pt[i]);
		printf("enter no of gifts:");
		scanf("%d",&pr[i]);
	}
  	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pr[i]<pr[j])
			{
				temp1=pr[i];
				pr[i]=pr[j];
				pr[j]=temp1;
				temp1=pt[i];
				pt[i]=pt[j];
				pt[j]=temp1;
				strcpy(temp,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],temp);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+wt[i-1];
		totwt=totwt+wt[i];
	}
	avgwt=(float)totwt/n;
	printf("G_name\t P_time\t No.Gifts\n");
	for(i=0;i<n;i++)
	{
	   printf(" %s\t %d\t %d\t  \n" ,p[i],pt[i],pr[i]);
	}
	//printf("total waiting time=%d\navg waiting time=%f",totwt,avgwt);
	
}

