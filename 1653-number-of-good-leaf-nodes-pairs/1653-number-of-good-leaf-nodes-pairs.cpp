class Solution {
public:
    int cnt=0;
    vector<int> calcPairs(TreeNode* root, int dist){
        if((root->left == NULL) && (root->right == NULL)){
            vector<int> v;
            return v;
        }
        vector<int> left,right;
        if(root->left){
            left=calcPairs(root->left, dist);
            if(left.size()==0)left.push_back(1);
        }
        if(root->right){
            right=calcPairs(root->right, dist);
            if(right.size()==0)right.push_back(1);
        }
        for(int i=0; i<left.size(); i++){
            // cout<<left[i]<<" ";
            for(int j=0; j<right.size(); j++){
                // cout<<left[i]<<" ";
                if(left[i]+right[j]<=dist)cnt++;
            }
            cout<<endl;
        }
        int i=0;
        for(int i=0; i<left.size(); i++) left[i]+=1;
        while(i<right.size()){
            left.push_back(right[i]+1);
            i++;
        }
        // cout<<"Root->val:"<<root->val<<";";
        // for(auto it: left) cout<<"LEft:"<<it<<" ";
        // for(auto it: right) cout<<"Right:"<<it<<" ";
        // cout<<endl;
        return left;       
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> v = calcPairs(root, distance);
        return cnt;
    }
};