#include "Timer.h"

namespace PNet
{
	Timer::Timer()
	{
		start = std::chrono::high_resolution_clock::now();
		stop = std::chrono::high_resolution_clock::now();
	}

	double Timer::GetMilisecondsElapsed()
	{
		if (isrunning)
		{
			auto elapsed = std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - start);
			return elapsed.count();
		}
		else
		{
			auto elapsed = std::chrono::duration<float, std::milli>(stop - start);
			return elapsed.count();
		}
	}

	double Timer::GetMicrosecondsElapsed()
	{
		if (isrunning)
		{
			auto elapsed = std::chrono::duration<float, std::micro>(std::chrono::high_resolution_clock::now() - start);
			return elapsed.count();
		}
		else
		{
			auto elapsed = std::chrono::duration<float, std::micro>(stop - start);
			return elapsed.count();
		}
	}

	double Timer::GetNanosecondsElapsed()
	{
		if (isrunning)
		{
			auto elapsed = std::chrono::duration<float, std::nano>(std::chrono::high_resolution_clock::now() - start);
			return elapsed.count();
		}
		else
		{
			auto elapsed = std::chrono::duration<float, std::nano>(stop - start);
			return elapsed.count();
		}
	}

	void Timer::Restart()
	{
		isrunning = true;
		start = std::chrono::high_resolution_clock::now();
	}

	bool Timer::Stop()
	{
		if (!isrunning)
			return false;
		else
		{
			stop = std::chrono::high_resolution_clock::now();
			isrunning = false;
			return true;
		}
	}

	bool Timer::Start()
	{
		if (isrunning)
		{
			return false;
		}
		else
		{
			start = std::chrono::high_resolution_clock::now();
			isrunning = true;
			return true;
		}
	}
}