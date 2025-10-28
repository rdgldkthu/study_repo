/*
    영역 제한 열거형 (열거형 클래스) Scoped Enumerations (Enum Class)
*/
#include <iostream>

int main()
{
    using namespace std;

    enum class Color
    {
        RED,
        BLUE,
    };

    enum class Fruit
    {
        BANANA,
        APPLE,
    };

    Color color = Color::RED;
    Fruit fruit = Fruit::BANANA;

    /*if (color == fruit)
        cout << "Color is Fruit?" << endl;*/

    return 0;
}