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

/*==================[macros and definitions]=================================*/
#define LED0_PATH       "/sys/class/leds/beaglebone:green:heartbeat/brightness"
#define LED1_PATH       "/sys/class/leds/beaglebone:green:mmc0/brightness"
#define LED2_PATH       "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED3_PATH       "/sys/class/leds/beaglebone:green:usr3/brightness"

#define TRIGGER0_PATH   "/sys/class/leds/beaglebone:green:heartbeat/trigger"
#define TRIGGER1_PATH   "/sys/class/leds/beaglebone:green:mmc0/trigger"
#define TRIGGER2_PATH   "/sys/class/leds/beaglebone:green:usr2/trigger"
#define TRIGGER3_PATH   "/sys/class/leds/beaglebone:green:usr3/trigger"

/*==================[internal data declaration]==============================*/
static FILE *ledHandle[LEDS_TOTAL];

static const char *ledPath[LEDS_TOTAL] =
{
   LED0_PATH,
   LED1_PATH,
   LED2_PATH,
   LED3_PATH,
};

static const char *triggerPath[LEDS_TOTAL] =
{
   TRIGGER0_PATH,
   TRIGGER1_PATH,
   TRIGGER2_PATH,
   TRIGGER3_PATH,
};

/*==================[external functions definition]==========================*/

extern int32_t Leds_init(void)
{
   FILE *triggerHandle;
   int32_t ret = 0;
   int32_t loopi;

   for (loopi = 0 ; (LEDS_TOTAL > loopi) && (0 == ret) ; loopi++)
   {
      /* configura led 0 para ser controlado por el usuario */
      triggerHandle = fopen(triggerPath[loopi], "w");

      if (NULL != triggerHandle)
      {
         fwrite("none", sizeof("none"), 1, triggerHandle);
         fclose(triggerHandle);

         /* abre archivo del led */
         ledHandle[loopi] = fopen(ledPath[loopi], "w+");

         if (NULL == ledHandle[loopi])
         {
            ret = -1;
         }
         else
         {
            Leds_msg(loopi, LEDS_MSG_OFF);
         }
      }
      else
      {
         ret = -1;
      }
   }

   return ret;
}

extern void Leds_deinit(void)
{
   uint32_t loopi;

   for (loopi = 0 ; loopi < LEDS_TOTAL ; loopi++)
   {
      fclose(ledHandle[loopi]);
   }
}

extern int32_t Leds_msg(Leds_idEnum id, Leds_msgEnum msg)
{
   char c = '0';
   int32_t ret = 0;

   switch (msg)
   {
      case LEDS_MSG_ON:
         c = '1';
         break;

      case LEDS_MSG_OFF:
         c = '0';
         break;
   }

   if (fwrite(&c, sizeof(c), 1, ledHandle[id]) != 1)
   {
      ret = -1;
   }

   if (fflush(ledHandle[id]) != 0)
   {
      ret = -1;
   }

   return ret;
}



/*==================[end of file]============================================*/
