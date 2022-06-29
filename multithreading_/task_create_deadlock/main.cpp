#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


namespace rkognitive {
    struct Point {
        int x{};
        int y{};
    };

    void showPoints(const std::vector<Point> & points) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        for (const auto & [x, y] : points) {
            std::cout << "x: " << x << ", y: " << y << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void spamMessageNTimes(const std::string & msg, const std::size_t n) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        for (std::size_t i = 0; i < n; ++i) {
            std::cout << msg;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

int main()
{
    using namespace rkognitive;

    std::vector<Point> points { {1, 1}, {2, 2}, {3, 3}, {4, 4} };

    std::thread th1(showPoints, points);
    std::thread th2(spamMessageNTimes, "Surprise, Vitzliputzli!\n", 5);

    th1.join();
    th2.join();
}
