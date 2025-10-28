/*
    이동 생성자 Move constructors와 이동 대입 Move assignment
*/  
#include <iostream>
#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10'000'000));

    return res;
}

int main()
{
    using namespace std;

    streambuf* orig_buf = cout.rdbuf();
    //cout.rdbuf(NULL); // disconnect cout from buffer

    Timer timer;

    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();
    }

    cout.rdbuf(orig_buf);
    timer.elapsed();

    return 0;
}