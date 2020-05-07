#include "build/temp/_test_flash.c"
#include "build/test/mocks/mock_flash.h"
#include "src/config.h"
#include "D:/flash/vendor/ceedling/vendor/unity/src/unity.h"




uint8_t simulated_flash[4096];



static void mock_read(uint8_t *dest_buffer, uint8_t *source_address, size_t count, int num_calls)

{



    if (source_address >= (uint8_t *)4096)

    {

        UnityFail( (("invalid flash memory address")), (UNITY_UINT)(15));

    }



    memcpy(dest_buffer, &simulated_flash[(int)source_address], count);

}



static void mock_write(uint8_t *source_data, uint8_t *target_address, size_t count, int num_calls)

{

    if (target_address >= (uint8_t *)4096)

    {

        UnityFail( (("invalid flash memory address")), (UNITY_UINT)(25));

    }

    memcpy(&simulated_flash[(int)target_address], source_data, count);

}



static void config_load(config_t *cfg)

{

    flash_read((uint8_t *)cfg, (4096 - 1), 1);

}



void setUp(void)

{

    flash_read_Stub(mock_read);

    flash_write_Stub(mock_write);

}



void tearDown(void)

{

}



void test_write_read(void)

{

    uint8_t write_data[100];

    for (int i = 1; i < 100; i++)

    {

        write_data[i] = i;

    }

    uint8_t *flash_address = (uint8_t *)0;

    flash_write(write_data, flash_address, 100);



    uint8_t read_data[100];

    flash_read(&read_data, flash_address, 100);

    UnityAssertEqualIntArray(( const void*)((write_data)), ( const void*)((read_data)), (UNITY_UINT32)((100)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}

void test_when_flash_is_erased_then_the_config_load_count_is_reset(void)

{



    memset(simulated_flash, 0xff, 4096);

    simulated_flash[4096 - 1] = 0x01;





    config_t config = {0};



    config_load(&config);





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0x01)), (UNITY_INT)(UNITY_INT32)((config.load_count)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX32);

}
