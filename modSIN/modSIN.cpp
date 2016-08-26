#include "modSIN.h"

	
static unsigned short sin_value[360];

SIN_cl::SIN_cl(unsigned char new_freq)
{
	if((new_freq != 1) || (new_freq != 10) || (new_freq != 20) || (new_freq != 50))
	{
		err = 1;
		return;
	}
	else 
	{
		SIN_cl::freq = new_freq;
		SIN_cl::counter = 0;
		SIN_cl::err = 0;
		for(unsigned short i = 0; i < 360; i++)
		{
			sin_value[i] = (unsigned short) ((sin(i*(3.14159265359/180)) + 1)*4095/2); 		
		}
		confDAC();
		SIN_cl::init_flg = 1;
	}
}

SIN_cl::~SIN_cl()
{
	SIN_cl::counter = 0;
	SIN_cl::err = 0;
	SIN_cl::freq = 0;
	setDAC(0);
	SIN_cl::init_flg = 0;
}

unsigned char SIN_cl::SIN_set_freq(unsigned char new_freq)
{
	if(SIN_cl::init_flg)
	{
		if((new_freq != 1) || (new_freq != 10) || (new_freq != 20) || (new_freq != 50))
		{
			SIN_cl::err = 1;
		}
		else
		{
			SIN_cl::freq = new_freq;
			SIN_cl::err = 0;
		}
	}
	else 
	{
		SIN_cl::err = 1;
	}
	return SIN_cl::err;
}

unsigned char SIN_cl::getErr(void)
{
	return SIN_cl::err;
}

void SIN_cl::Run(void)
{
	static unsigned short i = 0;
	
	if(SIN_cl::init_flg)
	{
		switch(SIN_cl::freq)
		{
			case 1:
				if(SIN_cl::counter == 99)
				{
					setDAC(sin_value[i]);
					i++;
					SIN_cl::counter = 0;
				}
				else 
					SIN_cl::counter++;
				break;
			case 10:
				if(SIN_cl::counter == 9)
				{
					setDAC(sin_value[i]);
					i++;
					SIN_cl::counter = 0;
				}
				else 
					SIN_cl::counter++;
				break;
			case 20:
				if(SIN_cl::counter == 4)
				{
					setDAC(sin_value[i]);
					i++;
					SIN_cl::counter = 0;
				}
				else 
					SIN_cl::counter++;
				break;
			case 50:
				if(SIN_cl::counter == 1)
				{
					setDAC(sin_value[i]);
					i++;
					SIN_cl::counter = 0;
				}
				else 
					SIN_cl::counter++;
				break;
			default:
				break;
		}
		if(i == 360)
			i = 0;
	}
}

