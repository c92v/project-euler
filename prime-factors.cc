#include <iostream>
#include <vector>
// Largest prime factor, Problem 3
// "The prime factors of 13195 are 5, 7, 13, and 29.
// What is the largest prime factor of the number 600851475143?

// Why is this SEGFAULTing :(
using namespace std;

bool is_prime(int n)
{
   if (!(n % 2 == 0) &&
      !(n % 3 == 0) &&
      !(n % 5 == 0) &&
      !(n % 7 == 0))
      return true;

    return false;
}

void prime_factor(int n)
{
   vector<int> factors;
   for (int i = 1; i <= n; ++i) 
   {
        if (n % i == 0) factors.push_back(i);
   }

   for (size_t i = 0; i < factors.size(); ++i) 
        if (is_prime(factors.at(i)))
            cout << factors.at(i) << endl;
}

int main()
{
    int n = 13195;
    prime_factor(n);
}
