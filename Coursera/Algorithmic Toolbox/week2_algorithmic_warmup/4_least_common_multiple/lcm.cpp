#include <iostream>

long long gcd_fast(long long a,long long b)
{
  if(b==0)return a;
  return gcd_fast(b,a%b);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long long a, long long b) {
  long long c=gcd_fast(a,b);
  a/=c;
  //b/=c;
  return a*b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
