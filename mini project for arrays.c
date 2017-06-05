#include <stdio.h>
#include <math.h>
int main()
{
  int A[100],i,n,temp[100];
  char ch;
  printf("Enter your choice:");
  scanf(" %c",&ch);
  append(A,10);
  cycle(A,10,-3);
  disp(A,10);
  return 0;
}

void menu();
void menu()
{
  printf("MENU\na.Append elements\nb.Modify Element\nc.Search Element\nd.Delete Occurrences\ne.Sort Array\nf.Cyclic rotation\ng.Display Elements\nh.Statistics\ni.EXIT\n");
}

void stat_MENU();
void stat_MENU()
{
  printf("STATISTICS MENU\na.Array Sum\nb.Array Product\nc.Harmonic Array Sum\nd.Largest Element\ne.Smallest Element\nf.Count Occurrences\ng.Mean\nh.Median\ni.Mode\nj.Range\nk.Standard Deviation\nl.Variance\n");
}

void sort_MENU();
void sort_MENU()
{
  printf("SORTING MENU\na.Ascending\nb.Descending\n");
}

void append(int A[],int);
void append(int A[100],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter an element:");
    scanf("%d",&A[i]);
  }
}

int max(int A[],int);
int max(int A[100],int n)
{
  int i,max=A[0];
  for(i=0;i<n;i++)
  {
    if(A[i]>max)
    {
      max=A[i];
    }
  }
  return max;
}

int min(int A[],int);
int min(int A[100],int n)
{
  int i,min=A[0];
  for(i=0;i<n;i++)
  {
    if(A[i]<min)
    {
      min=A[i];
    }
  }
  return min;
}

int sum(int A[],int);
int sum(int A[100],int n)
{
  float S=0;int i;
  for(i=0;i<n;i++)
  {
    S+=A[i];
  }
  return S;
}

int prod(int A[],int);
int prod(int A[100],int n)
{
  int P=1,i;
  for(i=0;i<n;i++)
  {
    P*=A[i];
  }
  return P;
}

int count(int A[],int,int);
int count(int A[100],int n,int x)
{
  int i,c=0;
  for(i=0;i<n;i++)
  {
    if(A[i]==x)
    {
      c++;
    }
  }
  return c;
}

void asc_sort(int A[],int);
void asc_sort(int A[100],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(A[i]>A[j])
      {
        temp=A[i];A[i]=A[j];A[j]=temp;
      }
    }
  }
}

void dsc_sort(int A[],int);
void dsc_sort(int A[100],int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(A[i]<A[j])
      {
        temp=A[i];A[i]=A[j];A[j]=temp;
      }
    }
  }
}

int med(int A[],int);
int med(int A[100],int n)
{
  int i,temp[100];
  for(i=0;i<n;i++)
  {
    temp[i]=A[i];
  }
  asc_sort(temp,n);
  if(n%2!=0)
  {
    return temp[n/2];
  }
  else
  {
    return ((temp[n/2]+temp[n/2-1])/2);
  }
}

int mode(int A[],int);
int mode(int A[100],int n)
{
  int counter[100],i;
  for(i=0;i<n;i++)
  {
    counter[i]=count(A,n,A[i]);
  }
  for(i=0;i<n;i++)
  {
    if(counter[i]==max(counter,n))
    {
      return A[i];
      break;
    }
  }
}

void modify(int A[]);
void modify(int A[100])
{
  int i;
  printf("Enter index to modify:");
  scanf("%d",&i);
  printf("Enter replacement:");
  scanf("%d",&A[i]);
}

void disp(int A[],int);
void disp(int A[100],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d ",A[i]);
  }
}

int search(int A[],int,int);
int search(int A[100],int n,int x)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(A[i]==x)
    {
      return 1;
      break;
    }
  }
}

void del(int A[],int,int);
void del(int A[100],int n,int x)
{
  int i,j,c=count(A,n,x);
  while(c--)
  {
    for(i=0;i<n;i++)
    {
      if(A[i]==x)
      {
        for(j=i;j<n-1;j++)
        {
          A[j]=A[j+1];
        }
      }
    }
    n--;
  }
}

void cycle(int A[],int,int);
void cycle(int A[100],int n,int k)
{
  int temp[100],i=0;
  if(k>=0)
  {
    for(i=0;i<k;i++)
    {
      temp[i]=A[n-k+i];
    }
    for(i=0;i<n-k;i++)
    {
      A[k+i]=A[i];
    }
    for(i=0;i<k;i++)
    {
      A[i]=temp[i];
    }
  }
  else
  {
    for(i=0;i<-k;i++)
    {
      temp[i]=A[i];
    }
    for(i=0;i<(n+k);i++)
    {
      A[i]=A[i-k];
    }
    for(i=0;i<k;i++)
    {
      A[n-k+i]=temp[i];
    }
  }

}


