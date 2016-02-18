
#include <glib.h>
#include <glib/gprintf.h>  /* Needed by g_*printf functions, pulls stdio.h */

int main(int argc, char *argv[])
{
  g_printf("Hello World !\n");
  return 0;
}
