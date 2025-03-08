#include <iostream>
#include <bitset>

using namespace std;

int solution(int N) {
    int max_gap = 0;
    int current_gap = 0;
    bool counting = false;

    while (N > 0) {
        if (N & 1) {  // If the last bit is 1
            if (counting) {  
                max_gap = std::max(max_gap, current_gap);
            }
            counting = true;  // Start counting zeros
            current_gap = 0;  // Reset gap count
        } else {  // If the last bit is 0
            if (counting) {
                current_gap++;
            }
        }
        N >>= 1;  // Right shift to check the next bit
    }

    return max_gap;
}

int main() {
    int N = 1041;
	bitset<32> bin(N);
	cout<<"Binary number is "<<bin;
    std::cout << "Longest binary gap: " << solution(N) << std::endl;
    return 0;
}