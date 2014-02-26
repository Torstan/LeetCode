/*
http://oj.leetcode.com/problems/merge-k-sorted-lists/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <algorithm>
using std::vector;

template <class T>
class MinHeap
{
public:
    void init(int n)
    {
        data_.clear();
        data_.reserve(n);
    }
    
    int empty() const
    {
        return (int)data_.size() == 0;
    }
    
    void insert(const T& elem)
    {
        int n = (int)data_.size();
        data_.push_back(elem);
        heapify_up(n);
    }
    
    int delete_min(T& elem)
    {
        int n = (int)data_.size();
        if(n == 0)
            return -1;
        elem = data_[0];
        data_[0] = data_[n-1];
        data_.pop_back();
        heapify_down(0);
        return 0;
    }
private:
    int left_child(int id) const
    {
        return 2*id+1;
    }
    int right_child(int id) const
    {
        return 2*id+2;
    }
    int parent(int id) const
    {
        return (id-1)/2;
    }
    void heapify_up(int id)
    {
        while(id >= 1 && data_[id] < data_[parent(id)]) //operator <
        {
            std::swap(data_[id], data_[parent(id)]);
            id = parent(id);
        }
    }
    void heapify_down(int id)
    {
        int n = (int)data_.size();
        while(id < n && left_child(id) < n)
        {
            int child = left_child(id);
            if(right_child(id) < n && data_[right_child(id)] < data_[child]) //operator <
            {
                child = right_child(id);
            }
            if(data_[child] < data_[id])
            {
                std::swap(data_[id], data_[child]);
                id = child;
            }
            else
                break;
        }
    }
    vector<T> data_;
};

class Elem
{
public:
    Elem(int v=0, ListNode* n=NULL) : val_(v), node_(n) {}
    Elem(const Elem& e)
    {
        val_ = e.val_;
        node_ = e.node_;
    }
    Elem& operator = (const Elem& e)
    {
        if(this != &e)
        {
            val_ = e.val_;
            node_ = e.node_;            
        }
        return *this;
    }
    
    bool operator < (const Elem & e) const
    {
        return val_ < e.val_;
    }
    
    int val_;
    ListNode * node_;
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        MinHeap<Elem> min_heap;
        int n = (int)lists.size();
        min_heap.init(n);
        //insert n elements
        for(int i=0;i<n;i++)
        {
            if(lists[i] != NULL)
            {
                Elem e(lists[i]->val, lists[i]);
                min_heap.insert(e);
            }
        }
        
        ListNode* head = NULL, *tail = NULL;
        while(!min_heap.empty())
        {
            Elem min;
            min_heap.delete_min(min);
            if(head == NULL)
            {
                head = tail = min.node_;
            }
            else
            {
                tail->next = min.node_;
                tail = min.node_;
            }
            
            if(min.node_->next != NULL)
            {
                Elem f(min.node_->next->val, min.node_->next);
                min_heap.insert(f);
            }
        }
        if(tail != NULL)
            tail->next = NULL;
            
        return head;
    }
};