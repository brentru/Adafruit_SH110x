/*!
 * @file Adafruit_SH110X.h
 *
 * This is part of for Adafruit's SSD1306 library for monochrome
 * OLED displays: http://www.adafruit.com/category/63_98
 *
 * These displays use I2C or SPI to communicate. I2C requires 2 pins
 * (SCL+SDA) and optionally a RESET pin. SPI requires 4 pins (MOSI, SCK,
 * select, data/command) and optionally a reset pin. Hardware SPI or
 * 'bitbang' software SPI are both supported.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries, with
 * contributions from the open source community.
 *
 * BSD license, all text above, and the splash screen header file,
 * must be included in any redistribution.
 *
 */

#ifndef _Adafruit_SH110X_H_
#define _Adafruit_SH110X_H_

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_MonoOLED.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SPIDevice.h>

        /// fit into the SH110X_ naming scheme
#define SH110X_BLACK               0    ///< Draw 'off' pixels
#define SH110X_WHITE               1    ///< Draw 'on' pixels
#define SH110X_INVERSE             2    ///< Invert pixels

#define SH110X_MEMORYMODE          0x20 ///< See datasheet
#define SH110X_COLUMNADDR          0x21 ///< See datasheet
#define SH110X_PAGEADDR            0x22 ///< See datasheet
#define SH110X_SETCONTRAST         0x81 ///< See datasheet
#define SH110X_CHARGEPUMP          0x8D ///< See datasheet
#define SH110X_SEGREMAP            0xA0 ///< See datasheet
#define SH110X_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SH110X_DISPLAYALLON        0xA5 ///< Not currently used
#define SH110X_NORMALDISPLAY       0xA6 ///< See datasheet
#define SH110X_INVERTDISPLAY       0xA7 ///< See datasheet
#define SH110X_SETMULTIPLEX        0xA8 ///< See datasheet
#define SH110X_DISPLAYOFF          0xAE ///< See datasheet
#define SH110X_DISPLAYON           0xAF ///< See datasheet
#define SH110X_SETPAGEADDR         0xB0 ///< Specify page address to load display RAM data to page address register
#define SH110X_COMSCANINC          0xC0 ///< Not currently used
#define SH110X_COMSCANDEC          0xC8 ///< See datasheet
#define SH110X_SETDISPLAYOFFSET    0xD3 ///< See datasheet
#define SH110X_SETDISPLAYCLOCKDIV  0xD5 ///< See datasheet
#define SH110X_SETPRECHARGE        0xD9 ///< See datasheet
#define SH110X_SETCOMPINS          0xDA ///< See datasheet
#define SH110X_SETVCOMDETECT       0xDB ///< See datasheet
#define SH110X_SETDISPSTARTLINE    0xDC ///< Specify Column address to determine the initial display line or COM0.

#define SH110X_SETLOWCOLUMN        0x00 ///< Not currently used
#define SH110X_SETHIGHCOLUMN       0x10 ///< Not currently used
#define SH110X_SETSTARTLINE        0x40 ///< See datasheet

#define SH110X_EXTERNALVCC         0x01 ///< External display voltage source
#define SH110X_SWITCHCAPVCC        0x02 ///< Gen. display voltage from 3.3V

#define SH110X_RIGHT_HORIZONTAL_SCROLL              0x26 ///< Init rt scroll
#define SH110X_LEFT_HORIZONTAL_SCROLL               0x27 ///< Init left scroll
#define SH110X_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SH110X_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL  0x2A ///< Init diag scroll
#define SH110X_DEACTIVATE_SCROLL                    0x2E ///< Stop scroll
#define SH110X_ACTIVATE_SCROLL                      0x2F ///< Start scroll
#define SH110X_SET_VERTICAL_SCROLL_AREA             0xA3 ///< Set scroll range


/*!
    @brief  Class that stores state and functions for interacting with
            SH110X OLED displays.
*/
class Adafruit_SH110X : public Adafruit_MonoOLED {
 public:
  // NEW CONSTRUCTORS -- recommended for new projects
  Adafruit_SH110X(uint16_t w, uint16_t h, TwoWire *twi=&Wire, int8_t rst_pin=-1,
		    uint32_t preclk=400000, uint32_t postclk=100000);
  Adafruit_SH110X(uint16_t w, uint16_t h, int8_t mosi_pin, int8_t sclk_pin,
    int8_t dc_pin, int8_t rst_pin, int8_t cs_pin);
  Adafruit_SH110X(uint16_t w, uint16_t h, SPIClass *spi,
    int8_t dc_pin, int8_t rst_pin, int8_t cs_pin, uint32_t bitrate=8000000UL);

  ~Adafruit_SH110X(void);

  bool      begin(uint8_t switchvcc=SH110X_SWITCHCAPVCC,
                  uint8_t i2caddr=0x3C, boolean reset=true);
  void         display(void);

 private:
};

#endif // _Adafruit_SH110X_H_
