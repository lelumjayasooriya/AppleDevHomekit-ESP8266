#include <Arduino.h>
#include <arduino_homekit_server.h>
#include "wifi_info.h"

#define LOG_D(fmt, ...)   printf_P(PSTR(fmt "\n") , ##__VA_ARGS__);


#define S1 33
#define R1 0

#define S2 35
#define R2 2

#define S3 34
#define R3 4

#define S4 36
#define R4 5

void setup() {
  Serial.begin(115200);
  wifi_connect(); 
  my_homekit_setup();
}

void loop() {
  my_homekit_loop();
  delay(10);
}


extern "C" homekit_server_config_t config;
extern "C" homekit_characteristic_t cha_switch1_on;
extern "C" homekit_characteristic_t cha_switch2_on;
extern "C" homekit_characteristic_t cha_switch3_on;
extern "C" homekit_characteristic_t cha_switch4_on;

static uint32_t next_heap_millis = 0;



void cha_switch1_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch1_on.value.bool_value = on;  //sync the value
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(R1, on ? LOW : HIGH);
}



void cha_switch2_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch2_on.value.bool_value = on;  //sync the value
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(R2, on ? LOW : HIGH);
}


void cha_switch3_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch3_on.value.bool_value = on;  //sync the value
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(R3, on ? LOW : HIGH);
}


void cha_switch4_on_setter(const homekit_value_t value) {
  bool on = value.bool_value;
  cha_switch4_on.value.bool_value = on;  //sync the value
  LOG_D("Switch: %s", on ? "ON" : "OFF");
  digitalWrite(R4, on ? LOW : HIGH);
}

void my_homekit_setup()
{

 pinMode(R1, OUTPUT); 
  digitalWrite(R1, HIGH);
  
  pinMode(R2, OUTPUT);
  digitalWrite(R2, HIGH);
  
  pinMode(R3, OUTPUT);
  digitalWrite(R3, HIGH);
  
   pinMode(R4, OUTPUT);
  digitalWrite(R4, HIGH);



  cha_switch1_on.setter = cha_switch1_on_setter;
  cha_switch2_on.setter = cha_switch2_on_setter;
  cha_switch3_on.setter = cha_switch3_on_setter;
  cha_switch4_on.setter = cha_switch4_on_setter;

  arduino_homekit_setup(&config);

}


void my_homekit_loop() {
  arduino_homekit_loop();
  const uint32_t t = millis();
  if (t > next_heap_millis) {
    // show heap info every 5 seconds
    next_heap_millis = t + 5 * 1000;
    LOG_D("Free heap: %d, HomeKit clients: %d",
          ESP.getFreeHeap(), arduino_homekit_connected_clients_count());

  }

}
