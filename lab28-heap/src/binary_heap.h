#ifndef MESA_CISC187_BINARY_HEAP_H
#define MESA_CISC187_BINARY_HEAP_H

#include <cstdlib>
#include <ostream>
#include <vector>
#include <iostream>

namespace mesa {

    template <class T, class Container = std::vector<T>>
    // require T is comparable
    class binary_heap
    {
    public:
        using value_type = T;
        binary_heap() = default;

        explicit binary_heap(const std::vector<T> v)
            : size_{ v.size() }
            , heap_(size_ + 1)
        {
            for (size_t i = 0; i < v.size(); ++i) {
                heap_[i + 1] = v[i];  //need to add 1 extra space temp storage in pos 0
            }
            for (auto i = heap_.size() / 2; i < heap_.size(); --i) {
                percolate_down(i);
            }
        }
        Container getheap_() {
            return heap_;
        }

        constexpr bool empty() const noexcept {
            if (size_ == 0) {
                return true;
            } return false;
        }
        constexpr size_t size() const noexcept {
            return size_;
        }
        constexpr const T& front() const noexcept {
            return heap_[1];  //must return the 1st index bc index 0 is the tmp position
        }
        constexpr void clear() noexcept {
            for (int i = 0; i < heap_.size(); i++) {
                heap_.pop_back();
            }
            size_ = 0;
        }

        void pop() {
            heap_.erase(heap_.begin());
            size_--;
            for (auto i = heap_.size() / 2; i < heap_.size(); --i) {
                percolate_down(i);
            }
        }

        void push(const T& value) noexcept {
            if (heap_.size() - size_ <= 1) {
                heap_.resize(heap_.size() + 1);
            }
            size_++;
            percolate_up(value);
        }

    private:
        size_t size_ = 0;
        Container heap_ = { T{} };

        void percolate_down(size_t hole) noexcept
        {
            T tmp = std::move(heap_[hole]);

            for (size_t child; hole * 2 <= size_; hole = child) {
                child = hole * 2;
                if (child != size_ && heap_[child + 1] < heap_[child]) {
                    ++child;
                }
                if (heap_[child] < tmp) {
                    heap_[hole] = std::move(heap_[child]);
                }
                else {
                    break;
                }
            }
            heap_[hole] = std::move(tmp);
        }

        void percolate_up(T value) {
            heap_[0] = value; //put value in the tmp position
            auto hole = size_;
            while (value < heap_[hole / 2]) {
                heap_[hole] = std::move(heap_[hole / 2]);//swapping parent with child. parent is at hole/2
                hole = hole / 2;  //set parent position to hole
            } heap_[hole] = std::move(heap_[0]);  //moving the value (stored in heap_[0] to move it in the location where we want it)

        }

        friend
            std::ostream& operator<<(std::ostream& os, const binary_heap& rhs)
        {
            for (const auto& value : rhs.heap_) {
                os << value << ' ';
            }
            return os;
        }

    };

} // end namespace mesa

#endif