#include <stdio.h>
#include <stddef.h>
#define TEST_HEADER printf("\n=============%s=============\n",__FUNCTION__)
void Swap(int *pa,int *pb)
{
    int tmp=*pa;
    *pa=*pb;
    *pb=tmp;
}
//冒泡排序
void BubbleSort(int arr[],size_t size)
{
    if(arr==NULL||size<=0)
    {
        return;
    }
    size_t bound=0;
    for(;bound<size;bound++)
    {
        size_t cur=size-1;
        for(;cur>0;cur--)
        {
            if(arr[cur]<arr[cur-1])
            {
                Swap(&arr[cur],&arr[cur-1]);
            }
        }
    }
}
//选择排序
void SelectSort(int arr[],size_t size)
{
    if(arr==NULL||size<=0)
    {
        return;
    }
    size_t bound=0;
    for(;bound<size;bound++)
    {
        size_t cur=bound+1;
        for(;cur<size;cur++)
        {
            if(arr[bound]>arr[cur])
            {
                Swap(&arr[bound],&arr[cur]);
            }
        }
    }
}
//插入排序
void InsertSort(int arr[],size_t size)
{
    if(arr==NULL||size<=0)
    {
        return;
    }
    size_t bound=1;
    for(;bound<size;bound++)
    {
        size_t cur=bound;
        int bound_value=arr[bound];
        for(;cur>0;cur--)
        {
            if(bound_value<arr[cur-1])
            {
                arr[cur]=arr[cur-1];
            }
            else
            {
                break;
            }
        }
        arr[cur]=bound_value;
    }
}
/////////////////////////////////
//测试代码
////////////////////////////////
void TestPrint(int arr[],int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestBubbleSort()
{
    TEST_HEADER;
    int arr[]={1,2,3,4,9,8,7,5,6};
    size_t len=sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,len);
    TestPrint(arr,len);
}
void TestSelectSort()
{
    TEST_HEADER;
    int arr[]={1,2,3,4,9,8,7,5,6};
    size_t len=sizeof(arr)/sizeof(arr[0]);
    SelectSort(arr,len);
    TestPrint(arr,len);
}
void TestInsertSort()
{
    TEST_HEADER;
    int arr[]={1,2,3,4,9,8,7,5,6};
    size_t len=sizeof(arr)/sizeof(arr[0]);
    InsertSort(arr,len);
    TestPrint(arr,len);
}
int main()
{
    TestBubbleSort();
    TestSelectSort();
    TestInsertSort();
    return 0;
}
