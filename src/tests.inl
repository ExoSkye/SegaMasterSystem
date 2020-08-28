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
z80.r_B = 64;
z80.r_C = 64;
)
TEST_CONDITION(z80.BC() == 16448)