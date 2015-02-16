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
#define AIN0_PATH          "/sys/bus/iio/devices/iio:device0/in_voltage3_raw"
#define AIN0_STR_LENGTH    10

#define SLOTS_PATH   "/sys/devices/bone_capemgr.9/slots"
#define DATAW_SLOTS  "cape-bone-iio"
/*==================[external functions definition]==========================*/

int main(void)
{
   FILE *ain0Handle;
   FILE *slotsHandle;
   char str[AIN0_STR_LENGTH];

   slotsHandle = fopen(SLOTS_PATH, "w");
   fwrite(DATAW_SLOTS, sizeof(DATAW_SLOTS), 1, slotsHandle);
   fclose(slotsHandle);

   while (1)
   {
      ain0Handle = fopen(AIN0_PATH, "r");
      fread(str, AIN0_STR_LENGTH, 1, ain0Handle);
      fclose(ain0Handle);

      printf("AIN=%s\r",str);
      usleep(100000);
   }

   return EXIT_SUCCESS;
}

/*==================[end of file]============================================*/
