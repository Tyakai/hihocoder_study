#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;


//
int main()
{

    int arrayCount = 0;
    cin>>arrayCount;
    if(arrayCount<=0 || arrayCount>100)
    {
        return -1;
    }
    char (*arrayName)[100] = new char[arrayCount][100];
    memset(arrayName,0,100*arrayCount*sizeof(char));
    int offset = 'a' - 'A';
    for(int i=0;i<arrayCount;++i)
    {
        char temp[100] = {0};
        cin>>temp;
        int position=0;
        int tempLen = strlen(temp);
        for(int j=0;j<tempLen;++j)
        {
            if(position == 98)
            {
                break;
            }
            if(temp[j]>='A' && temp[j]<='Z')//大写，则改为_x的形式
            {
                arrayName[i][position] = '_';
                ++position;
                arrayName[i][position] = temp[j] +offset;
                ++position;
            }
            else if(temp[j] == '_')//遇到_x，则改为X
            {
                if(j<tempLen)//不是最后一个
                {
                    if(temp[j+1])
                    {
                        arrayName[i][position] = temp[j+1]-offset;
                        ++j;
                        ++position;
                    }
                    else//
                    {

                    }
                }
                else//最后一个
                {

                }
            }
            else
            {
                arrayName[i][position] = temp[j];
                ++position;
            }
        }
    }

    for(int i=0;i<arrayCount;++i)
    {
        cout<<arrayName[i]<<endl;
    }
    return 0;
}
