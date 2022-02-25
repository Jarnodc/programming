#include "MiniginPCH.h"
#include "FpsCounter.h"
#include <SDL_ttf.h>
#include "Renderer.h"
#include "Texture2D.h"
#include "TimerInfo.h"

dae::FpsCounter::FpsCounter(const std::shared_ptr<Font>& font)
	:TextObject("", font)
	,prevFps{}
{
}

dae::FpsCounter::FpsCounter()
	: TextObject("", ResourceManager::GetInstance().LoadFont("Lingua.otf", 36))
	,prevFps{}
{
}


void dae::FpsCounter::Update()
{
	const int fps = static_cast<int>(1 / dae::TimerInfo::GetInstance().GetElapsedSec());
	if (std::abs(fps - prevFps) >= 2)//Update only When fps has a big difference
	{
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), std::to_string(fps).c_str(),	m_Color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(),	surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") +		SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_TextTexture = std::make_shared<Texture2D>(texture);
		prevFps = fps;
	}
}
void dae::FpsCounter::FixedUpdate()
{
}

