//
// Created by mars on 2021/6/27.
//

#ifndef INC_2_SEARCH__BINARYSEARCH_HPP_
#define INC_2_SEARCH__BINARYSEARCH_HPP_

#include <queue>
#include <cassert>

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

// 二分搜索树
template<typename Key, typename Val>
class BinarySearchTree {
  // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
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

    Node(Node *node) {
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
    }
  };

  Node *root; // 根节点
  int count;  // 树中的节点个数

  //向以node为根的二叉搜索树中, 插入节点(key, value), 返回插入新节点后的二叉搜索树的根
  Node *insert(Node *node, Key key, Val value) {
    if (node == nullptr) {
      count++;
      return new Node(key, value);
    }
    if (key == node->key) {
      node->value = value;
    } else if (key < node->key) {
      node->left = insert(node->left, key, value);
    } else {
      node->right = insert(node->right, key, value);
    }
    return node;
  }

  //__insert的非递归实现
  Node *insert2(Node *node, Key key, Val value) {
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
      std::cout << node->key << " ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }

  void inOrder(Node *node) {
    if (node != nullptr) {
      inOrder(node->left);
      std::cout << node->key << " ";
      inOrder(node->right);
    }
  }

  void postOrder(Node *node) {
    if (node != nullptr) {
      postOrder(node->left);
      postOrder(node->right);
      std::cout << node->key << " ";
    }
  }

  void destroy(Node *node) {
    if (node != nullptr) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }
  // 返回以node为根的二分搜索树的最小键值所在的节点
  Node *minimum(Node *node) {
    if (node->left) {
      return minimum(node->left);
    } else {
      return node;
    }
  }
  // 返回以node为根的二分搜索树的最大键值所在的节点
  Node *maximum(Node *node) {
    if (node->right) {
      return maximum(node->right);
    } else {
      return node;
    }
  }
  // 删除掉以node为根的二分搜索树中的最小节点
  // 返回删除节点后新的二分搜索树的根
  Node *removeMin(Node *node) {
    if (node->left) {
      node->left = removeMin(node->left);
      return node;
    } else {
      // 可能存在比最小节点键值大的右节点, 也可能为空
      // It dosen't matter, 不影响, 直接取最小节点的右节点返回给当前节点
      Node *rightNode = node->right;
      delete node;
      count--;
      return rightNode;
    }
  }
  // 删除掉以node为根的二分搜索树中的最大节点
  // 返回删除节点后新的二分搜索树的根
  Node *removeMax(Node *node) {
    if (node->right) {
      node->right = removeMax(node->right);
      return node;
    } else {
      // 可能存在比最大节点键值小的左节点, 也可能为空
      // It dosen't matter, 不影响, 直接取最大节点的左节点返回给当前节点
      Node *leftNode = node->left;
      delete node;
      count--;
      return leftNode;
    }
  }
  // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
  // 返回删除节点后新的二分搜索树的根
  Node *remove(Node *node, Key key) {
    if (node == nullptr)
      return nullptr;

    if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    } else if (key > node->key) {
      node->right = remove(node->right, key);
      return node;
    } else {
      // 待删除节点左子树为空的情况
      if (node->left == nullptr) {
        Node *rightNode = node->right;
        delete node;
        count--;
        //node = node->right;
        return rightNode;
      }
      // 待删除节点右子树为空的情况
      if (node->right == nullptr) {
        Node *leftNode = node->left;
        delete node;
        count--;
        //node = node->left;
        return leftNode;
      }
      // 待删除节点左右子树均不为空的情况
      // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
      // 用这个节点替代待删除节点的位置(后继节点)
      Node *successor = new Node(minimum(node->right));
      count ++;
      successor->left = node->left;
      successor->right = removeMin(node->right);
      count --;
      return successor;
      // 同理也可以使用前驱节点替代
#if 0
      Node *precursors = new Node(maximum(node->left));
      count ++;
      precursors->right = node->right;
      precursors->left = removeMax(node->left);
      count --;
      return precursors;
#endif
    }
  }

 public:
  // 构造函数, 默认构造一棵空二分搜索树
  BinarySearchTree() {
    root = nullptr;
    count = 0;
  }
  // 析构函数, 释放二分搜索树的所有空间
  ~BinarySearchTree() {
    destroy(root);
  }
  // 返回二分搜索树的节点个数
  int size() {
    return count;
  }
  // 返回二分搜索树是否为空
  bool isEmpty() {
    return count == 0;
  }
  // 向二分搜索树中插入一个新的(key, value)数据对
  void insert(Key key, Val value) {
    root = insert(root, key, value);
  }
  // 查看二分搜索树中是否存在键key
  bool contain(Key key) {
    return contain(root, key);
  }
  // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
  Val *search(Key key) {
    return search(root, key);
  }
  // 二分搜索树的前序遍历
  void preOrder() {
    preOrder(root);
    std::cout << std::endl;
  }
  // 二分搜索树的中序遍历
  void inOrder() {
    inOrder(root);
    std::cout << std::endl;
  }
  // 二分搜索树的后序遍历
  void postOrder() {
    postOrder(root);
    std::cout << std::endl;
  }

  //二分搜索树的层序遍历 BFS
  void levelOrder() {
    std::queue<Node *> q;
    if (root == nullptr) return;
    q.push(root);
    while (!q.empty()) {
      Node *node = q.front();
      std::cout << node->key << " ";

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      q.pop();
    }
    std::cout << std::endl;
  }
  // 寻找二分搜索树的最小的键值
  Key minimum() {
    assert(count > 0 && root != nullptr);
    Node *node = minimum(root);
    return node->key;
  }
  // 寻找二分搜索树的最大的键值
  Key maximum() {
    assert(count > 0 && root != nullptr);
    Node *node = maximum(root);
    return node->key;
  }
  // 从二分搜索树中删除最小值所在节点
  void removeMin() {
    if (root)
      root = removeMin(root);
  }
  // 从二分搜索树中删除最大值所在节点
  void removeMax() {
    if (root)
      root = removeMax(root);
  }
  // 从二分搜索树中删除键值为key的节点
  void remove(Key key) {
    root = remove(root, key);
  }
};

#endif //INC_2_SEARCH__BINARYSEARCH_HPP_
