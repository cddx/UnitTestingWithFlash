#include "build/temp/_test_config.c"
#include "src/config.h"
#include "D:/UnitTestingWithFlash/flash/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void)

{

}

void tearDown(void)

{

}



void test_config(void)

{

    CONFIG_T cfg;

    cfg.flash_type = 0xAA;

    cfg.firmware_version = 0x1234;

    strcpy(cfg.vendor, "cddx");

    config_set(&cfg);

}
