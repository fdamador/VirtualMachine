
#include <vm_arduino.h>

#ifndef USE_SD_XCP
const unsigned char xcp_code[] =
{
0x1C,0x15,0x00,0x00, 0x01,0x00,0x1C,0x15, 0x01,0x00,0x01,0x00, 0x1C,0x15,0x02,0x00,
0x02,0x00,0x00,0x1C, 0x16,0x00,0x00,0x08, 0x01,0x1C,0x16,0x00, 0x00,0x34,0x01,0x1C,
0x1D,0x19,0x00,0x1C, 0x15,0x0C,0x00,0x04, 0x00,0x00,0x00,0x00, 0x1C,0x15,0x01,0x00,
0x01,0x00,0x1C,0x15, 0x08,0x00,0x04,0x00, 0x00,0x00,0x00,0x1C, 0x13,0x05,0x10,0x02,
0x00,0x00,0x00,0x1C, 0x02,0x02,0x00,0x60, 0x00,0x1C,0x15,0x01, 0x00,0x01,0x00,0x1C,
0x15,0x08,0x00,0x04, 0x00,0x00,0x00,0x00, 0x1C,0x17,0x0C,0x00, 0x1C,0x00,0x94,0x00,
0x05,0x10,0x02,0x00, 0x01,0x00,0x1C,0x02, 0x02,0x00,0x94,0x00, 0x1C,0x17,0x10,0x00,
0x02,0x0B,0x08,0x00, 0x10,0x00,0x0C,0x00, 0x11,0x0B,0x02,0x00, 0x08,0x00,0x04,0x00,
0x1C,0x02,0x02,0x00, 0x94,0x00,0x1C,0x15, 0x01,0x00,0x01,0x01, 0x1C,0x1F,0x08,0x00,
0x04,0x00,0x04,0x00, 0x1C,0x13,0x1C,0x15, 0x03,0x00,0x01,0x00, 0x1C,0x15,0x04,0x00,
0x01,0x00,0x1C,0x15, 0x05,0x00,0x01,0x00, 0x1C,0x15,0x06,0x00, 0x01,0x00,0x1C,0x13,
0x1C,0x02,0x01,0x00, 0xCC,0x00,0x05,0x10, 0x08,0x00,0x05,0x00, 0x1C,0x02,0x08,0x00,
0xCC,0x00,0x1C,0x15, 0x07,0x00,0x01,0x01, 0x1C,0x00,0xD2,0x00, 0x1C,0x15,0x07,0x00,
0x01,0x00,0x1C,0x02, 0x07,0x00,0xE4,0x00, 0x1C,0x02,0x00,0x00, 0xE4,0x00,0x05,0x10,
0x06,0x00,0x06,0x00, 0x1C,0x02,0x02,0x00, 0xF0,0x00,0x1C,0x15, 0x06,0x00,0x01,0x00,
0x1C,0x1F,0x03,0x00, 0x06,0x00,0x01,0x00, 0x05,0x10,0x04,0x00, 0x03,0x00,0x1C,0x1F,
0x05,0x00,0x01,0x00, 0x01,0x00,0x1C,0x13, 0x1C,0x16,0x38,0x00, 0x96,0x00,0x1C,0x16,
0x20,0x00,0x23,0x00, 0x1C,0x16,0x08,0x00, 0x23,0x00,0x1C,0x15, 0x04,0x00,0x01,0x00,
0x1C,0x15,0x05,0x00, 0x01,0x00,0x1C,0x15, 0x06,0x00,0x01,0x00, 0x1C,0x15,0x07,0x00,
0x01,0x00,0x1C,0x13, 0x05,0x10,0x08,0x00, 0x06,0x00,0x1C,0x15, 0x0C,0x00,0x04,0xE8,
0x03,0x00,0x00,0x1C, 0x16,0x08,0x00,0x3D, 0x00,0x1C,0x1F,0x05, 0x00,0x09,0x00,0x01,
0x00,0x1C,0x1F,0x20, 0x00,0x05,0x00,0x01, 0x00,0x1C,0x15,0x24, 0x00,0x04,0xD0,0x07,
0x00,0x00,0x1C,0x16, 0x20,0x00,0x3D,0x00, 0x1C,0x1F,0x06,0x00, 0x21,0x00,0x01,0x00,
0x1C,0x15,0x38,0x00, 0x01,0x01,0x1C,0x1F, 0x39,0x00,0x00,0x00, 0x01,0x00,0x1C,0x15,
0x3A,0x00,0x01,0x00, 0x1C,0x16,0x38,0x00, 0xB0,0x00,0x1C,0x1F, 0x07,0x00,0x3B,0x00,
0x01,0x00,0x08,0x20, 0x04,0x00,0x05,0x00, 0x07,0x00,0x1C,0x1F, 0x01,0x00,0x04,0x00,
0x01,0x00,0x1C,0x13
};
#endif

VMArduino cpdev;

#define LEDPIN    2 //LED_BUILTIN
#define BUTTONPIN 6

// Addresses of CPDev variables
#define ONOFF_ADDRESS 0
#define LIGHT_ADDRESS 1

void setup()
{
  Serial.begin(9600);
  while(!Serial);

#ifdef USE_SD_XCP
  if (cpdev.VMP_LoadProgramAndData(L"blink.xcp") != 0)    // note that SD library supports short (8+3) filenames only
#else
  if (cpdev.VMP_LoadProgramFromArray(xcp_code) != 0)
#endif  
  {
    Serial.print("Cannot load program into VM");
    while (1);
  }
  else
  {
    cpdev.task_cycle = 100;
    cpdev.WM_Initialize(WM_MODE_FIRST_START | WM_MODE_NORMAL);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(1, INPUT_PULLUP);
  }
}

void loop()
{
  WM_BYTE light, button;

  if (cpdev.bRunMode)
  {
    button = digitalRead(BUTTONPIN);  // or set to 1 if you dont have a pushbutton
    cpdev.WM_SetData(ONOFF_ADDRESS, sizeof(button), &button);
    cpdev.WM_RunCycle();
    cpdev.WM_GetData(LIGHT_ADDRESS, sizeof(light), &light);
    digitalWrite(LEDPIN, light);
  }
  else
    cpdev.WM_Shutdown();

}
