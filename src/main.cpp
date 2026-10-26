#include "Buffer.h"
#include <iostream>
#include <utility>

Buffer createTempObject(size_t s) {
    Buffer temp(s);
    temp.setValue(0, 999);
    return temp; 
}

int main() {
    std::cout << "Test 3 & 4: Constructor si Destructor\n";
    {
        Buffer b1(5);
        b1.setValue(0, 10);
        b1.print();
    }
    std::cout << "Memoria a fost eliberata\n\n";

    std::cout << "Test 5: Deep Copy\n";
    Buffer b2(3);
    b2.setValue(0, 100);
    
    Buffer b3 = b2; 
    
    b3.setValue(0, 200);
    
    std::cout << "Originalul (b2): "; b2.print();
    std::cout << "Copia (b3): "; b3.print();
    std::cout << "\n";

    std::cout << "Test 6: Move Constructor\n";
    Buffer b4 = createTempObject(2);
    std::cout << "Obiect creat prin move: ";
    b4.print();
    
    std::cout << "\nMutare explicita:\n";
    Buffer b5 = std::move(b4);
    std::cout << "Noul proprietar (b5): "; b5.print();
    std::cout << "Fostul proprietar (b4): "; b4.print();

    std::cout << "\nFinal Program\n";
    return 0;
}