TEST_INFO("Mapper RAM Mirroring\n")
TEST_CODE(SMS_Mapper subject(1);
        subject[0xc001] = 1;
)
TEST_CONDITION(subject[0xe001] == 1)