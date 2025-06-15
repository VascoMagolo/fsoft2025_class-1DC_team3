
#include "../Project/models/Admin.h"
#include <gtest/gtest.h>

TEST(AdminTest, DefaultConstructor) {
  Admin admin;
  EXPECT_EQ(admin.getName(), "");
  EXPECT_EQ(admin.getPassword(), "");
}

TEST(AdminTest, ParamConstructor) {
  Admin admin("root", "admin123");
  EXPECT_EQ(admin.getName(), "root");
  EXPECT_EQ(admin.getPassword(), "admin123");
}

TEST(AdminTest, AuthenticateSuccess) {
  Admin admin("admin", "admin123");
  EXPECT_TRUE(admin.authenticate("admin123"));
}

TEST(AdminTest, AuthenticateFailure) {
  Admin admin("admin", "admin123");
  EXPECT_FALSE(admin.authenticate("wrongpassword"));
}
