// money.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char num[10][3] = { "零","壹","贰","叁","肆","伍","陆","柒","捌","玖" };
	char wei[4][3] = { "千","百","十","" };
	char shu[3][3] = { "亿","万","" };
	char fu[3] = "负"; char dian[3] = "点";
	char m[25], mon[23];
	int i, j, t, n, flag, k, zero, nzero, t1, k1, first;
	while (cin >> m)
	{
		flag = zero = nzero = first = 0;
		n = strlen(m);
		if (n == 1 && m[0] == '0')
		{
			cout << num[0];
			continue;
		}
		for (i = 0; i<22; i++)
		{
			if (i == 0)
				mon[i] = '*';
			else if (i <= 10 && i % 5 == 0)
				mon[i] = ',';
			else if (i == 15)
				mon[i] = '.';
			else    mon[i] = '0';
		}
		mon[i] = '\0';
		if (m[0] == '-')
		{
			t1 = 1;
			mon[0] = '-';
		}
		else {
			t1 = 0;   mon[0] = '+';
		}
		for (i = 0; i<n; i++)
		{
			if (m[i] == '.')
			{
				flag = 1;    t = i;    break;
			}
		}
		if (flag)
		{
			for (i = t + 1, j = 16; i<n&&j<22; i++, j++)
				mon[j] = m[i];
		}
		else {
			t = n;
		}
		for (i = t - 1, k = 0, j = 14; i >= t1&&j >= 1; i--, j--)
		{
			mon[j] = m[i];
			k++;
			if (k == 4)
			{
				j--;
				k = 0;
			}
		}
		k = 0, k1 = 0;
		for (i = 0; i<15; i++)
		{
			if (mon[i] == '-')
				cout << fu;
			else if (mon[i] == '+')
				continue;
			else if (mon[i] == ',')
			{
				k = 0;
				if (nzero)
				{
					cout << shu[k1++];
					nzero = 0;
				}
				else {
					k1++;
					continue;
				}
			}
			else if (mon[i] == '0')
			{
				zero = 1;    k++;
			}
			else {
				if (!first)
				{
					if (!nzero&&mon[i] == '1'&&k == 2)
						cout << wei[k++];
					else
						cout << num[mon[i] - '0'] << wei[k++];
					first = 1;
				}
				else {
					if (zero) {
						if (!nzero&&mon[i] == '1'&&k == 2)
							cout << num[0] << wei[k++];
						else
							cout << num[0] << num[mon[i] - '0'] << wei[k++];
					}
					else {
						cout << num[mon[i] - '0'] << wei[k++];
					}
				}
				zero = 0;
				nzero = 1;
			}
		}  for (i = 21; i >= 16; i--)
		{
			if (mon[i] != '0')
			{
				t = i;    break;
			}
		}  if (i != 15)
		{
			cout << dian;
			for (j = 16; j <= t; j++)
				cout << num[mon[j] - '0'];
		}
		cout << endl;
	}
}
