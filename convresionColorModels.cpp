#include <iostream>

// Function to convert RGB to CMY
void rgbToCmy(float r, float g, float b, float &c, float &m, float &y) {
    c = 1.0f - r;
    m = 1.0f - g;
    y = 1.0f - b;
}

// Function to convert RGB to CMYK
void rgbToCmyk(float r, float g, float b, float &c, float &m, float &y, float &k) {
    c = 1.0f - r;
    m = 1.0f - g;
    y = 1.0f - b;

    float minCmy = std::min(c, std::min(m, y));
    k = 1.0f - std::max(c, std::max(m, y));
    c = (c - minCmy) / (1.0f - minCmy);
    m = (m - minCmy) / (1.0f - minCmy);
    y = (y - minCmy) / (1.0f - minCmy);
}

int main() {
    float r, g, b, c, m, y, k;

    // Input RGB values
    std::cout << "Enter RGB values (0.0 - 1.0): ";
    std::cin >> r >> g >> b;

    if (r < 0.0 || r > 1.0 || g < 0.0 || g > 1.0 || b < 0.0 || b > 1.0) {
        std::cout << "Invalid RGB values. Please use values in the range [0.0, 1.0]." << std::endl;
        return 1;
    }

    // Convert RGB to CMY
    rgbToCmy(r, g, b, c, m, y);
    std::cout << "CMY: " << c << " " << m << " " << y << std::endl;

    // Convert RGB to CMYK
    rgbToCmyk(r, g, b, c, m, y, k);
    std::cout << "CMYK: " << c << " " << m << " " << y << " " << k << std::endl;

    return 0;
}

