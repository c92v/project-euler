#include <iostream>
#include <fstream>
#include <chrono>


using namespace std;
//TODO:
// 1. Research matrix, matrix exponentation for fibonacci
// 2. Create function for test (lots of redundancy in main)
// 3. WHY is fibonacci_faster so much faster? 
// Think and write out the trees of fibonacci vs. fibonacci_faster in computation

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }
private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};

template<typename T>
inline T fibonacci(T n) 
{
    if (n == 0) n = 0;
    else if (n == 1) n = 1;
    else n = fibonacci(n-1) + fibonacci(n-2);
    return n;
}

inline int fibonacci_faster(int n) 
{
    int a = 0, b = 1;
    int c;

    if (n == 0) return a;
    for (int i = 2; i <= n; ++i) 
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    const int MAX = 4000000;
    int length = 50;
    Timer time;

    ofstream data;
    data.open("times.txt");

    cout << "Fibonacci numbers (int):\n";
    for (int i = 0; i < length; ++i) 
    {
        int temp = fibonacci(i);
        // if (temp > MAX) break;
        cout << (i+1) << ". " << temp << '\n';
    }
    
    data << time.elapsed() << endl;

    time.reset();

    cout << "Fibonacci numbers (double):\n";
    for (double i = 0; i < length; ++i)
    {
        int temp = fibonacci(i);
        // if (temp > MAX) break;
        cout << (i+1) << ". " << temp << '\n';
    }

    data << time.elapsed() << endl;

    time.reset();

    cout << "Fibonacci numbers (faster):\n";
    for (int i = 0; i < length; ++i)
    {
        int temp = fibonacci_faster(i);
        // if (temp > MAX) break;
        cout << (i+1) << ". " << temp << '\n';
    }

    data << time.elapsed() << endl;

    data.close();
}
