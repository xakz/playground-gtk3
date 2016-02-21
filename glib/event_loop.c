#include <glib.h>

guint gTimeoutCallbackCallCount = 0;
GMainLoop *gLoop = NULL;

static gboolean
timeout_callback(gpointer data)
{
  gulong val = GPOINTER_TO_SIZE(data);
  g_message("Timer fired: interval: %lu", val);
  ++gTimeoutCallbackCallCount;
  if (gTimeoutCallbackCallCount > 20) {
    g_main_loop_quit(gLoop);
  }
  return TRUE;
}

int main(int argc, char *argv[])
{
  //GSource *source = NULL;

  for (guint i = 0; i < 10; ++i) {
    guint timeout = i % 5 + 1;
    guint id = g_timeout_add_seconds(timeout, timeout_callback, GSIZE_TO_POINTER(timeout)); 
    g_message("Created timeout source with id `%u' and interval of %u seconds", id, timeout);
  }

  



  gLoop = g_main_loop_new(NULL, FALSE);

  g_message("Starting the main event loop");

  g_main_loop_run(gLoop);
  g_main_loop_unref(gLoop);

  
  
  return 0;
}
