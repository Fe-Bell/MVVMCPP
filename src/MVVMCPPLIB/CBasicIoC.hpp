#pragma once
#include <functional>
#include <memory>
#include <unordered_set>
#include "DSharedDef.hpp"
#include <typeinfo>

namespace DependencyInjection
{
	class BasicIoc
	{
	public:
		typedef std::unique_ptr<BasicIoc> SafeBasicIocPtr;

		~BasicIoc();

		template<typename T>
		T* acquire();

		template<typename T>
		BasicIoc* store(const std::function<T*()>& builder);

		template<typename T>
		BasicIoc* remove(T* obj);

		static BasicIoc* instance();

	private:

		class IoCNode
		{
		private:
			IoCNode* next = nullptr;
			std::function<Object()> factory = nullptr;
			Object instance = nullptr;
			const std::type_info* typeInfo = nullptr;

		public:
			IoCNode(const std::type_info& typeInfo, const std::function<Object()>& factory) {
				this->typeInfo = &typeInfo;
				this->factory = factory;
			}
			
			~IoCNode() {
				this->dismount();
				delete (this->next);
			}

			void dismount() {
				Object object = popInstance();
				delete (object);
			}

			std::function<Object()> getFactory() {
				return this->factory;
			}

			Object getInstance() const {
				return this->instance;
			}

			IoCNode* getNext() {
				return this->next;
			}
		
			const bool isMounted() const {
				return this->instance != nullptr;
			}

			const bool isOfType(const std::type_info& typeInfo) const {
				return this->typeInfo->hash_code() == typeInfo.hash_code();
			}

			void mount() {
				if (!this->factory)
					return;

				/*if (this->instance != nullptr)
					delete (this->instance);*/

				this->instance = this->factory();
			}

			Object popInstance() {
				Object object = this->instance;
				this->instance = nullptr;
				return object;
			}
		
			void setNext(IoCNode*& node) {
				this->next = node;
			}
		};

		IoCNode* nodes = nullptr;
		static SafeBasicIocPtr s_instance;

		BasicIoc();

		void disposeContents();
	};

	template<typename T>
	inline T* BasicIoc::acquire()
	{
		T* ptr = nullptr;

		IoCNode* currentNode = this->nodes;
		while (currentNode != nullptr)
		{
			if (!currentNode->isOfType(typeid(T)))
			{
				currentNode = currentNode->getNext();
				continue;
			}

			if (!currentNode->isMounted())
			{
				currentNode->mount();
			}

			ptr = static_cast<T*>(currentNode->getInstance());
			break;
		}

		return ptr;
	}

	template<typename T>
	inline BasicIoc* BasicIoc::store(const std::function<T* ()>& builder)
	{
		if (this->nodes == nullptr) {
			this->nodes = new IoCNode(typeid(T), builder);
			return this;
		}

		IoCNode* currentNode = this->nodes;
		while (currentNode != nullptr)
		{
			if (currentNode->isOfType(typeid(T)))
			{
				return nullptr;
			}

			if (currentNode->getNext() != nullptr)
			{
				currentNode = currentNode->getNext();
				continue;
			}

			IoCNode* newNode = new IoCNode(typeid(T), builder);
			currentNode->setNext(newNode);
			break;
		}

		return this;
	}

	template<typename T>
	inline BasicIoc* BasicIoc::remove(T* obj)
	{
		IoCNode* currentNode = this->nodes;
		while (currentNode != nullptr)
		{
			if (!currentNode->isOfType(typeid(T)))
			{
				currentNode = currentNode->getNext();
				continue;
			}

			if (!currentNode->isMounted())
			{
				return nullptr;
			}

			//User shoudl be responsible for the destruction of the instance.
			currentNode->popInstance();
			break;
		}

		return this;
	}
}