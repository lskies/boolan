#include <time.h>
#include <sys/time.h>
long now() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000 + time.tv_usec);
}

class HitCounter {
private:
    deque<pair<long, int>> hits;
    long last_count = 0;
    const int second = 1000000;
    const int minute = 60 * second;
    const int hour = 60 * minute;

    void prune() {
        auto old = upper_bound(hits.begin(), hits.end(), make_pair(now() - 1 * hour, -1));
        if (old != hits.end()) {
            hits.erase(hits.begin(), old);
        }
    }

public:
    void hit() {
        hits.push_back(make_pair(now(), ++last_count));
        prune();
    }

    long hitsInLastSecond() {
        auto before = lower_bound(hits.begin(), hits.end(), make_pair(now() - 1 * second, -1));
        if (before == hits.end()) { return 0; }
        return last_count - before->second + 1;
    }

    long hitsInLastMinute() {
        auto before = lower_bound(hits.begin(), hits.end(), make_pair(now() - 1 * minute, -1));
        if (before == hits.end()) { return 0; }
        return last_count - before->second + 1;
    }

    long hitsInLastHour() {
        auto before = lower_bound(hits.begin(), hits.end(), make_pair(now() - 1 * hour, -1));
        if (before == hits.end()) { return 0; }
        return last_count - before->second + 1;
    }
};
