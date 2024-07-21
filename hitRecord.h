#ifndef HITRECORD_H
#define HITRECORD_H

class hitRecord
{
public:
	hitRecord(int d, int i) : distance(d), instance(i) {}

	const int getDistance() const
	{
		return distance;
	}

private:
	int distance;
	int instance;
};

#endif HITRECORD_H