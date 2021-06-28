//
// Created by mars on 2021/6/27.
//

#ifndef INC_2_SEARCH__BINARYSEARCH_HPP_
#define INC_2_SEARCH__BINARYSEARCH_HPP_

#include <queue>

template<typename T>
int binarySearch(T arr[], int n, T target) {
  int l = 0, r = n - 1;
  while (l <= r) {
	int mid = l + (r - l) / 2;
	if (arr[mid] == target) {
	  return mid;
	} else if (arr[mid] > target) {
	  r = mid - 1;
	} else {
	  l = mid + 1;
	}
  }

  return -1;
}

template<typename T>
std::pair<int, int> binarySearchFloorAndCeil(T arr[], int n, T target) {
  int l = 0, r = n - 1;
  std::pair<int, int> ret = std::make_pair(-1, -1);

  while (l <= r) {
	int mid = l + (r - l) / 2;
	if (arr[mid] == target) {
	  return std::make_pair(mid, mid);
	} else if (arr[mid] > target) {
	  ret.second = mid;
	  r = mid - 1;
	} else {
	  ret.first = mid;
	  l = mid + 1;
	}
  }

  return ret;
}

template<typename Key, typename Val>
class BST {
 private:
  struct Node {
	Key key;
	Val value;
	Node *left;
	Node *right;

	Node(Key key, Val value) {
	  this->key = key;
	  this->value = value;
	  this->left = this->right = NULL;
	}
  };

  Node *root;
  int count;

  //向以node为根的二叉搜索树中, 插入节点(key, value), 返回插入新节点后的二叉搜索树的根
  Node *__insert(Node *node, Key key, Val value) {
	if (node == nullptr) {
	  count++;
	  return Node(key, value);
	}
	if (key == node->key) {
	  node->value = value;
	} else if (key < node->key) {
	  node->left = __insert(node->left, key, value);
	} else {
	  node->right = __insert(node->right, key, value);
	}
	return node;
  }

  //__insert的非递归实现
  Node *__insert2(Node *node, Key key, Val value) {
	if (node == nullptr) {
	  count++;
	  return new Node(key, value);
	}

	Node *root = node;
	while (node) {
	  if (key == node->key) {
		node->value = value;
		return root;
	  } else if (key < node->key) {
		node = node->left;
	  } else {
		node = node->right;
	  }
	}
	node = new Node(key, value);

	return root;
  }

  //在以node为根的二叉搜索树中, 查看是否包含键为key的节点
  bool contain(Node *node, Key key) {
	if (node == nullptr)
	  return false;

	if (node->key == key) {
	  return true;
	} else if (key < node->key) {
	  return contain(node->left, key);
	} else {
	  return contain(node->right, key);
	}
  }

  //在以node为根的二叉搜索树中, 返回键为key的节点的值的地址
  Val *search(Node *node, Key key) {
	if (node == nullptr)
	  return nullptr;

	if (node->key == key) {
	  return &node->value;
	} else if (key < node->key) {
	  return search(node->left, key);
	} else {
	  return search(node->right, key);
	}
  }

  void preOrder(Node *node) {
	if (node != nullptr) {
	  std::cout << node->key << " " << std::endl;
	  preOrder(node->left);
	  preOrder(node->right);
	}
  }

  void inOrder(Node *node) {
	if (node != nullptr) {
	  inOrder(node->left);
	  std::cout << node->key << " " << std::endl;
	  inOrder(node->right);
	}
  }

  void postOrder(Node *node) {
	if (node != nullptr) {
	  postOrder(node->left);
	  postOrder(node->right);
	  std::cout << node->key << " " << std::endl;
	}
  }

  void destory(Node *node) {
	if (node != nullptr) {
	  destory(node->left);
	  destory(node->right);
	  delete node;
	  count--;
	}
  }

 public:
  BST() {
	root = nullptr;
	count = 0;
  }
  ~
  BST() {
	destory(root);
  }

  int size() {
	return count;
  }

  bool isEmpty() {
	return count == 0;
  }

  void insert(Key key, Val value) {
	__insert(root, key, value);
  }

  bool contain(Key key) {
	return contain(root, key);
  }

  Val *search(Key key) {
	return search(root, key);
  }

  void preOrder() {
	preOrder(root);
  }

  void inOrder() {
	inOrder(root);
  }

  void postOrder() {
	postOrder(root);
  }

  //BFS
  void levelOrder() {
    std::queue<Node*> q;
	if (root == nullptr) return;
    q.push(root);
    while (!q.empty()) {
      Node * node = q.front();
      std::cout << node->key << std::endl;

      if (node->left)
        q.push(node->left);
	  if (node->right)
		q.push(node->right);

	  q.pop();
    }
  }
};

#endif //INC_2_SEARCH__BINARYSEARCH_HPP_
