#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <libgen.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/time.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

#define LOG(LEVEL, FMT, ...)                                                   \
    do {                                                                       \
        fprintf(stderr, "(%s:%d) " FMT "\n", __func__, __LINE__,               \
                ##__VA_ARGS__);                                                \
    } while (0)

#define PRINT_DEBUG(FMT, ...) LOG(LOG_DEBUG, FMT, ##__VA_ARGS__)
#define PRINT_INFO(FMT, ...) LOG(LOG_INFO, FMT, ##__VA_ARGS__)
#define PRINT_WARN(FMT, ...) LOG(LOG_WARNING, FMT, ##__VA_ARGS__)
#define PRINT_ERROR(FMT, ...) LOG(LOG_ERR, FMT, ##__VA_ARGS__)

#define PRINT_HELP_FORMATS "  %-10s -- %s\r\n"
static void print_usage(const char *exe_name) {
    int eventid = 0;
    printf("Usage: %s <options> ...\r\n", exe_name);
    printf("Options:\r\n");
    printf(PRINT_HELP_FORMATS, "-h,--help", "Show this help message.");
    printf(PRINT_HELP_FORMATS, "-l TRIANGLE_LINES,--line=TRIANGLE_LINES",
           "Lines of triangle to print.");
    printf("\r\n");
}

#define ODD_N(n) ((2 * (n)) - 1)
#define CHR_TRIANGLE '*'
#define CHR_BLANK ' '
void print_triangle(int32_t lines) {
    uint32_t max_triangle = 0;
    uint32_t i = 0, j = 0;
    uint32_t s = 0, b = 0;

    if (lines <= 0) {
        return;
    }

    max_triangle = ODD_N(lines);
    for (i = 1; i <= lines; i++) {
        s = ODD_N(i);
        b = ((max_triangle - s) / 2);
        for (j = 0; j < max_triangle; j++) {
            if ((j < b) || (j >= (s + b))) {
                printf("%c", CHR_BLANK);
            } else {
                printf("%c", CHR_TRIANGLE);
            }
        }
        printf("\r\n");
    }
}

int32_t main(int32_t argc, char **argv) {
    int ecode = 0;
    int opt = 0, opt_index = 0;
    int opt_num = 0;
    int32_t triangle_lines = 0;

    static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                           {"line", required_argument, 0, 'l'},
                                           {0, 0, 0, 0}};

    while ((opt = getopt_long(argc, argv, "l:h", long_options, &opt_index)) !=
           -1) {
        opt_num++;
        switch (opt) {
        case 0:
            if (strcmp("line", long_options[opt_index].name) == 0) {
                triangle_lines = atoi(optarg);
            }
            break;
        case 'l':
            triangle_lines = atoi(optarg);
            break;
        case 'h':
            print_usage(argv[0]);
            ecode = 1;
            goto error;
        default:
            printf("Unknown option -- %c\n\n", opt);
            print_usage(argv[0]);
            goto error;
        }
    }

    if (opt_num < 1) {
        print_usage(argv[0]);
        ecode = 1;
        goto error;
    }

    if (triangle_lines <= 0) {
        PRINT_ERROR("Invalid parameter!");
        ecode = 2;
        goto error;
    }

    print_triangle(triangle_lines);

    ecode = 0;
error:
    return ecode;
}