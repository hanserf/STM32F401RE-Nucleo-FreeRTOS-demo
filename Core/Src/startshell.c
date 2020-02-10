
// You need these includes
#include "global_defines.h"
#include "cmsis_os.h"
#include "ntshell.h"
#include "ntlibc.h"
#include "ntShellThread.h"
#include "mbed_port.h"
#include <stdio.h>

ntshell_t ntshell;
void ntShellTask()
{

  printf("Started ntshell\n");
  setvbuf(stdin, NULL, _IONBF, 0);
  ntshell_init(
	       &ntshell,
	       ntshell_read,
	       ntshell_write,
	       ntshell_callback,
	       (void *)&ntshell);
  ntshell_set_prompt(&ntshell, "BlueTank>");
  vtsend_erase_display(&ntshell.vtsend);
  ntshell_execute(&ntshell);

}

