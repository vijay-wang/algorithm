#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50000

int comparation_num=0,move_num=0;

void swap(int& a,int& b){//swap two numbers
    int tmp=a;
    a=b;
    b=tmp;
}

void split_insert_sort(int A[],int n){
    int low,high,mid,i,j;
    for(i=2;i<=n;i++)
        if(A[i]<A[i-1]){
            A[0]=A[i];
            low=1;
            high=i-1;
            while(high>=low){
                mid=(high+low)/2;
                if(A[0]<A[mid]){
                    high=mid-1;
                    comparation_num++;
                }
                else
                    low=mid+1;
            }
            for(j=i;j>low;j--){
                A[j]=A[j-1];
                move_num++;
            }
            A[low]=A[0];
            move_num++;
        }

}

void insert_sort(int A[],int n){
    int i,j;
    for(i = 2;i<=n;i++)
        if(A[i] < A[i-1]){
            A[0] = A[i];
            for(j = i - 1;A[0] < A[j];j--){
                A[j+1] = A[j];
                move_num++;
                comparation_num++;
            }
            A[j+1] = A[0];
            move_num++;
        }
}

void result_print(int arry[],int size){
   // for(int i=1;i<=size;i++)
     //   printf("%d,",arry[i]);
    printf("\nnumber of comparation:%d\n",comparation_num);
    printf("number of movment:%d\n",move_num);
}

void shell_sort(int arry[],int size){
    int d,i,j;      //distance
    for(d=size/2;d>=1;d=d/2){
        for(i=d+1;i<=size;i++){
            if(arry[i]<arry[i-d]){
                arry[0]=arry[i];
                move_num++;
                for(j=i-d;arry[0]<arry[j]&&j>0;j-=d){
                    arry[j+d]=arry[j];
                    comparation_num++;
                    move_num++;
                }
                arry[j+d]=arry[0];
                move_num++;

            }
        }
    }
}

void BubbleSort(int A[],int size){
    bool flag=false;
    for(int i=1;i<=size;i++){
        for(int j=size;j>i;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                move_num+=3;
                comparation_num++;
                if(!flag) flag=true;
            }
        }
        if(!flag)   return;
    }
}

void QuickSort(int A[],int low,int high){
    if(low<high){
        int low_2=low,high_2=high;
        A[0]=A[low];
        while(low<high){
            while(A[high]>=A[0]&&high>low)   {high--;comparation_num++;}
                A[low]=A[high];move_num++;
            while(A[low]<A[0]&&low<high) {low++;comparation_num++;}
                A[high]=A[low];move_num++;
        }
        A[low]=A[0];
        QuickSort(A,low_2,high-1);
        QuickSort(A,low+1,high_2);
    }
}

void SelectSort(int A[],int size){
    int min;
    for(int i=1;i<size;i++){
        min=i;
        for(int j=i+1;j<=size;j++){
            comparation_num++;
            if(A[i]>A[j])   min=j;
        }
        if(i!=min)  {swap(A[i],A[min]);move_num+=3;}

    }

}

void HeapAdjust(int A[],int root,int len){//将以root为根节点的子树调整为大根堆
	A[0]=A[root];
	if(A[0]<A[root*2]||A[0]<A[root*2+1])	swap(A[0],A[A[root*2]>A[root*2+1]?root*2:root*2+1]);
}

void BuildMaxHeap(int A[],int size){//建立大堆
	for(int i=size/2;i>0;i--)//从后往前调整非终端节点
		HeadAdjust(A,i,size);
}

void HeapSort(int A[],int size){
	for(int i=size;i>1;i--)
}

int main(){
    srand((unsigned int)time(NULL));
    int arry[SIZE+1];
    for(int i=1;i<=SIZE;i++){
        arry[i]=rand()%65533+1;
    }
    //insert_sort(arry,SIZE);
    //split_insert_sort(arry,SIZE);
    //shell_sort(arry,SIZE);
    //BubbleSort(arry,SIZE);
    //QuickSort(arry,1,SIZE);
    SelectSort(arry,SIZE);
    result_print(arry,SIZE);

    return 0;
}
