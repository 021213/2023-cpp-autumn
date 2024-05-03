#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data;
		return stream;
	}
};

class BTree
{
public:
	BTree() : root(nullptr) {}
	~BTree()
	{
		dispose(root);
	}
	void Add(int data)
	{
		add(root, data);
	}
	void Remove(int data)
	{
		Node* node = extractNode(searchNode(root, data));
		if (node != nullptr)
		{
			delete node;
		}
	}
	void RotateLeft(int data)
	{
		rotateLeft(searchNode(root, data));
	}
	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "__________TREE START___________" << std::endl;
		tree.printLineTree(stream, tree.root);
		stream << std::endl;
		stream << "_______________________________" << std::endl;
		tree.printVerticalTree(stream, tree.root);
		stream << "__________TREE  END ___________" << std::endl;
		return stream;
	}
private:
	Node* root;
	void dispose(Node*& node)
	{
		if (node != nullptr) //if(node)
		{
			dispose(node->left);
			dispose(node->right);
			delete node;
		}
	}
	void add(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
		}
		else if (node->data > data)
		{
			add(node->left, data);
		}
		else if (node->data < data)
		{
			add(node->right, data);
		}
	}
	void printVerticalTree(std::ostream& stream, Node*& node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}
		printVerticalTree(stream, node->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			stream << "\t";
		}
		stream << node << std::endl;
		printVerticalTree(stream, node->right, depth + 1);
	}
	void printLineTree(std::ostream& stream, Node*& node)
	{
		if (node == nullptr)
		{
			return;
		}
		printLineTree(stream, node->left);
		stream << node << " ";
		printLineTree(stream, node->right);
	}
	void rotateLeft(Node*& node)
	{
		if (node == nullptr || node->right == nullptr)
		{
			return;
		}
		Node* temp = node->right;
		node->right = node->right->left;
		temp->left = node;
		node = temp;
	}
	Node*& searchNode(Node*& node, int data)
	{
		if (node == nullptr || node->data == data)
		{
			return node;
		}
		if (node->data > data)
		{
			return searchNode(node->left, data);
		}
		else
		{
			return searchNode(node->right, data);
		}
	}
	Node* extractNode(Node*& node)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (node->left == nullptr && node->right == nullptr)
		{
			Node* temp = node;
			node = nullptr;
			return temp;
		}
		if (node->left == nullptr)
		{
			Node* temp = node;
			node = node->right;
			temp->right = temp->left = nullptr;
			return temp;
		}
		if (node->right == nullptr)
		{
			Node* temp = node;
			node = node->left;
			temp->right = temp->left = nullptr;
			return temp;
		}
		Node* leftMostRight = nullptr;
		if (node->right->left == nullptr)
		{
			leftMostRight = extractNode(node->right);
		}
		else
		{
			leftMostRight = node->right;
			while(leftMostRight->left->left != nullptr)
			{
				leftMostRight = leftMostRight->left;
			}
			leftMostRight = extractNode(leftMostRight->left);
		}
		Node* res = node;
		leftMostRight->left = node->left;
		leftMostRight->right = node->right;
		node = leftMostRight;
		return res;
	}
};

int main(int argc, char* argv[])
{
	BTree tree;
	tree.Add(16);
	tree.Add(8);
	tree.Add(4);
	tree.Add(2);
	tree.Add(1);
	tree.Add(3);
	tree.Add(5);
	tree.Add(6);
	tree.Add(7);
	tree.Add(32);
	tree.Add(20);
	tree.Add(21);
	tree.Add(22);
	tree.Add(25);
	tree.Add(23);
	tree.Add(24);
	tree.Add(28);
	tree.Add(12);
	tree.Add(9);
	tree.Add(10);
	tree.Add(14);
	tree.Add(15);
	tree.Add(13);
	tree.Add(11);
	std::cout << tree << std::endl;

	tree.RotateLeft(2);
	tree.Remove(50);
	std::cout << tree << std::endl;
	tree.Remove(24);
	std::cout << tree << std::endl;
	tree.Remove(9);
	std::cout << tree << std::endl;
	tree.Remove(3);
	tree.Remove(5);
	std::cout << tree << std::endl;
	tree.Remove(4);
	std::cout << tree << std::endl;
	tree.Remove(8);
	std::cout << tree << std::endl;
	tree.Remove(16);
	std::cout << tree << std::endl;
	

	return EXIT_SUCCESS;
}