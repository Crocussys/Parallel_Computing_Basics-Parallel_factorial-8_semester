#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex ans_mutex;

void interval_multiplication(int start, int end, unsigned long long* ans){
    if (end >= start){
        for (int i = start; i <= end; i++){
            ans_mutex.lock();
            *ans *= i;
            ans_mutex.unlock();
        }
    }
}

int main(int argc, char* argv[])
{
    int num = 0;
    int cores = 0;
    if (argc < 2){
        cout << "Недостаточно аргументов" << endl;
        cout << "Укажите факториал какого числа надо посчитать" << endl;
        return 1;
    }
    if (isdigit(*argv[1])){
        num = stoi(argv[1]);
    }else{
        cout << argv[1] <<" не число!" << endl;
        return 2;
    }
    if (num > 20){
        cout << "Число слишком большое" << endl;
        return 4;
    }
    if (argc < 3){
        cores = thread::hardware_concurrency();
        if (cores == 0){
            cout << "Невозможно вычислить оптимальное количество потоков автоматически. Пожалуйста, укажите количество потоков явно." << endl;
            return 3;
        }
    }else{
        if (isdigit(*argv[2])){
            cores = stoi(argv[2]);
        }else{
            cout << argv[2] <<" не число!" << endl;
            return 2;
        }
    }
    auto begin_time = chrono::steady_clock::now();
    int lenght_interval = num / cores;
    int averaging = num % cores;
    int start = 1;
    int end = lenght_interval;
    unsigned long long ans = 1;
    thread threads[cores];
    for (int i = 0; i < cores; i++){
        if (averaging > i){
            end++;
        }
        threads[i] = thread(interval_multiplication, start, end, &ans);
        start = end + 1;
        end += lenght_interval;
    }
    for (int i = 0; i < cores; i++){
        threads[i].join();
    }
    auto end_time = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end_time - begin_time);
    cout << "Ответ: " << ans << endl;
    cout << "Ответ получен за: " << elapsed_ms.count() << "ns" << endl;
    return 0;
}
