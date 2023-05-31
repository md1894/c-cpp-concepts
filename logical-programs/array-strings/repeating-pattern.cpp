#include <iostream>
#include <string>

std::string findRepeatingPattern(const std::string& str) {
    int strLen = str.length();
    for (int patternLen = 1; patternLen <= strLen / 2; ++patternLen) {
        if (strLen % patternLen == 0) {
            std::string pattern = str.substr(0, patternLen);
            bool isRepeatingPattern = true;
            for (int i = patternLen; i < strLen; i += patternLen) {
                if (str.substr(i, patternLen) != pattern) {
                    isRepeatingPattern = false;
                    break;
                }
            }
            if (isRepeatingPattern) {
                return pattern;
            }
        }
    }
    return "";
}

int main() {
    std::string input = "aabcaabcaabcaabc";

    std::string repeatingPattern = findRepeatingPattern(input);

    if (repeatingPattern.empty()) {
        std::cout << "No repeating pattern found." << std::endl;
    } else {
        std::cout << "Repeating pattern: " << repeatingPattern << std::endl;
    }

    return 0;
}
