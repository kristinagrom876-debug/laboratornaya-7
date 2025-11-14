/********************************
 * Автор: Щербакова Кристина    *
 * Вариант: 14                  *
 ********************************/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {

  ifstream file("text.txt");
    
  if (!file.is_open()) {
    cout << "Ошибка! Файл не найден." << endl;
    return 1;
}
    
  map<char, int> letters;   
  map<string, int> pairs;    
    
  char currentNumber, previousNumber = ' ';
    
  while (file.get(currentNumber)) {
      if ((currentNumber >= 'a' && currentNumber <= 'z')
          (currentNumber >= 'A' && currentNumber <= 'Z')
          (currentNumber >= 'а' && currentNumber <= 'я')
          (currentNumber >= 'А' && currentNumber <= 'Я')) {
            
        if (currentNumber >= 'A' && currentNumber <= 'Z') {
            currentNumber = currentNumber - 'A' + 'a';
        }
        if (currentNumber >= 'А' && currentNumber <= 'Я') {
            currentNumber = currentNumber - 'А' + 'а';
        }
        letters[currentNumber]++;

        if (previous != ' ') {
            string pair = string(1, previousNumber) + currentNumber;
            pairs[pair]++;
        }
            
        previousNumber = currentNumber;
    }
}
    
file.close();

cout << "Частота букв:\n";
for (auto elem : letters) {
    cout << elem.first << " - " << elem.second << " раз\n";
}
cout << "\nЧастота пар букв:\n";
for (auto elem : pairs) {
    cout << elem.first << " - " << elem.second << " раз\n";
}
    return 0;
}
