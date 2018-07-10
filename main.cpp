#include <iostream>

using namespace std;

//Function to find greatest common divisor
int gcd(int a, int b)
{
    if(a == b)
        return a;
    if(a > b)
        return gcd(a - b, b);
    if(a < b)
        return gcd(a, b - a);
}

//Function to find the min of two numbers
int MIN(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

//Function calculating the steps
int MinSteps(int n, int m, int k, int vesselN, int vesselM , int steps )
{
    if((k > n) && (k > m))
        return -1;

    if(k % gcd(n, m) != 0)
        return -1;

    if((vesselN == k) || (vesselM == k))
        return steps;

    if(vesselM == 0)
        return MinSteps(n, m, k, vesselN, m, steps + 1);

    if(vesselN == n)
        return MinSteps(n, m, k, 0, vesselM , steps + 1);

        return MinSteps(n, m, k, vesselN + MIN(( n - vesselN), vesselM),
                                 vesselM - MIN(( n - vesselN), vesselM), steps + 1);
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    int k;
    cin >> k;

    int steps = 0;
    int vN = 0;
    int vM = 0;

    int result = MIN(MinSteps(n , m, k, vN, vM, steps), MinSteps(m, n, k, vN, vM, steps));

    cout << result << endl;


    return 0;
}
