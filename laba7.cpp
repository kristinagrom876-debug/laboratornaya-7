/********************************
 * Автор: Щербакова Кристина    *
 * Вариант: 14                  *
 ********************************/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    // Открываем файл
    ifstream file("text.txt");
    
    // Проверяем, открылся ли файл
    if (!file.is_open()) {
        cout << "Ошибка! Файл не найден." << endl;
        return 1;
    }
    
    // Создаем словари для подсчета
    map<char, int> letters;    // для букв
    map<string, int> pairs;    // для пар букв
    
    char current, previous = ' ';
    
    // Читаем файл посимвольно
    while (file.get(current)) {
        // Если символ - буква
        if ((current >= 'a' && current <= 'z') || 
            (current >= 'A' && current <= 'Z') ||
            (current >= 'а' && current <= 'я') ||
            (current >= 'А' && current <= 'Я')) {
            
            // Приводим к нижнему регистру
            if (current >= 'A' && current <= 'Z') {
                current = current - 'A' + 'a';
            }
            if (current >= 'А' && current <= 'Я') {
                current = current - 'А' + 'а';
            }
            
            // Считаем букву
            letters[current]++;
            
            // Считаем пару букв
            if (previous != ' ') {
                string pair = string(1, previous) + current;
                pairs[pair]++;
            }
            
            previous = current;
        }
    }
    
    file.close();
    
    // Выводим результаты для букв
    cout << "Частота букв:\n";
    for (auto elem : letters) {
        cout << elem.first << " - " << elem.second << " раз\n";
    }
    
    // Выводим результаты для пар
    cout << "\nЧастота пар букв:\n";
    for (auto elem : pairs) {
        cout << elem.first << " - " << elem.second << " раз\n";
    }
    
    return 0;
}
