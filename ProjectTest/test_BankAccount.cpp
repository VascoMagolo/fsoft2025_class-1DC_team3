
#include <gtest/gtest.h>
#include "../Project/models/BankAccount.h"

TEST(BankAccountTest, DefaultConstructor) {
    BankAccount acc;
    EXPECT_EQ(acc.getAccountNumber(), 0);
    EXPECT_EQ(acc.getBalance(), 0.0);
}

TEST(BankAccountTest, ParameterizedConstructor) {
    BankAccount acc(123, 500.0, 30, "João", "Rua A", "pass");
    EXPECT_EQ(acc.getAccountNumber(), 123);
    EXPECT_EQ(acc.getBalance(), 500.0);
    EXPECT_EQ(acc.getAge(), 30);
    EXPECT_EQ(acc.getName(), "João");
    EXPECT_EQ(acc.getAddress(), "Rua A");
    EXPECT_EQ(acc.getPassword(), "pass");
}

TEST(BankAccountTest, Deposit) {
    BankAccount acc(123, 100.0, 30, "João", "Rua A", "pass");
    EXPECT_TRUE(acc.deposit(50.0));
    EXPECT_EQ(acc.getBalance(), 150.0);
    EXPECT_FALSE(acc.deposit(-10.0));
}

TEST(BankAccountTest, Withdraw) {
    BankAccount acc(123, 100.0, 30, "João", "Rua A", "pass");
    EXPECT_TRUE(acc.withdraw(40.0));
    EXPECT_EQ(acc.getBalance(), 60.0);
    EXPECT_FALSE(acc.withdraw(200.0));  // saldo insuficiente
    EXPECT_FALSE(acc.withdraw(-10.0));  // valor inválido
}

TEST(BankAccountTest, Setters) {
    BankAccount acc;
    acc.updateName("Maria");
    acc.updateAddress("Rua B");
    acc.updateAge(45);
    acc.updatePassword("nova");

    EXPECT_EQ(acc.getName(), "Maria");
    EXPECT_EQ(acc.getAddress(), "Rua B");
    EXPECT_EQ(acc.getAge(), 45);
    EXPECT_EQ(acc.getPassword(), "nova");
}

TEST(BankAccountTest, JsonSerialization) {
    BankAccount acc(321, 750.0, 28, "Rui", "Rua C", "segredo");
    json j = acc.toJson();
    BankAccount novo = BankAccount::fromJson(j);
    EXPECT_EQ(novo.getAccountNumber(), 321);
    EXPECT_EQ(novo.getBalance(), 750.0);
    EXPECT_EQ(novo.getAge(), 28);
    EXPECT_EQ(novo.getName(), "Rui");
    EXPECT_EQ(novo.getAddress(), "Rua C");
    EXPECT_EQ(novo.getPassword(), "segredo");
}
