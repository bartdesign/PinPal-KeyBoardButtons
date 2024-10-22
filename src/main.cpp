
#define BOUNCE_WITH_PROMPT_DETECTION
#include "Arduino.h"
#include "USB.h"
#include "USBHIDKeyboard.h"
#include "Bounce2.h"
//#include <Keyboard.h>

// USBHIDKeyboard Keyboard;
USBHIDKeyboard  Keyboard;  // Set up BLE keyboard
Bounce2::Button leftFlipperButton = Bounce2::Button();
Bounce2::Button rightFlipperButton = Bounce2::Button();
Bounce2::Button plungerButton = Bounce2::Button();
Bounce2::Button startButton = Bounce2::Button();
Bounce2::Button leftNudgeButton = Bounce2::Button();
Bounce2::Button rightNudgeButton = Bounce2::Button();

void setup()
{
  // make pin 0 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  // Keyboard.begin();
  // USB.begin();


  Keyboard.begin();
  USB.begin();
  Keyboard.setShiftKeyReports(false);
  

  leftFlipperButton.attach(3, INPUT_PULLUP);
  leftFlipperButton.interval(5);
  leftFlipperButton.setPressedState(LOW);

  rightFlipperButton.attach(4, INPUT_PULLUP);
  rightFlipperButton.interval(5);
  rightFlipperButton.setPressedState(LOW);

  plungerButton.attach(5, INPUT_PULLUP);
  plungerButton.interval(5);
  plungerButton.setPressedState(LOW);

  startButton.attach(6, INPUT_PULLUP);
  startButton.interval(5);
  startButton.setPressedState(LOW);

  leftNudgeButton.attach(11, INPUT_PULLUP);
  leftNudgeButton.interval(5);
  leftNudgeButton.setPressedState(LOW);

  rightNudgeButton.attach(10, INPUT_PULLUP);
  rightNudgeButton.interval(5);
  rightNudgeButton.setPressedState(LOW);
}

void loop()
{

    leftFlipperButton.update();
    rightFlipperButton.update();
    plungerButton.update();
    startButton.update();
    leftNudgeButton.update();
    rightNudgeButton.update();

    if (leftFlipperButton.pressed())
    {
      Keyboard.pressRaw(HID_KEY_SHIFT_LEFT); // Left Flipper
    }
    if (leftFlipperButton.released())
    {
      Keyboard.releaseRaw(HID_KEY_SHIFT_LEFT); // Left Flipper
    }

    if (rightFlipperButton.pressed())
    {
      Keyboard.pressRaw(HID_KEY_SHIFT_RIGHT); // Right Flipper
    }
    if (rightFlipperButton.released())
    {
      Keyboard.releaseRaw(HID_KEY_SHIFT_RIGHT); // Right Flipper
    }
    if (plungerButton.pressed())
    {
      Keyboard.press(KEY_RETURN); // Plunger
      Serial.println("PLUNGER");
    }
    if (plungerButton.released())
    {
      Keyboard.release(KEY_RETURN); // Plunger
    }
    if (startButton.pressed())
    {
      Keyboard.press(0x31); // Start game
    }
    if (startButton.released())
    {
      Keyboard.release(0x31); // Start game
    }

    if (leftNudgeButton.pressed())
    {
      Keyboard.press('z'); // Start game
    }
    if (leftNudgeButton.released())
    {
      Keyboard.release('z'); // Start game
    }

    if (rightNudgeButton.pressed())
    {
      Keyboard.press('/'); // Start game
    }
    if (rightNudgeButton.released())
    {
      Keyboard.release('/'); // Start game
    }
}
