/*
    비트 플래그 bit flag, 비트 마스크 bit mask    
*/
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    // bit flag
    //const unsigned char opt0 = 1 << 0;
    //const unsigned char opt1 = 1 << 1;
    //const unsigned char opt2 = 1 << 2;
    //const unsigned char opt3 = 1 << 3;
    //// opt 4, 5, 6, 7

    //cout << bitset<8>(opt0) << endl;
    //cout << bitset<8>(opt1) << endl;
    //cout << bitset<8>(opt2) << endl;
    //cout << bitset<8>(opt3) << endl;

    //unsigned char items_flag = 0;

    //cout << "No item " << std::bitset<8>(items_flag) << endl;

    //// item0 on 
    //items_flag |= opt0;
    //cout << "Item0 obtained " << std::bitset<8>(items_flag) << endl;

    //// item3 on 
    //items_flag |= opt3;
    //cout << "Item3 obtained " << std::bitset<8>(items_flag) << endl;

    //// item3 lost 
    //items_flag &= ~opt3;
    //cout << "Item3 lost " << std::bitset<8>(items_flag) << endl;

    //// has item1? 
    //if (items_flag & opt1) { cout << "has item1 " << endl; }

    //// has item0? 
    //if (items_flag & opt0) { cout << "has item0 " << endl; }

    //// obtain item 2,3
    //items_flag |= (opt2 | opt3);
    //cout << "Item2,3 obtained " << std::bitset<8>(items_flag) << endl;

    //if ((items_flag & opt2) && !(items_flag & opt1)) { items_flag ^= (opt2 | opt1); }

    //cout << std::bitset<8>(items_flag) << endl;

    //bit mask
    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;

    unsigned int pixel_color = 0xDAA520;

    cout << std::bitset<32>(pixel_color) << endl;

    unsigned char red = (pixel_color & red_mask) >> 16;
    cout << std::bitset<8>(red) << " " << int(red) << endl;
    unsigned char green = (pixel_color & green_mask) >> 8;
    cout << std::bitset<8>(green) << " " << int(green) << endl;
    unsigned char blue = pixel_color & blue_mask;
    cout << std::bitset<8>(blue) << " " << int(blue) << endl;


    return 0;
}