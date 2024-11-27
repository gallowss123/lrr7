// Лошкарев Тимофей ИУ8-15 Вариант 16
// deque и set
// 1. Добавление элементов в начало deque и вставка в set
// 2. Поиск элементов
// 3. Удаление элементов из конца deque и удаление из set
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
#include <profile.h>
using namespace std;
using namespace chrono;
class LogDuration {
public:
 explicit LogDuration(const string& msg = "")
  : message(msg + ": ")
  , start(steady_clock::now())
 {
 }
 ~LogDuration() {
  auto finish = steady_clock::now();
  auto dur = finish - start;
  cerr << message
   << duration_cast<milliseconds>(dur).count()
   << " ms" << endl;
 }
private:
 string message;
 steady_clock::time_point start;
};
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__){message};
int main(){
    deque <int> deq;
    {
        LogDuration log("Add in deq 100000");
        for (int i = 0;i < 100000;i++){
            deq.push_back(rand()%1000);
        }
    }
    deque <int> deqt;
    set <int> sett;
    {
    LogDuration log("Add in deqt 100000");
    for (int i = 0;i < 100000;i++){
        deqt.push_front(deq[i]);
    }   
    cout << "complexity is O(1)" << endl;
    }
    {
    LogDuration log("Search in deqt 100000");
    for (int i = 0;i < 100000;i++){
        find(deqt.begin(),deq.end(),deq[i]);
        }
    }
    cout << "complexity is Sorted:= O(log(n))/ Other:=O(n)" << endl;
    {
    LogDuration log("Delete in deqt 100000");
    for (int i = 0;i < 100000;i++){
        deqt.pop_back();
        }
        cout << "complexity is  O(1)" << endl;
    }
    {
    LogDuration log("Add in set 100000");
    for (int i = 0;i < 100000;i++){
        sett.insert(rand() % 1000);
        }
        cout << "complexity is O(log(n))" << endl;
    }
    {
    LogDuration log("Search in set 100000");
    for (int i = 0;i < 100000;i++){
        sett.find(i);
        }
        cout << "complexity is O(log(n))" << endl;
    }
    {
    LogDuration log("Delete in set 100000");
    for (int i = 0;i < 100000;i++){
        sett.erase(i);
        }
        cout << "complexity is O(log(n))" << endl;
    }
    cout << "Добавление элементов в deq быстрее чем в set" << endl;
    cout << "Поиск элементов в deq медленне чем в set" << endl;
    cout << "Удаление элементов в set быстрее чем в deq" << endl;
}