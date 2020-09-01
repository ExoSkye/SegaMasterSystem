TEST_INFO("Mapper RAM Mirroring check 0xc001 to 0xe001\n")
TEST_CODE(SMS_Mapper subject(1);
        subject[0xc001] = 1;
)
TEST_CONDITION(subject[0xe001] == 1)
TEST_INFO("Mapper RAM Mirroring check 0xe001 to 0xc001\n")
TEST_CODE(SMS_Mapper subject(1);
subject[0xe001] = 1;
)
TEST_CONDITION(subject[0xc001] == 1)
TEST_INFO("Z80 double register support\n")
TEST_CODE(SMS_Z80 z80;
bool success1 = true;
z80.r_B = 64;
z80.r_C = 64;
success1 = success1 && (z80.r_BC() == 16448);
z80.r_HL++;
success1 = success1 && (z80.r_HL() == 1)  ;
z80.r_HL--;
success1 = success1 && (z80.r_HL() == 0)  ;
        )
TEST_CONDITION(success1)
TEST_INFO("Mapper out of range support\n")
TEST_CODE(SMS_Mapper map(1);
bool caught = false;
try {
map[0x10000] = 0;
}
catch (const std::out_of_range& e) {
    caught = true;
}
)
TEST_CONDITION(caught)
TEST_INFO("After init the ROM is all zeros (through SMS_Mapper)\n")
TEST_CODE(SMS_Mapper map(1);)
TEST_CONDITION(map[0] == 0)
TEST_INFO("After init the ROM is all zeros (through SMS_ROM)\n")
TEST_CODE(SMS_ROM map(1);)
TEST_CONDITION(map[0] == 0)
TEST_INFO("After init the RAM is all zeros (through SMS_Mapper)\n")
TEST_CODE(SMS_Mapper mapram(1);
bool allzero = true;
for (int i = 0xc000; i < 0xe000; i++) {
    if (mapram[i] != 0) {
        allzero = false;
    }
})
TEST_CONDITION(allzero)
TEST_INFO("After init the RAM is all zeros (through SMS_RAM)\n")
TEST_CODE(SMS_RAM ram;
bool allzero1 = true;
for (int i = 0; i < 0x2000; i++) {
if (ram[i] != 0) {
allzero1 = false;
}
})
TEST_CONDITION(allzero1)