#include <iostream>
using namespace std;

int main() {
        int sec;
        cout << "введіть кількість секунд від початку доби: ";
        cin >> sec;
        int h = sec / 3600;
        int m = (sec % 3600) / 60;
        int s = sec % 60;
        cout << "час: " << h << " годин " << m << " хвилин " << s << " секунд" << endl;
        int left = 24 * 3600 - sec;
        int lh = left / 3600;
        int lm = (left % 3600) / 60;
        int ls = left % 60;
        cout << "о півночі залишилось " << lh << " годин " << lm << " хвилин " << ls << " с" << endl;

        double d;
        cout << "введіть діаметр кола: ";
        cin >> d;
        double r = d / 2.0;
        double pi = 3.14159;
        double p = pi * d;
        double s = pi * r * r;
        cout << "периметр: " << p << endl;
        cout << "площа: " << s << endl;

        double a, b;
        cout << "Введіть два числа: ";
        cin >> a >> b;
        cout << "сума = " << a + b << endl;
        cout << "добуток = " << a * b << endl;
        cout << "Середнє арифметичне = " << (a + b) / 2 << endl;
        double a, b, c;
        cout << "введіть три числа: ";
        cin >> a >> b >> c;
        cout << "Сума = " << a + b + c << endl;
        cout << "добуток = " << a * b * c << endl;
        cout << "середнє арифметичне = " << (a + b + c) / 3 << endl;

        double price, discount;
        int count;
        cout << "введіть ціну ноутбука: ";
        cin >> price;
        cout << "введіть кількість ";
        cin >> count;
        cout << "введіть відсоток знижки ";
        cin >> discount;
        double sum = price * count;
        double finalSum = sum - sum * discount / 100.0;
        cout << "гагальна сума: " << finalSum << endl;

        double sales;
        cout << "Введіть суму угод: ";
        cin >> sales;
        double salary = 100 + sales * 0.05;
        cout << "Зарплата менеджера: " << salary << " $" << endl;

        double gb, speed;
        cout << "розмір файлу (ГБ): ";
        cin >> gb;
        cout << "швидкість інтернету (біт/сек): ";
        cin >> speed;
        double bits = gb * 1024 * 1024 * 1024 * 8;
        double totalSec = bits / speed;
        int h = totalSec / 3600;
        int m = ((int)totalSec % 3600) / 60;
        int s = (int)totalSec % 60;
        cout << "чЧас завантаження " << h << " год " << m << " хв " << s << " с" << endl;

}
