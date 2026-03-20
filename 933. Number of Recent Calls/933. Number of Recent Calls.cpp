// https://leetcode.com/problems/number-of-recent-calls/description/

#include <vector>

class RecentCounter {
    const size_t cWindow = 3000;
public:
    RecentCounter() : latest_ping_(0), pings_(0) {
    }
    
    int ping(int t) {
        pings_.push_back(t);
        while (CheckWindow()) {
            MoveWindow();
        }

        return pings_.size() - latest_ping_;
    }
private:
    size_t latest_ping_ = 0;
    std::vector<int> pings_;

    void MoveWindow() {
        ++latest_ping_;
    }

    bool CheckWindow() {
        return pings_.back() - pings_[latest_ping_] > cWindow;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */