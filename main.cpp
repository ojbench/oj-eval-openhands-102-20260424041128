
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return std::toupper(c) - 'A' + 10;
    }
}

char digitToChar(int digit) {
    if (digit < 10) {
        return '0' + digit;
    } else {
        return 'A' + (digit - 10);
    }
}

int main() {
    int m, n, B;
    std::cin >> m >> n >> B;
    
    std::string str1, str2;
    std::cin >> str1 >> str2;
    
    // Calculate the width (excluding the null terminator)
    int width = std::max(m - 1, n - 1);
    
    // Reverse the strings to process from least significant digit
    std::reverse(str1.begin(), str1.end());
    std::reverse(str2.begin(), str2.end());
    
    std::string result(width, '0');
    int carry = 0;
    
    // Perform addition digit by digit
    for (int i = 0; i < width; i++) {
        int digit1 = (i < str1.length()) ? charToDigit(str1[i]) : 0;
        int digit2 = (i < str2.length()) ? charToDigit(str2[i]) : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / B;
        int digit = sum % B;
        
        result[i] = digitToChar(digit);
    }
    
    // Reverse back to get the correct order
    std::reverse(result.begin(), result.end());
    
    std::cout << result << std::endl;
    
    return 0;
}
