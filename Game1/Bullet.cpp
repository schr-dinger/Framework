#include "stdafx.h"

Bullet::Bullet()
{
	arrow.scale.x = 50.0f;
	arrow.isVisible = false;
	//isFired = false;

	potato->SetParentRT(arrow);
	potato->scale = Vector2(10.0f, 10.0f);
	potato->isAxis = true;
	potato->SetLocalPos(Vector2(50.0f, 50.0f));
	potato->color = Color(106.0f / 255.0f, 60.0f / 255.0f, 215.0f / 255.0f, 1.0f);
	potato->revolution = -90.0f*ToRadian ;

}

Bullet::~Bullet()
{
}

void Bullet::Update(ObRect rc, ObRect ga)
{
	if (!arrow.isVisible) return;
	arrow.MoveWorldPos(arrow.GetRight() * (100.0f+sp*3) * DELTA);
	//arrow.MoveWorldPos(arrow.GetRight() * (ga.scale.x*2) * DELTA);
	potato->revolution += 360.0f * ToRadian * DELTA;
	potato->rotation += 60.0f * ToRadian * DELTA;

	arrow.Update();
	potato->Update();

	//거리비교
	Vector2 dis = arrow.GetWorldPos() - rc.GetWorldPos();
	if (dis.Length() > 800.0f)
	{
		//isFired = false;
		arrow.isVisible = false;
	}


}

void Bullet::Render()
{
	if (!arrow.isVisible) return;

	//arrow.Render();
	potato->Render();

}

bool Bullet::Shoot(ObRect rc, ObRect ga)
{
	//함수호출방식 

	if (!arrow.isVisible)
	{
		
		arrow.isVisible = true;
		arrow.SetWorldPos(rc.GetWorldPos());
		arrow.rotation = Utility::DirToRadian(rc.GetRight());
		sp = ga.scale.x;
		//arrow.isVisible = true;

		return true;
	}
	return false;
}
