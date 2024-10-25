#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

struct Point {
    long double x;
    long double y;
};

// Function to convert a single character to its decimal value
int charToDecimal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

// Function to convert string from any base (2-16) to decimal
long double convertToDecimal(string value, int base) {
    long double result = 0;
    long double power = 1;
    
    // Process from right to left
    for (int i = value.length() - 1; i >= 0; i--) {
        result += charToDecimal(value[i]) * power;
        power *= base;
    }
    
    return result;
}

// Lagrange interpolation to find f(0)
long double lagrangeInterpolation(vector<Point>& points, int k) {
    long double result = 0;
    
    // Use only k points
    for (int i = 0; i < k; i++) {
        long double term = points[i].y;
        
        for (int j = 0; j < k; j++) {
            if (i != j) {
                // For f(0), we use x = 0 in the formula
                term = term * (0 - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }
    
    return round(result);
}

// Process a single test case
long double processTestCase(int testCaseNum) {
    int n, k;
    
    if (testCaseNum == 1) {
        n = 4; k = 3;
        vector<Point> points;
        
        // Test case 1 points
        points.push_back({1, convertToDecimal("4", 10)});
        points.push_back({2, convertToDecimal("111", 2)});
        points.push_back({3, convertToDecimal("12", 10)});
        points.push_back({6, convertToDecimal("213", 4)});
        
        return lagrangeInterpolation(points, k);
    }
    else {
        n = 10; k = 7;
        vector<Point> points;
        
        // Test case 2 points
        points.push_back({1, convertToDecimal("13444211440455345511", 6)});
        points.push_back({2, convertToDecimal("aed7015a346d63", 15)});
        points.push_back({3, convertToDecimal("6aeeb69631c227c", 15)});
        points.push_back({4, convertToDecimal("e1b5e05623d881f", 16)});
        points.push_back({5, convertToDecimal("316034514573652620673", 8)});
        points.push_back({6, convertToDecimal("2122212201122002221120200210011020220200", 3)});
        points.push_back({7, convertToDecimal("20120221122211000100210021102001201112121", 3)});
        points.push_back({8, convertToDecimal("20220554335330240002224253", 6)});
        points.push_back({9, convertToDecimal("45153788322a1255483", 12)});
        points.push_back({10, convertToDecimal("1101613130313526312514143", 7)});
        
        return lagrangeInterpolation(points, k);
    }
}

int main() {
    // Process both test cases
    long double secret1 = processTestCase(1);
    long double secret2 = processTestCase(2);
    
    cout << fixed;  // Use fixed-point notation
    cout << "Secret for test case 1: " << (long long)secret1 << endl;
    cout << "Secret for test case 2: " << (long long)secret2 << endl;
    
    return 0;
}
