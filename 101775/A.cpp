#include <cstdio>

const int M = 1000000007;
int inv[200000];
int T, n, k;

int pow_mod(int x, int p, int M)
{
	int ans = 1;
	int tmp = x;
	while (p)
	{
		if (p & 1)
		{
			ans = (long long)ans * tmp % M;
		}
		tmp = (long long)tmp * tmp % M;
		p >>= 1;
	}
	return ans;
}

int main()
{
	inv[0] = 1;
	for (int i = 1; i <= 100000; i++)
	{
		inv[i] = (long long)inv[i - 1] * pow_mod(i, M - 2, M) % M;
	}
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &k);
		long long ans = pow_mod(2, n, M);
		long long tmp = 1;
		long long sum = 0;
		for (int i = 0; i <= k - 1; i++)
		{
			sum = (sum + (long long)tmp * inv[i] % M) % M;
			tmp = (long long)tmp * (n - i) % M;
		}
		printf("Case #%d: %lld\n", cas, ((ans - sum) % M + M) % M);
	}
	return 0;
}
