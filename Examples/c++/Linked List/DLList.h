#pragma once

#include <algorithm>
#include <utility>

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
		using ValueType = typename List::ValueType;
		using NodePtr = typename List::NodePtr;
		using PointerType = ValueType*;
		using RefType = ValueType&;
	public:
		DLLIterator()
			: m_Ptr(nullptr), m_SentinelNode(nullptr)
		{
		}

		DLLIterator(NodePtr ptr, NodePtr sentinelNode)
			: m_Ptr(ptr), m_SentinelNode(sentinelNode)
		{
		}

		DLLIterator& Increment(int32_t offset)
		{
			ASSERT(offset >= 0, "Invalid offset!");

			for (int32_t i = 0; i < offset; i++)
				(*this)++;

			return *this;
		}

		DLLIterator& Decrement(int32_t offset)
		{
			ASSERT(offset >= 0, "Invalid offset!");

			for (int32_t i = 0; i < offset; i++)
				(*this)--;

			return *this;
		}

		RefType operator*()
		{
			ASSERT(m_Ptr != m_SentinelNode, "Cannot dereference end iterator!");
			return m_Ptr->Data;
		}

		NodePtr operator->()
		{
			ASSERT(m_Ptr != m_SentinelNode, "Cannot access end interator!");
			return m_Ptr;
		}

		DLLIterator& operator++()
		{
			ASSERT(m_Ptr != m_SentinelNode, "Cannot increment end iterator!");
			m_Ptr = m_Ptr->Next;
			return *this;
		}

		DLLIterator operator++(int)
		{
			DLLIterator<List> iterator = *this;
			++(*this);
			return iterator;
		}

		DLLIterator& operator--()
		{
			ASSERT(m_Ptr->Previous != m_SentinelNode, "Cannot decrement begin iterator!");
			m_Ptr = m_Ptr->Previous;
			return *this;
		}

		DLLIterator operator--(int)
		{
			DLLIterator<List> iterator = *this;
			--(*this);
			return iterator;
		}

		bool operator==(const DLLIterator& rhs) const
		{
			return m_Ptr == rhs.m_Ptr;
		}

		bool operator!=(const DLLIterator& rhs) const
		{
			return !(*this == rhs);
		}

		operator NodePtr()
		{
			return m_Ptr;
		}
	private:
		NodePtr m_Ptr;
		NodePtr m_SentinelNode;
	};


	template<typename T>
	struct DLNode
	{
		using NodePtr = DLNode<T>*;

		T Data = T();
		NodePtr Next = nullptr;
		NodePtr Previous = nullptr;

		DLNode() = default;
		DLNode(const T& data, NodePtr prev, NodePtr next)
			: Data(data), Previous(prev), Next(next) {}
		DLNode(T&& data, NodePtr prev, NodePtr next)
			: Data(std::move(data)), Previous(prev), Next(next) {}
	};

	template<typename T>
	class DLList
	{
	public:
		using ValueType = T;
		using Node = DLNode<T>;
		using NodePtr = DLNode<T>*;
		using Iterator = DLLIterator<DLList<T>>;
	public:
		DLList()
		{
			m_SentinelNode = new Node();
			m_SentinelNode->Next = m_SentinelNode;
			m_SentinelNode->Previous = m_SentinelNode;
		}

		~DLList()
		{
			Clear();
			delete m_SentinelNode;
		}

		void PushFront(const T& data)
		{
			InsertAfter(m_SentinelNode, data);
		}

		void PushFront(T&& data)
		{
			InsertAfter(m_SentinelNode, std::move(data));
		}

		template<typename... Args>
		T& EmplaceFront(Args&&... args)
		{
			return EmplaceAfter(m_SentinelNode, std::forward<Args>(args)...);
		}

		void PushBack(const T& data)
		{
			InsertBefore(m_SentinelNode, data);
		}

		void PushBack(T&& data)
		{
			InsertBefore(m_SentinelNode, std::move(data));
		}

		template<typename... Args>
		T& EmplaceBack(Args&&... args)
		{
			return EmplaceBefore(m_SentinelNode, std::forward<Args>(args)...);
		}

		void Insert(Iterator where, const T& data)
		{
			InsertBefore((NodePtr)where, data);
		}

		void Insert(Iterator where, T&& data)
		{
			InsertBefore((NodePtr)where, std::move(data));
		}

		template<typename... Args>
		T& Emplace(Iterator where, Args&&... args)
		{
			return EmplaceBefore((NodePtr)where, std::forward<Args>(args)...);
		}

		void PopFront()
		{
			DeleteNode(m_SentinelNode->Next);
		}

		void PopBack()
		{
			ASSERT(!Empty(), "PopBack() called on an empty list!");
			DeleteNode(m_SentinelNode->Previous);
		}

		void Erase(Iterator where)
		{
			ASSERT((NodePtr)where != m_SentinelNode, "Invalid Iterator");
			DeleteNode(where);
		}

		void MoveToBack(Iterator from, Iterator to)
		{
			if (m_Size <= 1 || to == end())
				return;

			NodePtr startNode = (NodePtr)from;
			NodePtr endNode = ((NodePtr)to)->Previous;

			NodePtr startNodePrevious = startNode->Previous;

			endNode->Next = m_SentinelNode;
			m_SentinelNode->Previous->Next = startNode;
			startNode->Previous = m_SentinelNode->Previous;

			m_SentinelNode->Previous = endNode;
			startNodePrevious->Next = (NodePtr)to;
			((NodePtr)to)->Previous = startNodePrevious;

		}

		void Reverse()
		{
			NodePtr current = m_SentinelNode->Next;

			while (current != m_SentinelNode)
			{
				std::swap(current->Next, current->Previous);
				current = current->Previous;
			}

			std::swap(m_SentinelNode->Next, m_SentinelNode->Previous);
			
			m_SentinelNode->Previous->Next = m_SentinelNode;
			m_SentinelNode->Next->Previous = m_SentinelNode;
		}

		void Reverse(Iterator from, Iterator to)
		{
			if (from == to)
				return;

			NodePtr beginNode = (NodePtr)from;
			NodePtr endNode = ((NodePtr)to)->Previous;
			NodePtr beginNodePrevious = beginNode->Previous;
			NodePtr endNodeNext = (NodePtr)to;

			endNode->Next = nullptr;

			NodePtr current = beginNode;
			NodePtr prev = nullptr;

			while (current != nullptr)
			{
				std::swap(current->Next, current->Previous);
				prev = current;
				current = current->Previous;
			}

			beginNodePrevious->Next = prev;
			beginNode->Next = endNodeNext;
		}

		void Clear()
		{
			if (m_Size == 0)
				return;

			NodePtr current = m_SentinelNode->Next;

			while (current != m_SentinelNode)
			{
				NodePtr temp = current;
				current = current->Next;
				delete temp;
			}

			m_SentinelNode->Next = m_SentinelNode;
			m_SentinelNode->Previous = m_SentinelNode;

			m_Size = 0;
		}

		void Resize(int32_t size)
		{
			ASSERT(size >= 0, "Invalid size value!");

			NodePtr current = m_SentinelNode->Previous;
			int32_t difference = size - m_Size;

			if (difference > 0)
			{
				for (size_t i = 0; i < difference; i++)
					PushBack(T());
			}
			else if (difference < 0)
			{
				int32_t absoluteDifference = abs(difference);
				for (size_t i = 0; i < absoluteDifference; i++)
					PopBack();
			}
		}

		size_t Size() const { return m_Size; }
		bool Empty() const { return m_Size == 0; }

		T& Head() const { return m_SentinelNode->Next->Data; }
		T& Tail() const { return m_SentinelNode->Previous->Data; }

		Iterator begin() { return Iterator(m_SentinelNode->Next, m_SentinelNode); }
		Iterator end() { return Iterator(m_SentinelNode, m_SentinelNode); }
	private:
		void InsertBefore(NodePtr node, const T& data)
		{
			NodePtr newNode = new Node(data, node->Previous, node);
			node->Previous->Next = newNode;
			node->Previous = newNode;
			m_Size++;
		}

		void InsertBefore(NodePtr node, T&& data)
		{
			NodePtr newNode = new Node(std::move(data), node->Previous, node);
			node->Previous->Next = newNode;
			node->Previous = newNode;
			m_Size++;
		}

		void InsertAfter(NodePtr node, const T& data)
		{
			NodePtr newNode = new Node(data, node, node->Next);
			node->Next->Previous = newNode;
			node->Next = newNode;
			m_Size++;
		}

		void InsertAfter(NodePtr node, T&& data)
		{
			NodePtr newNode = new Node(std::move(data), node, node->Next);
			node->Next->Previous = newNode;
			node->Next = newNode;
			m_Size++;
		}

		template<typename... Args>
		T& EmplaceBefore(NodePtr node, Args&&... args)
		{
			NodePtr newNode = new Node();
			newNode->Previous = node->Previous;
			newNode->Next = node;
			new(&(newNode->Data)) T(std::forward<Args>(args)...);

			node->Previous->Next = newNode;
			node->Previous = newNode;
			m_Size++;

			return newNode->Data;
		}

		template<typename... Args>
		T& EmplaceAfter(NodePtr node, Args&&... args)
		{
			NodePtr newNode = new Node();
			newNode->Previous = node;
			newNode->Next = node->Next;
			new(&(newNode->Data)) T(std::forward<Args>(args)...);

			node->Next->Previous = newNode;
			node->Next = newNode;
			m_Size++;

			return newNode->Data;
		}

		void DeleteNode(NodePtr node)
		{
			node->Previous->Next = node->Next;
			node->Next->Previous = node->Previous;
			delete node;

			m_Size--;
		}
	private:
		size_t m_Size = 0;
		NodePtr m_SentinelNode;
	};
}