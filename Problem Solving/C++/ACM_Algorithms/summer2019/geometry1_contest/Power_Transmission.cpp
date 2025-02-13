#include <cstdio>
#include <map>
#include <set>
#include <utility>
const int N = 1001;
int x[N], y[N];
std::map<std::pair<int,int>,std::set<long long>> slope_map;

int gcd(int a, int b) 
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &x[i], &y[i]);
	long long total = 0, res = 0;
	for (int i = 1; i <= n - 1; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
			int a = y1 - y2, b = x1 - x2;
			int d = gcd(a, b); a /= d, b /= d;
			if (a < 0 || (a == 0 && b < 0))
			{
			    a = -a;
			    b = -b;
			}
			std::pair<int,int> slope(a, b);
			long long c = 1LL * a * x1 - 1LL * b * y1;
			if (!slope_map[slope].count(c))
			{
				++total;
				slope_map[slope].insert(c);
				res += total - slope_map[slope].size();
			}
		}
	printf("%lld\n", res);
}