#ifndef TIMER_HPP
#define TIMER_HPP

namespace hydro {

class Timer {
public:
	virtual ~Timer() {};

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual long get_nanoseconds() = 0;
    virtual double get_seconds() = 0;
};

class CTimer : public Timer {
private:
	timespec start_time;
	long run_times;

public:
	CTimer() {
		run_times = 0;
	};
	~CTimer() {};

	void start() override {
		clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
	}

	void stop() override {
		timespec end_time;
		clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
        run_times += 1e9 * (end_time.tv_sec - start_time.tv_sec);
		run_times += end_time.tv_nsec - start_time.tv_nsec;
	}

	long get_nanoseconds() override {
		return (long) run_times;
	}

    double get_seconds() override {
        return double(get_nanoseconds()) / 1e9;
    }
};

} /* namespace hydro */

#endif /* TIMER_HPP */
