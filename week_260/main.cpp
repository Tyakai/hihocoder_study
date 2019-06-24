#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    int row,column;
    long long maxSum;
    cin>>row>>column>>maxSum;
    int** rowArray = new int*[row];
    for(int i=0;i<row;++i)
    {
        rowArray[i] = new int[column];
    }
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<column;++i)
        {

            cin>>rowArray[i][j];
        }
    }
    int elementNum = 0;
    //确定左右边界，其中右边界不能小于左边界
    for(int left=0;left<column;++left)
    {
        for(int right = left;right<column;++right)
        {
            long long *rowSum = new  long long[row];
            memset(rowSum,0,row*sizeof(int));
            bool needContinue=false;
            //将二维转一维
            for(int i=0;i<row;++i)
            {
                for(int j=left;j<=right;++j)
                {
                    rowSum[i]+=rowArray[i][j];
                }
            }

            long long tempMaxSum=0;
            int maxNum = 0;
            for(int i=0;i<row;++i)
            {
                for(int j=i;j<row;++j)
                {
                    for(int a=i;a<=j;++a)
                    {
                        tempMaxSum+=rowSum[a];
                        if(tempMaxSum>maxSum)
                        {

                        }
                    }
                }
            }

        }


    }
}
