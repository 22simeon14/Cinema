#pragma once
#include <stdexcept> // for std::out_of_range

template<typename T>
class Vector
{
private:
	T* data;
	int count;
	int capacity;

	void copyfrom(const Vector& other);
	void free();
	void resize(int newCap);

public:
	void Pop();
	void Push(const T element);
	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void remove_by_id(int id);

	int get_count() const;
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
};


template <typename T>
void Vector<T>::free() {
	for (int i = 0; i < count; i++) {
		delete data[i]; 
	}
	delete[] data;
	data = nullptr;
	count = 0;
	capacity = 0;
}
template<>
inline void Vector<double>::free() {
	delete[] data;
	data = nullptr;
	count = 0;
	capacity = 0;
}

template <typename T>
void Vector<T>::copyfrom(const Vector& other) {
	this->capacity = other.capacity;
	this->count = other.count;
	this->data = new T[capacity];
	for (int i = 0; i < count; i++) {
		//this->data[i] = new typename std::remove_pointer<T>::type(*other.data[i]); // deep copy
		this->data[i] = other.data[i];
	}
}

template <typename T>
void Vector<T>::resize(int newCap) {
	T* newdata = new T[newCap];
	for (int i = 0; i < count; i++) {
		newdata[i] = data[i];
		//newdata[i] = new typename std::remove_pointer<T>::type(*data[i]); // deep copy
	}
	delete[] data;
	//free(); // clean up old data
	data = newdata;
	capacity = newCap;
}

template<typename T>
void Vector<T>::Pop() {
	if (count > 0) {
		--count;
		delete data[count];
		data[count] = nullptr;
	}
}

template<typename T>
void Vector<T>::Push(const T t) {
	if (count >= capacity) {
		resize(capacity == 0 ? 2 : capacity * 2);
	}
	data[count++] = t; // shallow copy (store pointer)
}

template<typename T>
Vector<T>::Vector() {
	count = 0;
	capacity = 2;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& other) {
	copyfrom(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

template<>
inline Vector<double>& Vector<double>::operator=(const Vector& other) {
	if (this != &other) {
		free();
		copyfrom(other);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector() {
	free();
}

template<>
inline Vector<double>::~Vector() {
}

template<typename T>
void Vector<T>::remove_by_id(int id) {
	for (int i = 0; i < count; i++) {
		if (data[i]->get_id() == id) {
			if (i != count - 1) {
				std::swap(data[i], data[count - 1]);
			}
			Pop();
			break;
		}
	}
}

template<typename T>
int Vector<T>::get_count() const {
	return count;
}


template<typename T>
T& Vector<T>::operator[](size_t index) {
	if (index >= static_cast<size_t>(count))
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
	if (index >= static_cast<size_t>(count))
		throw std::out_of_range("Index out of bounds");
	return data[index];
}

