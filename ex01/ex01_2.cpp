//The exercise was from the 0th, so 64 bits are from 0 to 63.
#include<iostream>
#include<string>

bool isPrime(int n){
    if(n<=1){
        return false;
    }
    if(n<=3){
        return true;
    }
    if(n%2==0||n%3==0){
        return false;
    }
    for(int i=5; i*i<=n; i+=6){
        if (n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}

int main() {
    std::string patterns[] = {
        "0111011011010011001011010010011001011001010010001011011010000001",
        "0100110000110010010100100110000110110000010000010110100110000100",
        "1001001100101100001000000101101000000100100001101001000100100101",
        "0010001010001000011000011001010010001011010000010001010001010010",
        "0000110000000010010000100100110010000100100110010010110000010000",
        "1101001001100000101001000100001000100001000100100101000100101000",
        "1010000001000010000011000011011000010000001011010000001011010000",
        "0000010100010000100010100100100000010100100100010010000010100110"
    };

    for (int p = 0; p < 8; p++) {
        std::string pattern = patterns[p];
        std::cout << "Pattern P" << p << ":" << std::endl;

        for (int k = 0; k < pattern.length(); k++) {
            char bit = pattern[k];
            int cal = 2 * k + 1;
            if (isPrime(cal)==1) {
                std::cout << k << " : " << cal << " -> ";
                std::cout << cal << " is true" << std::endl;
            }else if(isPrime(cal)==0){
                std::cout<<k<<" : "<<cal<<" -> ";
                std::cout<<cal<< " is false" << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
