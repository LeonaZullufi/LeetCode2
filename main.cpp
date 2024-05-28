#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <list>
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
       cout << root->val << " ";
        printInOrder(root->right);
    }
}
//Convert binary number in a linked list to integer
//Time complexity O(n)
//Space complecity 0(n)
class LinkedList1 {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0)
                continue;
            else
                ans+=pow(2,v.size()-i-1);
        }
        return ans;
    }
};
//Middle of the linked list
//Time complexity O(n)
//Space complecity 0(1)
class LinkedList2 {
        public:
        ListNode* middleNode(ListNode* head) {
            int i = 0;
            ListNode* dummy = head;
            while(dummy != NULL){
                dummy = dummy -> next;
                i++;
            }
            int ans = i/2;
            ListNode* temp = head;
            int j = 0;
            while(j < ans){
                temp = temp -> next;
                j++;
            }
            return temp;
        }
};
//Reverse linked list
//Time complexity O(n)
//Space complecity 0(1)
class  LinkedList3 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }
};
//Merge two sorted lists
//Time complexity O(m+n)
//Space complecity 0(1)
class LinkedList4 {
        public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

            ListNode* p1=list1;
            ListNode* p2=list2;
            ListNode* temp= new ListNode(-1);
            ListNode* p3=temp;

            while(p1!=NULL && p2!=NULL){
                if(p1->val<p2->val){
                    p3->next=p1;
                    p1=p1->next;
                }

                else{
                    p3->next=p2;
                    p2=p2->next;
                }

                p3=p3->next;
            }

            while(p1!=NULL){
                p3->next=p1;
                p1=p1->next;
                p3=p3->next;

            }

            while(p2!=NULL){
                p3->next=p2;
                p2=p2->next;
                p3=p3->next;

            }

            return temp->next;

        }
};
//Palindrome linked list
//Time complexity O(n)
//Space complecity 0(n)
class LinkedList5 {
public:
    bool f(ListNode*&st , ListNode*&end){
        if(end==NULL)return true;

        bool ans=f(st,end->next);

        bool ans2=(st->val==end->val);
        ans=ans & ans2;
        st=st->next;

        return ans;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*st=head;
        ListNode*end=head;


        return f(st,end);
    }
};

//Number of students unable to eat lunch
//Time complexity O(n)
//Space complecity 0(1)
class StackQueue1 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0, zeroes = 0;
        for(int i : students) {

            ones += i;
        }
        zeroes = students.size() - ones;

        for(int i = 0; i < sandwiches.size(); i++) {

            int val = sandwiches[i];
            if(val == 0) {

                if(zeroes == 0) {

                    return sandwiches.size() - i;
                }
                zeroes--;
            } else {

                if(ones == 0) {

                    return sandwiches.size() - i;
                }
                ones--;
            }
        }

        return 0;
    }
};

//Final prices with a special discount
//Time complexity O(n^2)
//Space complecity 0(n)
class StackQueue2 {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    res.push_back(prices[i] - prices[j]);
                    flag = true;
                    break;
                }
            }
            if (!flag)
                res.push_back(prices[i]);
        }

        return res;
    }
};
//Maximum nesting depth of the parentheses
//Time complexity O(n)
//Space complecity 0(n)
class StackQueue3 {
public:
    int maxDepth(string s) {
        stack<char> stack;
        int mx = 0;
        for (char c : s) {
            if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                mx = max((int)stack.size(), mx);
                stack.pop();
            }
        }
        return mx;
    }
};

//First unique character in a string
//Time complexity O(n)
//Space complecity 0(1)
class StackQueue4 {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26, 0);
        for(auto i : s) mp[i-'a']++;
        for(int i  = 0;i < s.length();i++)
            if(mp[s[i] - 'a'] == 1) return i;

        return -1;
    }
};
//Number of recent calls
//Time complexity O(n)
//Space complecity 0(n)
class StackQueue5 {
public:
    queue<int> q;

    int ping(int t) {
        int lower = t - 3000;
        while(!q.empty() && lower > q.front()){
            q.pop();
        }

        q.push(t);
        return q.size();
    }
};

//Search in a binary search tree
//Time complexity O(h)   h-the height of the tree
//Space complecity 0(1)
class BinarySearchTree1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->val==val)return temp;
            else if(temp->val<val)temp=temp->right;
            else temp=temp->left;
        }
        return temp;
    }
};
//Increasing order search tree
//Time complexity O(n)
//Space complecity 0(n)
class BinarySearchTree2 {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};
//Convert sorted array to binary search tree
//Time complexity O(n)
//Space complecity 0(n)
class BinarySearchTree3 {
public:
    TreeNode* helper(vector<int> &nums, int l, int r) {
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
//Minimum distance between BST nodes
//Time complexity O(n)
//Space complecity 0(n)
class BinarySearchTree4 {
public:
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mini=min(mini,v[i+1]-v[i]);
        }
        return mini;
    }
};
//Find mode in binary search tree
//Time complexity O(n)
//Space complecity 0(n)
class BinarySearchTree5 {
public:
    void helper(TreeNode* root,unordered_map<int,int>& ans){
        if(root==NULL){
            return;
        }
        ans[root->val]++;
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> ans;
        helper(root,ans);
        int max=0;
        for(auto it:ans){
            if(it.second>max){
                max=it.second;
            }
        }
        vector<int> n;
        for(auto it:ans){
            if(it.second==max){
                n.push_back(it.first);
            }
        }
        return n;
    }
};
//Number of good pairs
//Time complexity O(n^2)
//Space complecity 0(1)
class HashTable1 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c=0;
        for(int j=nums.size()-1;j>=0;j--){
            for(int i=j-1;i>=0;i--){
                if(nums[i]==nums[j]){
                    c++;
                }
            }
        }
        return c;
    }
};

//How many numbers are smaller than the current number
//Time complexity O(n^2)
//Space complecity 0(n)
class HashTable2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int count;
        for (int i = 0; i < nums.size(); i++) {
            count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
//Decode the message
//Time complexity O(n)
//Space complecity 0(1)
class HashTable3 {
public:
    string decodeMessage(string k, string m) {
        map<char,char>mp;
        char temp  = 'a';
        for(int i = 0; i < k.length(); i++) {
            if(k[i] != ' ' && mp.find(k[i]) == mp.end()) {
                mp[k[i]] = temp;
                temp++;
            }

        }

        string res = "";

        for(int i = 0; i < m.length(); i++) {
            if(m[i] != ' ') {
                res+= mp[m[i]];
            }
            else {
                res+= " ";
            }
        }

        return res;
    }
};
//Number of arithmetic triplets
//Time complexity O(n^2)
//Space complecity 0(1)
class HashTable4 {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int left = 0, right = 0;
        int count = 0;
        while (left < nums.size() && right < nums.size()) {
            if(nums[right] - nums[left] < diff) {
                ++right;
            } else if (nums[right] - nums[left] > diff) {
                ++left;
            } else {
                while(right < nums.size() && nums[right] - nums[left] != 2 * diff) {
                    ++right;
                    if(right < nums.size() && nums[right] - nums[left] == 2 * diff) {
                        ++count;
                    }
                }
                ++left;
                right = left;
            }
        }
        return count;
    }
};
//Check if the sentence is pangram
//Time complexity O(n)
//Space complecity 0(1)
class HashTable5 {
        public:
        bool checkIfPangram(string sentence) {
            vector<int> v(26, 0);
            int n = sentence.size();
            for(int i=0;i<n;i++)
            {
                v[sentence[i] - 'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(v[i] == 0)
                {
                    return false;
                }
            }
            return true;
        }
};

void LinkedList(int n){
    switch(n){
        case 1:{
            ListNode* head = new ListNode(1);
            head->next = new ListNode(0);
            head->next->next = new ListNode(1);

            LinkedList1 linkedList;
            int decimalValue = linkedList.getDecimalValue(head);

            cout << "Decimal value: " << decimalValue << endl;

            ListNode* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        } break;
        case 2:{
            ListNode* head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);

            LinkedList2 linkedList;
            ListNode* middle = linkedList.middleNode(head);

            cout << "Middle node value: " << middle->val << endl;


            ListNode* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;}

        }break;
        case 3: {
            ListNode* head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);

            cout << "Original list: ";
            printList(head);

            LinkedList3 linkedList;
            ListNode* reversedHead = linkedList.reverseList(head);

            cout << "Reversed list: ";
            printList(reversedHead);
            ListNode* temp;
            while (reversedHead != nullptr) {
                temp = reversedHead;
                reversedHead = reversedHead->next;
                delete temp;}
        }break;
        case 4:{
            ListNode* list1 = new ListNode(1);
            list1->next = new ListNode(3);
            list1->next->next = new ListNode(5);


            ListNode* list2 = new ListNode(2);
            list2->next = new ListNode(4);
            list2->next->next = new ListNode(6);

            cout << "List 1: ";
            printList(list1);

            cout << "List 2: ";
            printList(list2);

            LinkedList4 linkedList;
            ListNode* mergedHead = linkedList.mergeTwoLists(list1, list2);

            cout << "Merged list: ";
            printList(mergedHead);

            ListNode* temp;
            while (mergedHead != nullptr) {
                temp = mergedHead;
                mergedHead = mergedHead->next;
                delete temp;
            }
        }break;
        case 5:{
            ListNode* head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(2);
            head->next->next->next->next = new ListNode(1);

            LinkedList5 linkedList;
            bool palindrome = linkedList.isPalindrome(head);

            if (palindrome) {
               cout << "The linked list is a palindrome." << endl;
            } else {
                cout << "The linked list is not a palindrome." << endl;
            }


            ListNode* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;}
        }break;
        default:
            cout<<"End of the program";

    }
}
void StackQueue(int n ){
    switch(n) {
        case 1 : {
            vector<int> students = {1, 1, 0, 0};
            vector<int> sandwiches = {0, 1, 0, 1};

            StackQueue1 stackQueue;
            int notPreferred = stackQueue.countStudents(students, sandwiches);

            cout << "Number of students who will not get their preferred sandwiches: " << notPreferred << endl;

        }
            break;
        case 2:{
            vector<int> prices = {8, 4, 6, 2, 3};

            StackQueue2 stackQueue;
            vector<int> finalPrices = stackQueue.finalPrices(prices);

            cout << "Final prices after discounts: ";
            for (int price : finalPrices) {
                cout << price << " ";
            }
            cout << endl;
        }break;
        case 3:{
            string sequence = "(())()(()())";

            StackQueue3 stackQueue;
            int maxDepth = stackQueue.maxDepth(sequence);

            cout << "Maximum nesting depth of the parentheses: " << maxDepth << endl;

        }break;
        case 4:{
            string str = "leetcode";

            StackQueue4 stackQueue;
            int firstUniqueIndex = stackQueue.firstUniqChar(str);

            if (firstUniqueIndex != -1) {
                cout << "Index of the first unique character in the string: " << firstUniqueIndex << endl;
                cout << "The first unique character is: " << str[firstUniqueIndex] << endl;
            } else {
                cout << "No unique character found in the string." << endl;
            }
        }break;
        case 5:{
            StackQueue5 stackQueue;


            cout << "Number of ping requests at time 1: " << stackQueue.ping(1) << endl;
            cout << "Number of ping requests at time 100: " << stackQueue.ping(100) << endl;
            cout << "Number of ping requests at time 3001: " << stackQueue.ping(3001) << endl;
            cout << "Number of ping requests at time 3002: " << stackQueue.ping(3002) << endl;

        }break;
        default:
            cout<<"End of the program";
    }
};
void BinarySearchTree(int n){
    switch(n){
        case 1:{
            TreeNode* root = new TreeNode(4);
            root->left = new TreeNode(2);
            root->right = new TreeNode(7);
            root->left->left = new TreeNode(1);
            root->left->right = new TreeNode(3);
            root->right->left = new TreeNode(5);

            BinarySearchTree1 bst;
            int target = 2;
            TreeNode* result = bst.searchBST(root, target);

            if (result != nullptr) {
               cout << "Found value " << target << " in the binary search tree." << endl;
            } else {
                cout << "Value " << target << " not found in the binary search tree." << endl;
            }

            delete root->left->right;
            delete root->left->left;
            delete root->left;
            delete root->right->left;
            delete root->right;
            delete root;
        }break;
        case 2:{
            TreeNode* root = new TreeNode(5);
            root->left = new TreeNode(3);
            root->right = new TreeNode(6);
            root->left->left = new TreeNode(2);
            root->left->right = new TreeNode(4);
            root->left->left->left = new TreeNode(1);

            BinarySearchTree2 bst;
            TreeNode* skewedRoot = bst.increasingBST(root);
           cout << "Values of the right-skewed binary search tree: ";
            printInOrder(skewedRoot);
            cout << endl;

            delete root->left->left->left;
            delete root->left->left;
            delete root->left->right;
            delete root->left;
            delete root->right;
            delete root;

        }break;
        case 3:{
            vector<int> nums = {-10, -3, 0, 5, 9};

            BinarySearchTree3 bst;

            TreeNode* root = bst.sortedArrayToBST(nums);

            cout << "Values of the balanced binary search tree (in-order traversal): ";
            printInOrder(root);
            cout << endl;

            delete root->right;
            delete root->left;
            delete root;

        }break;
        case 4:{
            TreeNode* root = new TreeNode(4);
            root->left = new TreeNode(2);
            root->right = new TreeNode(6);
            root->left->left = new TreeNode(1);
            root->left->right = new TreeNode(3);

            BinarySearchTree4 bst;
            int minDiff = bst.minDiffInBST(root);

            cout << "Minimum absolute difference between values of any two nodes in the binary search tree: " << minDiff << endl;

            delete root->left->right;
            delete root->left->left;
            delete root->left;
            delete root->right;
            delete root;
        }break;
        case 5:{
            TreeNode* root = new TreeNode(1);
            root->right = new TreeNode(2);
            root->right->left = new TreeNode(2);

            BinarySearchTree5 bst;

            vector<int> modes = bst.findMode(root);

            cout << "Mode(s) in the binary search tree: ";
            for (int mode : modes) {
                cout << mode << " ";
            }
           cout << endl;
            delete root->right->left;
            delete root->right;
            delete root;


        }break;
        default:
            cout<<"End of the program";
    }
};
void HashTable(int n){
    switch(n){
        case 1:{
            vector<int> nums = {1, 2, 3, 1, 1, 3, 3, 2, 2};
            HashTable1 hashTable;
            int numPairs = hashTable.numIdenticalPairs(nums);
            cout << "Number of identical pairs in the vector: " << numPairs << endl;
        }break;
        case 2:{
            vector<int> nums = {8, 1, 2, 2, 3};
            HashTable2 hashTable;
            vector<int> result = hashTable.smallerNumbersThanCurrent(nums);
            cout << "Counts of numbers smaller than each element in the vector: ";
            for (int count : result) {
                cout << count << " ";
            }
           cout << std::endl;

        }break;
        case 3:{
            HashTable3 hashTable;
            string key = "abcdefghijklmnopqrstuvwxyz";
            string message = "abcd efgh";
            string decodedMessage = hashTable.decodeMessage(key, message);
            cout << "Decoded message: " << decodedMessage << endl;
        }break;
        case 4:{
            HashTable4 hashTable;
            vector<int> nums = {1, 3, 5, 7, 9};
            int diff = 2;
            int numTriplets = hashTable.arithmeticTriplets(nums, diff);
            cout << "Number of arithmetic triplets with difference " << diff << ": " << numTriplets << endl;
        }break;
        case 5:{
            HashTable5 hashTable;
            string sentence = "thequickbrownfoxjumpsoverthelazydog";
            bool isPangram = hashTable.checkIfPangram(sentence);

            if (isPangram) {
                cout << "The sentence is a pangram." << endl;
            } else {
                cout << "The sentence is not a pangram." << endl;
            }
        }break;
        default:
            cout<<"End of the program";
    }
}

int main(){
    int choose;
    int problem;
    cout<<"Hello! Please choose a number from 1 to 4 for the fields you want: (Linked List(1), Stack or Queue(2), Binary Search Tree(3), Hash Table(4)). If you want to exit the program, press 0.";
    cin>>choose;

    switch(choose){
        case 1: cout<<"Enter a number from 1 to 5 to choose a random task from the Linked List field.If you want to exit the program, press 0.";
            cin>>problem;
            LinkedList(problem);
            break;
        case 2: cout<<"Enter a number from 1 to 5 to choose a random task from the Stack or Queue field.If you want to exit the program, press 0.";
            cin>>problem;
            StackQueue(problem);
            break;
        case 3: cout<<"Enter a number from 1 to 5 to choose a random task from the Binary Search Tree field.If you want to exit the program, press 0.";
            cin>>problem;
            BinarySearchTree(problem);
            break;
        case 4: cout<<"Enter a number from 1 to 5 to choose a random task from the Hash Table field.If you want to exit the program, press 0.";
            cin>>problem;
            HashTable(problem);
            break;
        default:
            cout<<"End of the program";




    }

    return 0;
}
