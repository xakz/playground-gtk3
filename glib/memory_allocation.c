#include <glib.h>

struct node {
  guint id;
  gfloat foo;
  gpointer next;
};

int main(int argc, char *argv[])
{
  // Install memory profiler table
  g_mem_set_vtable(glib_mem_profiler_table);

  // fibonacci using classic memory allocation
  guint64 *fib;
  fib = g_new(guint64, 50);
  g_message("Allocates memory block at %p", fib);
  for (guint i = 0; i < 50; ++i) {
    if (i < 2) {
      fib[i] = 1;
    } else {
      fib[i] = fib[i-1] + fib[i-2];
    }
  }
  for (guint i = 0; i < 50; ++i) {
    g_message("%llu ", fib[i]);
  }
  g_message("Free block at %p", fib);
  g_free(fib); fib = NULL;
  // display memory allocation stats
  g_mem_profile();


  // very simple linked list of data block allocated using slice allocator
  // (preferred from classic allocation, to use if block is still known at
  // freeing time and block size >= 2*sizeof gpointer)
  struct node head;
  struct node *current = &head;
  struct node *next = NULL;

  g_message("Allocates 100 blocks");
  for (guint i = 0; i < 100; ++i) {
    next = g_slice_new(struct node);
    next->id = i;
    next->foo = i * 30.0f / 3.23f;
    next->next = NULL;
    current->next = next;
    current = next;
  }
  g_mem_profile();
  g_message("Free 100 blocks");
  g_slice_free_chain(struct node, head.next, next);
  g_mem_profile();
    
  
  return 0;
}
