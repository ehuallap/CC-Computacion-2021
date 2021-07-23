#ifndef __PATRON_ITERATOR__
#define __PATRON_ITERATOR__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename U>
class patronIterator {
private:
    U* m_p_data_;
    T* m_it_;
    unsigned int actual_pos;
    unsigned int list_size;
public:
    patronIterator(U* p_data) : m_p_data_(p_data) {
        m_it_ = m_p_data_->getHead();
        actual_pos = 1;
        list_size = m_p_data_->getSize();
    }

    void First() {
        m_it_ = m_p_data_->getHead();
        actual_pos = 1;
    }
    void Last() {
        while (m_it_->hasNext()) {
            m_it_ = m_it_->getNext();
        }
        actual_pos = list_size;
    }
    void Next() {
        if (m_it_ == m_p_data_->getHead())
            list_size = m_p_data_->getSize();
        if (m_it_->hasNext()) {
            m_it_ = m_it_->getNext();
            actual_pos += 1;
        }
        else
            actual_pos += 1;
    }
    bool IsDone() {
        return (actual_pos > list_size);
    }
    T Current() {
        return *m_it_;
    }
    int getSize() {
        list_size = m_p_data_->getSize();
        return list_size;
    }
};

#endif