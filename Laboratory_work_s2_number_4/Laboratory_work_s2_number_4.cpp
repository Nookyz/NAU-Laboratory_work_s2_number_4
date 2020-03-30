
#include <iostream>
#include <ctime>
#include <queue>
#include <string>

using namespace std;


int a;
void taskOne();
void taskTwo();
// Приводим число к абсолютному значению
int absolute(int num) {
    return num < 0 ? -num : num;
}

int main()
{
    //Завдання(Варіант 7, на добре)
    //Застосовуючи чергу, написати функцію, яка замінює всі відємні елементи черги на їх абсолютні значення
    setlocale(LC_ALL, "Russian");
    
    int switchNumber;
    
    cout << "Введите 1 (Задание 1)" << endl;
    cout << "Введите 2 (Задание 2)" << endl;

    cin >> switchNumber;

    switch (switchNumber) {
        case 1:
            taskOne();
            break;
        case 2:
            taskTwo();
            break;
        default:
            break;
    }
    system("pause");
    return 0;
}

void taskOne() {
    //Завдання(1, на добре)
    //Написати  програму створення черги за добомогою шаблонів С++
    //та включити до програми виконання функції відповідно до варіанта
    queue <int> queue;
    int a;

    cout << "Введите 5 чисел" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        queue.push(a);
    }
    cout << "Первый элемент очереди - " << queue.front() << endl;
    cout << "Количество элементов в очереди: " << queue.size() << endl;
    
    //!!! есть баг
    //!!! если задать второе число со сзнаком минус, то ччисло не перейдет в абсолютное значение
    while (!queue.empty()) {
        if (queue.front() < 0) {
            int variable = queue.front();
            queue.pop();
            queue.push(absolute(variable));
        }
        cout << queue.front() << endl;
        queue.pop();
    }
    
}
void taskTwo() {
    //Завдання(2, на добре)
    //Написати  програму створення черги за добомогою масиву
    //та включити до програми виконання функції відповідно до варіанта
    int arrayQueue[5];
    int start = 0;
    int ends = 0;

    cout << "Введите 5 чисел" << endl;

    for (int i = 0; i < 5; i++) {
        int b;
        cin >> b;
        arrayQueue[start++] = b;
    }

    while (start != ends) {
        int minus = 0;
        minus++;
        if (arrayQueue[start - minus] < 0) {
            arrayQueue[start - minus] = absolute(arrayQueue[start - minus]);
        }
        cout << minus <<" элемент в очереди: " << arrayQueue[start - minus] << endl;
        cout << "Новый " << minus <<  " элемент (после удаления): " << arrayQueue[start - minus] << endl;
        cout << "Последний элемент в очереди: " << arrayQueue[ends] << endl;
        cout << "--------------------------------------" << endl;
        start--;
        
    }

    if (start != ends) {
        cout << "Очередь не пустая" << endl;
    }
}





