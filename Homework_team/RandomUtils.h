#pragma once

#include <random>
#include <limits>

// ����: int randInt = RandomUtil::getInt(1, 10);		// 1~10 ������ ���� 
namespace RandomUtil {
	// ���� static random ����
	inline std::mt19937& engine()
	{
		static std::mt19937 eng{ std::random_device{}() }; // ���� 1ȸ �õ�
		return eng;
	}

	// ������ ���� ���� (a~b)
	inline int getInt(int a, int b)
	{
		std::uniform_int_distribution<int> dist(a, b);
		return dist(engine());
	}
}