#include <stdio.h>
#include <stdarg.h>

int printf(const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, "hello modified");
	ret = vfprintf(stdout, "hello modified", ap);
	va_end(ap);
	return ret;
}
#ifdef __wasilibc_unmodified_upstream // Changes to optimize printf/scanf when long double isn't needed
#else
weak_alias(printf, iprintf);
weak_alias(printf, __small_printf);
#endif
