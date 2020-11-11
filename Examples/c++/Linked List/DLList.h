#pragma once

#include <utility>
#include <iostream>
#include <algorithm>

// This macro breaks the debugger and stops the program execution at the point where it is called if the statement 'x' is false
// IMPORTANT: If not in debug mode('DEBUG' is not defined) the macro does nothing
#ifdef DEBUG
	#define ASSERT(x,...) { if(!(x)){ std::cout << __VA_ARGS__ << std::endl; __debugbreak(); } }
#else
	#define ASSERT(x,...)
#endif

namespace DSA
{
	template<typename List>
	class DLLIterator
	{
	public:
		using ValueType = typename List::ListType;
		using Node = typename List::Node;
	public:
		/// <summary>
		/// Default constructor
		/// </summary>
		DLLIterator()
			: mListNodePointer(nullptr), mListEndNode(nullptr)
		{
		}

		/// <summary>
		/// Parameterized Constructor
		/// </summary>
		/// <param name="ptr">Pointer to the current node of the list</param>
		/// <param name="sentinelNode">The 'dummy' node of the list which indicates the end</param>
		DLLIterator(Node* ptr, Node* sentinelNode)
			: mListNodePointer(ptr), mListEndNode(sentinelNode)
		{
		}

		/// <summary>
		/// Returns iterator to the next element of the list
		/// </summary>
		/// <param name="offset">Tells how many increments should happen</param>
		/// <returns></returns>
		DLLIterator& Increment(int32_t offset)
		{
			ASSERT(offset >= 0, "Invalid offset!");

			for (int32_t i = 0; i < offset; i++)
				(*this)++;

			return *this;
		}

		/// <summary>
		/// Returns iterator to the previous element
		/// </summary>
		/// <param name="offset">Tells how many decrements should happen</param>
		/// <returns></returns>
		DLLIterator& Decrement(int32_t offset)
		{
			ASSERT(offset >= 0, "Invalid offset!");

			for (int32_t i = 0; i < offset; i++)
				(*this)--;

			return *this;
		}

		/// <summary>
		/// Dereference operator
		/// </summary>
		/// <returns></returns>
		ValueType& operator*()
		{
			ASSERT(mListNodePointer != mListEndNode, "Cannot dereference end iterator!");
			return mListNodePointer->Data;
		}

		/// <summary>
		/// Access operator
		/// </summary>
		/// <returns></returns>
		Node* operator->()
		{
			ASSERT(mListNodePointer != mListEndNode, "Cannot access end interator!");
			return mListNodePointer;
		}

		/// <summary>
		/// Post-increment operator
		/// </summary>
		/// <returns></returns>
		DLLIterator& operator++()
		{
			ASSERT(mListNodePointer != mListEndNode, "Cannot increment end iterator!");
			mListNodePointer = mListNodePointer->Next;
			return *this;
		}

		/// <summary>
		/// Pre-increment operator
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		DLLIterator operator++(int)
		{
			DLLIterator<List> iterator = *this;
			++(*this);
			return iterator;
		}

		/// <summary>
		/// Post-decrement operator
		/// </summary>
		/// <returns></returns>
		DLLIterator& operator--()
		{
			ASSERT(mListNodePointer->Previous != mListEndNode, "Cannot decrement begin iterator!");
			mListNodePointer = mListNodePointer->Previous;
			return *this;
		}

		/// <summary>
		/// Pre-decrement operator
		/// </summary>
		/// <param name=""></param>
		/// <returns></returns>
		DLLIterator operator--(int)
		{
			DLLIterator<List> iterator = *this;
			--(*this);
			return iterator;
		}

		/// <summary>
		/// Comparisson operator
		/// </summary>
		/// <param name="rhs">Object of comparisson</param>
		/// <returns></returns>
		bool operator==(const DLLIterator& rhs) const
		{
			return mListNodePointer == rhs.mListNodePointer;
		}

		/// <summary>
		/// Not-equals operator
		/// </summary>
		/// <param name="rhs">Object of comparisson</param>
		/// <returns></returns>
		bool operator!=(const DLLIterator& rhs) const
		{
			return !(*this == rhs);
		}

		/// <summary>
		/// Node* cast operator. Returns the iterator's actual pointer
		/// </summary>
		operator Node*()
		{
			return mListNodePointer;
		}
	private:
		Node* mListNodePointer;			// Pointer to a list node
		Node* mListEndNode;				// Dummy node which indicates the end of the list and NOT THE LIST'S LAST ELEMENT
	};


	template<typename DataType>
	struct DLNode
	{
		using Node = DLNode<DataType>;

		DataType Data = DataType();		// Data
		Node* Next = nullptr;			// Pointer to the next element/node
		Node* Previous = nullptr;		// Pointer to the previous element/node

		/// <summary>
		/// Default Constructor
		/// </summary>
		DLNode() = default;

		/// <summary>
		/// Parameterized Constructor
		/// </summary>
		/// <param name="data">The value that the node will contain</param>
		/// <param name="prev">Pointer to the new node's previous node</param>
		/// <param name="next">Pointer to the new node's next node</param>
		DLNode(const DataType& data, Node* prev, Node* next)
			: Data(data), Previous(prev), Next(next) {}

		/// <summary>
		/// Constructor with rvalue reference data parameter used for utilizing move semantics(if the object type supports it)
		/// </summary>
		/// <param name="data">Rvalue reference(temporary object) of the value </param>
		/// <param name="prev">Pointer to the new node's previous node</param>
		/// <param name="next">Pointer to the new node's next node</param>
		DLNode(DataType&& data, Node* prev, Node* next)
			: Data(std::move(data)), Previous(prev), Next(next) {}
	};

	template<typename DataType>
	class DLList
	{
	public:
		using ListType = DataType;
		using Node = DLNode<DataType>;
		using Iterator = DLLIterator<DLList<DataType>>;
	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		DLList()
		{
			mListEndNode = new Node();
			mListEndNode->Next = mListEndNode;
			mListEndNode->Previous = mListEndNode;
		}

		/// <summary>
		/// Destructor
		/// </summary>
		~DLList()
		{
			Clear();
			delete mListEndNode;
		}

		/// <summary>
		/// Adds an element to the beginning of the list
		/// </summary>
		/// <param name="data">The value of the new node</param>
		void PushFront(const DataType& data)
		{
			InsertAfter(mListEndNode, data);
		}

		/// <summary>
		/// Adds an element to the beginning of the list
		/// </summary>
		/// <param name="data">Rvalue reference to the value(temporary object) of the new node</param>
		void PushFront(DataType&& data)
		{
			InsertAfter(mListEndNode, std::move(data));
		}

		/// <summary>
		/// Adds an element to the end of the list
		/// </summary>
		/// <param name="data">The value of the new node</param>
		void PushBack(const DataType& data)
		{
			InsertBefore(mListEndNode, data);
		}

		/// <summary>
		/// Adds an element to the end of the list
		/// </summary>
		/// <param name="data">Rvalue reference to the value(temporary object) of the new node</param>
		void PushBack(DataType&& data)
		{
			InsertBefore(mListEndNode, std::move(data));
		}

		/// <summary>
		/// Inserts a new element on the specified position
		/// </summary>
		/// <param name="where">Insertion position</param>
		/// <param name="data">The value of the new node</param>
		void Insert(Iterator where, const DataType& data)
		{
			InsertBefore((Node*)where, data);
		}

		/// <summary>
		/// Inserts a new element on the specified position
		/// </summary>
		/// <param name="where">Insertion position</param>
		/// <param name="data">Rvalue reference to the value(temporary object) of the new node</param>
		void Insert(Iterator where, DataType&& data)
		{
			InsertBefore((Node*)where, std::move(data));
		}

		/// <summary>
		/// Constructs an object in-place at the beginning of the list
		/// </summary>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args">New element parameters</param>
		/// <returns></returns>
		template<typename... Args>
		DataType& EmplaceFront(Args&&... args)
		{
			return EmplaceAfter(mListEndNode, std::forward<Args>(args)...);
		}

		/// <summary>
		/// Constructs an object in-place at the end of the list
		/// </summary>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="...args">New element parameters</param>
		/// <returns></returns>
		template<typename... Args>
		DataType& EmplaceBack(Args&&... args)
		{
			return EmplaceBefore(mListEndNode, std::forward<Args>(args)...);
		}

		/// <summary>
		/// Constructs an object in-place on the specified position
		/// </summary>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="where">Iterator to the position of insertion</param>
		/// <param name="...args">New element parameters</param>
		/// <returns></returns>
		template<typename... Args>
		DataType& Emplace(Iterator where, Args&&... args)
		{
			return EmplaceBefore((Node*)where, std::forward<Args>(args)...);
		}

		/// <summary>
		/// Removes the first element
		/// </summary>
		void PopFront()
		{
			DeleteNode(mListEndNode->Next);
		}

		/// <summary>
		/// Removes the last element
		/// </summary>
		void PopBack()
		{
			ASSERT(!Empty(), "PopBack() called on an empty list!");
			DeleteNode(mListEndNode->Previous);
		}

		/// <summary>
		/// Removes the element on the specified position
		/// </summary>
		/// <param name="where">Iterator to the element to be removed</param>
		void Erase(Iterator where)
		{
			ASSERT((Node*)where != mListEndNode, "Invalid Iterator");
			DeleteNode(where);
		}

		/// <summary>
		/// Reverses the list elements in the specified range: [from, to)
		/// </summary>
		/// <param name="from">Range start</param>
		/// <param name="to">Range end</param>
		void Reverse(Iterator from, Iterator to)
		{
			if (from == to)
				return;

			Node* beginNode = (Node*)from;
			Node* endNode = ((Node*)to)->Previous;
			Node* beginNodePrevious = beginNode->Previous;
			Node* endNodeNext = (Node*)to;

			endNode->Next = nullptr;

			Node* current = beginNode;
			Node* prev = nullptr;

			while (current != nullptr)
			{
				std::swap(current->Next, current->Previous);
				prev = current;
				current = current->Previous;
			}

			beginNodePrevious->Next = prev;
			beginNode->Next = endNodeNext;
		}

		/// <summary>
		/// Deletes every element in the list
		/// </summary>
		void Clear()
		{
			if (mSize == 0)
				return;

			Node* current = mListEndNode->Next;

			while (current != mListEndNode)
			{
				Node* temp = current;
				current = current->Next;
				delete temp;
			}

			mListEndNode->Next = mListEndNode;
			mListEndNode->Previous = mListEndNode;

			mSize = 0;
		}

		/// <summary>
		/// Resizes the list with the specified amount
		/// </summary>
		/// <param name="size">Number of elements</param>
		void Resize(int32_t size)
		{
			ASSERT(size >= 0, "Invalid size value!");

			Node* current = mListEndNode->Previous;
			int32_t difference = size - mSize;

			if (difference > 0)
			{
				for (size_t i = 0; i < difference; i++)
					EmplaceBack();
			}
			else if (difference < 0)
			{
				int32_t absoluteDifference = abs(difference);
				for (size_t i = 0; i < absoluteDifference; i++)
					PopBack();
			}
		}

		/// <summary>
		/// Returns the size of the list
		/// </summary>
		/// <returns></returns>
		size_t Size() const { return mSize; }

		/// <summary>
		/// Checks if the list is empty
		/// </summary>
		/// <returns></returns>
		bool Empty() const { return mSize == 0; }

		/// <summary>
		/// Returns the value of the first element
		/// </summary>
		/// <returns></returns>
		DataType& Head() const { return mListEndNode->Next->Data; }

		/// <summary>
		/// Returns the value of the last element
		/// </summary>
		/// <returns></returns>
		DataType& Tail() const { return mListEndNode->Previous->Data; }

		/// <summary>
		/// Returns an iterator to the beginning of the list
		/// </summary>
		/// <returns></returns>
		Iterator begin() { return Iterator(mListEndNode->Next, mListEndNode); }

		/// <summary>
		/// Returns an iterator to the end of the list
		/// </summary>
		/// <returns></returns>
		Iterator end() { return Iterator(mListEndNode, mListEndNode); }
	private:
		/// <summary>
		/// Inserts an element before the specified node
		/// </summary>
		/// <param name="node">The node of reference</param>
		/// <param name="data">The value of the new node</param>
		void InsertBefore(Node* node, const DataType& data)
		{
			Node* newNode = new Node(data, node->Previous, node);
			node->Previous->Next = newNode;
			node->Previous = newNode;
			mSize++;
		}

		/// <summary>
		/// Inserts an element before the specified node. This function takes rvalue reference parameter and should used for temporary DataType objects utilizing move semantics
		/// </summary>
		/// <param name="node">The node of reference</param>
		/// <param name="data">The value of the new node</param>
		void InsertBefore(Node* node, DataType&& data)
		{
			Node* newNode = new Node(std::move(data), node->Previous, node);
			node->Previous->Next = newNode;
			node->Previous = newNode;
			mSize++;
		}

		/// <summary>
		/// Inserts an element after the specified node
		/// </summary>
		/// <param name="node">The node of reference</param>
		/// <param name="data">The value of the new node</param>
		void InsertAfter(Node* node, const DataType& data)
		{
			Node* newNode = new Node(data, node, node->Next);
			node->Next->Previous = newNode;
			node->Next = newNode;
			mSize++;
		}

		/// <summary>
		/// Inserts an element after the specified node. This function takes rvalue reference parameter and should used for temporary DataType objects utilizing move semantics
		/// </summary>
		/// <param name="node">The node of reference</param>
		/// <param name="data">The value of the new node</param>
		void InsertAfter(Node* node, DataType&& data)
		{
			Node* newNode = new Node(std::move(data), node, node->Next);
			node->Next->Previous = newNode;
			node->Next = newNode;
			mSize++;
		}

		/// <summary>
		/// Constructs the element in-place given its parameters before the specified node
		/// </summary>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="node">The node of reference</param>
		/// <param name="...args">Element parameters</param>
		/// <returns></returns>
		template<typename... Args>
		DataType& EmplaceBefore(Node* node, Args&&... args)
		{
			Node* newNode = new Node();
			newNode->Previous = node->Previous;
			newNode->Next = node;
			new(&(newNode->Data)) DataType(std::forward<Args>(args)...);

			node->Previous->Next = newNode;
			node->Previous = newNode;
			mSize++;

			return newNode->Data;
		}

		/// <summary>
		/// Constructs the element in-place given its parameters after the specified node
		/// </summary>
		/// <typeparam name="...Args"></typeparam>
		/// <param name="node">The node of reference</param>
		/// <param name="...args">Element parameters</param>
		/// <returns></returns>
		template<typename... Args>
		DataType& EmplaceAfter(Node* node, Args&&... args)
		{
			Node* newNode = new Node();
			newNode->Previous = node;
			newNode->Next = node->Next;
			new(&(newNode->Data)) DataType(std::forward<Args>(args)...);

			node->Next->Previous = newNode;
			node->Next = newNode;
			mSize++;

			return newNode->Data;
		}

		/// <summary>
		/// Removes the specified node from the list
		/// </summary>
		/// <param name="node">Node to be removed</param>
		void DeleteNode(Node* node)
		{
			node->Previous->Next = node->Next;
			node->Next->Previous = node->Previous;
			delete node;

			mSize--;
		}
	private:
		// Number of elements in the list
		size_t mSize = 0;			

		// Pointer to the end list node NOT TO THE LAST ELEMENT. This node's next is the list's first element and the previous is the list's last element
		Node* mListEndNode;	
	};
}