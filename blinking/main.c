/* ==========================================================================
 * Autores:
 * Gustavo Muro gustmuro@gmail.com
 * Luciano Diamand lucianodiamand@yahoo.com
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Leds.h"

/*==================[external functions definition]==========================*/

int main(void)
{
   if (Leds_init() != 0)
   {
      printf("Error al inicializar los leds\n");
   }
   else
   {
      printf("Encendiendo leds...\n");

      Leds_msg(LEDS_ID_0, LEDS_MSG_ON);
      sleep(1);
      Leds_msg(LEDS_ID_1, LEDS_MSG_ON);
      sleep(1);
      Leds_msg(LEDS_ID_2, LEDS_MSG_ON);
      sleep(1);
      Leds_msg(LEDS_ID_3, LEDS_MSG_ON);
      sleep(2);

      printf("Apagando leds...\n");
      Leds_msg(LEDS_ID_3, LEDS_MSG_OFF);
      sleep(1);
      Leds_msg(LEDS_ID_2, LEDS_MSG_OFF);
      sleep(1);
      Leds_msg(LEDS_ID_1, LEDS_MSG_OFF);
      sleep(1);
      Leds_msg(LEDS_ID_0, LEDS_MSG_OFF);

      Leds_deinit();
   }

   return EXIT_SUCCESS;
}

/*==================[end of file]============================================*/
