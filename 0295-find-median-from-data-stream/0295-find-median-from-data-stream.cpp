class MedianFinder {
// max heap to store the smaller half elements
    priority_queue<double> s;
 
    // min heap to store the greater half elements
    priority_queue<double,vector<double>,greater<double> > g;

    bool empty;
    double med;
public:
    /** initialize your data structure here. */
    MedianFinder():empty(true) { }
    
    void addNum(int num) {
        if(empty) {
            med = num;
            s.push(num);
            empty = false;
        } else {
            if (s.size() > g.size())
            {
                if (num < med)
                {
                    g.push(s.top());
                    s.pop();
                    s.push(num);
                }
                else g.push(num);

                med = (s.top() + g.top())/2.0;
            }

            // case2(both heaps are balanced)
            else if (s.size()==g.size())
            {
                if (num < med)
                {
                    s.push(num);
                    med = (double)s.top();
                }
                else
                {
                    g.push(num);
                    med = (double)g.top();
                }
            }

            // case3(right side heap has more elements)
            else
            {
                if (num > med)
                {
                    s.push(g.top());
                    g.pop();
                    g.push(num);
                }
                else
                    s.push(num);

                med = (s.top() + g.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */