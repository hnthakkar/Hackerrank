#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, n;
		cin >> n;
		int odd = 0, even = 0, a[n];
		for (i = 0; i<n; i++)
		{
			cin >> a[i];
			if (a[i] % 2)
				odd++;
			else
				even++;
		}
		cout << odd*even << endl;
	}
	return 0;
}
