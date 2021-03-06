#include "testAvlTree.h"
#include <memory>

using namespace std;

TEST(AvlTreeTest, Insert_Not_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
}

TEST(AvlTreeTest, Insert_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_FALSE(tree.insert(2));
}

TEST(AvlTreeTest, Search_Empty) {
    AvlTree tree;
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Not_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_TRUE(tree.search(1));

}

TEST(AvlTreeTest, Search_Exists_Right) {
    AvlTree tree;
    tree += 5;
    tree += 9;
    tree += 2;
    tree += 1;
    tree += 10;
    ASSERT_TRUE(tree.search(10));
}

TEST(AvlTreeTest, Search_Exists_Left) {
    AvlTree tree;
    tree += 5;
    tree += 9;
    tree += 2;
    tree += 1;
    ASSERT_TRUE(tree.search(1));
}

TEST(AvlTreeTest, Insert_LeftRotateForce) {
    AvlTree tree;
    for (int i = 1; i <= 30; i++) {
        tree.insert(i);
    }
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Insert_RightRotateForce) {
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Root) {
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(15);
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_2Childs) {
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(11);
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_1Childs) {
    AvlTree tree;
    for (int i = 26; i > 0; i--) {
        tree.insert(i);
    }
    tree.remove(2);
    EXPECT_TRUE(tree.isBalanced());
}



TEST(AvlTreeTest, RemoveEmptyTree) {
    AvlTree tree;
    ASSERT_FALSE(tree.remove(0));
}

TEST(AvlTreeTest, RemoveItem0Childs) {
    AvlTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    ASSERT_TRUE(tree.remove(3));
}

TEST(AvlTreeTest, RemoveItemNotExist) {
    AvlTree tree;
    tree.insert(1);
    ASSERT_FALSE(tree.remove(0));
}

TEST(AvlTreeTest, OperatorOutput) {
    AvlTree tree;
    tree.insert(0);
    cout << tree;
}

TEST(AvlTreeTest, OperatorRemove) {
    AvlTree tree;
    tree += 2;
    tree -= 2;
    ASSERT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, OperatorAdd) {
    AvlTree tree;
    tree += 2;
    ASSERT_TRUE(tree.search(2));
}

TEST(AvlTreeTest, RemoveRotateRightInner) {
    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 30;
    tree += 5;
    tree += 25;
    tree += 40;
    tree += 35;
    tree += 45;
    tree -= 25;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_RotateRightLeft) {
    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 30;
    tree += 5;
    tree += 25;
    tree += 40;
    tree += 35;
    tree += 45;
    tree += 34;
    ASSERT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Remove_RotateLeftRight) {
    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 30;
    tree += 15;
    tree += 5;
    tree += 40;
    tree += 2;
    tree += 7;
    tree -= 15;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Insert_RotateLeftRight) {
    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 30;
    tree += 15;
    tree += 5;
    tree += 40;
    tree += 2;
    tree += 7;
    tree += 9;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRight) {

    AvlTree tree;
    tree += 20;
    tree += 25;
    tree += 10;
    tree += 5;
    tree += 15;
    tree -= 15;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftRightNoOtherChild) {

    AvlTree tree;
    tree += 20;
    tree += 25;
    tree += 10;
    tree += 15;
    tree -= 15;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeftNoOtherChild) {

    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 25;
    tree += 5;
    tree += 15;
    tree += 22;
    tree -= 22;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeaf) {

    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 5;
    tree += 15;
    tree -= 15;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_LeftLeaf) {

    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 5;
    tree += 15;
    tree -= 5;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_RightLeft) {

    AvlTree tree;
    tree += 20;
    tree += 10;
    tree += 25;
    tree += 5;
    tree += 15;
    tree += 22;
    tree += 23;
    tree -= 22;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Rem) {
    AvlTree tree;
    for (int i = 20; i > 0; i--) {
        tree.insert(i);
    }
    tree -= 6;
    tree -= 18;
    tree -= 4;
    tree -= 1;
    tree -= 20;
    tree -= 12;
    tree -= 9;
    tree -= 6;
    tree -= 2;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Rem2){
    AvlTree tree;
    for (int i = 10; i > 0; i--) {
        tree.insert(i);
    }
    tree -= 4;
    tree -= 2;
    tree -= 10;
    tree -= 9;
    ASSERT_TRUE(tree.isBalanced());

}