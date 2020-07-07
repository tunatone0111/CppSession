#include <iostream>

void Swap(int &a, int &b);

int main()
{
    // // 1
    // char name[30];
    // int age;
    // std::cout << "당신의 이름은? " << std::endl;
    // std::cin >> name;
    // std::cout << "당신의 나이는? " << std::endl;
    // std::cin >> age;
    // std::cout << "나의 이름은 " << name << "이고, " << age << "살입니다." << std::endl;

    // //3
    // char *p = new char[12];
    // delete[] p;

    // //4
    // int a(2), b(3);
    // std::cout << a << b << std::endl;
    // Swap(a, b);
    // std::cout << a << b << std::endl;

    //6
    int aList[5] = {10, 20, 30, 40, 50};
    for (int i = 5 - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (aList[j] < aList[j + 1])
                Swap(aList[j], aList[j + 1]);
        }
    }

    for (auto x : aList)
        std::cout << x << ' ';

    std::cout << std::endl;

    return 0;
}

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}