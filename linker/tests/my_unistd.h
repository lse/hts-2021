#pragma once

#include <asm/unistd.h>
#include "syscall.h"

static long write(int fd, const void *buf, size_t sz)
{
	return syscall3(__NR_write, fd, (uint64_t)buf, sz);
}

static void _exit(int status)
{
	syscall1(__NR_exit, status);
}
