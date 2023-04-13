MySensors with Attiny support (v0.1). "Fork" from [MySensors Library v2.4.0-alpha.](https://www.mysensors.org/)


# What is not working :
- Interrupt

# What should work :
- Any Attiny
- Optiboot (save 1.5KB)
- no bootloader

# How to make it work :

1. Take an arduino (UNO/Nano/...), put the sketch Examples/arduinoISP/arduinoISP

2. Connect the arduino to the Attiny85 : (https://www.instructables.com/How-to-Program-an-Attiny85-From-an-Arduino-Uno/)

| Attiny | Attiny (Pin number) | (Pin number) Arduino |
| --- | --- | --- |
| Reset/PB5 | (1) | (10) |
| PB3 | (2) | - |
| PB4 | (3) | - |  
| GND | (4) | GND |
| MOSI/PB0 | (5) | (11) |
| MISO/PB1 | (6) | (12) |
| SCK/PB2 | (7) | (13) |
| VCC | (8) | 5V |

Add a Capacitor (10uF) on arduino beetween ground & reset.

3. Add Attiny85 board on Arduino IDE

4. (Optional) Try it with blink test & adding a LED

5. Download AVRDUDESS (https://github.com/ZakKemble/AVRDUDESS)

6.
- 6a Download Micronucleus (https://github.com/micronucleus/micronucleus)
- 6b Download Optiboot
- 6c Only use arduino as ISP

7. Launch AVRDUDESS and put the bootloader, change fuse if needed.

8. Connect HW-260 card or same, put Attiny85, install the drivers (W10) with zadig from micronucleus directory

/!\ The Attiny85 need to be at least at 8Mhz /!\
/!\ Don't remove writing capacity /!\
/!\ Don't put external clock /!\

9. Connect RFM69 to Attiny85 :

**RFM69 don't support 5V, use convertor**

| Attiny | Attiny (Pin number) | RFM69 |
| --- | --- | --- |
| SS/PB3 | (2) | SCK |
| MOSI/PB1 | (6) | MOSI |
| MISO/PB0 | (5) | MISO |
| SCK/PB2 | (7) | SCK |

/!\ In documentation, PB1 = MISO & PB0 = MOSI, Spence Konde explain it here : (ATTinyCore/hardware/avr/1.5.2/variants/tinyX5pins_arduino.h)
"This part has a USI, not an SPI module. Accordingly, there is no MISO/MOSI in hardware. There's a DI and a DO. When the chip is used as master, DI is used as MISO, DO is MOSI; the defines here specify the pins for master mode, as SPI master is much more commonly used in Arduino-land than SPI slave, and these defines are required for compatibility. Be aware of this when using the USI SPI fucntionality (and also, be aware that the MISO and MOSI markings on the pinout diagram in the datasheet are for ISP programming, where the chip is a slave. The pinout diagram included with this core attempts to clarify this)"


10. Use Arduino IDE to send sketch, select Attiny85 (Micronucleus) board & Micronucleus as programmer
/!\ Actually (27/03/2023), Arduino IDE 2.0.4 don't work, looks like it need some update from Attinycore (1.5.2), use the 1.8.x version
Enjoy

# In case of, to burn the fuse :
https://www.best-microcontroller-projects.com/unbrick-attiny.html

# Pseudo Versionning :
V0.1 :
- Passive Node with RFM69 on Attiny85 @ 8Mhz with [micronucleus](https://github.com/micronucleus/micronucleus) & [tinySPI](https://github.com/JChristensen/tinySPI)

![I don't know what i'm doing](http://edutechniques.com/wp-content/uploads/2019/09/e8df23cc-9bfe-4776-ae54-22d67d47f15a-6442-000008859e923c5f.png)
