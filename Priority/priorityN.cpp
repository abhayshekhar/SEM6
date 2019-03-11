#include <iostream>
using namespace std;
void gantt(int s[],int n,int l)
{
	int i,j;
	cout<<"\nGANTT CHART"<<endl;
	for(i=0;i<=n;i++)
	{
		cout<<"-- ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(s[i]!=0)
		{
		//if(s[i]==s[i+1] && s[i]!=s[i-1])
		//	cout<<"|P"<<s[i];
			if(s[i]==10)
				cout<<"|ID";
			if(s[i]!=s[i-1] && s[i]!=10)
				cout<<"|P"<<s[i];
			if(s[i]==s[i-1])
				cout<<"   ";
			
		}
		else
			cout<<"   ";
		if(i==n-1)
				cout<<"|";
	}
	cout<<endl;
	for(i=0;i<=n;i++)
	{
		cout<<"-- ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			cout<<i<<"  ";
			continue;
		}
		if(s[i]==10)
			cout<<i<<"  ";
		if(s[i]>0 && s[i]<=l)
			cout<<i<<"  ";
		if(s[i]==0)
			cout<<"   ";
		if(i==n-1)
			cout<<n;
	}
	
		
}

int main()
{
	int b[10],w[10],a[10],c[10],t[10],p[10],wtime[10],tatime[10],s[50];
	int i, largest, count = 0, time,n;
	double wt = 0, tat = 0, ct;
	float awt, atat;
	cout<<"enter the number of process"<<endl;
	cin>>n;
	for(i=0;i<50;i++)
		s[i]=0;
	cout<<"\nEnter Details of process"<<endl;
        for(i = 0; i < n; i++)
        {
            cout<<"\nEnter Arrival Time:\t";
            cin>>a[i];
            cout<<"Enter Burst Time:\t";
            cin>> b[i];
	    cout<<"enter the priority: \t";
	    cin>>p[i]; 
            t[i] = b[i];
		w[i]=b[i];
        }
	p[9]=0;
	//s[0]=0;
	for(time=0;count!=n;time++)
	{
		largest=9;
		for(i=0;i<n;i++)
		{
			if(a[i]<=time && p[i]>=p[largest] && b[i]>0)
			{
				if(p[i]==p[largest])
				{
					if(a[i]<a[largest])
						largest=i;
				}
				else
					largest=i;
			}
		}
		//s[time]=largest+1;
		if(largest != 9)
            	{
                  count++;
                  ct = time + b[largest];
		  c[largest]=ct;
		  s[time]=largest+1;
		  time=ct-1;
		  
                  wt += ct - a[largest] - t[largest];
		  //wtime[largest]=wt;
                  tat += ct - a[largest];
		 // tatime[largest]=tat;
		//s[time+1]=largest+1;
		b[largest]=0;
            	}
		else
			continue;
	
	}
	for(i=0;i<n;i++)
	{
		tatime[i]=c[i]-a[i];
		wtime[i]=tatime[i]-t[i];
	}
	/*for(i=0;i<time;i++)
		cout<<s[i]<<"-";*/
	
	gantt(s,time,n);
	awt = wt / n; 
      	atat = tat / n;
      	cout<<"\n\nAverage Waiting Time:\t"<< awt<<endl;
      	cout<<"Average Turnaround Time:\t"<< atat<<endl;
	
	
	
	cout<<"process\tarrival\tburst priority\tcompletion \ttat \twaiting"<<endl;
	cout<<"       \ttime   \ttime  \ttime  \ttime       \ttime\ttime"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<a[i]<<"\t"<<t[i]<<"\t"<<p[i]<<"\t"<<c[i]<<"\t\t"<<tatime[i]<<"\t"<<wtime[i]<<endl;
	}

	//ganttchart( t,  n)
	
      	return 0;
}
