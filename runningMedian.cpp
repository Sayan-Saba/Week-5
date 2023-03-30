#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

void runningMedian(std::vector<int> stream)
{
    std::vector<int> nums;
    for (int i = 0; i < stream.size(); i++)
    {
        int num = stream[i];
        auto it = std::lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
        std::cout << "[";
        for (int j = 0; j < nums.size(); j++)
        {
            std::cout << nums[j];
            if (j < nums.size() - 1)
            {
                std::cout << ", ";
            }
        }
        int size = nums.size();
        if (size % 2 == 0)
        {
            std::cout << "] " << std::fixed << std::setprecision(1) << (double)(nums[size / 2 - 1] + nums[size / 2]) / 2.0 << std::endl;
        }
        else
        {
            std::cout << "] " << std::fixed << std::setprecision(1) << (double)nums[size / 2] << std::endl;
        }
    }
}

int main()
{
    std::vector<int> stream = {7, 3, 5, 2};
    runningMedian(stream);
    return 0;
}