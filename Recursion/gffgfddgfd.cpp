#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IN(var, type)  type var;cin >> var
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define VEC4(name, type, size, value) vector<type> name(size, value)
#define VEC3(name, type, size) vector<type> name(size)
#define VEC2(name, type) vector<type> name
#define VEC(type) vector<type>
#define SORT(name) sort(name.begin(), name.end())

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    for (auto e : v)
        os << e << " ";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, pair<T, T> &p)
{
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

// Example: https://www.codechef.com/viewsolution/54414764
long long int const mod = 1e9 + 7;
long long int inverse_modulo(long long int p, long long int q)
{
    long long int expo = mod - 2;
    while (expo)
    {
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        expo >>= 1;
    }
    return p;
}
// long long int const inverse = inverse_modulo(1, 4);

void solution();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    IN(T, int);
    FOR(t, 0, T)
    solution();

    return 0;
}

void solution()
{
    IN(N, long long int);

    --N;
    double limit = sqrt(N);
    long long int count = 0;

    for (long long int i = 1; i <= limit; ++i)
    {
        if (N % i == 0)
            ++count;
    }

    cout << count * 2ll - (limit == (long long int)limit) << "\n";
}

/*


*/


