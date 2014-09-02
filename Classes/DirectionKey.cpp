#include "DirectionKey.h"

bool DirectionKey::init(){
	if (!Menu::init())
	{
		return false;
	}
	createDir();
	return true;
}

//���������
void DirectionKey::createDir(){
	auto upKey = MenuItemImage::create("tutorial_guide8.png","tutorial_guide8.png",[=](Ref *){
		up();
	}); 
	upKey->setPosition(0,30);
	upKey->setScale(0.2);

	auto downKey = MenuItemImage::create("tutorial_guide2.png","tutorial_guide2.png",[=](Ref *){
		down();
	});
	downKey->setPosition(0,-30);
	downKey->setScale(0.2);

	auto leftKey = MenuItemImage::create("tutorial_guide4.png","tutorial_guide4.png",[=](Ref *){
		left();
	});
	leftKey->setPosition(-30,0);
	leftKey->setScale(0.2);

	auto rightKey = MenuItemImage::create("tutorial_guide6.png","tutorial_guide6.png",[=](Ref *){
		right();
	});
	rightKey->setPosition(30,0);
	rightKey->setScale(0.2);

	//�����Ʒ������ӵ��˵���
	this->addChild(upKey);
	this->addChild(downKey);
	this->addChild(leftKey);
	this->addChild(rightKey);
}