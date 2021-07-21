class MedianFinder {
public:
    /** initialize your data structure here. */
    float median;
    priority_queue <int> leftHeap;
    priority_queue <int, vector<int>, greater<int> > rightHeap;
    MedianFinder() {
        median = 0;
    }

    void addNum(int num) {
        if (leftHeap.size() == 0 and rightHeap.size() == 0) {
            leftHeap.push(num);
            median = num;
        }
        else if (leftHeap.size() > rightHeap.size()) {
            if (num > median) {
                rightHeap.push(num);
            }
            else {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if (rightHeap.size() > leftHeap.size()) {
            if (num < median) {
                leftHeap.push(num);
            }
            else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else {
            if (num < median) {
                leftHeap.push(num);
                median = leftHeap.top();
            }
            else {
                rightHeap.push(num);
                median = rightHeap.top();
            }
        }

    }

    double findMedian() {
        return median;
    }
};