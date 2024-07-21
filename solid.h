#ifndef SOLID_H
#define SOLID_H

class solid
{
public:
	~solid() = default;

	const virtual bool hit(const ray& r) const {}
};

#endif SOLID_H