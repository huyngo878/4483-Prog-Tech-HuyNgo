#include <iostream>
using namespace std;

// if n is even, divide by 2
// if n is odd, multiply by 3 and add 1
// repeat until n becomes 1
int main()
{
  int i, j;
  while (cin >> i >> j)
  {
    int a = min(i, j);
    int b = max(i, j);

    int maxLength = 0;

    for (int x = a; x <= b; x++)
    {
      int n = x;
      int currentLength = 1;

      while (n != 1)
      {
        // if odd
        if ((n % 2) == 1)
        {
          n = 3 * n + 1;
        }
        // else even
        else
        {
          n /= 2;
        }
        currentLength++;
      }
      // see which one is the greater number and puts it in maxLength
      maxLength = max(maxLength, currentLength);
    }

    cout << i << " " << j << " " << maxLength << endl;
  }

  return 0;
}