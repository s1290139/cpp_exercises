#include <iostream>

void isPrime(int x){
    int count;
    for (int i=1; i<=x; i++){
        if(x%i==0)count++;
    }
    if(count==2)std::cout<<"true";
    else std::cout<<"false";
}

int main(){
    int number;
    std::cout<<"please input number->";
    std::cin>>number;
    isPrime(number);
}