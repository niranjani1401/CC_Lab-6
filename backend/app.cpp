#include <iostream>
#include <unistd.h>

int main() {
    while(true) {
        std::cout << "Backend running..." << std::endl;
        sleep(5);
    }
    return 0;
}

