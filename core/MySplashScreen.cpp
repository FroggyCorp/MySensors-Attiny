/*
* The MySensors Arduino library handles the wireless radio link and protocol
* between your home built sensors/actuators and HA controller of choice.
* The sensors forms a self healing radio network with optional repeaters. Each
* repeater and gateway builds a routing tables in EEPROM which keeps track of the
* network topology allowing messages to be routed to nodes.
*
* Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
* Copyright (C) 2013-2022 Sensnology AB
* Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
*
* Documentation: http://www.mysensors.org
* Support Forum: http://forum.mysensors.org
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*/

#include "MySensorsCore.h"

void displaySplashScreen(void)
{
#if !defined(MY_DISABLED_SERIAL) && defined(MY_DEBUGDEVICE)
	static const uint8_t splashScreen[] PROGMEM = {
		0x20, 0x7C, 0x5F, 0x5c, 0x2F, 0x60, 0x2C, 0x0A, // substitution matrix
		0x07, 0x02, 0x20, 0x02, 0x20, 0xB2, 0x87, 0x10, 0x03, 0x40, 0x01, 0x20, 0x00, 0x24, 0x02, 0x22,
		0x10, 0x02, 0x22, 0x02, 0x02, 0x20, 0x02, 0x22, 0x00, 0x22, 0x20, 0x02, 0x02, 0x20, 0x22, 0x27,
		0x10, 0x13, 0x41, 0x01, 0x01, 0x01, 0x03, 0x22, 0x20, 0x30, 0x40, 0x20, 0x30, 0x52, 0x03, 0x40,
		0x22, 0x14, 0x02, 0x03, 0x10, 0x52, 0x24, 0x02, 0x21, 0x71, 0x01, 0x00, 0x10, 0x10, 0x12, 0x10,
		0x12, 0x22, 0x10, 0x10, 0x02, 0x24, 0x01, 0x01, 0x03, 0x22, 0x03, 0x00, 0x20, 0x01, 0x01, 0x00,
		0x32, 0x20, 0x37, 0x12, 0x10, 0x01, 0x21, 0x32, 0x26, 0x01, 0x28, 0x40, 0x32, 0x22, 0x12, 0x10,
		0x12, 0x12, 0x22, 0x43, 0x22, 0x24, 0x12, 0x10, 0x01, 0x22, 0x24, 0x70, 0xC1, 0x22, 0x24,
		0x0F, 0x0F
	};
	uint8_t pos = 16;
	char display = 0;
	while (pos<sizeof(splashScreen)*2) {
		uint8_t val = pgm_read_byte(&(splashScreen[pos>>1]));
		val = (pos % 2) ? val & 0xF : val >> 4;
		pos++;
		if (val<8) {
			display = pgm_read_byte(&(splashScreen[val]));
		}
		const uint8_t rep = val > 7 ? val - 5 : 1;
		for (uint8_t c = 0; c<rep; c++) {
			MY_DEBUGDEVICE.print(display);
		}
	}
	MY_DEBUGDEVICE.println(F(MYSENSORS_LIBRARY_VERSION "\n"));
#endif
}
