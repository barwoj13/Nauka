#include <iostream>

int& getLocalVariable() { // to jest b³êdne poniewa¿ x nie istnieje poza funkcj¹ wiêc nie mo¿emy odwo³ywaæ siê do niego przez referencje
    int x = 10; 
    return x; // wisz¹ca referencja
}

void processValue(int* ptr) { 
    *ptr += 6;
}

int main() {
    int& ref = getLocalVariable();
    std::cout << ref << std::endl;

    int* p = nullptr;
    processValue(p); // ta funkcja podniesie wartoœæ po derefencji tego wskaŸnika, ale wyskoczy error poniewa¿ wartoœæ nie zosta³a wczeœniej zainicjalizowana
    return 0;
}