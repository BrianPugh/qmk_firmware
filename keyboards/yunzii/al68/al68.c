// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "uart.h"
#include "common/smart_ble.h"
#include "al68.h"

void keyboard_pre_init_kb(void) {
    // boardInit() sets BKP->DR10 = RTC_BOOTLOADER_FLAG, which causes the bootloader
    // to stay in DFU mode on next boot. Clear it so normal reboot works.
    // See: platforms/chibios/boards/STM32_F103_STM32DUINO/board/board.c
    BKP->DR10 = 0;

    AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk);
    AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_DISABLE; // disable JTAG (GD32 different to STM32)

    gpio_set_pin_output(A8);
    gpio_write_pin_high(A8); // ENABLE USB

    uart_init(460800);
    wait_ms(400);
}

// Override bootloader_jump to set the magic flag so bootloader stays in DFU mode.
void bootloader_jump(void) {
    BKP->DR10 = RTC_BOOTLOADER_FLAG;
    NVIC_SystemReset();
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        if ((keycode >= KC_BLE1) && (keycode <= KC_24G)) {
            wireless_start(keycode - KC_USB);
            return false;
        } else if (keycode == KC_USB) {
            wireless_stop();
            return false;
        }
    }
    return process_record_user(keycode, record);
}
