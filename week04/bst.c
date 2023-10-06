// WARNING: this file will not compile

// use this struct as the representation for a bst for these questions
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Q1: For each of the sequences below
//     - start from an initially empty binary search tree
//     - show the tree resulting from inserting values in the order given
/*
4 6 5 2 1 3 7
            4
           / \
          /   \
         2     6
        / \   / \ 
       1   3 5   7

5 2 3 4 6 1 7
            5
           / \
          /   \
         2     6
        / \     \
       1   3     7
            \
             4

7 6 5 4 3 2 1
                7
               /
              6 
             /
            5
           /
          4 
         /
        3
       /
      2
     /
    1
*/

// Q2: tree traversal
// What kind of trees have the property that their in-order traversal 
// is the same as their pre-order traversal?
// ans: "right-deep" degenerate tree (i.e. trees with no left subtrees)

// Are there any kinds of trees for which all output orders will be the same?
// ans: just root node, empty tree

// Q3: Count the number of odd values in a tree
// time complexity: O(n) -> recurse ~2n times, constant time operations in each call
int bstCountOdds(struct node *t) {
    // base case(s)
    if (t == NULL) return 0;

    if (t->value % 2 == 1) { // value is odd
        return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
    } else { // value is even
        return bstCountOdds(t->left) + bstCountOdds(t->right);
    }
}

// Q4: Count number of internal nodes in a given tree
// An internal node is a node with at least one child node
// time complexity: O(n) -> recurse ~2n times, constant time operations in each call
int bstCountInternal(struct node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;

    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// Q5: Return the level of the node containing a given key if such a node exists, 
// otherwise return -1 (when a given key is not in the binary search tree)
// The level of the root node is zero
// time complexity: O(h) 
//      -> we recurse ~h times at most since we either go left or right each time
//          and we can do that h times at most based on the height of the tree
//      -> constant time operations in each call
int bstNodeLevel(struct node *t, int key) {
    if (t == NULL) return -1;
    if (t->value == key) return 0;

    if (t->value > key) {
        int leftLevel = bstNodeLevel(t->left, key);
        if (leftLevel == -1) return -1;
        return leftLevel + 1; // add 1 to account for the root
    } else { // t->value < key
        int rightLevel = bstNodeLevel(t->right, key);
        if (rightLevel == -1) return -1;
        return rightLevel + 1;
    }
}

// Q6: Count the number of values that are greater than a given value. This function
// should avoid visiting nodes that it doesn't have to visit
// time complexity: O(n) 
//      -> recurse ~2n times in the worst case if every value in t is greater than val
//      -> constant time operations in each call
int bstCountGreater(struct node *t, int val) {
    if (t == NULL) return 0;

    if (t->value <= val) { // t->value < val
        return bstCountGreater(t->right, val);
    } else { // t->value > val
        return 1 + bstCountGreater(t->right, val) + bstCountGreater(t->left, val);
    }
}
