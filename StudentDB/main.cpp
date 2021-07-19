#include <iostream>
#include <string>
#include <student.h>

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        std::cout << "No Command-Line Arguments Entered\nExiting now...\n";
        return EXIT_FAILURE;
    }

    switch(argv[1])
    {
        case 'create':
            createStudent();
            break;
        case 'delete':
            deleteStudent();
            break;
        case 'update':
            updateStudent();
            break;
        case 'display':
            displayStudent();
            break;
        default:
            std::cout << "Invalid Command-Line Argument Entered\nExiting now...\n";
            return EXIT_FAILURE;
    }

    return 0;
}
