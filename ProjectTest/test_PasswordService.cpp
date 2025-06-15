
#include "../Project/services/PasswordServices.h"
#include <gtest/gtest.h>

TEST(PasswordServiceTest, ValidPassword) {
  std::string valid = "Teste123!";
  EXPECT_TRUE(PasswordService::isValidPassword(valid));
}

TEST(PasswordServiceTest, InvalidPasswords) {
  EXPECT_FALSE(PasswordService::isValidPassword("short"));
  EXPECT_FALSE(PasswordService::isValidPassword("semDigito!"));
  EXPECT_FALSE(PasswordService::isValidPassword("12345678"));
  EXPECT_FALSE(PasswordService::isValidPassword("SemEspecial1"));
}

TEST(PasswordServiceTest, PasswordRequirementsMessage) {
  std::string msg = PasswordService::getPasswordRequirements();
  EXPECT_NE(msg.find("least"), std::string::npos);
}

TEST(PasswordServiceTest, HashConsistency) {
  std::string pw = "Segura123!";
  std::string hash1 = PasswordService::hashPassword(pw);
  std::string hash2 = PasswordService::hashPassword(pw);
  EXPECT_EQ(hash1, hash2);
  EXPECT_FALSE(hash1.empty());
}

TEST(PasswordServiceTest, VerifyPasswordCorrect) {
  std::string pw = "OutraSegura123!";
  std::string hash = PasswordService::hashPassword(pw);
  EXPECT_TRUE(PasswordService::verifyPassword(pw, hash));
}

TEST(PasswordServiceTest, VerifyPasswordIncorrect) {
  std::string hash = PasswordService::hashPassword("Correta123!");
  EXPECT_FALSE(PasswordService::verifyPassword("Errada321!", hash));
}
