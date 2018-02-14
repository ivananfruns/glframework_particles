#include <imgui\imgui.h>
#include <imgui\imgui_impl_sdl_gl3.h>
#include <glm\vec3.hpp>

namespace LilSpheres {
	extern const int maxParticles;
	extern void updateParticles(int startIdx, int count, float* array_data);
}
struct vec3 { float x, y, z; };
glm::vec3 positions[10000];
glm::vec3 velocitys[10000];
int start;
int end;

bool show_test_window = false;
void GUI() {
	bool show = true;
	ImGui::Begin("Physics Parameters", &show, 0);

	// Do your GUI code here....
	{	
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);//FrameRate
		
	}
	// .........................
	
	ImGui::End();

	// Example code -- ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

void PhysicsInit() {
	// Do your initialization code here...
	// ...................................
	start = 0;
	end = 999;
	for (int i = 0; i < 1000; i++)
	{
		positions[i].x = rand() % 3;
		positions[i].y = rand() % 3;
		positions[i].z = rand() % 3;

		if(i%2==0)
			velocitys[i].x = ((float)rand()) / (float)RAND_MAX;
		else
			velocitys[i].x = -((float)rand()) / (float)RAND_MAX;

		if (i % 3 == 0)
			velocitys[i].y = ((float)rand()) / (float)RAND_MAX;
		else
			velocitys[i].y = -((float)rand()) / (float)RAND_MAX;

		if (i % 4 == 0)
			velocitys[i].z = ((float)rand()) / (float)RAND_MAX;
		else
			velocitys[i].z = -((float)rand()) / (float)RAND_MAX;
	}

}

void PhysicsUpdate(float dt) {
	for (int i = start; i <= end; i++)
	{
		positions[i].x+= velocitys[i].x / 5;
		positions[i].y+= velocitys[i].y / 5;
		positions[i].z+= velocitys[i].z / 5;
	}
	LilSpheres::updateParticles(0, 999, reinterpret_cast<float*>(positions));
}

void PhysicsCleanup() {
	// Do your cleanup code here...
	// ............................
}