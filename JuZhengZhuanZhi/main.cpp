/**样例输入
1 2 3
4 5 6
7 8 9
样例输出
1 4 7
2 5 8
3 6 9
 */
#include<iostream>
#include <string>
using namespace std;
int main() {

   string str;
   getline(cin,str);
    int **n,length=int((str.length()+1)*0.5);
    n=(int **)malloc(length*sizeof(int*));
    for (int i = 0; i < length; i++)
        n[i]=(int*)malloc(length*sizeof(int));

	for (int a = 0; a < length; a++)
	{   int m=0;
	    for(int k=0;k<length;k++) {
            n[a][k] = int(str[m]);
            m+=2;
	    }
	    if(a!=length-1)
          getline(cin,str);
	}

    for(int i=0;i<length;i++)//主对角线对称
        for(int j=i;j<length;j++)
        {
            int temp=n[i][j];
            n[i][j]=n[j][i];
            n[j][i]=temp;
        }
	for (int a = 0; a < length; a++) {
		for (int b = 0; b < length; b++){
			cout << n[a][b]-48 << " ";
		}
		cout << endl;
	}
	return 0;
}