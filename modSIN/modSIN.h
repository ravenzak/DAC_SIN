#ifndef MODSIN_H__
#define MODSIN_H__

#include <math.h>
#include "halSIN.h"

class SIN_cl
{
	public:

		SIN_cl();		//конструктор
		SIN_cl(unsigned char new_freq);		//конструктор
		~SIN_cl();		//деструктор
	
	unsigned char SIN_set_freq(unsigned char new_freq);		//функция установки частоты
	void Run(void);											//функция, вызываемая для работы модуля. Этот метод должен вызываться с частотой 100Гц.
	unsigned char getErr(void);
		
	private:
		unsigned char freq;
		unsigned short counter;
		unsigned char err;
		unsigned char init_flg;
		
};


#endif
