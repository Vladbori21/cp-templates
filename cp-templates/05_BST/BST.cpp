#include<iostream>
#include<string>
#include<vector>

using namespace std;

//node
struct node {
	int val;
	node* left;
	node* right;
	node(int x) : val(x), left(nullptr), right(nullptr) {};
};
//insertion node
node* insert(node* root, int val) {
	if (!root) return new node(val);
	if (val < root->val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);
	return(root);
}
//searching val
bool search(node* root, int val) {
	if (!root) return false;
	if (val < root->val) return search(root->left, val);
	else if (val > root->val) return search(root->right, val);
	else return true;
}
//printing root->left->right
void preorder(const node* root) {
	if (!root) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}
//printing left->root->right
void inorder(const node* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}
//printing left->right->root
void postorder(const node* root) {
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}
//destroying nodes(dynamic memory)
void destroy(node* root) {
	if (!root) return;
	destroy(root->left);
	destroy(root->right);
	cout << "Óäàëÿþ óçåë " << root->val << endl;
	delete root;
}
//printing in levels
void levelOrder(node* root) {
	if (!root) return;
	queue<node*> q;

	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			node* n = q.front();
			cout << n->val << " ";
			if (n->left) q.push(n->left);
			if (n->right) q.push(n->right);
			q.pop();
		}
		cout << endl;
	}

}
//deleting nodes
node* removeNode(node* root, int val) {
	if (!root) return nullptr;
	if (val < root->val) root->left = removeNode(root->left, val);
	else if (val > root->val) root->right = removeNode(root->right, val);
	else {
		if (root->left && root->right) {
			node* succ = root->right;
			while (succ->left) succ = succ->left;
			root->val = succ->val;
			root->right = removeNode(root->right, succ->val);
		}
		else if ((root->left && !root->right) || (!root->left && root->right)) {
			node* child = root->left ? root->left : root->right;
			delete root;
			return child;
		}
		else if (!root->left && !root->right) {
			delete root;
			return nullptr;
		}
	}
	return root;
}
//finding max val
int findMax(node* root) {
	while (root->right) root = root->right;
	return root->val;
}
//finding min val
int findMin(node* root) {
	while (root->left) root = root->left;
	return root->val;
}
//sum of nodes
int sum(node* root) {
	if (!root) return 0;
	return sum(root->left) + sum(root->right) + root->val;
}
//amount of nodes
int count(node* root) {
	if (!root) return 0;
	return count(root->left) + count(root->right) + 1;
}
//height of tree
int height(node* root) {
	if (!root) return 0;
	return max(height(root->left), height(root->right)) + 1;
}
//depth of node
int depth(node* root, int val) {
	if (!root) return 0;
	else if (root->val == val) return 1;

	int d = 0;
	if (val < root->val) d = depth(root->left, val);
	else if (val > root->val) d = depth(root->right, val);

	return d ? d + 1 : 0;
}

int check(node* root) {
	if (!root) return 0;

	int left = check(root->left);
	if (left == -1) return -1;

	int right = check(root->right);
	if (right == -1) return -1;

	if (abs(left - right) > 1) return -1;

	return max(left, right) + 1;
}
//checking tree on balance
bool isBalanced(node* root) {
	return check(root) != -1;
}
//finding lowest common ancestor
node* LCA(node* root, int a, int b) {
	if (!root) return nullptr;
	if (a < root->val && b < root->val) return LCA(root->left, a, b);
	if (a > root->val && b > root->val) return LCA(root->right, a, b);
	else return root;
}

int main() {

	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	vector<vector<int>> tree;
	vector<int> nums{ 3, 2, 10, 6, 0 };
	node* root = nullptr;
	int n;


	for (const int& num : nums) {
		root = insert(root, num);
	}

	levelOrder(root);
	cout << endl;
	cout << sum(root) << " " << count(root);
	cout << endl;
	cout << boolalpha << isBalanced(root) << endl << endl << endl;


	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		cout << depth(root, x) << endl;

	}

	cout << endl << endl;
	levelOrder(root);
	cout << endl << endl;

	destroy(root);
	root = nullptr;

	return 0;
}



