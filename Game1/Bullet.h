#pragma once
class Bullet
{
public:
	ObLine arrow;
	ObCircle potato[BMAX];

	//bool isFired;

	float sp;

	Bullet();
	~Bullet();
	void Update(ObRect rc, ObRect ga);
	void Render();

	bool Shoot(ObRect rc, ObRect ga);
};

