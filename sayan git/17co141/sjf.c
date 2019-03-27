#include "stdio.h"
#include "stdlib.h"
struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
};
int main()
{
	int n,i,j;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct process proc[n],temp;
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process%d: ",i+1);
		scanf("%d",&proc[i].arrival_time);
		printf("Enter burst time for process%d: ",i+1);
		scanf("%d",&proc[i].burst_time);
		proc[i].process_id = i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].arrival_time<proc[j].arrival_time)
			{
				temp=proc[j];
				proc[j]=proc[i];
				proc[i]=temp;
			}
		}
	}

for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].arrival_time==proc[j].arrival_time)
			{  if(proc[i].burst_time<proc[j].burst_time)
				{
				temp=proc[j];
				proc[j]=proc[i];
				proc[i]=temp;
			}
				
			}
		}
	}


	int service_time[n];
	service_time[0]=proc[0].arrival_time;
	proc[0].waiting_time=0;	

	for(i=1;i<n;i++)
	{
		service_time[i]=service_time[i-1]+proc[i-1].burst_time;
		proc[i].waiting_time = service_time[i]-proc[i].arrival_time;

		if(proc[i].waiting_time<0)
			proc[i].waiting_time=0;
	}

	for(i=0;i<n;i++)
	{
		proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
	}
	printf("\n\n");
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
	int total_waiting_time=0,total_turn_around_time=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(proc[i].process_id<proc[j].process_id)
			{
				temp=proc[j];
				proc[j]=proc[i];
				proc[i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		total_waiting_time+=proc[i].waiting_time;
		total_turn_around_time+=proc[i].turn_around_time;

		int completion_time=proc[i].turn_around_time + proc[i].arrival_time;

		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].process_id,proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time,proc[i].turn_around_time,completion_time);
	}
	printf("Average waiting time: %f\n", (float)total_waiting_time/n);
	printf("Average turn around time: %f\n",(float)total_turn_around_time/n);
}