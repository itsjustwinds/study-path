/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
    bool helper(Node * root, int min, int max){
        if(!root) return true;

        if(root->data <= min || root->data >= max) return false;
        return (helper(root->left,min,root->data) && helper(root->right,root->data,max));

    }

    bool checkBST(Node* root) {

        int min = -1000;
        int max = 100000;
        return helper(root,min,max);
    }
