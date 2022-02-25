#include "MiniginPCH.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include <SDL_ttf.h>

dae::Texture::Texture()
	:m_Texture{nullptr}
{
}

dae::Texture::~Texture()
{
}

void dae::Texture::Update()
{
	
}
void dae::Texture::FixedUpdate()
{
}

void dae::Texture::Render() const
{
	if (m_Texture != nullptr)
	{
		const auto& pos = m_Transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void dae::Texture::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}
void dae::Texture::SetPosition(const float x, const float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
