class AVL {
  public:
    AVL* left;
    AVL* right;
    int val;
    int total;
    int height;

    AVL(int val, int total): left(nullptr), right(nullptr), val(val), total(total), height(1) {}
    AVL(): left(nullptr), right(nullptr), val(0), total(0), height(1) {}
    
    AVL* insert(int val) {
        if(val > this->val) {
            if(this->right != nullptr) {
                this->right = this->right->insert(val);
            } else {
                this->right = new AVL(val, 1);
            }
        } else {
            if(this->left != nullptr) {
                this->left = this->left->insert(val);
            } else {
                this->left = new AVL(val, 1);
            }
        }
        this->total++;
        
        /* 2. Update height of this ancestor node */
        this->updateHeight();

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = this->getBalance();

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && val < this->left->val)
        {
            return rightRotate(this);
        }

        // Right Right Case
        if (balance < -1 && val > this->right->val) {
            return leftRotate(this);
        }

        // Left Right Case
        if (balance > 1 && val > this->left->val)
        {
            this->left = leftRotate(this->left);
            return rightRotate(this);
        }

        // Right Left Case
        if (balance < -1 && val < this->right->val)
        {
            this->right = rightRotate(this->right);
            return leftRotate(this);
        }

        /* return the (unchanged) node pointer */
        return this;
    }

    int query(int val) {
        if(this->val < val) {
            int left = this->left == nullptr ? 0 : this->left->total;
            int right = this->right == nullptr ? 0 : this->right->query(val);
            return 1 + left + right;
        } else {
            if(this->left == nullptr) return 0;
            else return this->left->query(val);
        }
    }

  private:
    
    AVL *rightRotate(AVL *y)
    {
        if(y == nullptr) return y;
        AVL *x = y->left;
        if(x == nullptr) return y;
        AVL *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->updateHeight();
        x->updateHeight();

        // Update totals
        int yt = getTotal(y);
        y->total = yt - getTotal(x) + getTotal(T2);
        x->total = yt;

        // Return new root
        return x;
    }

    AVL *leftRotate(AVL *x)
    {
        if(x == nullptr) return x;
        AVL *y = x->right;
        if(y == nullptr) return x;
        AVL *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->updateHeight();
        y->updateHeight();
        
        // Update totals
        int xt = getTotal(x);
        x->total = xt - getTotal(y) + getTotal(T2);
        y->total = xt;

        // Return new root
        return y;
    }
    
    int getBalance()
    {
      int left = this->left == nullptr ? 0 : this->left->height;
      int right = this->right == nullptr ? 0 : this->right->height;
      return left - right;
    }

    void updateHeight() {
      int left = this->left == nullptr ? 0 : this->left->height;
      int right = this->right == nullptr ? 0 : this->right->height;
      this->height = max(left,right) + 1;
    }
    
    int getTotal(AVL *root)
    {
        if (root == nullptr) return 0;
        return root->total;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> right;
        vector<int> ans(n);
        ans[n - 1] = 0;
        AVL * root = new AVL(nums[n - 1], 1);
        
        for(int i = n - 2; i >= 0; --i) {
            ans[i] = root->query(nums[i]);
            root = root->insert(nums[i]);
        }
        
        return ans;
    }
};