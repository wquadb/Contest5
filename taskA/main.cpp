#include <iostream>
#include <set>
#include <vector>

int main()
{
    int n, k, val;
    std::cin >> n >> k;
    std::vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        vec.push_back(val);
    }
    std::multiset<int> m(vec.begin(), vec.begin() + k);
    std::cout << *m.begin() << "\n";
    for (int i = k; i < n; i++)
    {
        m.erase(m.lower_bound(vec[i - k]));
        m.insert(vec[i]);
        std::cout << *m.begin() << "\n";
    }
    return 0;
}
