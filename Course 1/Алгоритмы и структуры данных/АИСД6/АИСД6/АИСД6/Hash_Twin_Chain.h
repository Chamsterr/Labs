#pragma once
#include "Lists.h"
namespace hashTC
{
	struct Object
	{
		int size;
		int(*FunKey)(void*);
		listx::Object* Hash;

		Object(int Size, int(*f)(void*))
		{
			size = Size;
			FunKey = f;
			Hash = new listx::Object[Size]; 

		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
	};
	Object create(int size, int(*f)(void*));
}