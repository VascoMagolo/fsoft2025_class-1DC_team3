
#include "../Project/controllers/AdminController.h"
#include <gtest/gtest.h>

TEST(AdminControllerTest, AuthenticateCorrectPassword) {
  AdminController controller;
  // Assume que a password correta é "Admin123."
  EXPECT_TRUE(controller.authenticateAdmin("Admin123."));
}

TEST(AdminControllerTest, AuthenticateWrongPassword) {
  AdminController controller;
  EXPECT_FALSE(controller.authenticateAdmin("wrongpassword"));
}
