/*
  FeatherDebug_BringUp.ino - Feather Debug Bring-Up Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 26 March 2026
  by Zachary J. Fields
*/

// the setup function runs once when you press reset or power the board
void setup() {
  ::pinMode(LED_BUILTIN, OUTPUT);
  ::pinMode(USER_BTN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  ::digitalWrite(LED_BUILTIN, ::digitalRead(USER_BTN));
}
