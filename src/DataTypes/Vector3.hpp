#ifndef _VECTOR3_HPP__
#define _VECTOR3_HPP__

#include <limits>
#include <math.h>
#include <string>
#include <RakNet/BitStream.h>
#include <stdexcept>

class Vector3 {
public:
	// Properties
	float x, y, z;
	float sqrMagnitude() const { return powf(x, 2) + powf(y, 2) + powf(z, 2); }
	float magnitude() const { return sqrtf(this->sqrMagnitude()); }
	Vector3 normalized() const { return *this/this->magnitude(); }

	// Static properties
	static Vector3 up() { return Vector3(0, 1, 0); }
	static Vector3 down() { return Vector3(0, -1, 0); }
	static Vector3 forward() { return Vector3(0, 0, 1); }
	static Vector3 back() { return Vector3(0, 0, -1); }
	static Vector3 left() { return Vector3(-1, 0, 0); }
	static Vector3 right() { return Vector3(1, 0, 0); }
	static Vector3 positiveInfinity() { return Vector3(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity()); }
	static Vector3 negativeInfinity() { return Vector3(-std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity()); }
	static Vector3 one() { return Vector3(1, 1, 1); }
	static Vector3 zero() { return  Vector3(0, 0, 0); }

	// Constructors
	Vector3(const Vector3 &base) : x(base.x), y(base.y), z(base.z) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vector3(float a) : x(a), y(a), z(a) {}
	Vector3(RakNet::BitStream* bs) { bs->Read(*this); }

	// methods
	bool equals(Vector3 other) const { return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));	}
	bool equals(float other) const { return ((this->x == other) && (this->y == other) && (this->z == other));	}
	void set(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
	std::string toString() const { return "[ " + std::to_string(this->x) + " , " + std::to_string(this->y) + " , " + std::to_string(this->z) + " ]"; }

	// Static methods
	static float Dot(Vector3 lhs, Vector3 rhs) { return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z; }
	static Vector3 Cross(Vector3 lhs, Vector3 rhs) { return Vector3(abs(lhs.y*rhs.z-lhs.z*rhs.y), -abs(lhs.z*rhs.x-lhs.x*rhs.z), abs(lhs.x*rhs.y-lhs.y*rhs.x)); }
	static float Angle(Vector3 from, Vector3 to) { return (float)(acos(Dot(from, to)/(from.magnitude()*to.magnitude()))*180/acos(-1)); }
	static Vector3 ClampMagnitude(Vector3 vector, float maxLength) { return vector.normalized()*maxLength; }
	static float Distance(Vector3 a, Vector3 b) { return (a-b).magnitude(); }
	static Vector3 Lerp(Vector3 a, Vector3 b, float t) { (t<1?t:t=1); return a+(b-a)*t; }
	static Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t) { return a+(b-a)*t; }
	static Vector3 Max(Vector3 lhs, Vector3 rhs) { return Vector3((lhs.x>rhs.x?lhs.x:rhs.x), (lhs.y>rhs.y?lhs.y:rhs.y), (lhs.z>rhs.z?lhs.z:rhs.z)); }
	static Vector3 Min(Vector3 lhs, Vector3 rhs) { return Vector3((lhs.x<rhs.x?lhs.x:rhs.x), (lhs.y<rhs.y?lhs.y:rhs.y), (lhs.z<rhs.z?lhs.z:rhs.z)); }
	static Vector3 MoveTowards(Vector3 current, Vector3 target, float maxDistanceDelta) {
		Vector3 delta = target-current;
		if (delta.magnitude() < maxDistanceDelta) { return target; }
		else { return current+delta.normalized()*maxDistanceDelta; }
	}
	static Vector3 Normalize(Vector3 & value) {	value = value.normalized(); return value; } // Why return a Vector3?
	static Vector3 RotateTowards(Vector3 current, Vector3 target, float maxRadiansDelta, float maxMagnitudeDelta) {
		/// TODO implement
	}
	static Vector3 Scale(Vector3 a, Vector3 b) { return Vector3(a.x*b.x, a.y*b.y, a.z*b.z); }
	static float SignedAngle(Vector3 from, Vector3 to, Vector3 axis) {
		float angle = Angle(from, to);
		if (Angle(Cross(from, to), axis) < 90) { angle *= -1; }
		return angle;
	}
	static Vector3 Slerp(Vector3 a, Vector3 b, float t) {
		/// TODO implement
	}

	// Operators
	Vector3 operator + (Vector3 other) const { return Vector3(this->x+other.x, this->y+other.y, this->z+other.z);	}
	Vector3 operator + (float other) const { return Vector3(this->x+other, this->y+other, this->z+other); }
	Vector3 operator - (Vector3 other) const { return Vector3(this->x-other.x, this->y-other.y, this->z-other.z);	}
	Vector3 operator - (float other) const { return Vector3(this->x-other, this->y-other, this->z-other); }
	Vector3 operator * (Vector3 other) const { return Vector3(this->x*other.x, this->y*other.y, this->z*other.z);	}
	Vector3 operator * (float other) const { return Vector3(this->x*other, this->y*other, this->z*other);	}
	Vector3 operator / (Vector3 other) const { return Vector3(this->x/other.x, this->y/other.y, this->z/other.z);	}
	Vector3 operator / (float other) const { return Vector3(this->x/other, this->y/other, this->z/other);	}
	void operator += (Vector3 other) { *this = *this+other; }
	void operator += (float other) { *this = *this+other; }
	void operator -= (Vector3 other) { *this = *this-other; }
	void operator -= (float other) { *this = *this-other; }
	void operator *= (Vector3 other) { *this = *this*other; }
	void operator *= (float other) { *this = *this*other; }
	void operator /= (Vector3 other) { *this = *this/other; }
	void operator /= (float other) { *this = *this/other; }
	bool operator == (Vector3 other) const {
		return (((this->x > other.x-0.00001) && (this->x < other.x+0.00001))
				&& ((this->y > other.y-0.00001) && (this->y < other.y+0.00001))
				&& ((this->z > other.z-0.00001) && (this->z < other.z+0.00001)));
	}
	bool operator == (float other) const {
		return (((this->x > other-0.00001) && (this->x < other+0.00001))
				&& ((this->y > other-0.00001) && (this->y < other+0.00001))
				&& ((this->z > other-0.00001) && (this->z < other+0.00001)));
	}
	bool operator != (Vector3 other) const { return !(*this==other); }
	bool operator != (float other) const { return !(*this==other); }
	float operator [] (int index) const {
		switch(index) {
			case 0:	return this->x;
			case 1:	return this->y;
			case 2:	return this->z;
			default: throw new std::runtime_error("Index out of bounds");
		}
	}
};

#endif // !_VECTOR3_HPP__
