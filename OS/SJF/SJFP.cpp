#include <iostream>
using namespace std;
void gantt(int s[],int n)
{
	int i,j;
	cout<<"GANTT CHART"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"-- ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		
		//if(s[i]==s[i+1] && s[i]!=s[i-1])
		//	cout<<"|P"<<s[i];
		if(s[i]==10)
			cout<<"|ID";
		if(s[i]!=s[i-1] && s[i]!=10)
			cout<<"|P"<<s[i];
		if(s[i]==s[i-1])
			cout<<"   ";
		if(i==n-1)
			cout<<"|";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"-- ";
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		if(s[i]==10)
			cout<<i<<"  ";
		if(s[i]!=s[i-1] && s[i]!=10)
			cout<<i<<"  ";
		if(s[i]==s[i-1])
			cout<<"   ";
		if(i==n-1)
			cout<<n;
	}
	
		
}

int main()
{
	int b[10],w[10],a[10],c[10],t[10],s[50],g[50];
	int i, smallest, count = 0, time,n,tatime[10],wtime[10];
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
        }
	b[9] = 9999;  
	for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(a[i] <= time && b[i] <= b[smallest] && b[i] > 0)
                  {
			if(b[i]==b[smallest])
			{
				if(a[i]<a[smallest])
					smallest = i;
			}
			else
				smallest=i;
				
			
                        
                  }
            }
	    s[time]=smallest+1;
	    g[time]=time;
            b[smallest]--;
            if(b[smallest] == 0 && smallest!=9)
            {
                  count++;
                  ct = time + 1;
		  c[smallest]=ct;
                  wt += ct - a[smallest] - t[smallest];
                  tat += ct - a[smallest];
            }
      }
	int l=time;
	
	cout<<endl;
	
	cout<<endl;
	gantt(s,l);
	cout<<endl;
	for(i=0;i<n;i++)
	{
		tatime[i]=c[i]-a[i];
		wtime[i]=tatime[i]-t[i];
	}
	awt = wt / n; 
      	atat = tat / n;
      	cout<<"\n\nAverage Waiting Time:\t"<< awt<<endl;
      	cout<<"Average Turnaround Time:\t"<< atat<<endl<<endl;;
	cout<<"process\tarrival\tburst \tcompletion\ttat\t waiting"<<endl;
	cout<<"       \ttime   \ttime  \ttime      \ttime\ttime"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<a[i]<<"\t"<<t[i]<<"\t"<<c[i]<<"\t\t"<<tatime[i]<<"\t"<<wtime[i]<<endl;
	}
      	return 0;
}
