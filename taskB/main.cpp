#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <set>

double dotProduct(const std::vector<int>& v1, const std::vector<int>& v2)
{
    double dot = 0.0;
    for (size_t i = 0; i < v1.size(); ++i)
    {
        dot += v1[i] * v2[i];
    }
    return dot;
}

double magnitude(const std::vector<int>& v)
{
    double mag = 0.0;
    for (double component: v)
    {
        mag += component * component;
    }
    return std::sqrt(mag);
}

int main()
{
    int n, k, val;
    std::cin >> n >> k;
    std::string name, ref;

    std::unordered_map<std::string, std::vector<int>> dict;
    std::vector<int> loc;

    for (int i = 0; i < n; i++)
    {
        std::cin >> name;
        for (int j = 0; j < k; j++)
        {
            std::cin >> val;
            loc.push_back(val);
        }
        if (i == 0)
        {
            ref = name;
        }
        dict[name] = loc;
        loc = {};
    }
    double maxDotProduct = 0;
    double currProduct = 0;
    std::multiset<std::string> leaders = {};
    for (const std::pair<std::string, std::vector<int>>& word: dict)
    {
        if (word.first != ref)
        {
            currProduct = dotProduct(dict[ref], dict[word.first]) / (magnitude(dict[ref]) * magnitude(dict[word.first]));
            if (currProduct > maxDotProduct)
            {
                leaders = {};
                maxDotProduct = currProduct;
                leaders.insert(word.first);
            }
            else if (currProduct == maxDotProduct)
            {
                leaders.insert(word.first);
            }
        }
    }
    for (const std::string& leader: leaders)
    {
        std::cout << leader << "\n";
    }
    return 0;
}
