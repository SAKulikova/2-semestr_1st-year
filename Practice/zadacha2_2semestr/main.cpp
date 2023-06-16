#include <iostream>
int main() {
    const int N = 10;
    int mas_a [N] = {10,25,34,94,15,  36, 100, 3, 8, 13};
    std::cout<<"То, что нужно скопировать: ";
    for (int i=0;i<N;i++) //Копирование по одному символу, т.е. придется выполнить N копирований
        std::cout<<mas_a[i];
    std::cout<<std::endl;

    int mas_b[N] = {0};
    std::cout<<"До: ";
    for (int i = 0;i < N;i++)
        std::cout<<mas_b[i];
    std::cout<<std::endl;

    std::copy(std::begin(mas_a),std::end(mas_a),mas_b); //копирует машинные слова(т.е 32 или 64 бит)
    std::cout<<"После: ";
    for (int i=0;i<N;i++)
        std::cout<<mas_b[i];
    return 0;
}