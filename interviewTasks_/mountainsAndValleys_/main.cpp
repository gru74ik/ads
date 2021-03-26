#include <iostream>
#include <string>

int countingValleys(int steps, std::string path) {
    int count_valleys = 0;
    int curr_level = 0;
    int prev_level = curr_level;
    for (const auto elem : path) {
        prev_level = curr_level;
        if (elem == 'D') {
            --curr_level;
        }
        else {
            ++curr_level;
        }
        if (curr_level == 0 && curr_level > prev_level) {
            ++count_valleys;
        }
    }
    return count_valleys;
}

int main()
{
    std::string path = "DDUUUDDUUUDDUUUDDDUD";
    std::cout << countingValleys(path.size(), path) << std::endl;
}
