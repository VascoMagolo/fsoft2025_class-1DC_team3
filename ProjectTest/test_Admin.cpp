
#include "../Project/models/Admin.h"
#include <gtest/gtest.h>

TEST(AdminTest, DefaultConstructor) {
  Admin admin;
  EXPECT_EQ(admin.getName(), "admin");
  EXPECT_EQ(admin.getPassword(), "Admin123.");
}

TEST(AdminTest, ParamConstructor) {
  Admin admin("root", "Admin123.");
  EXPECT_EQ(admin.getName(), "root");
  EXPECT_EQ(admin.getPassword(), "Admin123.");
}

TEST(AdminTest, AuthenticateSuccess) {
  Admin admin("admin", "Admin123.");
  EXPECT_TRUE(admin.authenticate("Admin123."));
}

TEST(AdminTest, AuthenticateFailure) {
  Admin admin("admin", "admin123");
  EXPECT_FALSE(admin.authenticate("wrongpassword"));
}
