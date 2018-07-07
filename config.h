// do we wait for a gps location fix before transmitting ?
#undef FORCE_GPSLOCK

// do we want OTAA or ABP mode ? (see below for details)
#undef MODE_OTAA

// which board type
#undef BOARD_HELTEC
#define BOARD_TTGO

// restrict transmission to only this channel
#undef SINGLE_CHANNEL 0

// Schedule TX every this many seconds 
// (might become longer due to duty cycle limitations).
const unsigned TX_INTERVAL = 30;

// if we cant get a GPS lock, how many wifi APs info to send instead
#define WIFI_LIST_LEN 3

// Force use of a specific spreading factor
#define SINGLE_SF DR_SF7



/* 
 *  The following values are all obtained from the TTN Console
 *  when you register the device.
 *  
 *  Some values are common to all of your devices within an 
 *  'application' and others are different for each device.
 *  
 *  http://console.thethingsnetwork.org
 */

// Device EUI (lsb order) - different on every device
// make it up yourself, or hit the 'random' button
static const PROGMEM u1_t DEVEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// Application EUI (lsb order) - Common to all devices
static const PROGMEM u1_t APPEUI[8]= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


#ifdef MODE_OTAA
/* Activation Mode: OTAA
 *  
 * Lots of values will get automatically negotiated
 * including best Spreading Factor and channels to use
 * but requires a response from the things network at start of session
 */

// App Key (msb order) - 
static const PROGMEM u1_t APPKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#else

/* Activation Mode: ABP
 *  
 *  Faster to connect as no handshake required on first transmission
 *  (so much easier for testing, and stuff that powercycles a lot)
 */

// Device address (DevAddr) (msb order, mushed into one value)
static const u4_t DEVADDR = 0x2601185E;

// network session key (msb order)
static const PROGMEM u1_t NWKSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

// application session key (msb order)
static const u1_t PROGMEM APPSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#endif


/*
 * Board specific hardware connection details
 */

#ifdef BOARD_HELTEC   
//  Heltec LoRa 32 Board 
#define GPS_RX 12
#define GPS_TX 13

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

// LoRa radio Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 14,
    .dio = {26, 33, 32},
};
#endif // end of heltec board

#ifdef BOARD_TTGO   
//  TTGO LoRa board
#define GPS_RX 0
#define GPS_TX 4

// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 22, /* data=*/ 21);

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 14,
    .dio = {26, LMIC_UNUSED_PIN, LMIC_UNUSED_PIN},
};

#endif // end of TTGO board def




