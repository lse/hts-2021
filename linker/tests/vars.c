#include <stddef.h>
#include <stdint.h>

#include "my_string.h"
#include "my_unistd.h"

static void puts(const char *buf)
{
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
}

void (*print_func)(const char *var) = puts;

void _start()
{
	print_func("coucou!");

	_exit(0);
}
