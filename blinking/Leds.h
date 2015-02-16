/* ==========================================================================
 * Autores:
 * Gustavo Muro gustmuro@gmail.com
 * Luciano Diamand lucianodiamand@yahoo.com
 *===========================================================================*/


#ifndef LEDS_H_
#define LEDS_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

typedef enum
{
   LEDS_ID_0 = 0,
   LEDS_ID_1,
   LEDS_ID_2,
   LEDS_ID_3,
   LEDS_TOTAL
}Leds_idEnum;

typedef enum
{
   LEDS_MSG_OFF = 0,
   LEDS_MSG_ON,
}Leds_msgEnum;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** \brief Envía mensaje a led
**
** Esta función envia un mensaje al led indicado.
**
** \param[in] id Identificación del led
** \param[in] msg Mensaje
** \return  0 si no hubo error
**          -1 si hubo un error
**/
extern int32_t Leds_msg(Leds_idEnum id, Leds_msgEnum msg);

/** \brief Ininicalización de led
**
** Inicializa los led para ser controlados por el usuario.
** Los inicializa todos apagados.
**
** \return  0 si no hubo error
**          -1 si hubo un error
**/
extern int32_t Leds_init(void);

/** \brief Libera los leds
**
** Cierra los archivos asociados a los leds.
**
** \return
**/
extern void Leds_deinit(void);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef LEDS_H_ */
