#include "array_list.h"

template<class T>
void ArrayList<T>::push_front(const T &value) {
    if (num_of_element == max_capacity) {
        return;
    }

    // memcpy(data, data + 1, num_of_element * sizeof(T));  // why won't this work?
    for (size_t i = 0; i < num_of_element; i++) {
        data[num_of_element - i] = data[num_of_element - i - 1];
    }
    data[0] = value;
    num_of_element++;
}

template<class T>
void ArrayList<T>::push_back(const T &value) {
    if (num_of_element == max_capacity) {
        return;
    }
    data[num_of_element++] = value;
}

template<class T>
void ArrayList<T>::pop_back() {
    if (num_of_element == 0) {
        return;
    }
    num_of_element--;
}

template<class T>
void ArrayList<T>::pop_front() {
    if (num_of_element == 0) {
        return;
    }

    /*
     * solution 1
     */
    shift_left_to(0);
    num_of_element--;

    /*
     * solution 2: will this work?
     */
    //memcpy(data, data + 1, (-num_of_element) * sizeof(T));
}

template<class T>
void ArrayList<T>::remove(T &val) {
    for (size_t i = 0; i < num_of_element;) {
        if (data[i] == val) {
            shift_left_to(i);
            num_of_element--;
        } else {
            i++;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void ArrayList<T>::merge(const List<T> &ot) {
    auto &other_list = (ArrayList<T> &) ot;

    if (other_list.num_of_element == 0) {
        return;
    }

    size_t new_size = num_of_element + other_list.num_of_element;
    size_t new_capacity = max_capacity + other_list.max_capacity; // capacity doesn't affect tests

    T *new_buffer = new T[new_capacity];

    if (num_of_element == 0) {
        for (size_t i = 0; i < other_list.num_of_element; i++) {
            new_buffer[i] = other_list.data[i];
        }

        delete[] data;
        data = new_buffer;
        num_of_element = new_size;
        max_capacity = new_capacity;
        return;
    }

    size_t p1 = 0, p2 = 0;
    for (size_t i = 0; i < new_size; i++) {
        if (p1 == num_of_element) {
            new_buffer[i] = other_list[p2];
            p2++;
        } else if (p2 == other_list.num_of_element) {
            new_buffer[i] = data[p1];
            p1++;
        } else {
            if (data[p1] < other_list.data[p2]) {
                new_buffer[i] = data[p1];
                p1++;
            } else {
                new_buffer[i] = other_list.data[p2];
                p2++;
            }
        }
    }

    delete[] data;
    data = new_buffer;
    num_of_element = new_size;
    max_capacity = new_capacity;
}

template<class T>
void ArrayList<T>::reverse_iterative() {
    if (num_of_element < 2) {
        return;
    }
    for (size_t i = 0; i < num_of_element / 2; i++) {
        swap(i, num_of_element - i - 1);
    }
}

/*
 * optional
 */
template<class T>
void ArrayList<T>::_reverse_recursive(size_t idx) {

    if(idx >= num_of_element/2){
        return;
    }
    swap(idx, num_of_element - idx - 1);
    _reverse_recursive(idx + 1);
}

template<class T>
void ArrayList<T>::reverse_recursive() {

    if (num_of_element < 2) {
        return;
    }

    _reverse_recursive(0);
}