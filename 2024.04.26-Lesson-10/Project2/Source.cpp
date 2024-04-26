#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data,
		Node* left = nullptr,
		Node* right = nullptr)
		: data(data), left(left), right(right) {}
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		if (node == nullptr)
		{
			stream << "EMPTY";
		}
		else
		{
			stream << node->data;
		}
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
	void add(int data)
	{
		addNode(root, data);
	}
	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "___________TREE START_____________" << std::endl;
		tree.PrintHorizontal(stream, tree.root);
		stream << "__________________________________" << std::endl;
		tree.Print(stream, tree.root);
		stream << std::endl;
		stream << "___________TREE  END______________" << std::endl;
		return stream;
	}

private:
	Node* root;
	void dispose(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}
		dispose(node->left);
		dispose(node->right);
		delete node;
	}
	void addNode(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
		}
		else if (node->data > data)
		{
			return addNode(node->left, data);
		}
		else if (node->data < data)
		{
			return addNode(node->right, data);
		}
	}
	void PrintHorizontal(std::ostream& stream, Node* node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}
		PrintHorizontal(stream, node->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			stream << "\t";
		}
		stream << node->data << std::endl;
		PrintHorizontal(stream, node->right, depth + 1);
	}
	void Print(std::ostream& stream, Node* node, int depth = 0)
	{
		if (node == nullptr)
		{
			return;
		}
		Print(stream, node->left, depth + 1);
		stream << node->data << " ";
		Print(stream, node->right, depth + 1);
	}

};

int main(int argc, char* argv[])
{
	BTree tree;
	tree.add(5);
	tree.add(2);
	tree.add(3);
	tree.add(1);
	tree.add(4);
	tree.add(0);
	tree.add(11);
	tree.add(9);
	tree.add(8);
	tree.add(7);
	tree.add(-5);
	tree.add(-3);
	tree.add(-2);
	tree.add(-8);
	tree.add(10);
	std::cout << tree << std::endl;
	return EXIT_SUCCESS;
}