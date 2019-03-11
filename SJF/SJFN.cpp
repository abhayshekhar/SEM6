#include <iostream>
using namespace std;
void ganttchart(int t[], int s[], int p)
{
	int i, j;
	cout<<endl;	
	for (i=0; i<=p; i++)
		for (j=0; j<=2*(t[i+1]-t[i]); j++)
			if (j==0)
				cout<<" ";
			else
				cout<<"-";
	cout<<endl;
	for (i=0; i<=p; i++)
		for (j=0; j<=2*(t[i+1]-t[i]); j++)
			if (j==0)
				cout<<"|";
			else if (j==(t[i+1]-t[i])&&i!=0)
			{
				cout<<"P"<< s[i-1]+1;
				j++;
			}
			else if (j==(t[i+1]-t[i])&&i==0)
			{
				cout<<"ID";
				j++;
			}
			else
				cout<<" ";
	cout<<"|\n";			
	for (i=0; i<=p; i++)
		for (j=0; j<=2*(t[i+1]-t[i]); j++)
			if (j==0)
				cout<<" ";
			else
				cout<<"-";
	cout<<"\n";
	
	for (i=0; i<=p; i++)
		for (j=0; j<=2*(t[i+1]-t[i]); j++)
			if (j==0)
			{
				cout<<t[i];
				//j++;
			}
			else
				cout<<" ";
	cout<<t[p+1]<<endl;
}

int main()
{
	int b[10],w[10],a[10],c[10],t[10], gantt[50],tatime[10],wtime[10];
	int i,r=0, smallest, count = 0, time,n,s[50],j=0;
	double wt = 0, tat = 0, ct;
	float awt, atat;
	cout<<"enter the number of process"<<endl;
	cin>>n;

	cout<<"\nEnter Details of process"<<endl;
        for(i = 0; i < n; i++)
        {
            cout<<"\nEnter Arrival Time:\t";
            cin>>a[i];
            cout<<"Enter Burst Time:\t";
            cin>> b[i]; 
            t[i] = b[i];
		w[i]=b[i];
        }
	b[9]=9999;
	for(time=0;count!=n;time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(a[i]<=time && b[i]<=b[smallest] && b[i]>0)
			{
				if(b[i]==b[smallest])
				{
					if(a[i]<a[smallest])
						smallest=i;
				}
				else				
					smallest=i;
			}
		}
		//cout<<smallest<<"-";
		
		if(smallest != 9)
            	{
		  s[j]=smallest;
		    j++;
		  gantt[j]=time;
		
                  count++;
                  ct = time + b[smallest];
		  c[smallest]=ct;
		
		  time=ct-1;
		  
		  
		  
                  wt += ct - a[smallest] - t[smallest];
                  tat += ct - a[smallest];
		b[smallest]=0;
            	}
		else
			continue;
	}	
	for(i=0;i<n;i++)
	{
		tatime[i]=c[i]-a[i];
		wtime[i]=tatime[i]-t[i];
	}

	gantt[0]=0;
	gantt[j+1]=ct;
	
	ganttchart(gantt, s, n);
	awt = wt / n; 
      	atat = tat / n;
      	cout<<"\n\nAverage Waiting Time:\t"<< awt<<endl;
      	cout<<"Average Turnaround Time:\t"<< atat<<endl;
	cout<<"process\tarrival\tburst \tcompletion\ttat\t waiting"<<endl;
	cout<<"       \ttime   \ttime  \ttime      \ttime\ttime"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<a[i]<<"\t"<<t[i]<<"\t"<<c[i]<<"\t\t"<<tatime[i]<<"\t"<<wtime[i]<<endl;
	}
	
      	return 0;
}
