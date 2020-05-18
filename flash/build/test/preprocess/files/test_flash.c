#include "build/temp/_test_flash.c"
#include "build/test/mocks/mock_flash.h"
#include "D:/UnitTestingWithFlash/flash/vendor/ceedling/vendor/unity/src/unity.h"






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





void setUp(void)

{

    flash_write_Stub(mock_write);

    flash_read_Stub(mock_read);

}



void tearDown(void)

{

}



void test_write_read(void)

{



    UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT) ((4096)), (UNITY_INT) ((4096)), UNITY_SMALLER_OR_EQUAL, (("TEST_FLASH_SIZE should less FLASH_MAX_SIZE")), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);



    uint8_t write_data[4096];

    for (int i = 0; i < 4096; i++)

    {

        write_data[i] = i;

    }

    uint8_t *flash_address = (uint8_t *)0;

    flash_write(write_data, flash_address, 4096);



    uint8_t read_data[4096];

    flash_read(&read_data, flash_address, 4096);



    UnityAssertEqualIntArray(( const void*)((write_data)), ( const void*)((read_data)), (UNITY_UINT32)((4096)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}
