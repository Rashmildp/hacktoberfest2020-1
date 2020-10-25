// BUCKET SORTING
#include<stdio.h>

#include<stdlib.h>
#include<time.h>
void getRand();
void display(float b[]);
void selsort(float b[]);

float a[20];   

void main()
{
	 getRand();
	puts("unsorted number list : \n ");
	display(a);
	
	
	
	 selsort(a);
	 display(a);
	 
	 
	
	 
	
	

}
void getRand()
{
	int i;
	srand(time (NULL));
	for(i=0;i<20;i++)
	a[i]=  (float)rand()/RAND_MAX;
}
void display(float b[])
{
	int i;
	for(i=0;i<20;i++)
		printf("%f ",b[i]);
printf("\n");
	
}

void selsort(float b[])
{
	float temp,Bucket_Array[10][10];
	int i,j,k,bucket_element[10]={},bucket_no;
	for(i=0;i<20;i++)
	{
		bucket_no=b[i]/0.1;
		Bucket_Array[bucket_no][bucket_element[bucket_no]]=b[i];
		bucket_element[bucket_no]++;
	}
	printf("After the putting values into the bucket :");
	printf("\n");
	for(i=0;i<10;i++)
	{
		if (bucket_element[i]>0)
		{
			for(j=0;j<bucket_element[i];j++)
			{
				printf("%f ",Bucket_Array[i][j]);
			}
		}
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		if(bucket_element[i]>0)
		{
			for(j=0;j<bucket_element[i];j++)
			{
				for(k=j+1;k<bucket_element[i];k++)
					if(Bucket_Array[i][j]>Bucket_Array[i][k])
					{
						temp=Bucket_Array[i][j];
						Bucket_Array[i][j]=Bucket_Array[i][k];
						Bucket_Array[i][k]=temp;
						
					}
			}
		}
	}
	printf("Final sorting value:\n");
	int count=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<bucket_element[i];j++)
		{
			b[count]=Bucket_Array[i][j];
		 count++;
		}
		
	}
		

	
} 
