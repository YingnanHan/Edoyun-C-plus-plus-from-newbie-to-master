#pragma once
// 要考虑嵌套的先后问题，防止循环包含，或者使用防卫式声明
class Role
{
public:
	class skill;
};