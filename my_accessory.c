#include <homekit/homekit.h>
#include <homekit/characteristics.h>

void my_accessory_identify(homekit_value_t _value) {
	printf("accessory identify\n");
}


homekit_characteristic_t cha_switch1_on = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch2_on = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch3_on = HOMEKIT_CHARACTERISTIC_(ON, false);
homekit_characteristic_t cha_switch4_on = HOMEKIT_CHARACTERISTIC_(ON, false);


homekit_characteristic_t cha_name = HOMEKIT_CHARACTERISTIC_(NAME, "Bedroom Control");

homekit_accessory_t *accessories[] = {


    HOMEKIT_ACCESSORY(.id=1, .category=homekit_accessory_category_switch, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch1"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Apple"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
            HOMEKIT_CHARACTERISTIC(MODEL, "Bedroom Control"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "10.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
    HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]){
      &cha_switch1_on,
      &cha_name,
      NULL
    }),
        NULL
    }),



    HOMEKIT_ACCESSORY(.id=2, .category=homekit_accessory_category_switch, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch2"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Apple"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
            HOMEKIT_CHARACTERISTIC(MODEL, "Bedroom Control"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "10.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
    HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]){
      &cha_switch2_on,
      &cha_name,
      NULL
    }),
        NULL
    }),



    HOMEKIT_ACCESSORY(.id=3, .category=homekit_accessory_category_switch, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch3"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Apple"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
            HOMEKIT_CHARACTERISTIC(MODEL, "Bedroom Control"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "10.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
    HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]){
      &cha_switch3_on,
      &cha_name,
      NULL
    }),
        NULL
    }),

    
    HOMEKIT_ACCESSORY(.id=4, .category=homekit_accessory_category_switch, .services=(homekit_service_t*[]) {
        HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]) {
            HOMEKIT_CHARACTERISTIC(NAME, "Switch4"),
            HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Apple"),
            HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
            HOMEKIT_CHARACTERISTIC(MODEL, "Bedroom Control"),
            HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "10.0"),
            HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
            NULL
        }),
    HOMEKIT_SERVICE(SWITCH, .primary=true, .characteristics=(homekit_characteristic_t*[]){
      &cha_switch4_on,
      &cha_name,
      NULL
    }),
        NULL
    }),
    
    NULL
};

homekit_server_config_t config = {
		.accessories = accessories,
		.password = "200-23-510"
};
