/*
* 3, 6, 9 game
* If a number includes 3 or 6 or 9, print ! as many as number of 3 or 6 or 9
* ex) 3 -> !, 16 -> !, 30 -> !, 39 -> !!
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main()
{
	int n;

	cout << "Enter a number." << endl;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		int tmp = i;

		while (tmp / 10) // If qoutient is 0, stop
		{
			int remainer = tmp % 10;

			if (remainer % 3 == 0 && remainer != 0) // remainer != 0 -> To exculde 10, 20, 40, ...
				count++;

			tmp /= 10;
		}
		
		if (tmp % 3 == 0)
			count++;

		if (count > 0)
		{
			for (int j = 0; j < count; j++)
			{
				cout << "!";
			}
			cout << " ";
		}
		else
			cout << i << " ";

	}	

	return 0;
}