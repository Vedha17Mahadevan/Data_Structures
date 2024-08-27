// Vedha Mahadevan
// B23CS1262
// Linear and Binary Search

# include <stdlib.h>
# include <stdio.h>
void linear_search(int a[100],int len);
void binary_search(int a[100] ,int len);
int main()
{
	int len,n,i,ch1;
	int ans;
	int a[100];
	printf("Enter the limit for the array : \n");
	scanf("%d",&len);
	
	printf("Enter Array Elements");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Array : ");
	for(i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	
	do
	{
		printf("\nMenu : \n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Exit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&ch1);
		
		if(ch1==1)
		{
			linear_search(a,len);
		}
		else if(ch1==2)
		{
			binary_search(a,len);
		}
		else if(ch1==3)
		{
			printf("Exiting the menu");
			break;
		}
		else 
		{
			printf("Invalid Choice!!");
		}
		printf("\nDo you wish to continue?(0=yes/1=no)");
		scanf("%d",&ans);
	}
	while(ans==0);
}
//LINEAR SEARCH
void linear_search(int a[100],int len)
{
	int i,s;
	int flag=0;
	printf("\nEnter search element : ");
	scanf("%d",&s);
	for(i=0;i<len;i++)
	{
		if(a[i]==s)
		{
			flag=1;
			break;
		}
	}
	if (flag==1)
	{
		printf("The search element %d FOUND at index %d",s,i+1);
	}
	else 
	{
		printf("Search element NOT found in the array");
	}
}
//BINARY SEARCH
void binary_search(int a[100],int len)
{
	int s;								
	printf("\nEnter search element : ");
	scanf("%d",&s);
	
	int i,j,t;
	for(i=0;i<len;i++)						//bubble sort
	{
		for(j=0;j<len-i-1;j++)
			{
				if (a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
	}
	printf("Sorted Array : ");
	for (i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}

	int low=0,high=len-1,mid;					//binary search
	int flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if (a[mid]==s)
		{
			printf("\nSearch element found at index %d",mid+1);
			flag=1;
			break;
		}
		else if(a[mid] > s)
		{
			high=mid-1;
		}
		else if (a[mid]<s)
		{
			low=mid+1;
		}
	}
	if (flag==0)
	{
	printf("\nSearch element NOT found in the array");
	}
}

/*OUTPUT
Enter the limit for the array : 
5
Enter Array Elements10
50
20
40
30
Array : 10	50	20	40	30	
Menu : 
1. Linear Search
2. Binary Search
3. Exit
Enter your choice : 1

Enter search element : 0
Search element NOT found in the array
Do you wish to continue?(0=yes/1=no)0

Menu : 
1. Linear Search
2. Binary Search
3. Exit
Enter your choice : 1

Enter search element : 40
The search element 40 FOUND at index 4
Do you wish to continue?(0=yes/1=no)0

Menu : 
1. Linear Search
2. Binary Search
3. Exit
Enter your choice : 2

Enter search element : 0
Sorted Array : 10	20	30	40	50	
Search element NOT found in the array
Do you wish to continue?(0=yes/1=no)0

Menu : 
1. Linear Search
2. Binary Search
3. Exit
Enter your choice : 2 

Enter search element : 20
Sorted Array : 10	20	30	40	50	
Search element found at index 2
Do you wish to continue?(0=yes/1=no)0

Menu : 
1. Linear Search
2. Binary Search
3. Exit
Enter your choice : 6
Invalid Choice!!
Do you wish to continue?(0=yes/1=no)1
*/
