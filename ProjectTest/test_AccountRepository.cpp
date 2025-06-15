
#include "../Project/data/AccountRepository.h"
#include <cstdio> // remove()
#include <gtest/gtest.h>

const std::string testFile = "test_accounts.json";

class AccountRepositoryTest : public ::testing::Test {
protected:
  void TearDown() override { std::remove(testFile.c_str()); }
};

TEST_F(AccountRepositoryTest, SaveAndLoadAccount) {
  AccountRepository repo(testFile);
  BankAccount acc(1111, 250.0, 30, "Ana", "Rua 1", "pw123");
  EXPECT_TRUE(repo.saveAccount(acc));

  BankAccount loaded = repo.loadAccount(1111);
  EXPECT_EQ(loaded.getAccountNumber(), 1111);
  EXPECT_EQ(loaded.getBalance(), 250.0);
  EXPECT_EQ(loaded.getName(), "Ana");
}

TEST_F(AccountRepositoryTest, DeleteAccount) {
  AccountRepository repo(testFile);
  BankAccount acc(2222, 100.0, 40, "Luis", "Rua 2", "pw");
  repo.saveAccount(acc);
  EXPECT_TRUE(repo.deleteAccount(2222));
  EXPECT_FALSE(repo.accountExists(2222));
}

TEST_F(AccountRepositoryTest, AccountExists) {
  AccountRepository repo(testFile);
  BankAccount acc(3333, 300.0, 50, "Marta", "Rua 3", "pw");
  repo.saveAccount(acc);
  EXPECT_TRUE(repo.accountExists(3333));
  EXPECT_FALSE(repo.accountExists(9999));
}

TEST_F(AccountRepositoryTest, GenerateUniqueAccountNumber) {
  AccountRepository repo(testFile);
  int num1 = repo.generateUniqueAccountNumber();
  int num2 = repo.generateUniqueAccountNumber();
  EXPECT_NE(num1, num2);
}
