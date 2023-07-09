#include "stdafx.h"
#include "Main.h"
#include <vector>

void Main::Init()
{
	//rc.SetWorldPos(Vector2(400.0f, 300.0f));
	rc.scale = Vector2(250.0f, 300.0f);
	rc.isAxis = true;
	rc.isFilled = false;
	//rc.isVisible = false;
	rc.color = Color(0.5f, 0.0f, 0.5f, 1.0f);
	//rc.pivot = OFFSET_LB;

	pet.SetParentRT(rc);
	pet.scale = Vector2(50.0f, 50.0f);
	pet.isAxis = true;
	pet.SetLocalPos(Vector2(100.0f, 100.0f));
	pet.color = Color(106.0f / 255.0f, 60.0f / 255.0f, 215.0f / 255.0f, 1.0f);

	gauge.SetParentT(rc);
	gauge.pivot = OFFSET_L;
	gauge.scale = Vector2(100.0f, 30.0f);
	gauge.SetLocalPosY(80.0f);
	gauge.SetLocalPosX(-50.0f);
	gauge.color = Color(77.0f / 255.0f, 50.0f / 255.0f, 248.0f / 255.0f, 1.0f);
	gauge.isVisible = false;


	//for (int i = 0; i < BMAX; i++)
	//{
	//	potato[i].SetParentRT(arrow[i]);
	//	potato[i].scale = Vector2(10.0f, 10.0f);
	//	potato[i].isAxis = true;
	//	potato[i].SetLocalPos(Vector2(50.0f, 50.0f));
	//	potato[i].color = Color(106.0f / 255.0f, 60.0f / 255.0f, 215.0f / 255.0f, 1.0f);

	//}



}

void Main::Release()
{
}

void Main::Update()
{
	//ImGui::ColorEdit3("Color", (float*)&pet.color, ImGuiColorEditFlags_PickerHueBar);
	////%d 서식문자 int , %f 실수 , %.3f 
	//ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (INPUT->KeyPress(VK_UP))
	{
		rc.MoveWorldPos(rc.GetRight() * 200.0f * DELTA);
	}
	else if (INPUT->KeyPress(VK_DOWN))
	{
		rc.MoveWorldPos(-rc.GetRight() * 200.0f * DELTA);
	}
	if (INPUT->KeyPress(VK_LEFT))
	{
		rc.rotation += 120.0f * ToRadian * DELTA;
	} 
	else if (INPUT->KeyPress(VK_RIGHT))
	{
		rc.rotation -= 120.0f * ToRadian * DELTA;
	}

	if (INPUT->KeyDown(VK_SPACE))
	{

		gauge.scale.x = 0.0f;
		gauge.isVisible = true;
	}

	if (INPUT->KeyPress(VK_SPACE))
	{
		gauge.scale.x += 100.0f * DELTA;

		if (gauge.scale.x > 100.0f)
		{
			gauge.scale.x = 0.0f;
		}
	}

	if (INPUT->KeyUp(VK_SPACE))
	{
		gauge.isVisible = false;
		
		for (int i = 0; i < BMAX; i++)
		{
			if (bullet[i].Shoot(rc, gauge))
			{
				break;
			}
		}
	}

	pet.revolution += 60.0f * ToRadian * DELTA;

	rc.Update();
	for (int i = 0; i < BMAX; i++)
	{
		bullet[i].Update(rc, gauge);
	}
	pet.Update();
	gauge.Update();

}

void Main::LateUpdate()
{
}

void Main::Render()
{
	rc.Render();
	for (int i = 0; i < BMAX; i++)
	{
		bullet[i].Render();
	}
	pet.Render();
	gauge.Render();

}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400.0f ,800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}