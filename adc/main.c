/* ==========================================================================
 * Autores:
 * Gustavo Muro gustmuro@gmail.com
 * Luciano Diamand lucianodiamand@yahoo.com
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*==================[macros and definitions]=================================*/
#define AIN3_PATH          "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"
#define AIN3_STR_LENGTH    10

/*==================[external functions definition]==========================*/

int main(void)
{
   FILE *ain3Handle;
   char str[AIN3_STR_LENGTH];

   while (1)
   {
      ain3Handle = fopen(AIN3_PATH, "r");
      fread(str, AIN3_STR_LENGTH, 1, ain3Handle);
      fclose(ain3Handle);

      printf("AIN3=%s\r",str);
      usleep(100000);
   }

   return EXIT_SUCCESS;
}

/*==================[end of file]============================================*/
