
#include <gtest/gtest.h>
#include "../Project/controllers/AdminController.h"

TEST(AdminControllerTest, AuthenticateCorrectPassword) {
    AdminController controller;
    // Assume que a password correta é "admin"
    EXPECT_TRUE(controller.authenticateAdmin("admin"));
}

TEST(AdminControllerTest, AuthenticateWrongPassword) {
    AdminController controller;
    EXPECT_FALSE(controller.authenticateAdmin("wrongpassword"));
}
