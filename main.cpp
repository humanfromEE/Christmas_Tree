#include <iostream>

#include <conio.h> // ϳ��������� getch()
#include <windows.h> // ϳ��������� SetConsoleCP(), SetConsoleOutputCP(), HANDLE � ��� � ��� ���'�����

#include "functions.h" // ϳ��������� ������� ��� ��������� ������

int main () {
    // ������������ �������� � ������ (���������: windows-1251)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int 
        keyColorOutput, // ��� ������� ������
        lastKeyColorOutput; // ������� ���� ������
    
    HANDLE colorHandle = GetStdHandle(STD_OUTPUT_HANDLE); // ���� ������
    
    while(true) {
        std::cout << getStrSpacesOrStars(27, true) << "����I�!" << "\n" << std::endl;

        do {
            keyColorOutput = rand()%15 + 1; // ������������ �������� [1; 15]
            if (keyColorOutput == 8) { // ��� �� ���� �����-����� ������� (������ ����� � ������)
                keyColorOutput = (rand()%2 + 0) ? 1 : -1; // ���� ���� �� ����� 9 ��� 7
            }
        } while (keyColorOutput == lastKeyColorOutput); // ��� ������� �� �������������
        lastKeyColorOutput = keyColorOutput; // ���������� �������� �������

        SetConsoleTextAttribute(colorHandle, keyColorOutput); // ������������ �������     
        std::cout 
            << createStrChristmasTree() << "\n"
            << "������� ������������� �������� (��� - '+'): ";

        // ���������� � ����� � ��������
        int codeGetch = getch();
        std::cout << ( (codeGetch == (char)'+') ? "+" : "-" ) << std::endl;
        Sleep(1000); // ����� � �������
        system("cls"); // ������� ����
        if (codeGetch != (char)'+') {
            break;
        }
    }

    SetConsoleTextAttribute(colorHandle, 15); // ������������ �������: �����   
    std::cout 
        << "�����, ������� ���� � �������!" << "\n\n"
        << "�������� ���������, ��������� ����-��� ������ ��� �������� ���� ������ ..." << std::endl;

    getch(); // �������� ����

    return 0;
}
