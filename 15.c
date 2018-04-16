#include<stdio.h> 
 
int main() 
{ 
 
  int i,c,j,n,time,remain,m=0,time_quantum,x=0,s=1,temp; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10],pt[10],ptr[10]; 
  printf("Enter Total number of Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(c=0;c<n;c++) 
  { 
    printf("Enter Arrival Time,  Burst Time and Priority for Process Process  %d :",c+1); 
    scanf("%d",&at[c]); 
    scanf("%d",&bt[c]);
	scanf("%d",&pt[c]);
    rt[c]=bt[c]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,c=0;remain!=0;) 
  { 
    if(rt[c]<=time_quantum && rt[c]>0) 
    { 
      time+=rt[c]; 
      rt[c]=0; 
      m=1; 
    } 
    else if(rt[c]>0) 
    { 
      rt[c]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[c]==0 && m==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,time-at[c],time-at[c]-bt[c]); 
      wait_time+=time-at[c]-bt[c]; 
      turnaround_time+=time-at[c]; 
      m=0; 
    } 
    if(c==n-1) 
      c=0; 
    else if(at[c+1]<=time) 
      c++; 
    else 
      c=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
  for(i=0;i<n;i++)
  {
  	ptr[i]=pt[i];
  }
  for (i=0;i <n;i++)
    {
        for (j =0; j<(n-i-1);j++)
        {
            if (ptr[j] >ptr[j + 1])
            {
                temp =ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
  for(i=0;i<n;i++)
  {
  	for(j=0;j<n;j++)
  	{
  		if((ptr[i]==pt[j])&&(ptr[i]!=0))
  		{
		x=j+1;
  		printf("\nprocess %d come %d",x,s);
  		s=s+1;
	  }
	  if(ptr[i]==0)
	  {
	  	printf("\nprocess %d come %d",s);
	  }
}
  }
  return 0; 
}
