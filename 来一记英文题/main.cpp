/**
样例输入
1 2 5 6
2 3 4 2
样例输出
  _  _  _
| _||_ |_
||_  _||_|
 _  _     _
 _| _||_| _|
|_  _|  ||_
 提示
The digits showed by the digital clock are as follows:
  _  _     _  _  _  _  _  _
| _| _||_||_ |_   ||_||_|| |
||_  _|  | _||_|  ||_| _||_|
 */

#include <iostream>
#include <string>
using namespace std;
void playout(string str)
{

    for(int i=0;i<7;i=i+2)
    switch (str[i]) {
        case '1':cout<<" "<<" "<<" ";break;
        case '4':cout<<" "<<" "<<" ";break;
        case '2':cout<<" "<<"_"<<" ";break;
        case '3':cout<<" "<<"_"<<" ";break;
        case '5':cout<<" "<<"_"<<" ";break;
        case '6':cout<<" "<<"_"<<" ";break;
        case '7':cout<<" "<<"_"<<" ";break;
        case '8':cout<<" "<<"_"<<" ";break;
        case '9':cout<<" "<<"_"<<" ";break;
        case '0':cout<<" "<<"_"<<" ";break;
    }

    cout<<endl;

    for(int j=0;j<7;j=j+2)
    switch (str[j]) {
        case '1':cout<<" "<<" "<<"|";break;
        case '2':cout<<" "<<"_"<<"|";break;
        case '3':cout<<" "<<"_"<<"|";break;
        case '4':cout<<"|"<<"_"<<"|";break;
        case '5':cout<<"|"<<"_"<<" ";break;
        case '6':cout<<"|"<<"_"<<" ";break;
        case '7':cout<<" "<<" "<<"|";break;
        case '8':cout<<"|"<<"_"<<"|";break;
        case '9':cout<<"|"<<"_"<<"|";break;
        case '0':cout<<"|"<<" "<<"|";break;
    }

    cout<<endl;

    for(int k=0;k<7;k=k+2)
        switch (str[k]) {
            case '1':cout<<" "<<" "<<"|";break;
            case '2':cout<<"|"<<"_"<<" ";break;
            case '3':cout<<" "<<"_"<<"|";break;
            case '4':cout<<" "<<" "<<"|";break;
            case '5':cout<<" "<<"_"<<"|";break;
            case '6':cout<<"|"<<"_"<<"|";break;
            case '7':cout<<" "<<" "<<"|";break;
            case '8':cout<<"|"<<"_"<<"|";break;
            case '9':cout<<" "<<"_"<<"|";break;
            case '0':cout<<"|"<<"_"<<"|";break;
        }
    cout<<endl;
}
int main()
{
    string str;
    while ( getline(cin,str))
        playout(str);
    return 0;
}