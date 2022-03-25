#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length() - i - 1; j++) {
			if (str[j] > str[j + 1]) {
				char c = str[j];
				str[j] = str[j + 1];
				str[j + 1] = c;	
			}
		}
	}
	for (int i = 0; i < str.length(); i++)
		cout << str[i] << " ";
	return 0;


}
