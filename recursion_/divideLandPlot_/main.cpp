#include <iostream>

class LandPlot
{
public:
    LandPlot() = default;

    LandPlot(int length, int width) :
        m_length(length), m_width(width)
    {}

    void divideToEqualSquares()
    {

        if (m_width != m_length && m_width > 0 && m_length > 0)
        {
            int newWidth = m_length;
            while (newWidth > m_width)
            {
                newWidth -= m_width;
            }
            m_length = m_width;
            m_width = newWidth;
            divideToEqualSquares();
        }
    }

    int width() { return m_width; }
    int length() { return m_length; }

private:
    int m_length;
    int m_width;
};

int main()
{
    LandPlot landPlot(1680, 640);
    landPlot.divideToEqualSquares();
    std::cout << landPlot.width() << ", " << landPlot.length() << "\n\n";
}