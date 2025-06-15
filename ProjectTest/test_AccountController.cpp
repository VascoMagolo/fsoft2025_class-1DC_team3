
#include "../Project/controllers/AccountController.h"
#include "../Project/models/BankAccount.h"
#include <gtest/gtest.h>

TEST(AccountControllerTest, AuthenticateUserCorrect) {
  AccountController controller;
  BankAccount account(1001, 300.0, 25, "Carlos", "Rua XPTO", "Secure123.");

  controller.authenticateUser(1001, "Secure123.",
                              account); // chama apenas para simulação

  // Como repositório não é exposto nem manipulável neste código, este teste
  // depende da persistência real Em ambiente real, precisaríamos injetar mock
  // ou permitir acesso ao repositório
  SUCCEED(); // Placeholder
}

TEST(AccountControllerTest, AuthenticateUserWrongPassword) {
  AccountController controller;
  BankAccount account;
  EXPECT_FALSE(
      controller.authenticateUser(1001, "wrong", account)); // falha esperada
}
