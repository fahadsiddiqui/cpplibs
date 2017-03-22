#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
private:
  int size;
  int capacity;
  int topIndex;
  T *data;
  void resize();

public:
  Stack<T>();
  Stack<T>(const int);
  Stack<T>(const Stack<T> &);

  void push(const T &);
  T pop();
  const T &top();

  char *toString();
  char *toString(char);

  ~Stack<T>();
};

template<typename T>
Stack<T>::Stack(int size) {
  if(size <= 0) return;
  this -> data = new T[size];
  this -> size = size;
  this -> capacity = size;
}

template<typename T>
Stack<T>::Stack() {
  this -> data = (T *)0;
  this -> size = 0;
  this -> capacity = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &ref) {
  this -> size = ref.size;
  this -> data = new T[this -> size];
  for (int i = 0 ; i < size ; i++)
    data[i] = ref.data[i];

  this -> capacity = ref.capacity;
}

template<typename T>
void Stack<T>::resize() {
  int resizedCapacity = (double)(this -> capacity) * 1.5;
  T *dataCopy = new T[resizedCapacity];
  for (int i = 0 ; i < size ; i++) {
    dataCopy[i] = data[i];
  }
  capacity = resizedCapacity;

  if(data) delete[] data;
}

template<typename T>
void Stack<T>::push(const T &elem) {
  if(topIndex == capacity) {
    resize();
  }

  data[size++] = elem;
}

template<typename T>
T Stack<T>::pop() {
  return data[--size];
}

template<typename T>
const T &Stack<T>::top() {
  return data[size - 1];
}

template<>
char *Stack<int>::toString() {
  char *arr = new char[size];
  for (int i = 0 ; i < size ; i++)
    arr[i] = (char)(data[i] + 48);
  return arr;
}

// no space 1
// two spaces required 2(, )2
// 3(, )3(, )3
template<>
char *Stack<int>::toString(char separator) {
  char *arr = new char[size + (size - 1) * 2];
  for (int i = 0 ; i < size + (size - 1) * 2 ; i = i + 2) {
    arr[i] = (char)(data[i] + 48);
    if (size == 1) continue;
    arr[i + 1] = separator;
    arr[i + 2] = ' ';
  }
  return arr;
}

template<typename T>
Stack<T>::~Stack<T>() {
  if (data) delete []data;
  data = (T *)0;
  size = 0;
  capacity = 0;
}

#endif
