#include "MiniginPCH.h"
#include <SDL_ttf.h>
#include "TextObject.h"
#include "Renderer.h"
#include "Texture2D.h"

dae::TextObject::TextObject(const std::string& text, const std::shared_ptr<Font>& font) 
	:m_NeedsUpdate(true), m_Text(text), m_Font(font), m_TextTexture(nullptr), m_Color({ 255,255,255 })
{ }

void dae::TextObject::Update()
{
	if (m_NeedsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), m_Color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_TextTexture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}
void dae::TextObject::FixedUpdate()
{

}

void dae::TextObject::Render() const
{
	if (m_TextTexture != nullptr)
	{
		const auto& pos = m_Transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_TextTexture, pos.x, pos.y);
	}
}

// This implementation uses the "dirty flag" pattern
void dae::TextObject::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}

void dae::TextObject::SetFont(const std::shared_ptr<Font>& font)
{
	m_Font = font;
}

void dae::TextObject::SetColor(const SDL_Color& color)
{
	m_Color = color;
}

void dae::TextObject::SetPosition(const float x, const float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

