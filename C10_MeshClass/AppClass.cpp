#include "AppClass.h"
void Application::InitVariables(void)
{
	m_pWindow->setPosition(sf::Vector2i(710, 0));

	//Make MyMesh object
	m_pMeshCircle = new MyMesh();
	m_pMeshCircle->AddCircle(2.0f, 7, vector3(0.0f, 0.5f, 0.0f));

	m_pMeshCone = new MyMesh();
	m_pMeshCone->GenerateCone(2.0f, 5.0f, 7, vector3(0.0f, 0.5f, 0.0f));

	m_pMeshCylinder = new MyMesh();
	m_pMeshCylinder->GenerateCylinder(2.0f, 5.0f, 7, vector3(0.0f, 0.5f, 0.0f));

	m_pMeshTube = new MyMesh();
	m_pMeshTube->GenerateTube(3.0f, 2.0f, 5.0f, 7, vector3(0.0f, 0.5f, 0.0f));
	
	//Make MyMesh object
	/*m_pMesh = new MyMesh();
	m_pMesh->AddQuad(vector3(0.0f, 0.0f, 0.0f), vector3(-1.0f, 0.0f, 0.0f), vector3(0.0f, -1.0f, 0.0f), vector3(-1.0f, -1.0f, 0.0f));
	m_pMesh->AddVertexColor(vector3(1.0f, 1.0f, 0.0f));
	m_pMesh->AddVertexColor(vector3(1.0f, 1.0f, 0.0f));
	m_pMesh->AddVertexColor(vector3(0.0f, 1.0f, 0.0f));*/
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	//CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));
	//m_pMeshCircle->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));
	m_pMeshTube->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), ToMatrix4(m_qArcBall));

	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList("Skybox_02.png");
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	if (m_pMeshCircle != nullptr)
	{
		delete m_pMeshCircle;
		m_pMeshCircle = nullptr;
	}
	SafeDelete(m_pMeshCone);
	//release GUI
	ShutdownGUI();
}