#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

namespace rkognitive {
    struct Point {
        int x{};
        int y{};
    };

    std::mutex mtx1;
    std::mutex mtx2;

    void showPoints(const std::vector<Point> & points) {
        mtx1.lock();
        std::cout << "showPoints: mtx1.lock();\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        mtx2.lock();
        std::cout << "showPoints: mtx2.lock();\n";

        for (const auto & [x, y] : points) {
            std::cout << "x: " << x << ", y: " << y << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        mtx1.unlock();
        std::cout << "showPoints: mtx1.unlock();\n";

        mtx2.unlock();
        std::cout << "showPoints: mtx2.unlock();\n";
    }

    void spamMessageNTimes(const std::string & msg, const std::size_t n) {
        mtx1.lock();
        std::cout << "spamMessageNTimes: mtx1.lock();\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        mtx2.lock();
        std::cout << "spamMessageNTimes: mtx2.lock();\n";

        for (std::size_t i = 0; i < n; ++i) {
            std::cout << msg;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        
        mtx2.unlock();
        std::cout << "spamMessageNTimes: mtx2.unlock();\n";

        mtx1.unlock();
        std::cout << "spamMessageNTimes: mtx1.unlock();\n";
    }
} // namespace rkognitive

int main()
{
    using namespace rkognitive;

    std::vector<Point> points { {1, 1}, {2, 2}, {3, 3}, {4, 4} };

    std::thread th1(showPoints, points);
    std::thread th2(spamMessageNTimes, "Surprise, Vitzliputzli!\n", 5);

    th1.join();
    th2.join();
}
