#include <criterion/redirect.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

bool CreateFile(const char *path)
{
  FILE *file = fopen(path, "wb");
  if (!file)
    return false;

  const char *data = "THIS IS A TEST!";
  size_t data_size = strlen(data);

  size_t written = fwrite(data, 1, data_size, file);
  fclose(file);

  return written == data_size;
}

bool Cleanup(const char *path)
{
  return remove(path) == 0;
}

int FileExists(const char *path)
{
  return access(path, F_OK) != -1;
}

void SetupRedirect()
{
  cr_redirect_stdout();
  cr_redirect_stderr();
}

int RemoveDir(const char *path)
{
  char command[1024];

  snprintf(command, sizeof(command), "rm -rf %s", path);

  int result = system(command);

  if (result == -1)
  {
    perror("system");
    return -1;
  }

  return 0;
}

int CreateDir(const char *path)
{
  return mkdir(path, 0777) == 0;
}