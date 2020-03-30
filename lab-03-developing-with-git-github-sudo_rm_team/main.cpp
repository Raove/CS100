#include "c-echo.h"
#include "c-count.h"

int main(int argv, char** argc) {
    std::cout << echo(argv, argc);
	std::cout << std::endl;
}
