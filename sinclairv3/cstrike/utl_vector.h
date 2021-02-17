#pragma once

//	Refer to Cstrike leak

template <class T, class m = int>
class CUtlMemory {
public:
	T& operator[](m _index) { return m_memory[_index]; }

protected:
	T* m_memory;
	int m_allocation_count;
	int m_grow_size;
};

template <class T, class a = CUtlMemory<T>>
class CUtlVector {
	typedef a allocator;

public:
	T& operator[](int _index) { return m_memory[_index]; }

	int count() const { return m_size; }

	void set_size(int _value) { m_size = _value; }

protected:
	allocator m_memory;
	int m_size;
	T* m_elements;
};