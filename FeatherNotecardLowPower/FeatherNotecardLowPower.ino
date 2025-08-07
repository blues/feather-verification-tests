
#include <Notecard.h>
#include <STM32LowPower.h>

#ifdef USBCON
#error "Please disable USB in order to get correct deep sleep current measurements."
#endif

Notecard notecard;

void setup()
{

    LowPower.begin();

    notecard.begin();

    // Comment out this line to stop the leak.  Note that the bug is that this line, or
    // ANY notecard I/O over I2C, causes a ~300uA leak when in deep sleep. Note that I
    // tried to do just a _noteI2CReset(0x17) through brute force, and this did NOT cause
    // the leak.  Rather, the leak happens only when data is sent to/from the Notecard over I2C.
    NoteReset();

}

void loop()
{

    notecard.end();				// I tried, but this has no effect on stopping the current leak
    Wire.end();					// I tried, but This has no effect on stopping the current leak

    pinMode(USER_BTN, INPUT_ANALOG);
    pinMode(LED_BUILTIN, INPUT_ANALOG);
    pinMode(ENABLE_3V3, INPUT_ANALOG);
    pinMode(DISCHARGE_3V3, INPUT_ANALOG);
    pinMode(A0,INPUT_ANALOG);
    pinMode(A1,INPUT_ANALOG);
    pinMode(A2,INPUT_ANALOG);
    pinMode(A3,INPUT_ANALOG);
    pinMode(A4,INPUT_ANALOG);
    pinMode(A5,INPUT_ANALOG);
    pinMode(5,INPUT_ANALOG);
    pinMode(6,INPUT_ANALOG);
    pinMode(9,INPUT_ANALOG);
    pinMode(10,INPUT_ANALOG);
    pinMode(11,INPUT_ANALOG);
    pinMode(12,INPUT_ANALOG);
    pinMode(13,INPUT_ANALOG);

    LowPower.deepSleep();

}
