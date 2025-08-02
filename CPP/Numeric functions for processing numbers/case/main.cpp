#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    {
        // ----------------------------------------------
        // std::accumulate
        // ----------------------------------------------
        int initialValue = 0;
        std::vector<int> data = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        int sumValue = std::accumulate(data.begin(), data.end(), initialValue);
        std::cout << "Accumulate: " << sumValue << std::endl;
        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::inner_product
        // ----------------------------------------------
        int initialValue = 0;
        std::vector<int> data1 = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        std::vector<int> data2 = {1, 20, 3, 40, 5, 60, 7, 80, 9, 100};
        int dot = std::inner_product(data1.begin(), data1.end(), data2.begin(), initialValue);
        std::cout << "Inner_product: " << dot << std::endl;
        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::partial_sum
        // ----------------------------------------------
        std::vector<int> data = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        int outDataSize = data.size();
        std::vector<int> outData(outDataSize);
        std::partial_sum(data.begin(), data.end(), outData.begin());
        std::cout << "Partial_sum starts: " << std::endl;
        for (const auto &i : outData)
        {
            std::cout << i << std::endl;
        }
        std::cout << "Partial_sum stops" << std::endl;
        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::adjacent_difference
        // ----------------------------------------------
        std::vector<int> data = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        int diffSize = data.size();
        std::vector<int> diff(diffSize);
        std::adjacent_difference(data.begin(), data.end(), diff.begin());
        std::cout << "Adjacent_difference starts: " << std::endl;
        for (const auto &i : diff)
        {
            std::cout << i << std::endl;
        }
        std::cout << "Adjacent_difference stops" << std::endl;
        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::iota
        // ----------------------------------------------
        std::vector<int> emptyData(5);
        std::iota(emptyData.begin(), emptyData.end(), 1);
        std::cout << "Iota starts: " << std::endl;
        for (const auto &i : emptyData)
        {
            std::cout << i << std::endl;
        }
        std::cout << "Iota stops" << std::endl;
        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::reduce
        // ----------------------------------------------
        std::vector<int> data = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        int sumValue = std::reduce(data.begin(), data.end());
        std::cout << "Reduce: " << sumValue << std::endl;

        // ----------------------------------------------
    }

    {
        // ----------------------------------------------
        // std::transform_reduce
        // ----------------------------------------------
        int initialValue = 0;
        std::vector<int> data = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10};
        int result = std::transform_reduce(data.begin(), data.end(), data.begin(), initialValue);
        std::cout << "Transform_reduce: " << result << std::endl;
        // ----------------------------------------------
    }

    return 0;
}