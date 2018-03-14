#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <iostream>

namespace Ressources
{
	class Component;
	class GameObject;

	using ComponentID = std::size_t;
	constexpr  std::size_t maxComponents = 32;
	using ComponentBitSet = std::bitset<maxComponents>;
	using ComponentArray = std::array<Component*, maxComponents>;

	inline ComponentID getComponentTypeID()
	{
		static ComponentID lastID = 0u;
		return lastID++;
	}

	template<typename T> 
	ComponentID getComponentTypeID() noexcept
	{
		static ComponentID typeID = getComponentTypeID();
		return typeID;
	}

	class Component
	{
	public:
		GameObject* m_parent;

		virtual void Awake(){}
		virtual void Update(){}
		virtual void Draw(){}
		virtual void LateUpdate(){}

		virtual ~Component(){}
	};

	class GameObject
	{
	protected:
		bool m_active = true;
		std::vector<std::unique_ptr<Component>> m_components;

		ComponentArray m_componentArray;
		ComponentBitSet m_componentBitSet;

	public:

		~GameObject() {}

		void Update()
		{
			for (auto& c : m_components) c->Update();
		}

		void Draw()
		{
			for (auto& c : m_components) c->Draw();
		}

		void LateUpdate()
		{
			for (auto& c : m_components) c->LateUpdate();
		}

		bool IsActive() const { return m_active; }
		void Destroy() { m_active = false; }

		template<typename T>
		bool HasComponent() const
		{
			return m_componentBitSet[getComponentTypeID<T>()];
		}

		template<typename T, typename ...TArgs>
		T& AddComponent(TArgs&&... mArgs)
		{
			//Core::Debug::Assertion::Assert(!HasComponent <T>(), "ERROR::ENTITY_HAS_ALREADY::COMPONENT");

			T* c(new T(std::forward<TArgs>(mArgs)...));

			c->m_parent = this;
			std::unique_ptr<Component> cPtr{ c };
			m_components.emplace_back(std::move(cPtr));

			m_componentArray[getComponentTypeID<T>()] = c;
			m_componentBitSet[getComponentTypeID<T>()] = true;

			c->Awake();
			return *c;
		}

		template<typename T> T& GetComponent() const
		{
			//Core::Debug::Assertion::Assert(std::is_base_of<Component, T>::value, "ERROR::GETCOMPONENT::T_NOT_A_COMPONENT");

			auto ptr(m_componentArray[getComponentTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}
	};
}
