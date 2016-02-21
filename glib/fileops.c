#include <glib.h>

int main(int argc, char *argv[])
{
  gint retval = 0;
  gchar *filename;
  if (argc < 2) {
    filename = g_strdup("/etc/protocols");
  } else {
    filename = g_strdup(argv[1]);
  }
  GError *error = NULL;
  GIOChannel *f = g_io_channel_new_file(filename, "r", &error);
  if (f == NULL) {
    g_critical("Unable to open file `%s': %s\n", filename, error->message);
    retval = 1;
    goto out1;
  }

  gchar *line;
  gsize length;
  gsize term_pos;
  while (g_io_channel_read_line(f, &line, &length, &term_pos, &error) == G_IO_STATUS_NORMAL) {
    g_message("len=%lu, pos=%lu: %s", length, term_pos, line);
    g_free(line);
  }
  g_free(line);


  g_io_channel_unref(f);
out1:  
  g_free(filename);
  return retval;
}
