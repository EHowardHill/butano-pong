/*
 * Copyright (c) 2020-2022 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#include "../include/bn_hw_sram.h"

#include "bn_config_sram.h"
#include "../include/bn_hw_tonc.h"

namespace bn::hw::sram
{

static_assert(BN_CFG_SRAM_WAIT_STATE == BN_SRAM_WAIT_STATE_4 ||
        BN_CFG_SRAM_WAIT_STATE == BN_SRAM_WAIT_STATE_3 ||
        BN_CFG_SRAM_WAIT_STATE == BN_SRAM_WAIT_STATE_2 ||
        BN_CFG_SRAM_WAIT_STATE == BN_SRAM_WAIT_STATE_8);

namespace
{
    // https://forum.gbadev.org/viewtopic.php?f=4&t=2825
    alignas(int) __attribute__((used)) const char save_type[] = "SRAM_V113";
}

const char* init()
{
    BIT_SET(REG_WAITCNT_NV, BN_CFG_SRAM_WAIT_STATE);

    return save_type;
}

}
