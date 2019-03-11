

    //To Implement Predictive Parsing
 #include<stdio.h>  
 #include<string.h>
 #include<stdlib.h>   
    char token,input[100];
    int i;
	
	char nextToken(){
			return input[i+1];
			}
			
	void funS(){
			if(token=='a')
			{token=nextToken();
			funS();
				if(token=='c'){
				token=nextToken();
				}
			else
				 {printf("error");
				exit(0);}
			}
			else if(token=='b')
				funA();
			else
				printf("error");
		 }
	void funA(){
			}
		 
	int main(){
			 i=0;
			printf("Enter the string with $ in last");
			scanf("%s",input);
			token=nextToken();
			funS();
			if (token=='$'){
					printf("parsing successful");
					}
			else 
				{printf("parsing failed");}
				
			return 0;}
			
			
