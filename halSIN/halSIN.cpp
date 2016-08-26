#include "halSIN.h"

/**изменяемая часть*/
#include "dac.h"
/***/

void confDAC(void)						//функция настройки 12 разрядного ЦАПа под соотв. требования
{
	/**изменяемая часть*/
	{
	//здесь должна происходить инициализация ЦАП, но куб проинициализировал ее уже в начале
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	}
	/***/
}

void setDAC(unsigned short value)		//функция передачу значения в ЦАП
{
	/**изменяемая часть*/
	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1,DAC_ALIGN_12B_R, value);
	/***/
}
