#include <stdio.h>
#include <dlfcn.h>
#include "../src/dbg.h"

typedef int (*lib_function) (const char *data);

int main(int argc, char *argv[])
{
	char *file = "build/libex29.so";
	char *f = "print_a_message";
	char *msg = "hello there";
	int rc = 0;

	void *lib = dlopen(file, RTLD_NOW);
	check(lib != NULL, "failed to open lib %s: %s", file, dlerror());

	lib_function func = dlsym(lib, f);
	check(func != NULL, "Did not find function");

	rc = func(msg);
	check(rc == 0, "Function returned error");

	rc = dlclose(lib);
	check(rc == 0, "Failed to close");

	return 0;
error:
	return 1;
}
