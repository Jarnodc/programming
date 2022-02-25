#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	for (auto& comp : m_pComponents)
	{
		comp->Update();
	}
	for (auto& child : m_pChilds)
	{
		child->Update();
	}
}
void dae::GameObject::FixedUpdate()
{
	for (auto& comp : m_pComponents)
	{
		comp->FixedUpdate();
	}
	for (auto& child : m_pChilds)
	{
		child->FixedUpdate();
	}
}

void dae::GameObject::Render() const
{
	for (auto& comp : m_pComponents)
	{
		comp->Render();
	}
	for (auto& child : m_pChilds)
	{
		child->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::SetParent(const std::shared_ptr<GameObject>& parent)
{
	m_pParent = parent;
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetParent() const
{
	return m_pParent;
}

size_t dae::GameObject::GetChildCount() const
{
	return m_pChilds.size();
}

std::shared_ptr<dae::GameObject> dae::GameObject::GetChildAt(int index) const
{
	if (index > m_pChilds.size())
		return nullptr;

	return m_pChilds.at(index);
}

void dae::GameObject::RemoveChild(int index)
{
	if (index > m_pChilds.size())
		return;

	m_pChilds.at(index).swap(*m_pChilds.end());
	m_pChilds.pop_back();
}

void dae::GameObject::AddChild(const std::shared_ptr<GameObject>& go)
{
	m_pChilds.push_back(go);
}

