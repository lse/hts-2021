#include <stddef.h>
#include <stdint.h>

#include "my_string.h"
#include "my_unistd.h"

void _start()
{
	char buf[] = "hi!\n";

	write(1, buf, strlen(buf));

	_exit(0);
}
