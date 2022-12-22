#include <iostream>

#include <conio.h> // Підключення getch()
#include <windows.h> // Підключення SetConsoleCP(), SetConsoleOutputCP(), HANDLE і усе з цим пов'язане

#include "functions.h" // Підключення функції для створення ялинки

int main () {
    // Встановлення кирилиці у консолі (кодування: windows-1251)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int 
        keyColorOutput, // Код кольору виводу
        lastKeyColorOutput; // Минулий колір виводу
    
    HANDLE colorHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Колір консолі
    
    while(true) {
        std::cout << getStrSpacesOrStars(27, true) << "ПРИВIТ!" << "\n" << std::endl;

        do {
            keyColorOutput = rand()%15 + 1; // Встановлення діапазону [1; 15]
            if (keyColorOutput == 8) { // Щоб не було чорно-сірого кольору (погано видно у консолі)
                keyColorOutput = (rand()%2 + 0) ? 1 : -1; // Буде колір під кодом 9 або 7
            }
        } while (keyColorOutput == lastKeyColorOutput); // Щоб кольори не повторювалися
        lastKeyColorOutput = keyColorOutput; // Збереження минулого кольору

        SetConsoleTextAttribute(colorHandle, keyColorOutput); // Встановлення кольору     
        std::cout 
            << createStrChristmasTree() << "\n"
            << "БАЖАЄТЕ ПЕРЕЗАПУСТИТИ ПРОГРАМУ (ТАК - '+'): ";

        // Перезапуск і вихід з програми
        int codeGetch = getch();
        std::cout << ( (codeGetch == (char)'+') ? "+" : "-" ) << std::endl;
        Sleep(1000); // Пауза в секунду
        system("cls"); // Очистка вікна
        if (codeGetch != (char)'+') {
            break;
        }
    }

    SetConsoleTextAttribute(colorHandle, 15); // Встановлення кольору: білого   
    std::cout 
        << "БУВАЙ, ХОРОШИХ СВЯТ І НАСТРОЮ!" << "\n\n"
        << "Програма завершена, натисність будь-яку клавішу для закриття вікна консолі ..." << std::endl;

    getch(); // Затримка вікна

    return 0;
}
