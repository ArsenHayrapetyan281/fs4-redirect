#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string>

void initialize(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << argv[0] << std::endl;
        exit(EXIT_FAILURE);
    }

    const char* filepath = argv[1];
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("Error");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

int main(int argc, char** argv) {
    initialize(argc, argv);
    std::string input;
    std::cin >> input;
    std::string reversed(input.rbegin(), input.rend());
    std::cout << reversed << std::endl;
    return 0;
}

