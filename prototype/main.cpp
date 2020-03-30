#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char* args[2];

    const char* ls = "ls";

    args[0] = (char*) ls;
    args[1] = NULL;

    pid_t child = fork();

    if (child == 0) {
        std::cout << "child" << child << std::endl;
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
    }
    if (child > 0) {
        if (wait(0) == -1) {
            perror("wait");
        }
        std::cout << "parent1" << child << std::endl;
        waitpid(child, NULL, 0);
        std::cout << "parent2" << child << std::endl;
    }
    return 0;
}
