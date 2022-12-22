#pragma once

#include <string>

std::string getStrSpacesOrStars(int strLength, bool thisSpace) {
    std::string
        strSymbol = (thisSpace) ? " " : "*", // Символ у стоці
        strReturn = ""; // Рядок-результат
    for (int i = 0; i < strLength; i++) {
        strReturn += strSymbol;
    }
    return strReturn;
}

std::string createStrChristmasTree() {
    int
        countSpace = 30, // Кількість відступів (для верху дерева)
        countStars = 1, // Кількість відступів (тіло верху дерева)
        countSpaceTreeTrunk = countSpace - 3; // Кількість відступів для стовбура дерева (для низу дерева)
    
    std::string strChristmasTree = ""; // Рядок усього дерева (результат функції)
        
    // Створення верху дерева
    while (countSpace > 0) {
        std::string strSpace = getStrSpacesOrStars(countSpace, true); // Рядок відступів
        std::string strStars = getStrSpacesOrStars(countStars, false); // Рядок зірок (верх дерева)
        strChristmasTree += (strSpace + strStars + "\n");
        countSpace -= 1;
        countStars += 2; 
    }
        
    // Створення стовбура дерева
    std::string strSpaceTreeTrunk = getStrSpacesOrStars(countSpaceTreeTrunk, true);
    for (int i = 0; i < 5; i = i + 1)
    {
        strChristmasTree += (strSpaceTreeTrunk + "|     |" + "\n");
    }
    strChristmasTree += (strSpaceTreeTrunk + "|_____|" + "\n");

    return strChristmasTree;
}
