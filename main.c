#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    char *test_file = "test_file_1.txt"; // Specify the test file name

    // Open the test file
    fd = open(test_file, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening test file");
        return (1);
    }

    // Read and print each line until get_next_line returns NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    // Close the file
    close(fd);

    return (0);
}
